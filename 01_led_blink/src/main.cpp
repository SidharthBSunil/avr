#include <avr/io.h>

void dc_motor()
{
    DDRD |= (1 << DDD7) | (1 << DDD6);
}

void motor_forward()
{
    PORTD |= (1 << PORTD7);
    PORTD &= ~(1 << PORTD6);
}

int main(void)
{
    dc_motor();

    while (1)
    {
        motor_forward();
    }
}