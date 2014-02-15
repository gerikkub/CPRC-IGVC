/*
 FreeRTOS V6.1.0
 
 This is a basic RTOS program. It turns on the LEDs.
 Nothing too exciting.
 
 */

#include <stdint.h>
#include <avr/io.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "FreeRTOS.h"
#include <avr/interrupt.h>
#include "task.h"
#include "usart.h"
#include "sonar.h"
#include "queue.h"

void vTaskFunction_1(void *pvParameters);
void vIO_init(void);
void vApplicationTickHook();
void printNum(unsigned char i);
void printHex(int i);

int count = 0;

int sonarTime;

void vApplicationTickHook()
{
    count++;
}
/*-----------------------------------------------------------*/

int main( void )
{
    
    //- wimpy variable defs
	uint8_t val[2] = {0x3F, 0xFE};
    uint8_t *val0, *val1;
    
	//- avoid pesky warnings...
	val0 = val + 0;
	val1 = val + 1;
    
	DDRD = 0xFF;
	DDRE = 0xFF;
	DDRK = 0;

	PORTD = 0;
	PORTE = 0;
	PORTK = 2;

    //- init IO with goodness
	vIO_init();

	//- Create a 
	xTaskCreate( (pdTASK_CODE) vTaskFunction_1, (signed char *) "T0", configMINIMAL_STACK_SIZE+1000,
                (void *) val1, 1, NULL );
    
   xTaskCreate( (pdTASK_CODE) vTaskSonar, (signed char *) "T0", configMINIMAL_STACK_SIZE,
                (void *) val1, 1, NULL );

   xTaskCreate( (pdTASK_CODE) vTaskUARTWrite, (signed char *) "T0", configMINIMAL_STACK_SIZE,
   				(void *) val1, 1, NULL);

   xTaskCreate( (pdTASK_CODE) vTaskUARTRead, (signed char *) "T0", configMINIMAL_STACK_SIZE,
   				(void *) val1, 1, NULL);

    
    //- kick off the scheduler
	vTaskStartScheduler();
    
	return 0;
}
/*-----------------------------------------------------------*/

void printHex(int i){
	char hex[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

	USART_Write(hex[(i&0xF000) >> 12]);
	USART_Write(hex[(i&0xF00) >> 8]);
	USART_Write(hex[(i&0xF0) >> 4]);
	USART_Write(hex[i&0xF]);

}

void printNum(unsigned char i){
    
    char str[10];
    memset(str,0,10);
    itoa(i,str,9);
    char * irr = str;
    while(*irr){
        USART_Write((unsigned char )*irr);
        irr++;
    }
    
}

ISR(TIMER5_OVF_vect){

	PORTB ^= 0xFF;
	TCNT3L = 0;
	TCNT3H = 0;

}

unsigned int getTimerCount2(){

	//volatile char timerLow = TCNT3L;

	return TCNT0;

}

void vTaskFunction_1(void *pvParameters)
{	
    USART_Init(9600, 16000000);
	//static const char* str = "Hello World\n";
	for(;;){
		//PORTB = 0;
		//USART_AddToQueue('%');
		//USART_TransmitString("Hello World!\n");

		//USART_TransmitString("H\n");
		vTaskDelay(25);
	}
	/*for(;;){
		printNum(getTimerCount2());
		USART_Write('\n');
	}*/

    for (;;)  {
//        PORTB ^=  0xff;j
		//PCMSK2 = 1;

      printNum(getSonarData(0));
		USART_Write(' ');
		printNum(getSonarData(1));
		USART_Write('\n');
      vTaskDelay(25);
        /* Get and return received data from buffer */
        // UDR0;
    }
}

void vIO_init(void)
{
    //- set PortB as output
	DDRB = 0xFF; 
    PORTB = 0xFF; 
}


