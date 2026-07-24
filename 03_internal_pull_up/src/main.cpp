#define  F_CPU 16000000UL //clock frequency 
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    /* configuring PORTD pin 5 as input & PORTB Pin 2 as output*/
	DDRD &= ~(1 << DDD5);
	DDRB |= (1 << DDB2);
	
	PORTD |= (1 << PORTD5); //enabling internal pull - up
	
    while (1) 
    {
		/*
				xx1x xxxx
				0010 0000
			---------------
		*/
		
if(!(PIND & (1 << PIND5))) 
		{
			PORTB |= (1 << PORTB2);
		}
		else
		{
			PORTB &= ~(1 << PORTB2);
		}
		
    }
}
