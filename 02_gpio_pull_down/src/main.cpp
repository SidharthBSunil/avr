#define F_CPU 16000000UL
#include<avr/io.h>
int main()
{

  DDRB|=(1<<DDB3);
  DDRD&=~(1<<DDD6);
  while(1)
  {
    if(PIND&(1<<DDD6))
    {
      PORTB|=(1<<PORTB3);
    }
    else
    {
      PORTB&=~(1<<PORTB3);
    }

  }
}