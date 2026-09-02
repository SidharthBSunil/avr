#define F_CPU 16000000UL
#include<avr/io.h>
#include<avr/interrupt.h>
void interupt()
{
  DDRB&=~(1<<DDB3);//setup switch
  EIMSK|=(1<<INT1);
  EICRA|=((1<<ISC11)|(1<<ISC10));//rise mode

}
void led()
{
  DDRB|=(1<<DDB5);//setup led
  DDRB|=(1<<DDB2);
  PORTB &= ~(1 << PORTB2);//turn off led when booting
}
ISR(INT1_vect)
{
  //toggling the led when the external interrupt got triggered
	PORTB ^= (1 << PORTB2);	
}
int main()
{
  sei();
  interupt();
  led();
  while(1)
  {
    PORTB|=(1<<PORTB5);
  }
}