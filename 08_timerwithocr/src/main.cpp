#define F_CPU 16000000UL
#include<avr/io.h>
#include<avr/interrupt.h>
volatile uint16_t count = 0;
ISR(TIMER0_OVF_vect)
{
  count++;
  if(count>=1953)
  {
    PORTB^=(1<<PORTB2);
    count=0;
  }

}
void timer()
{
TCNT0=0;
TCCR0A&=~((1<<WGM01)|(1<<WGM00));
TCCR0B|=(1<<CS01)|(1<<CS00);
TCCR0B&=~(1<<CS02);
TIMSK0|=(1<<TOIE0);
}
int main()
{
  timer();
  sei();
  DDRB|=(1<<DDB2);
  PORTB&=~(1<<PORTB2);

  while(1)
  {

  }

}