#include "led.h"
#include <avr/io.h>

void led_init()
{
DDRB|=(1<<DDB0);
PORTB&=~(1<<PORTB0);

}

void led_on()
{
    PORTB|=(1<<PORTB0);

}

void led_off()
{
    PORTB&=~(1<<PORTB0);
}