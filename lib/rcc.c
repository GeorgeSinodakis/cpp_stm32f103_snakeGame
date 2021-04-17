#include "rcc.h"

void clock_72Mhz(void)
{
	RCC_CR |= (1 << 16);            // Enable HSE
	while (!(RCC_CR & (1 << 17)));  // Wait till HSE ready

	RCC_CFGR |= 1;                  // Swich to HSE temporarly
	RCC_CR   &= ~1;				 // Disable HSI

	RCC_CFGR |= (0b111 << 18);      // Set PLL multiplication to 9
	RCC_CFGR |= (1 << 16);          // HSE as PLL_SRC

	FLASH_ACR = 0b10010;            // Enable flash prefetch

	RCC_CR |= (1 << 24);            // Enable PLL
	while (!(RCC_CR & (1 << 25)));  // Wait till PLL ready

	RCC_CFGR = (RCC_CFGR | 0b10) & ~1; // Set PLL as Clock source
	while (!(RCC_CFGR & (1 << 3))); // Wait till PLL is CLK SRC
}
