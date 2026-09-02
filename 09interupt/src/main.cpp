#define F_CPU 16000000UL
#include<avr/io.h>
#include <avr/interrupt.h>
void ex_inter()
{
  //int0
  //pd2 enable as pull up for fall
  DDRD &=~(1<<DDD2);
  PORTD|=(1<<PORTD2);//inter pullup
  EICRA |=(1<<ISC01);
  EICRA &=~(1<<ISC01);
  //step 3enabling external interrupt int0
  EIMSK|=(1<<INT0);
}
ISR(INT0_vect)
{
  PORTB^=(1<<PORTB5);
}
void led()
{
  DDRB|=(1<<DDB5);
  PORTB &=~(1<<PORTB5);
}
int main()
{
led();
ex_inter();
sei();
while(1);

}