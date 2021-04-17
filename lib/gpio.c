#include "gpio.h"
#include "rcc.h"


void AFIO_clock_enable(void)
{
	RCC_APB2ENR |= 1 << 0;
}

void AFIO_clock_disable(void)
{
	RCC_APB2ENR &= ~(1 << 0);
}

void GPIOA_clock_enable(void)
{
	RCC_APB2ENR |= 1 << 2;
}

void GPIOA_clock_disable(void)
{
	RCC_APB2ENR &= ~(1 << 2);
}

void GPIOA_mode(u8 mode, u8 pin)
{
	if (pin <= 7)
	{
		GPIOA_CRL &= ~(0x0f << (pin * 4));
		GPIOA_CRL |= (mode << (pin * 4));
	}
	else
	{
		pin -= 8;
		GPIOA_CRH &= ~(0x0f << (pin * 4));
		GPIOA_CRH |= (mode << (pin * 4));
	}
}

//set gpio and enable pullup
void GPIOA_set(u8 pin)
{
	GPIOA_BSRR = 1 << pin;
}

//reset gpio and enable pulldown
void GPIOA_clear(u8 pin)
{
	GPIOA_BRR = 1 << pin;
}

void GPIOA_toggle(u8 pin)
{
	GPIOA_ODR ^= 1 << pin;
}

bool GPIOA_read(u8 pin)
{
	return GPIOA_IDR & (1 << pin);
}
/////////////////////////////////////////////////////////////////////////

void GPIOB_clock_enable(void)
{
	RCC_APB2ENR |= 1 << 3;
}

void GPIOB_clock_disable(void)
{
	RCC_APB2ENR &= ~(1 << 3);
}

void GPIOB_mode(u8 mode, u8 pin)
{
	if (pin <= 7)
	{
		GPIOB_CRL &= ~(0x0f << (pin * 4));
		GPIOB_CRL |= (mode << (pin * 4));
	}
	else
	{
		pin -= 8;
		GPIOB_CRH &= ~(0x0f << (pin * 4));
		GPIOB_CRH |= (mode << (pin * 4));
	}
}

//set gpio and enable pullup
void GPIOB_set(u8 pin)
{
	GPIOB_BSRR = 1 << pin;
}

//reset gpio and enable pulldown
void GPIOB_clear(u8 pin)
{
	GPIOB_BRR = 1 << pin;
}

void GPIOB_toggle(u8 pin)
{
	GPIOB_ODR ^= 1 << pin;
}

bool GPIOB_read(u8 pin)
{
	return GPIOB_IDR & (1 << pin);
}
/////////////////////////////////////////////////////////////////////////

void GPIOC_clock_enable(void)
{
	RCC_APB2ENR |= 1 << 4;
}

void GPIOC_clock_disable(void)
{
	RCC_APB2ENR &= ~(1 << 4);
}

void GPIOC_mode(u8 mode, u8 pin)
{
	if (pin <= 7)
	{
		GPIOC_CRL &= ~(0x0f << (pin * 4));
		GPIOC_CRL |= (mode << (pin * 4));
	}
	else
	{
		pin -= 8;
		GPIOC_CRH &= ~(0x0f << (pin * 4));
		GPIOC_CRH |= (mode << (pin * 4));
	}
}

//set gpio and enable pullup
void GPIOC_set(u8 pin)
{
	GPIOC_BSRR = 1 << pin;
}

//reset gpio and enable pulldown
void GPIOC_clear(u8 pin)
{
	GPIOC_BRR = 1 << pin;
}

void GPIOC_toggle(u8 pin)
{
	GPIOC_ODR ^= 1 << pin;
}

bool GPIOC_read(u8 pin)
{
	return GPIOC_IDR & (1 << pin);
}