#define F_CPU 16000000UL
#include <avr/io.h>

int main(void)
{
    DDRD &= ~(1 << DDD5);
    DDRB |= (1 << DDB2);

    uint8_t old_button = 0;
    uint8_t new_button;

    while (1)
    {
        new_button = PIND & (1 << PIND5);

        if (new_button && !old_button)
        {
            PORTB ^= (1 << PORTB2);
        }

        old_button = new_button;
    }
}