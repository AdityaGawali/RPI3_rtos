#include "printf.h"
#include "timer.h"
#include "irq.h"
#include "uart.h"


void kernel_main(void)
{
	uart_init(115200);
	irq_vector_init();
	timer_init();
	enable_interrupt_controller();
	enable_irq();

	while (1){
		uart_send(uart_recv());
	}	
}