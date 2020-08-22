
#include "regs.h"
#include "utils.h"
#include "uart.h"
#include "printf.h"

void uart_send ( char c )
{
    /* Wait for TX FIFO to not be Full. 
     * This would work way better if we used the fifo level interrupts :)
    */
	while(get32(UART_FR) & (1 << 5)) {}

	put32(UART_DR,c);
}

char uart_recv ( void )
{
    /* Block while RX FIFO empty */
	while(get32(UART_FR) & (1 << 4)) { }

	return(get32(UART_DR)&0xFF);
}

void uart_send_string(char* str)
{
	for (int i = 0; str[i] != '\0'; i ++) {
		uart_send((char)str[i]);
	}
}

void uart_init (  uint32_t baud_rate)
{
	unsigned int selector;

	selector = get32(GPFSEL1);
	selector &= ~(7<<12);                   // clean gpio14
	selector |= 4<<12;                      // set alt0 for gpio14
	selector &= ~(7<<15);                   // clean gpio15
	selector |= 4<<15;                      // set alt0 for gpio15
	put32(GPFSEL1,selector);

	put32(GPPUD,0);
	delay(150);
	put32(GPPUDCLK0,(1<<14)|(1<<15));
	delay(150);
	put32(GPPUDCLK0,0);

    put32(UART_CR, 0);                      // Disable UART while we mess around
    put32(UART_IMSC, 0);                    // Disable all interrupts 


    put32(UART_IBRD, 0xFFFF & (48000000 / (16 * baud_rate)));
    put32(UART_FBRD, 0x3f & (48000000 % (16 * baud_rate) * 64 / 48000000));

    // set to 8 bits, enable fifo
    put32(UART_LCRH, (3 << 5) | (1 << 4));

    // Enable RX, TX, UART
    put32(UART_CR, (1 << 9) | (1 << 8) | (1 << 0));
}

void _putchar (char chrachter)
{
    uart_send(chrachter);
}
