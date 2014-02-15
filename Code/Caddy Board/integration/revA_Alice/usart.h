/***************************
*
* Filename: usart.h
*
* Description: Provides print methods for various
*  datatypes using USART.
*
* Authors: Doug Gallatin and Jason Schray
*
***************************/


#ifndef USART_H_
#define USART_H_

uint8_t USART_Read(void);
void USART_Write(uint8_t data);
void USART_Write_Unprotected(uint8_t data);
void USART_Init(uint16_t baudin, uint32_t clk_speedin);
void USART_AddToQueue(uint8_t data);
void USART_TransmitString(char *str);
void vTaskUSARTWrite(void *param);
void vTaskUSARTRead(void *param);
uint8_t calcChecksum(uint8_t* buffer,uint8_t size);
void sendACK();
void sendNACK();
char waitForChecksum();

void USART_LogChar(uint8_t data);
void USART_LogString(char* str);
void vTaskUSARTLog(void *param);

#endif /* USART_H_ */
