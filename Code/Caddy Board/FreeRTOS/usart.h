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

#endif /* USART_H_ */
