#pragma once

#include <stdbool.h>
#include <stdint.h>
#include "gpio.h"

typedef uint64_t u64;
typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;

#define SPI1_BASE				0x40013000
#define SPI2_BASE				0x40003800

#define SPI1_CR1			(*(volatile u32*)(SPI1_BASE + 0x00))
#define SPI1_CR2			(*(volatile u32*)(SPI1_BASE + 0x04))
#define SPI1_SR				(*(volatile u32*)(SPI1_BASE + 0x08))
#define SPI1_DR				(*(volatile u32*)(SPI1_BASE + 0x0C))
#define SPI1_CRCPR			(*(volatile u32*)(SPI1_BASE + 0x10))
#define SPI1_RXCRCR			(*(volatile u32*)(SPI1_BASE + 0x14))
#define SPI1_TXCRCR			(*(volatile u32*)(SPI1_BASE + 0x18))
#define SPI1_I2SCFGR		(*(volatile u32*)(SPI1_BASE + 0x1C))
#define SPI1_I2SPR			(*(volatile u32*)(SPI1_BASE + 0x20))

#define SPI2_CR1			(*(volatile u32*)(SPI2_BASE + 0x00))
#define SPI2_CR2			(*(volatile u32*)(SPI2_BASE + 0x04))
#define SPI2_SR				(*(volatile u32*)(SPI2_BASE + 0x08))
#define SPI2_DR				(*(volatile u32*)(SPI2_BASE + 0x0C))
#define SPI2_CRCPR			(*(volatile u32*)(SPI2_BASE + 0x10))
#define SPI2_RXCRCR			(*(volatile u32*)(SPI2_BASE + 0x14))
#define SPI2_TXCRCR			(*(volatile u32*)(SPI2_BASE + 0x18))
#define SPI2_I2SCFGR		(*(volatile u32*)(SPI2_BASE + 0x1C))
#define SPI2_I2SPR			(*(volatile u32*)(SPI2_BASE + 0x20))

#define SPI_BIDIMODE			1<<15
#define SPI_BIDIOE				1<<14
#define SPI_CRCEN				1<<13
#define SPI_CRCNEXT				1<<12
#define SPI_DFF					1<<11
#define SPI_RXONLY				1<<10
#define SPI_SSM					1<<9
#define SPI_SSI					1<<8
#define SPI_LSBFIRST			1<<7
#define SPI_SPE					1<<6
#define SPI_BR2					1<<5
#define SPI_BR1					1<<4
#define SPI_BR0					1<<3
#define SPI_MSTR				1<<2
#define SPI_CPOL				1<<1
#define SPI_CPHA				1<<0
#define SPI_TXEIE				1<<7
#define SPI_RXNEIE				1<<6
#define SPI_ERRIE				1<<5
#define SPI_SSOE				1<<2
#define SPI_BSY					1<<7
#define SPI_OVR					1<<6
#define SPI_MODF				1<<5
#define SPI_CRCERR				1<<4
#define SPI_UDR					1<<3
#define SPI_CHSIDE				1<<2
#define SPI_TXE					1<<1
#define SPI_RXNE				1<<0

#define SPI1_PORT	GPIOA
#define CS1			4
#define SCK1		5
#define MISO1		6
#define MOSI1		7

void SPI1_clock_enable(void);

void SPI1_clock_disable(void);

//sends a byte and waits to receive one too
uint8_t SPI1_tranceiver(u8 data);

//checks if buffer is empty and sends the byte
void SPI1_send(u8 data);

void SPI1_deassert(void);

void SPI1_assert(void);

void SPI1_enable(bool LSBFIRST, bool CPOL, bool CPHA, u16 clock_divisor);

void SPI1_disable();

#define SPI2_PORT	GPIOB
#define CS2			12
#define SCK2		13
#define MISO2		14
#define MOSI2		15

void SPI2_clock_enable(void);

void SPI2_clock_disable(void);

//sends a byte and waits to receive one too
uint8_t SPI2_tranceiver(u8 data);

//checks if buffer is empty and sends the byte
void SPI2_send(u8 data);

void SPI2_deassert(void);

void SPI2_assert(void);

void SPI2_enable(bool LSBFIRST, bool CPOL, bool CPHA, u16 clock_divisor);

void SPI2_disable();