#include "delay.h"
#include <avr/io.h>

void time_delay()
{
    TCNT0=0;
    TCCR0A&=~((1<<COM0A1)|(1<<COM0A0)|(1<<WGM00)|(1<<WGM01)); //normal mode operation ocra is disconneted and wave mode off
    TCCR0B&=~(1<<WGM02);//wave  mode off
    TCCR0B&=~((1<<CS01)|(1<<CS00)); //CLOCK select to 256 prescaling
    TCCR0B|=(1<<CS02);
    // for make 1 sec 488 overflow want
    for(uint16_t i=0;i<488;i++)
    {
        while(!(TIFR0&(1<<TOV0))); //check overflow of register

        TIFR0|=(1<<TOV0); //remove overflow

    }   


}

void time_delay_half()
{
    TCNT0=0;
    TCCR0A&=~((1<<COM0A1)|(1<<COM0A0)|(1<<WGM00)|(1<<WGM01)); //normal mode operation ocra is disconneted and wave mode off
    TCCR0B&=~(1<<WGM02);//wave  mode off
    TCCR0B&=~((1<<CS01)|(1<<CS00)); //CLOCK select to 256 prescaling
    TCCR0B|=(1<<CS02);
    // for make 1 sec 488 overflow want
    for(uint16_t i=0;i<244;i++)
    {
        while(!(TIFR0&(1<<TOV0))); //check overflow of register

        TIFR0|=(1<<TOV0); //remove overflow

    }   


}