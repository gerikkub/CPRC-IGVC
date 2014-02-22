// Code to controller the Sonar sensors
#include "FreeRTOS.h"
#include "semphr.h"
#include <avr/interrupt.h>
#include <avr/io.h>

#include "../../protocol.h"
#include "Sonar.h"

xSemaphoreHandle* sonarSemaphore;
xSemaphoreHandle* sonarDataMutex[6];

unsigned char sonarData[6];
extern int count;

unsigned char currSonar;
unsigned char lastSonarData = 0;
   
void setSonarData(int i,unsigned char data){
// xSemaphoreTake(sonarDataMutex[i],portMAX_DELAY);
   sonarData[i] = data;
   //xSemaphoreGive(sonarDataMutex[i]);
}

unsigned char getSonarData(int i){
   //xSemaphoreTake(sonarDataMutex[i],portMAX_DELAY);
   //return sonarData[i];
   return i + 2;
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
      //USART_AddToQueue('U');
      beginCount = getTimerCount();
      PORTE = 0xFF;
   } else {
      //USART_AddToQueue('D');
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

char getAllSensors(unsigned short* responseData){
   unsigned short i;
   for(i=0;i<6;i++){
      responseData[i] = getSonarData(i);
      //responseData[i] = i;
   }
}

char getCertainSensor(char commandData,int* responseData){
   if(commandData < 6){
      responseData[commandData] = getSonarData(commandData);
   }
}

char getSensorGroup(char commandData,int* responseData){

   switch(commandData){
      case SONAR_GROUP_LEFT:
         responseData[0] = getSonarData(0);
         responseData[1] = getSonarData(1);
         break;
      case SONAR_GROUP_FRONT:
         responseData[0] = getSonarData(2);
         responseData[1] = getSonarData(3);
         break;
      case SONAR_GROUP_RIGHT:
         responseData[0] = getSonarData(4);
         responseData[1] = getSonarData(5);
         break;
   }

}