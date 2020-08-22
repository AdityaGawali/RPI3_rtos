#ifndef UART_H
#define UART_H
#include "inttypes.h"
void uart_send ( char c );


char uart_recv ( void );


void uart_send_string(char* str);


void uart_init (  uint32_t baud_rate);

#endif
