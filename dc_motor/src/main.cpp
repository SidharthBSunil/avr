#include <avr/io.h>

int main(void)
{
    DDRD |= (1 << PD7);      // D7 output
    PORTD |= (1 << PD7);     // D7 HIGH

    while (1)
    {
    }
}