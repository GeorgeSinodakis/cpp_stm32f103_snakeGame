#pragma once
#include <stdint.h>

typedef uint64_t u64;
typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;

#define FLASH_BASE			0x40022000
#define FLASH_ACR			(*(volatile u32*)(FLASH_BASE + 0x00))

#define RCC_BASE			0x40021000
#define RCC_CR				(*(volatile u32*)(RCC_BASE + 0x00))
#define RCC_CFGR			(*(volatile u32*)(RCC_BASE + 0x04))
#define RCC_CIR				(*(volatile u32*)(RCC_BASE + 0x08))
#define RCC_APB2RSTR		(*(volatile u32*)(RCC_BASE + 0x0C))
#define RCC_APB1RSTR		(*(volatile u32*)(RCC_BASE + 0x10))
#define RCC_AHBENR			(*(volatile u32*)(RCC_BASE + 0x14))
#define RCC_APB2ENR			(*(volatile u32*)(RCC_BASE + 0x18))
#define RCC_APB1ENR			(*(volatile u32*)(RCC_BASE + 0x1C))
#define RCC_BDCR			(*(volatile u32*)(RCC_BASE + 0x20))
#define RCC_CSR				(*(volatile u32*)(RCC_BASE + 0x24))

void clock_72Mhz(void);