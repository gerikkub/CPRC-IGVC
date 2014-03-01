/***************************
*
* Filename: usart.cpp
*
* Description: Provides print methods for various
*  datatypes using USART.
*
* Authors: Doug Gallatin and Jason Schray
* Edited by: Tim Peters & James Humphrey
*
***************************/

#include "FreeRTOS.h"
#include "semphr.h" 
#include "queue.h"
//#include "protocol.h"

#include <stdlib.h>
#include <stdint.h>
#include <avr/io.h>


#include "usart.h"

xQueueHandle USART_WriteQueue;
xQueueHandle USART_ReadQueue;

uint8_t calcChecksum(uint8_t* buffer,uint8_t size);
void sendACK();
void sendNACK();

/************************************
* Procedure: usart_init
*  
* Description: Initializes the USART module with 
*  the specified baud rate and clk speed.
*
* Param buadin: The desired Baud rate.
* Param clk_seedin: The clk speed of the ATmega328p
************************************/
void USART_Init(uint16_t baudin, uint32_t clk_speedin) {
    USART_WriteQueue = xQueueCreate(32,sizeof(uint8_t));
    USART_ReadQueue = xQueueCreate(8,sizeof(uint8_t));

    uint32_t ubrr = clk_speedin/(16UL)/baudin-1;
    UBRR1H = (unsigned char)(ubrr>>8) ;// & 0x7F;
    UBRR1L = (unsigned char)ubrr;
    
    //UBRR0H = 0; //115200
    //UBRR0L = 8;

    /* Enable receiver and transmitter */
    UCSR1B = (1<<RXEN1)|(1<<TXEN1);
    /* Set frame format: 8data, 1stop bit */
    UCSR1C = (1<<UCSZ11)|(1<<UCSZ10);
	// clear U2X0 for Synchronous operation
    UCSR1A &= ~(1<<U2X1);

    //UCSR0B |= (1<<UDRIE0);

}

/*the send function will put 8bits on the trans line. */
void USART_Write(uint8_t data) {
		/* Wait for empty transmit buffer */
		while ( !( UCSR0A & (1<<UDRE0)) )
		;
		/* Put data into buffer, sends the data */
		UDR0 = data;
}

/*the send function will put 8bits on the trans line. */
void USART_Write_Unprotected(uint8_t data) {
	/* Wait for empty transmit buffer */
	while ( !( UCSR0A & (1<<UDRE0)) )
	;
	/* Put data into buffer, sends the data */
	UDR0 = data;
}

/* the receive data function. Note that this a blocking call
Therefore you may not get control back after this is called 
until a much later time. It may be helpful to use the 
istheredata() function to check before calling this function
        @return 8bit data packet from sender
*/
uint8_t USART_Read(void) {
    /* Wait for data to be received */
    while ( !(UCSR0A & (1<<RXC0)) )
        ;
    /* Get and return received data from buffer */
    return UDR0;
}


ISR(USART1_RX_vect){
    uint8_t data;
    data = UDR1;
    xQueueSendToBackFromISR(USART_ReadQueue,&data,NULL);
}

void USART_AddToQueue(uint8_t data){
    
    xQueueSendToBack(USART_WriteQueue,&data,portMAX_DELAY);

}

void USART_TransmitString(char* str){
    while(*str) {
        USART_AddToQueue(*str);
        str++;
    }
}

void vTaskUARTWrite(void *pvParameters)
{
    uint8_t data;
    while(1){
        while(xQueueReceive(USART_WriteQueue,&data,portMAX_DELAY)==pdFALSE);

        while(!(UCSR1A & (1<<UDRE1))) vTaskDelay(1);
        UDR1 = data;

    }
}

void vTaskUARTRead(void *pvParameters){

    char bytesRecieved;
    uint8_t rxData;
    uint8_t buffer[8];
    char size;
    char groupID;
    char cmd;
    char timeout;

    //Command command;
    //Response response;

    while(1){
        //Get Header
        bytesRecieved = 0;
        while(bytesRecieved < 4){
            if((UCSR1A & (1<<RXC1))){
                rxData = UDR1;
                //PORTB = 0;
            //if(xQueueReceive(USART_ReadQueue,&rxData,portMAX_DELAY) == pdTRUE){
                buffer[bytesRecieved] = rxData;
                //USART_AddToQueue(rxData);
                bytesRecieved++;
            }
        }
        if(calcChecksum(buffer,3) != buffer[3]){
            sendNACK();
        } else {
            sendACK();
            bytesRecieved = 0;
            //command.groupID = buffer[0];
            //command.cmd = buffer[1];
            //command.crc = buffer[3];
            size = buffer[2];
            timeout = 0;
            while(1){
                if(size == 0){
                    //processCommand(&command,&response);
                }
                while((bytesRecieved < size+1) && (timeout < 50)){  //1 for crc
                    if(UCSR1A & (1<<RXC1)){
                        rxData = UDR1;

                        //PORTB = 0xFF;
                    //if(xQueueReceive(USART_ReadQueue,&rxData,portMAX_DELAY) == pdTRUE){
                        buffer[bytesRecieved] = rxData;
                        bytesRecieved++;
                    } else {
                        //timeout++;
                        timeout = 1;
                    }
                } 
                if(timeout >= 50){
                    break;
                }
                if(calcChecksum(buffer,size) != buffer[size]){
                    sendNACK();
                    bytesRecieved = 0;
                } else {
                    PORTB = buffer[0];
                    sendACK();
                    //memcpy(command.payload,buffer,size);
                    //processCommand(&command,&response);
                    break;
                }
            }
        }

    }

}

void sendACK(){
    USART_AddToQueue(0xFF);
}

void sendNACK(){
    USART_AddToQueue(0);
}

uint8_t calcChecksum(uint8_t* buffer,uint8_t size){
    uint8_t checksum = 0;
    while(size-- > 0){
        checksum += *(buffer++);
    }
    return checksum;
}