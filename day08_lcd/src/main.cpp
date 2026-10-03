

#define F_CPU 16000000UL

#include <avr/io.h>
#include "lcd.h"
#include "adc.h"
#include "delay.h"
#include "uart.h"
#include "led.h"
int main(void)
{
	lcd_init();
	adc_init();
	uart_init();
	led_init();
	uint16_t adc_value,temperature;
	

	while (1)
	{


		adc_value=adc_read(0);
		temperature=adc_value*0.488;
		lcd_set_cursor(0,0);
		led_on();
		time_delay_half();
		led_off();
		time_delay_half();
		lcd_print("Temperature is ");

		uart_data("Temperature is ");
		uart_num(temperature);
		uart_data("\n");

		lcd_set_cursor(1,0);
		time_delay();
		lcd_print_uint16(temperature);

		lcd_set_cursor(1,3);
		lcd_print("C");


	
		
		
	}
}