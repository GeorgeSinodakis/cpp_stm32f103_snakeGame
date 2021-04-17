#pragma once
#include <stdint.h>
#include <stdbool.h>

typedef uint64_t u64;
typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;

#define GPIOG_BASE			0x40012000
#define GPIOF_BASE			0x40011C00
#define GPIOE_BASE			0x40011800
#define GPIOD_BASE			0x40011400
#define GPIOC_BASE			0x40011000
#define GPIOB_BASE			0x40010C00
#define GPIOA_BASE			0x40010800

#define GPIO_CRL			0x00
#define GPIO_CRH			0x04
#define GPIO_IDR			0x08
#define GPIO_ODR			0x0C
#define GPIO_BSRR			0x10
#define GPIO_BRR			0x14
#define GPIO_LCKR			0x18

#define GPIOA_CRL			(*(volatile u32*)(GPIOA_BASE + GPIO_CRL))
#define GPIOA_CRH			(*(volatile u32*)(GPIOA_BASE + GPIO_CRH))
#define GPIOA_IDR			(*(volatile u32*)(GPIOA_BASE + GPIO_IDR))
#define GPIOA_ODR			(*(volatile u32*)(GPIOA_BASE + GPIO_ODR))
#define GPIOA_BSRR			(*(volatile u32*)(GPIOA_BASE + GPIO_BSRR))
#define GPIOA_BRR			(*(volatile u32*)(GPIOA_BASE + GPIO_BRR))
#define GPIOA_LCKR			(*(volatile u32*)(GPIOA_BASE + GPIO_LCKR))

#define GPIOB_CRL			(*(volatile u32*)(GPIOB_BASE + GPIO_CRL))
#define GPIOB_CRH			(*(volatile u32*)(GPIOB_BASE + GPIO_CRH))
#define GPIOB_IDR			(*(volatile u32*)(GPIOB_BASE + GPIO_IDR))
#define GPIOB_ODR			(*(volatile u32*)(GPIOB_BASE + GPIO_ODR))
#define GPIOB_BSRR			(*(volatile u32*)(GPIOB_BASE + GPIO_BSRR))
#define GPIOB_BRR			(*(volatile u32*)(GPIOB_BASE + GPIO_BRR))
#define GPIOB_LCKR			(*(volatile u32*)(GPIOB_BASE + GPIO_LCKR))

#define GPIOC_CRL			(*(volatile u32*)(GPIOC_BASE + GPIO_CRL))
#define GPIOC_CRH			(*(volatile u32*)(GPIOC_BASE + GPIO_CRH))
#define GPIOC_IDR			(*(volatile u32*)(GPIOC_BASE + GPIO_IDR))
#define GPIOC_ODR			(*(volatile u32*)(GPIOC_BASE + GPIO_ODR))
#define GPIOC_BSRR			(*(volatile u32*)(GPIOC_BASE + GPIO_BSRR))
#define GPIOC_BRR			(*(volatile u32*)(GPIOC_BASE + GPIO_BRR))
#define GPIOC_LCKR			(*(volatile u32*)(GPIOC_BASE + GPIO_LCKR))

#define INPUT_ANALOG					0x00
#define INPUT_FLOAT						0x04
#define INPUT_PULL_UPDOWN				0x08
#define OUTPUT_PUSHPULL					0x03
#define OUTPUT_OPENDRAIN				0x07
#define OUTPUT_ALTFN_PUSHPULL			0x0B
#define OUTPUT_ALTFN_OPENDRAIN			0x0F

void AFIO_clock_enable(void);
void AFIO_clock_disable(void);

void GPIOA_clock_enable(void);

void GPIOA_clock_disable(void);

void GPIOA_mode(u8 mode, u8 pin);

//set GPIOA and enable pullup
void GPIOA_set(u8 pin);

//reset GPIOA and enable pulldown
void GPIOA_clear(u8 pin);

void GPIOA_toggle(u8 pin);

bool GPIOA_read(u8 pin);
////////////////////////////////////////////////////////////////////

void GPIOB_clock_enable(void);

void GPIOB_clock_disable(void);

void GPIOB_mode(u8 mode, u8 pin);

//set GPIOB and enable pullup
void GPIOB_set(u8 pin);

//reset GPIOB and enable pulldown
void GPIOB_clear(u8 pin);

void GPIOB_toggle(u8 pin);

bool GPIOB_read(u8 pin);
/////////////////////////////////////////////////////////////////////////

void GPIOC_clock_enable(void);

void GPIOC_clock_disable(void);

void GPIOC_mode(u8 mode, u8 pin);

//set GPIOC and enable pullup
void GPIOC_set(u8 pin);

//reset GPIOC and enable pulldown
void GPIOC_clear(u8 pin);

void GPIOC_toggle(u8 pin);

bool GPIOC_read(u8 pin);


