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

int main()
{
  uint8_t prev=0; //to track 0 to 1
  
  dc_motor_and_button();
  pwm();
  motor_forward();
  
  int count=2;
  
 //ocr=(percentage*256)/100
  
  while(1)
  {
      uint8_t button=!(PIND&(1<<PIND5));
      if(prev==0 &&  button==1)
      { 
        switch(count)
        {
          case 1:
          OCR0A=0;//0
          count=2;
          break;

          case 2:
          OCR0A=64;//25%
          count=3;
          break;

          case 3:
          OCR0A=128;//50
          count=4;
          break;

          case 4:
          OCR0A=192;//75%
          count=5;
          break;

          case 5:
          OCR0A=250;//100%
          count=1;
          break;


        }
        
        
      }
      prev=button;
     
      

    
    
    
  }
}