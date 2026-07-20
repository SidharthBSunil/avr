#define  F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>


int main(void)
{
	
	//setting directions for PORTD pin5 (Input) and PORTB pin 2 (Output)
	DDRD &= ~(1 << DDD5);
	DDRB |= (1 << DDB2);
  PORTB &= ~(1 << PORTB2);
	//PORTB &= ~(1 << PORTB2);
    while (1) 
    {
		if (!(PIND & (1 << PIND5)))
		{
			//led should turn ON
			PORTB |= (1 << PORTB2);
		}
    else
    {
      PORTB &= ~(1 << PORTB2);
    }
    
		
    }
}
