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
    UBRR0H = (unsigned char)(ubrr>>8) ;// & 0x7F;
    UBRR0L = (unsigned char)ubrr;
    
    //UBRR0H = 0; //115200
    //UBRR0L = 8;

    /* Enable receiver and transmitter */
    UCSR0B = (1<<RXEN0)|(1<<TXEN0);
    /* Set frame format: 8data, 1stop bit */
    UCSR0C = (1<<UCSZ01)|(1<<UCSZ00);
	// clear U2X0 for Synchronous operation
    UCSR0A &= ~(1<<U2X0);

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


ISR(USART0_RX_vect){
    uint8_t data;
    data = UDR0;
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

        while(!(UCSR0A & (1<<UDRE0))) vTaskDelay(1);
        UDR0 = data;

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

    while(1){
        //Get Header
        bytesRecieved = 0;
        while(bytesRecieved < 4){
            if((UCSR0A & (1<<RXC0))){
                rxData = UDR0;
            //if(xQueueReceive(USART_ReadQueue,&rxData,portMAX_DELAY) == pdTRUE){
                buffer[bytesRecieved] = rxData;
                //USART_AddToQueue(rxData);
                bytesRecieved++;
            }
        }
        if(calcChecksum(buffer,3) != buffer[3]){
            while(1){
                sendNACK();
                PORTB ^= 0xFF;
                vTaskDelay(105);
            }
        } else {
            while(1){
                sendACK();
                PORTB ^= 0xFF;
                vTaskDelay(105);
            }
            /*bytesRecieved = 0;
            size = buffer[2];
            groupID = buffer[0];
            cmd = buffer[1];
            timeout = 0;
            while(1){
                while((bytesRecieved < size+1) && (timeout < 50)){  //1 for crc
                    if(xQueueReceive(USART_ReadQueue,&rxData,portMAX_DELAY) == pdTRUE){
                        buffer[bytesRecieved] = rxData;
                        bytesRecieved++;
                    } else {
                        timeout++;
                    }
                } 
                if(timeout >= 50){
                    break;
                }
                if(calcChecksum(buffer,size) != buffer[size]){
                    sendNACK();
                    bytesRecieved = 0;
                } else {
                    sendACK();
                    processData(groupID,cmd,size,buffer);
                    break;
                }
            }*/
        }

    }

}

void sendACK(){
    USART_AddToQueue('y');
}

void sendNACK(){
    USART_AddToQueue('n');
}

uint8_t calcChecksum(uint8_t* buffer,uint8_t size){
    uint8_t checksum = 0;
    while(size-- > 0){
        checksum += *(buffer++);
    }
    return checksum;
}