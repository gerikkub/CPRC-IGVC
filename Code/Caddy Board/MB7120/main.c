#include <Arduino.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void setup() {
  //setup serial
  Serial.begin(9600);
  //set up ADC
  //enable the ADC
  ADCSRA |= _BV(ADEN);
  //use avcc as reference
  ADMUX |= _BV(REFS0);
  //allow for all interrupts
  sei();
}

void ADCStart() {
  //only if there is not a current conversion...
  if(!(ADCSRA & _BV(ADSC))) {
    //allow for ADC interrups
    ADCSRA |= _BV(ADIE);
    //start conversion bit
    ADCSRA |= _BV(ADSC);
  }
}

ISR(ADC_vect) {
  //capture result
  int result = (ADCL);
  result |= (ADCH << 8);
  //print out the result...
  Serial.println(result);
  //disable interrupt for now
  ADCSRA &= ~(_BV(ADIE));
}
  

void loop() {
  ADCStart();
  _delay_ms(100);
}
