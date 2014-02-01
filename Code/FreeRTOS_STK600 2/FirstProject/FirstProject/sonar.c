// Code to controller the Sonar sensors
#include "FreeRTOS.h"
#include "semphr.h"
#include <avr/interrupt.h>
#include "sonar.h"
#include <avr/io.h>

xSemaphoreHandle*	sonarSemaphore;
xSemaphoreHandle* sonarDataMutex[6];

unsigned char sonarData[6];
extern int count;

unsigned char currSonar;
unsigned char lastSonarData = 0;
	
void setSonarData(int i,unsigned char data){
//	xSemaphoreTake(sonarDataMutex[i],portMAX_DELAY);
	sonarData[i] = data;
	//xSemaphoreGive(sonarDataMutex[i]);
}

unsigned char getSonarData(int i){
	//xSemaphoreTake(sonarDataMutex[i],portMAX_DELAY);
	return sonarData[i];
	//xSemaphoreGive(sonarDataMutex[i]);
}

unsigned char getTimerCount(){
	return TCNT0;
}

inline void setTimerCount(unsigned char i){
	TCNT0 = i;
}

ISR(PCINT2_vect) {

	unsigned char beginCount;
	unsigned char currCount;
	char i=0;	

	if(PINK&(1<<currSonar)){
		beginCount = getTimerCount();
		PORTE = 0xFF;
	} else {
		currCount = getTimerCount();
		if(currCount > beginCount){
			lastSonarData = currCount - beginCount;
		}
		PORTE = 0;
		xSemaphoreGiveFromISR(sonarSemaphore,0);
	}

}

void initializeSonarSensors(){
	//DDRD &= 0xFE;	
	DIDR2 = 0;
	DDRK = 0;
	DDRC = 0;

	PORTC = 0;

	//EICRA = 1;
	//EIMSK = 1;

	PCMSK2 = 0xFF;
	PCICR = 0x7;

	TCCR0A = 0;
	TCCR0B = 5;

}

void vTaskSonar(void* parameter){

	int i;
	initializeSonarSensors();
	
	vSemaphoreCreateBinary(sonarSemaphore);
		
	currSonar = 0;

	while(1){
		for(i=0;i<2;i++){
			currSonar = i;
			PORTC = (1<<i);
			xSemaphoreTake(sonarSemaphore,portMAX_DELAY);
			setSonarData(i,lastSonarData);
		}
	}
				
} 
