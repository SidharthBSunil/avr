#define F_CPU 16000000UL
#include <avr/io.h>

int main(void)
{
    DDRD &= ~(1 << DDD5);      // Button input
    DDRB |= (1 << DDB2);       // LED output

    PORTB &= ~(1 << PORTB2);   // LED OFF

    uint8_t prevButton = 0;

    while (1)
    {
        uint8_t button = (PIND >> PD5) & 1;

        if (button && !prevButton)
        {
            PORTB ^= (1 << PORTB2);      // Toggle LED
        }

        prevButton = button;             // Save previous button state
    }
}