#include "spi.h"
#include "rcc.h"

////////////////////////////////////////////////// SPI1 //////////////////////////////////////////////

void SPI1_clock_enable(void)
{
	RCC_APB2ENR |= 1 << 12;
}

void SPI1_clock_disable(void)
{
	RCC_APB2ENR &= ~(1 << 12);
}

//sends a byte and waits to receive one too
u8 SPI1_tranceiver(u8 data)
{
	SPI1_DR = (0x00ff & data);
	while (!(SPI1_SR & SPI_RXNE));
	return (SPI1_DR & 0x00FF);
}

//checks if buffer is empty and sends the byte
void SPI1_send(u8 data)
{
	while (!(SPI1_SR & SPI_TXE));
	SPI1_DR = (0x00ff & data);
}

void SPI1_deassert(void)
{
	GPIOA_set(CS1);
}

void SPI1_assert(void)
{
	GPIOA_clear(CS1);
}

void SPI1_enable(bool LSBFIRST, bool CPOL, bool CPHA, u16 clock_divisor)
{
	if (SPI1_CR1 & SPI_SPE) return;

	SPI1_clock_enable();
	GPIOA_clock_enable();
	AFIO_clock_enable();

	GPIOA_mode(OUTPUT_PUSHPULL, CS1);
	GPIOA_mode(OUTPUT_ALTFN_PUSHPULL, SCK1);
	GPIOA_mode(INPUT_FLOAT, MISO1);
	GPIOA_mode(OUTPUT_ALTFN_PUSHPULL, MOSI1);

	SPI1_deassert(); //xreiazetai gia na doulepsei swsta to spi

	switch (clock_divisor)
	{
	case 2:
		SPI1_CR1 = LSBFIRST * SPI_LSBFIRST | CPOL * SPI_CPOL | CPHA * SPI_CPHA | SPI_MSTR;
		break;
	case 4:
		SPI1_CR1 = SPI_BR0 | LSBFIRST * SPI_LSBFIRST | CPOL * SPI_CPOL | CPHA * SPI_CPHA | SPI_MSTR;
		break;
	case 8:
		SPI1_CR1 = SPI_BR1 | LSBFIRST * SPI_LSBFIRST | CPOL * SPI_CPOL | CPHA * SPI_CPHA | SPI_MSTR;
		break;
	case 16:
		SPI1_CR1 = SPI_BR0 | SPI_BR1 | LSBFIRST * SPI_LSBFIRST | CPOL * SPI_CPOL | CPHA * SPI_CPHA | SPI_MSTR;
		break;
	case 32:
		SPI1_CR1 = SPI_BR2 | LSBFIRST * SPI_LSBFIRST | CPOL * SPI_CPOL | CPHA * SPI_CPHA | SPI_MSTR;
		break;
	case 64:
		SPI1_CR1 = SPI_BR0 | SPI_BR2 | LSBFIRST * SPI_LSBFIRST | CPOL * SPI_CPOL | CPHA * SPI_CPHA | SPI_MSTR;
		break;
	case 128:
		SPI1_CR1 = SPI_BR1 | SPI_BR2 | LSBFIRST * SPI_LSBFIRST | CPOL * SPI_CPOL | CPHA * SPI_CPHA | SPI_MSTR;
		break;
	case 256:
		SPI1_CR1 = SPI_BR0 | SPI_BR1 | SPI_BR2 | LSBFIRST * SPI_LSBFIRST | CPOL * SPI_CPOL | CPHA * SPI_CPHA | SPI_MSTR;
		break;
	}

	SPI1_CR2 = SPI_SSOE;
	SPI1_CR1 |= SPI_SPE;
}

void SPI1_disable()
{
	SPI1_CR1 &= ~(SPI_SPE);
	SPI1_clock_disable();

	GPIOA_mode(INPUT_FLOAT, CS1);
	GPIOA_mode(INPUT_FLOAT, SCK1);
	GPIOA_mode(INPUT_FLOAT, MISO1);
	GPIOA_mode(INPUT_FLOAT, MOSI1);

	GPIOA_clear(CS1);
}

////////////////////////////////////////////////////////// SPI2 //////////////////////////////////////////////////////////

void SPI2_clock_enable(void)
{
	RCC_APB1ENR |= 1 << 14;
}

void SPI2_clock_disable(void)
{
	RCC_APB1ENR &= ~(1 << 14);
}

//sends a byte and waits to receive one too
u8 SPI2_tranceiver(u8 data)
{
	SPI2_DR = (0x00ff & data);
	while (!(SPI2_SR & SPI_RXNE));
	return (SPI2_DR & 0x00FF);
}

//checks if buffer is empty and sends the byte
void SPI2_send(u8 data)
{
	while (!(SPI2_SR & SPI_TXE));
	SPI2_DR = (0x00ff & data);
}

void SPI2_deassert(void)
{
	GPIOB_set(CS2);
}

void SPI2_assert(void)
{
	GPIOB_clear(CS2);
}

void SPI2_enable(bool LSBFIRST, bool CPOL, bool CPHA, u16 clock_divisor)
{
	if (SPI2_CR1 & SPI_SPE) return;

	SPI2_clock_enable();
	GPIOB_clock_enable();
	AFIO_clock_enable();

	GPIOB_mode(OUTPUT_PUSHPULL, CS2);
	GPIOB_mode(OUTPUT_ALTFN_PUSHPULL, SCK2);
	GPIOB_mode(INPUT_FLOAT, MISO2);
	GPIOB_mode(OUTPUT_ALTFN_PUSHPULL, MOSI2);

	SPI2_deassert(); //xreiazetai gia na doulepsei swsta to spi

	switch (clock_divisor)
	{
	case 2:
		SPI2_CR1 = LSBFIRST * SPI_LSBFIRST | CPOL * SPI_CPOL | CPHA * SPI_CPHA | SPI_MSTR;
		break;
	case 4:
		SPI2_CR1 = SPI_BR0 | LSBFIRST * SPI_LSBFIRST | CPOL * SPI_CPOL | CPHA * SPI_CPHA | SPI_MSTR;
		break;
	case 8:
		SPI2_CR1 = SPI_BR1 | LSBFIRST * SPI_LSBFIRST | CPOL * SPI_CPOL | CPHA * SPI_CPHA | SPI_MSTR;
		break;
	case 16:
		SPI2_CR1 = SPI_BR0 | SPI_BR1 | LSBFIRST * SPI_LSBFIRST | CPOL * SPI_CPOL | CPHA * SPI_CPHA | SPI_MSTR;
		break;
	case 32:
		SPI2_CR1 = SPI_BR2 | LSBFIRST * SPI_LSBFIRST | CPOL * SPI_CPOL | CPHA * SPI_CPHA | SPI_MSTR;
		break;
	case 64:
		SPI2_CR1 = SPI_BR0 | SPI_BR2 | LSBFIRST * SPI_LSBFIRST | CPOL * SPI_CPOL | CPHA * SPI_CPHA | SPI_MSTR;
		break;
	case 128:
		SPI2_CR1 = SPI_BR1 | SPI_BR2 | LSBFIRST * SPI_LSBFIRST | CPOL * SPI_CPOL | CPHA * SPI_CPHA | SPI_MSTR;
		break;
	case 256:
		SPI2_CR1 = SPI_BR0 | SPI_BR1 | SPI_BR2 | LSBFIRST * SPI_LSBFIRST | CPOL * SPI_CPOL | CPHA * SPI_CPHA | SPI_MSTR;
		break;
	}

	SPI2_CR2 = SPI_SSOE;
	SPI2_CR1 |= SPI_SPE;
}

void SPI2_disable()
{
	SPI2_CR1 &= ~(SPI_SPE);
	SPI2_clock_disable();

	GPIOB_mode(INPUT_FLOAT, CS2);
	GPIOB_mode(INPUT_FLOAT, SCK2);
	GPIOB_mode(INPUT_FLOAT, MISO2);
	GPIOB_mode(INPUT_FLOAT, MOSI2);

	GPIOB_clear(CS2);
}