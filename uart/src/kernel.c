#include "uart.h"
#include "printf.h"
void kernel_main(void)
{
    uart_init(115200);
    printf("Aditya bhai is the besttt\n");
}