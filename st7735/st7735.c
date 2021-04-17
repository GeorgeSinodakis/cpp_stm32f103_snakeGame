#include "st7735.h"
#include <math.h>
#include "gpio.h"
#include "spi.h"
#include "delay.h"
#include "rcc.h"

uint8_t w = ST7735_TFTWIDTH;
uint8_t l = ST7735_TFTLENGTH;

void st7735_reset()
{
	GPIOA_clear(RESET);
	ms(2);
	GPIOA_set(RESET);
	ms(2);
}

void st7735_write(uint8_t byte, uint8_t mode)
{
	GPIOA_clear(CS1);
	if (mode)
	{
		GPIOA_set(RS);
	}
	else
	{
		GPIOA_clear(RS);
	}
	SPI1_send(byte);
	GPIOA_set(CS1);
}

void st7735_Word_Write(uint16_t value)
{
	GPIOA_clear(CS1);
	GPIOA_set(RS);
	SPI1_send(((value & 0xFF00) >> 0x08));
	SPI1_send(value & 0x00FF);
	GPIOA_set(CS1);
}

void st7735_Set_Addr_Window(uint8_t xs, uint8_t ys, uint8_t xe, uint8_t ye)
{
	st7735_write(ST7735_CASET, CMD);
	st7735_write(0x00, DAT);
	st7735_write(xs, DAT);
	st7735_write(0x00, DAT);
	st7735_write(xe, DAT);

	st7735_write(ST7735_RASET, CMD);
	st7735_write(0x00, DAT);
	st7735_write(ys, DAT);
	st7735_write(0x00, DAT);
	st7735_write(ye, DAT);

	st7735_write(ST7735_RAMWR, CMD);
}

void st7735_init(uint8_t rotation)
{
	SPI1_enable(false, false, false, 2);

	GPIOA_clock_enable();
	
	GPIOA_mode(OUTPUT_PUSHPULL, RESET);
	GPIOA_mode(OUTPUT_PUSHPULL, RS);

	GPIOA_clear(RESET);
	GPIOA_clear(RS);
	GPIOA_clear(CS1);

	ms(100);
	st7735_reset();

	st7735_write(ST7735_SWRESET, CMD);
	ms(1);
	st7735_write(ST7735_SLPOUT, CMD);
	ms(1);
	st7735_write(ST7735_FRMCTR1, CMD);
	st7735_write(0x01, DAT);
	st7735_write(0x2C, DAT);
	st7735_write(0x2D, DAT);
	st7735_write(ST7735_FRMCTR2, CMD);
	st7735_write(0x01, DAT);
	st7735_write(0x2C, DAT);
	st7735_write(0x2D, DAT);
	st7735_write(ST7735_FRMCTR3, CMD);
	st7735_write(0x01, DAT);
	st7735_write(0x2C, DAT);
	st7735_write(0x2D, DAT);
	st7735_write(0x01, DAT);
	st7735_write(0x2C, DAT);
	st7735_write(0x2D, DAT);
	st7735_write(ST7735_INVCTR, CMD);
	st7735_write(0x07, DAT);
	st7735_write(ST7735_PWCTR1, CMD);
	st7735_write(0xA2, DAT);
	st7735_write(0x02, DAT);
	st7735_write(0x84, DAT);
	st7735_write(ST7735_PWCTR1, CMD);
	st7735_write(0xC5, DAT);
	st7735_write(ST7735_PWCTR2, CMD);
	st7735_write(0x0A, DAT);
	st7735_write(0x00, DAT);
	st7735_write(ST7735_PWCTR3, CMD);
	st7735_write(0x8A, DAT);
	st7735_write(0x2A, DAT);
	st7735_write(ST7735_PWCTR4, CMD);
	st7735_write(0x8A, DAT);
	st7735_write(0xEE, DAT);
	st7735_write(ST7735_PWCTR5, CMD);
	st7735_write(0x0E, DAT);
	st7735_write(ST7735_VMCTR1, CMD);
	st7735_write(0x00, DAT);
	st7735_write(ST7735_COLMOD, CMD);
	st7735_write(0x05, DAT);
	st7735_write(ST7735_MADCTL, CMD);
	st7735_write(0xC8, DAT);

	st7735_Set_Addr_Window(0x00, 0x00, 0x7F, 0x9F);

	st7735_write(ST7735_GMCTRP1, CMD);
	st7735_write(0x02, DAT);
	st7735_write(0x1C, DAT);
	st7735_write(0x07, DAT);
	st7735_write(0x12, DAT);
	st7735_write(0x37, DAT);
	st7735_write(0x32, DAT);
	st7735_write(0x29, DAT);
	st7735_write(0x2D, DAT);
	st7735_write(0x29, DAT);
	st7735_write(0x25, DAT);
	st7735_write(0x2B, DAT);
	st7735_write(0x39, DAT);
	st7735_write(0x00, DAT);
	st7735_write(0x01, DAT);
	st7735_write(0x03, DAT);
	st7735_write(0x10, DAT);
	st7735_write(ST7735_GMCTRN1, CMD);
	st7735_write(0x03, DAT);
	st7735_write(0x1D, DAT);
	st7735_write(0x07, DAT);
	st7735_write(0x06, DAT);
	st7735_write(0x2E, DAT);
	st7735_write(0x2C, DAT);
	st7735_write(0x29, DAT);
	st7735_write(0x2D, DAT);
	st7735_write(0x2E, DAT);
	st7735_write(0x2E, DAT);
	st7735_write(0x37, DAT);
	st7735_write(0x3F, DAT);
	st7735_write(0x00, DAT);
	st7735_write(0x00, DAT);
	st7735_write(0x02, DAT);
	st7735_write(0x10, DAT);
	st7735_write(ST7735_NORON, CMD);
	ms(10);
	st7735_write(ST7735_DISPON, CMD);
	ms(100);
	st7735_write(ST7735_RAMWR, CMD);
	ms(100);
	st7735_write(ST7735_MADCTL, CMD);

	switch (rotation)
	{
	case 1:
		st7735_write((MADCTL_MX | MADCTL_MY | MADCTL_RGB), DAT);
		w = ST7735_TFTWIDTH;
		l = ST7735_TFTLENGTH;
		break;
	case 2:
		st7735_write((MADCTL_MY | MADCTL_MV | MADCTL_RGB), DAT);
		w = ST7735_TFTLENGTH;
		l = ST7735_TFTWIDTH;
		break;
	case 3:
		st7735_write((MADCTL_RGB), DAT);
		w = ST7735_TFTWIDTH;
		l = ST7735_TFTLENGTH;
		break;
	case 4:
		st7735_write((MADCTL_MX | MADCTL_MV | MADCTL_RGB), DAT);
		w = ST7735_TFTLENGTH;
		l = ST7735_TFTWIDTH;
		break;
	}
	return;
}

uint16_t st7735_Swap_Colour(uint16_t colour)
{
	//RRRRR GGGGGG BBBBB -> BBBBB GGGGGG RRRRR
	return ((colour << 0x000B) | (colour & 0x07E0) | (colour >> 0x000B));
}

void st7735_fill(uint16_t colour)
{
	colour = st7735_Swap_Colour(colour);
	st7735_Set_Addr_Window(0, 0, (w - 1), (l - 1));

	GPIOA_clear(CS1);
	GPIOA_set(RS);

	for (uint16_t i = 0; i <= 20479; i++)
	{
		SPI1_send(((colour & 0xFF00) >> 0x08));
		SPI1_send(colour & 0x00FF);
	}

	GPIOA_set(CS1);
}

void st7735_rect(uint8_t x_s, uint8_t y_s, uint8_t x_e, uint8_t y_e, uint16_t colour)
{
	colour = st7735_Swap_Colour(colour);
	st7735_Set_Addr_Window(x_s, y_s, x_e, y_e);
	x_e -= x_s;
	x_e++;
	y_e -= y_s;
	y_e++;
	uint16_t pixels = x_e * y_e;
	for (uint16_t i = 0; i < pixels; i++)
	{
		st7735_Word_Write(colour);
	}
}

void st7735_circle(uint8_t x_c, uint8_t y_c, uint8_t r, uint16_t colour , uint16_t b_colour)
{
	colour = st7735_Swap_Colour(colour);
	b_colour = st7735_Swap_Colour(b_colour);
	st7735_Set_Addr_Window(x_c - r , y_c - r , x_c + r , y_c + r);
	for (int8_t y = -r ; y <= r ; y++)
	{
		for (int8_t x = -r ; x <= r ; x++)
		{
			//ms(50);
			if (x == (uint8_t)sqrt((double)(r * r - y * y)) || x == -(uint8_t)sqrt((double)(r * r - y * y)))
			{
				st7735_Word_Write(colour);
			}
			else
			{
				st7735_Word_Write(b_colour);
			}
		}
	}
}

void st7735_Draw_Font_Pixel(char x_pos, char y_pos, uint16_t colour, uint8_t pixel_size)
{
	char i = 0x00;

	st7735_Set_Addr_Window(x_pos, y_pos, (x_pos + pixel_size - 1), (y_pos + pixel_size - 1));

	for (i = 0x00; i < (pixel_size * pixel_size); i++)
	{
		st7735_Word_Write(colour);
	}
}

void st7735_print_char(char x_pos, char y_pos, char font_size, uint16_t colour, uint16_t back_colour, char ch)
{

	colour = st7735_Swap_Colour(colour);
	back_colour = st7735_Swap_Colour(back_colour);

	char i = 0x00;
	char j = 0x00;

	char value = 0x00;

	if (x_pos < font_size)
	{
		x_pos = font_size;
	}

	for (i = 0x00; i < 0x05; i++)
	{
		for (j = 0x00; j < 0x08; j++)
		{
			value = 0x00;
			value = ((font[ch - 0x20][i]));

			if ((value >> j)  & 0x01)
			{
				st7735_Draw_Font_Pixel(x_pos, y_pos, colour, font_size);
			}
			else
			{
				st7735_Draw_Font_Pixel(x_pos, y_pos, back_colour, font_size);
			}

			y_pos = y_pos + font_size;
		}
		y_pos -= (font_size << 0x03);
		x_pos += font_size;

	}
	x_pos += font_size;

	if (x_pos > w)
	{
		x_pos = (font_size + 0x01);
		y_pos += (font_size << 0x03);
	}
}

//if you want to print a number use sprintf to create a string and print the string
void st7735_print_str(char x_pos, char y_pos, char font_size, uint16_t colour, uint16_t back_colour, std::string *str)
{
	for(auto &c : *str)
	{
		if(c != '\0')
		{
			st7735_print_char(x_pos, y_pos, font_size, colour, back_colour, c);
			x_pos += (font_size * 0x06);
		}
	}
}
