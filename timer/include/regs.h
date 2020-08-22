#ifndef	_REGS_H
#define	_REGS_H
#include "inttypes.h"
#define __REG_TYPE	volatile uint32_t
#define __REG		__REG_TYPE *

#define PBASE 0x3F000000


#define UART_OFFS 0x00201000

#define UART_DR     (PBASE + UART_OFFS + 0x00)
#define UART_RSRECR (PBASE + UART_OFFS + 0x04)
#define UART_FR     (PBASE + UART_OFFS + 0x18)
#define UART_ILPR   (PBASE + UART_OFFS + 0x20)
#define UART_IBRD   (PBASE + UART_OFFS + 0x24)
#define UART_FBRD   (PBASE + UART_OFFS + 0x28)
#define UART_LCRH   (PBASE + UART_OFFS + 0x2C)
#define UART_CR     (PBASE + UART_OFFS + 0x30)
#define UART_IFLS   (PBASE + UART_OFFS + 0x34)
#define UART_IMSC   (PBASE + UART_OFFS + 0x38)
#define UART_RIS    (PBASE + UART_OFFS + 0x3C)
#define UART_MIS    (PBASE + UART_OFFS + 0x40)
#define UART_ICR    (PBASE + UART_OFFS + 0x44)
#define UART_DMACR  (PBASE + UART_OFFS + 0x48)
#define UART_ITCR   (PBASE + UART_OFFS + 0x80)
#define UART_ITIP   (PBASE + UART_OFFS + 0x84)
#define UART_ITOP   (PBASE + UART_OFFS + 0x88)
#define UART_TDR    (PBASE + UART_OFFS + 0x8C)


#define GPFSEL1         (PBASE+0x00200004)
#define GPSET0          (PBASE+0x0020001C)
#define GPCLR0          (PBASE+0x00200028)
#define GPPUD           (PBASE+0x00200094)
#define GPPUDCLK0       (PBASE+0x00200098)



#define TIMER_CS        (PBASE+0x00003000)
#define TIMER_CLO       (PBASE+0x00003004)
#define TIMER_CHI       (PBASE+0x00003008)
#define TIMER_C0        (PBASE+0x0000300C)
#define TIMER_C1        (PBASE+0x00003010)
#define TIMER_C2        (PBASE+0x00003014)
#define TIMER_C3        (PBASE+0x00003018)

#define TIMER_CS_M0	(1 << 0)
#define TIMER_CS_M1	(1 << 1)
#define TIMER_CS_M2	(1 << 2)
#define TIMER_CS_M3	(1 << 3)

#define IRQ_BASIC_PENDING	(PBASE+0x0000B200)
#define IRQ_PENDING_1		(PBASE+0x0000B204)
#define IRQ_PENDING_2		(PBASE+0x0000B208)
#define FIQ_CONTROL		(PBASE+0x0000B20C)
#define ENABLE_IRQS_1		(PBASE+0x0000B210)
#define ENABLE_IRQS_2		(PBASE+0x0000B214)
#define ENABLE_BASIC_IRQS	(PBASE+0x0000B218)
#define DISABLE_IRQS_1		(PBASE+0x0000B21C)
#define DISABLE_IRQS_2		(PBASE+0x0000B220)
#define DISABLE_BASIC_IRQS	(PBASE+0x0000B224)

#define SYSTEM_TIMER_IRQ_0	(1 << 0)
#define SYSTEM_TIMER_IRQ_1	(1 << 1)
#define SYSTEM_TIMER_IRQ_2	(1 << 2)
#define SYSTEM_TIMER_IRQ_3	(1 << 3)


#endif