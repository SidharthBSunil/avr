#define F_CPU 16000000UL
#include<avr/io.h>
#include<util/delay.h>

void dc_motor()
{
DDRB|=((1<<DDB1)|(1<<DDB2));
}

void motor_forward()
{
  PORTB|=(1<<PORTB1);
  PORTB&=~(1<<PORTB2);
}
int main()
{
dc_motor();
while(1)
{

  //moto
  
  motor_forward();

}



}