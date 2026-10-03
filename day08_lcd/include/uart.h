#ifndef UART_H_
#define UART_H_
#include <stdio.h>
void uart_init(void);
void uart_data(const char *s);
void uart_char(char c);
void uart_num(uint16_t v);
#endif