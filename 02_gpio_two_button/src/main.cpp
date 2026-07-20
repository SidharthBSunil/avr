#define F_CPU 16000000UL
#include<avr/io.h>
int main()
{
  DDRD&=~(1<<DDD5);
  DDRD&=~(1<<DDD6);
  DDRB|=(1<<DDB2);
  while(1)
  {
    if(PIND&(1<<PIND5))
    {
      PORTB|=(1<<PORTB2);
    }
    else if(PIND&(1<<PIND6))
    {
      PORTB&=~(1<<PORTB2);
    }
    else if(&&)
    
  }
}