/*
This library assumes that the hardware spi of the microcontroller is initialized
and the pins of the spi are set to output.
You should also define:
	the name of the function used to tranceive bytes with the spi
	the command used to set the reset, rs and cs pins as outputs, low and high
	the name of the function used to delay in milliseconds and in microseconds
	LED=3.3V , SCK=A5 , SDA=A7 , RS=A2 , RESET=A3 , CS=A4 , GND , VCC
*/

#pragma once
#include "font.h"
#include "stdint.h"
#include <string>


#define ST7735_NOP        		0x00
#define ST7735_SWRESET    		0x01
#define ST7735_RDDID      		0x04
#define ST7735_RDDST      		0x09
#define ST7735_RDDPM      		0x0A
#define ST7735_RDD_MADCTL 		0x0B
#define STT7735_RDD_COLMOD		0x0C
#define ST7735_RDDIM      		0x0D
#define ST7735_RDDSM      		0x0E
#define ST7735_SLPIN      		0x10
#define ST7735_SLPOUT     		0x11
#define ST7735_PTLON      		0x12
#define ST7735_NORON      		0x13
#define ST7735_INVOFF     		0x20
#define ST7735_INVON      		0x21
#define ST7735_GAET     		0x26
#define ST7735_DISPOFF    		0x28
#define ST7735_DISPON     		0x29
#define ST7735_CASET      		0x2A
#define ST7735_RASET      		0x2B
#define ST7735_RAMWR      		0x2C
#define ST7735_RAMRD      		0x2E
#define ST7735_PTLAR      		0x30
#define ST7735_TEOFF      		0x34
#define ST7735_TEON       		0x35
#define ST7735_MADCTL     		0x36
#define ST7735_IDMOFF     		0x38
#define ST7735_IDMON      		0x39
#define ST7735_COLMOD     		0x3A
#define ST7735_RDID1      		0xDA
#define ST7735_RDID2      		0xDB
#define ST7735_RDID3      		0xDC
#define ST7735_RDID4      		0xDD
#define ST7735_FRMCTR1    		0xB1
#define ST7735_FRMCTR2    		0xB2
#define ST7735_FRMCTR3    		0xB3
#define ST7735_INVCTR     		0xB4
#define ST7735_DISSET5    		0xB6
#define ST7735_PWCTR1     		0xC0
#define ST7735_PWCTR2     		0xC1
#define ST7735_PWCTR3     		0xC2
#define ST7735_PWCTR4     		0xC3
#define ST7735_PWCTR5     		0xC4
#define ST7735_VMCTR1     		0xC5
#define ST7735_RDID1      		0xDA
#define ST7735_RDID2      		0xDB
#define ST7735_RDID3      		0xDC
#define ST7735_RDID4      		0xDD
#define ST7735_PWCTR6     		0xFC
#define ST7735_GMCTRP1    		0xE0
#define ST7735_GMCTRN1    		0xE1
#define BLACK             		0x0000
#define BLUE              		0x001F
#define RED               		0xF800
#define GREEN             		0x07E0
#define CYAN              		0x07FF
#define MAGENTA           		0xF81F
#define YELLOW            		0xFFE0
#define WHITE             		0xFFFF
#define MADCTL_MY         		0x80
#define MADCTL_MX         		0x40
#define MADCTL_MV         		0x20
#define MADCTL_ML         		0x10
#define MADCTL_RGB        		0x08
#define MADCTL_MH         		0x04
#define ST7735_TFTWIDTH   		128
#define ST7735_TFTLENGTH  		160
#define CMD               		0x0
#define DAT               		0x1
#define SQUARE            		0x00
#define ROUND             		0x01
#define NO                		0x00
#define YES						0x01

#define TFT_PORT				GPIOA
#define RESET					3
#define RS						2

void st7735_reset();
void st7735_write(uint8_t byte, uint8_t mode);
void st7735_Word_Write(uint16_t value);
void st7735_Set_Addr_Window(uint8_t xs, uint8_t ys, uint8_t xe, uint8_t ye);
void st7735_init(uint8_t rotation);
uint16_t st7735_Swap_Colour(uint16_t colour);
void st7735_fill(uint16_t colour);
void st7735_rect(uint8_t x_s, uint8_t y_s, uint8_t x_e, uint8_t y_e, uint16_t colour);
void st7735_circle(uint8_t x_c, uint8_t y_c, uint8_t r, uint16_t colour , uint16_t b_colour);
void st7735_Draw_Font_Pixel(char x_pos, char y_pos, uint16_t colour, uint8_t pixel_size);
void st7735_print_char(char x_pos, char y_pos, char font_size, uint16_t colour, uint16_t back_colour, char ch);
void st7735_print_str(char x_pos, char y_pos, char font_size, uint16_t colour, uint16_t back_colour, std::string *str);
