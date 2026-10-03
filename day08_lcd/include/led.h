#ifndef LED_H_
#define LED_H_

#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>


void led_init(void);
void led_on(void);
void led_off(void);
#endif