
#define F_CPU 16000000UL
#include <avr/io.h>


void timer0_1s_delay() 
{
 //load initial value to TCNT0
 TCNT0 = 0;
 //configured into normal mode
 TCCR0A &= ~((1 << WGM00) | (1 << WGM01));
 //configuring 64 pre-scaler mode
 TCCR0B |=  ((1 << CS01) | (1 << CS00));
 TCCR0B &= ~(1 << CS02);
 
 /*-------------------CALCULATION------------------------
 NB: when using pre-scaler value should divide clock frequency using it and use the resultant value
  eg: pre-scaler: 64 | clock frequency = 16,000,000 
   new clock frequency = 16,000,000 / 64 = 250,000
   
  Clock-frequency : 250,000
  1. Tick = 1 / clock frequency
         = 1 / 250,000
      = 0.00 000 4 seconds
      = 4 micro-seconds
      
 ` 2. Time required for one overflow = total ticks x time required for 1 tick
            = 256 x 4 micro-seconds
            = 1024 micro-seconds
            
  3. How many overflow required to make one second 
   1 second = 1000 ms = 1000 000 micro-seconds
   = 1000 000/1020
   = 977 -> overflows required to make 1 second
 -----------------------------------------------------------------------------------  
 
*/
 for(uint16_t i = 0; i < 977; i++)
 {
  //wait until the overflow flag (TOV0) is set
  while (!(TIFR0 & (1 << TOV0))); //0 -> false | 1 -> true
  //clear the overflow flag in TOV0 by writing logic 1 to it
  TIFR0 |= (1 << TOV0);
 }
}

int main(void)
{
 //configuring PORTB PIN 2 as Output
 
 DDRB |= (1 << DDB2);
    
    while (1) 
    {
  //making portb as high
  PORTB |= (1 << PORTB2);
  timer0_1s_delay();
  //making my portb as low
  PORTB &= ~(1 << PORTB2);
  timer0_1s_delay();
  
    }
}