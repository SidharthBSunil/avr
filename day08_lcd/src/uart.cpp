#include "uart.h"
#include <avr/io.h>

void uart_init()
{

    
    UBRR0H=0;
    UBRR0L=103;

    //enabling tx and rx
    UCSR0B|=((1<<RXEN0)|(1<<TXEN0));

    // 8 bit frame 

    UCSR0C|=((1<<UCSZ00)|(1<<UCSZ00));
    UCSR0B&=~(1<<UCSZ02);

    //NO PARITY

    UCSR0C&=~((1<<UPM01)|(1<<UPM00));

    //stop bit

    UCSR0C &=~(1<<USBS0);

}

void uart_data(const char *s)
{
    while (*s)
    {
        while (!(UCSR0A & (1 << UDRE0)))
        {
            // Wait until UART is ready
        }

        UDR0 = *s++;
    }
}

void uart_char(char c)
{
    while (!(UCSR0A & (1 << UDRE0)))
    {
    }

    UDR0 = c;
}

void uart_num(uint16_t v)
{
    if (v >= 10)
    {
        uart_num(v / 10);
    }

    uart_char('0' + (v % 10));
}