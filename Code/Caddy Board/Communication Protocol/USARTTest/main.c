
#include <avr/io.h>



void USART_Init(uint16_t baudin, uint32_t clk_speedin) {
    uint32_t ubrr = clk_speedin/(16UL)/baudin-1;
    UBRR0H = (unsigned char)(ubrr>>8) ;// & 0x7F;
    UBRR0L = (unsigned char)ubrr;
    
    //UBRR0H = 0; //115200
    //UBRR0L = 8;

    /* Enable receiver and transmitter */
    UCSR0B = (1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0);
    /* Set frame format: 8data, 1stop bit */
    UCSR0C = (1<<UCSZ01)|(1<<UCSZ00);
	// clear U2X0 for Synchronous operation
    UCSR0A &= ~(1<<U2X0);

    //UCSR0B |= (1<<UDRIE0);


    //UART0 Logging

    /*USART_WriteQueueLog = xQueueCreate(32,sizeof(uint8_t));

    ubrr = clk_speedin/(16UL)/baudin-1;
    UBRR0H = (unsigned char)(ubrr>>8) ;// & 0x7F;
    UBRR0L = (unsigned char)ubrr;
    
    //UBRR0H = 0; //115200
    //UBRR0L = 8;

    /* Enable receiver and transmitter */
    //UCSR0B = (1<<RXEN0)|(1<<TXEN0);
    /* Set frame format: 8data, 1stop bit */
    //UCSR0C = (1<<UCSZ01)|(1<<UCSZ00);
    // clear U2X0 for Synchronous operation
    //UCSR0A &= ~(1<<U2X0);*/

}


int main(){
	USART_Init(9600, 16000000);
	DDRB = 0xFF;
	PORTB = 0;
	asm("sei");
	while(1){
		if((UCSR1A & (1<<RXC0))){
			//PORTB = 0xFF;
		}
	}

}

ISR(USART0_RX_vect){
	PORTB = 0xFF;
}