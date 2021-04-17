#include "delay.h"

volatile u32 countsLeft;

extern "C" void SysTick_Handler(void)
{
	if (countsLeft) countsLeft--;
}

void startCount(u32 ms)
{
	countsLeft = ms;

	STK_LOAD = 8999;
	STK_VAL = 8999;
	STK_CTRL = 0;
	STK_CTRL = 1 << 0 | 1 << 1;
}

bool endCount(void)
{
	if (countsLeft)
	{
		return false;
	}
	STK_CTRL = 0;
	return true;
}

void ms(u32 ms)
{
	STK_LOAD = 8999;
	STK_VAL = 8999;
	STK_CTRL = 0;
	STK_CTRL = 1 << 0;

	while (ms)
	{
		while (!(STK_CTRL & 1 << 16))
			;
		ms--;
	}
	return;
}

void us(u32 us)
{
	STK_LOAD = us * 8;
	STK_VAL = us * 8;
	STK_CTRL = 0;
	STK_CTRL = 1 << 0;

	while (!(STK_CTRL & 1 << 16));
	return;
}
