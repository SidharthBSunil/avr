#define F_CPU 16000000UL
#include<avr/io.h>
void pwm()
{
  
DDRD |= (1 << DDD6);
//non-inverting mode
TCCR0A&=~(1<<COM0A0);
TCCR0A|=(1<<COM0A1); 
//pwm phase correct
TCCR0A|=(1<<WGM00); 
//prescaling 8
TCCR0B|=(1<<CS01);
}
void dc_motor_and_button()
{
  DDRB|=(1<<DDB3)|(1<<DDB4);//for forward motor
  DDRD&=~(1<<DDD5);//button
  PORTD|=(1<<PORTD5);//ON INTERNAL RESISTOR
}
void motor_forward()
{
  PORTB|=(1<<PORTB3);//B3 ON
  PORTB&=~(1<<PORTB4);//B4 OFF
  
}
void motor_backward()
{
  PORTB&=~(1<<PORTB3);//B3 OFF
  PORTB|=(1<<PORTB4);//B4 ON
}
int main()
{

  pwm();
  dc_motor_and_button();
  OCR0A=125;

  
 
  
  while(1)
  {
      
      if(!(PIND&(1<<PIND5)))
      {
        motor_forward();
      }
      else
      {
        motor_backward();
      }
      

    
    
    
  }
}