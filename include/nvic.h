#pragma once
#include <stdint.h>

typedef uint64_t u64;
typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;

#define NVIC_BASE		0xE000E100
#define NVIC_ISER0		(*(volatile u32*)(NVIC_BASE + 0x000))
#define NVIC_ISER1		(*(volatile u32*)(NVIC_BASE + 0x004))
#define NVIC_ISER2		(*(volatile u32*)(NVIC_BASE + 0x008))
#define NVIC_ICER0		(*(volatile u32*)(NVIC_BASE + 0x080))
#define NVIC_ICER1		(*(volatile u32*)(NVIC_BASE + 0x084))
#define NVIC_ICER2		(*(volatile u32*)(NVIC_BASE + 0x088))
#define NVIC_ISPR0		(*(volatile u32*)(NVIC_BASE + 0x100))
#define NVIC_ISPR1		(*(volatile u32*)(NVIC_BASE + 0x104))
#define NVIC_ISPR2		(*(volatile u32*)(NVIC_BASE + 0x108))
#define NVIC_ICPR0		(*(volatile u32*)(NVIC_BASE + 0x180))
#define NVIC_ICPR1		(*(volatile u32*)(NVIC_BASE + 0x184))
#define NVIC_ICPR2		(*(volatile u32*)(NVIC_BASE + 0x188))
#define NVIC_IABR0		(*(volatile u32*)(NVIC_BASE + 0x200))
#define NVIC_IABR1		(*(volatile u32*)(NVIC_BASE + 0x204))
#define NVIC_IABR2		(*(volatile u32*)(NVIC_BASE + 0x208))

void configure_priority_for_irqs(uint8_t irq_no, uint8_t priority_value)
{
	u32 *NVIC_IPR0 = (u32*)(0xE000E100 + 0x300);

	NVIC_IPR0[irq_no / 4] &= ~(0xFF << ((irq_no % 4) * 8));
	NVIC_IPR0[irq_no / 4] &= ~(priority_value << ((irq_no % 4) * 8));
}
