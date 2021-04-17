#include <stdint.h>
#include "delay.h"
#include "rcc.h"
#include "gpio.h"
#include "st7735.h"
#include "snake.h"

typedef uint64_t u64;
typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;

Game snake;

void configureGpio(void)
{
	GPIOA_clock_enable();
	GPIOA_mode(INPUT_PULL_UPDOWN, 10);
	GPIOA_mode(INPUT_PULL_UPDOWN, 11);
	GPIOA_mode(INPUT_PULL_UPDOWN, 12);
	GPIOA_mode(INPUT_PULL_UPDOWN, 15);
	GPIOA_set(10);
	GPIOA_set(11);
	GPIOA_set(12);
	GPIOA_set(15);
}

void checkButtons()
{
	startCount(300);
	while(!endCount())
	{
		if(!GPIOA_read(10)) snake.goUp();
		if(!GPIOA_read(11)) snake.goDown();
		if(!GPIOA_read(12)) snake.goLeft();
		if(!GPIOA_read(15)) snake.goRight();
	}
}

int main(void)
{
	clock_72Mhz();

	configureGpio();

	st7735_init(3);

	snake.init();

	while (1)
	{
		snake.draw();
		snake.loss_check();
		checkButtons();
		snake.move();
	}
}