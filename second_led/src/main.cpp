
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    DDRB = (1 << PB4)|(1 << PB3)|(1<<PB5);

    while (1)
    {
        
        
        for(int i=3;i<=5;i++)
        {
          PORTB |= (1 << i);
          _delay_ms(500);
         
        }
        
        for(int i=5;i>=3;i--)
        {
          PORTB &= ~(1 << i);
          _delay_ms(500);
          
        }
        
    }
}