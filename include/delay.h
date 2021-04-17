#pragma once
#include <stdint.h>
#include <stdbool.h>

typedef uint64_t u64;
typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;

#define STK_BASE			0xE000E010
#define STK_CTRL			(*(volatile u32*)(STK_BASE + 0x00))
#define STK_LOAD			(*(volatile u32*)(STK_BASE + 0x04))
#define STK_VAL				(*(volatile u32*)(STK_BASE + 0x08))
#define STK_CALIB			(*(volatile u32*)(STK_BASE + 0x0C))

void startCount(u32 ms);

bool endCount(void);

void ms(u32 ms);

void us(u32 us);
