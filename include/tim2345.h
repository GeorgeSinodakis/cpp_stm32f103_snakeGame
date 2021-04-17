#pragma once
#include <stdint.h>

typedef uint64_t u64;
typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;

#define TIM2345_CR1			0x00
#define TIM2345_CR2			0x04
#define TIM2345_SMCR		0x08
#define TIM2345_DIER		0x0C
#define TIM2345_SR			0x10
#define TIM2345_EGR			0x14
#define TIM2345_CCMR1		0x18
#define TIM2345_CCMR2		0x1C
#define TIM2345_CCER		0x20
#define TIM2345_CNT			0x24
#define TIM2345_PSC			0x28
#define TIM2345_ARR			0x2C
#define TIM2345_CCR1		0x34
#define TIM2345_CCR2		0x38
#define TIM2345_CCR3		0x3C
#define TIM2345_CCR4		0x40
#define TIM2345_DCR			0x48
#define TIM2345_DMAR		0x4C

////////////////////////TIM2///////////////////////////////

#define TIM2_BASE	0x40000000

#define TIM2_CR1 			(*(volatile u32*)(TIM2_BASE + TIM2345_CR1))
#define TIM2_CR2 			(*(volatile u32*)(TIM2_BASE + TIM2345_CR2))
#define TIM2_SMCR 			(*(volatile u32*)(TIM2_BASE + TIM2345_SMCR))
#define TIM2_DIER 			(*(volatile u32*)(TIM2_BASE + TIM2345_DIER))
#define TIM2_SR 			(*(volatile u32*)(TIM2_BASE + TIM2345_SR))
#define TIM2_EGR 			(*(volatile u32*)(TIM2_BASE + TIM2345_EGR))
#define TIM2_CCMR1 			(*(volatile u32*)(TIM2_BASE + TIM2345_CCMR1))
#define TIM2_CCMR2 			(*(volatile u32*)(TIM2_BASE + TIM2345_CCMR2))
#define TIM2_CCER 			(*(volatile u32*)(TIM2_BASE + TIM2345_CCER))
#define TIM2_CNT 			(*(volatile u32*)(TIM2_BASE + TIM2345_CNT))
#define TIM2_PSC 			(*(volatile u32*)(TIM2_BASE + TIM2345_PSC))
#define TIM2_ARR 			(*(volatile u32*)(TIM2_BASE + TIM2345_ARR))
#define TIM2_CCR1 			(*(volatile u32*)(TIM2_BASE + TIM2345_CCR1))
#define TIM2_CCR2 			(*(volatile u32*)(TIM2_BASE + TIM2345_CCR2))
#define TIM2_CCR3 			(*(volatile u32*)(TIM2_BASE + TIM2345_CCR3))
#define TIM2_CCR4 			(*(volatile u32*)(TIM2_BASE + TIM2345_CCR4))
#define TIM2_DCR 			(*(volatile u32*)(TIM2_BASE + TIM2345_DCR))
#define TIM2_DMAR 			(*(volatile u32*)(TIM2_BASE + TIM2345_DMAR))

////////////////////////TIM3///////////////////////////////

#define TIM3_BASE	0x40000400

#define TIM3_CR1 			(*(volatile u32*)(TIM3_BASE + TIM2345_CR1))
#define TIM3_CR2 			(*(volatile u32*)(TIM3_BASE + TIM2345_CR2))
#define TIM3_SMCR 			(*(volatile u32*)(TIM3_BASE + TIM2345_SMCR))
#define TIM3_DIER 			(*(volatile u32*)(TIM3_BASE + TIM2345_DIER))
#define TIM3_SR 			(*(volatile u32*)(TIM3_BASE + TIM2345_SR))
#define TIM3_EGR 			(*(volatile u32*)(TIM3_BASE + TIM2345_EGR))
#define TIM3_CCMR1 			(*(volatile u32*)(TIM3_BASE + TIM2345_CCMR1))
#define TIM3_CCMR2 			(*(volatile u32*)(TIM3_BASE + TIM2345_CCMR2))
#define TIM3_CCER 			(*(volatile u32*)(TIM3_BASE + TIM2345_CCER))
#define TIM3_CNT 			(*(volatile u32*)(TIM3_BASE + TIM2345_CNT))
#define TIM3_PSC 			(*(volatile u32*)(TIM3_BASE + TIM2345_PSC))
#define TIM3_ARR 			(*(volatile u32*)(TIM3_BASE + TIM2345_ARR))
#define TIM3_CCR1 			(*(volatile u32*)(TIM3_BASE + TIM2345_CCR1))
#define TIM3_CCR2 			(*(volatile u32*)(TIM3_BASE + TIM2345_CCR2))
#define TIM3_CCR3 			(*(volatile u32*)(TIM3_BASE + TIM2345_CCR3))
#define TIM3_CCR4 			(*(volatile u32*)(TIM3_BASE + TIM2345_CCR4))
#define TIM3_DCR 			(*(volatile u32*)(TIM3_BASE + TIM2345_DCR))
#define TIM3_DMAR 			(*(volatile u32*)(TIM3_BASE + TIM2345_DMAR))

////////////////////////TIM4///////////////////////////////

#define TIM4_BASE	0x40000800

#define TIM4_CR1 			(*(volatile u32*)(TIM4_BASE + TIM2345_CR1))
#define TIM4_CR2 			(*(volatile u32*)(TIM4_BASE + TIM2345_CR2))
#define TIM4_SMCR 			(*(volatile u32*)(TIM4_BASE + TIM2345_SMCR))
#define TIM4_DIER 			(*(volatile u32*)(TIM4_BASE + TIM2345_DIER))
#define TIM4_SR 			(*(volatile u32*)(TIM4_BASE + TIM2345_SR))
#define TIM4_EGR 			(*(volatile u32*)(TIM4_BASE + TIM2345_EGR))
#define TIM4_CCMR1 			(*(volatile u32*)(TIM4_BASE + TIM2345_CCMR1))
#define TIM4_CCMR2 			(*(volatile u32*)(TIM4_BASE + TIM2345_CCMR2))
#define TIM4_CCER 			(*(volatile u32*)(TIM4_BASE + TIM2345_CCER))
#define TIM4_CNT 			(*(volatile u32*)(TIM4_BASE + TIM2345_CNT))
#define TIM4_PSC 			(*(volatile u32*)(TIM4_BASE + TIM2345_PSC))
#define TIM4_ARR 			(*(volatile u32*)(TIM4_BASE + TIM2345_ARR))
#define TIM4_CCR1 			(*(volatile u32*)(TIM4_BASE + TIM2345_CCR1))
#define TIM4_CCR2 			(*(volatile u32*)(TIM4_BASE + TIM2345_CCR2))
#define TIM4_CCR3 			(*(volatile u32*)(TIM4_BASE + TIM2345_CCR3))
#define TIM4_CCR4 			(*(volatile u32*)(TIM4_BASE + TIM2345_CCR4))
#define TIM4_DCR 			(*(volatile u32*)(TIM4_BASE + TIM2345_DCR))
#define TIM4_DMAR 			(*(volatile u32*)(TIM4_BASE + TIM2345_DMAR))

////////////////////////TIM5///////////////////////////////

#define TIM5_BASE	0x40000C00

#define TIM5_CR1 			(*(volatile u32*)(TIM5_BASE + TIM2345_CR1))
#define TIM5_CR2 			(*(volatile u32*)(TIM5_BASE + TIM2345_CR2))
#define TIM5_SMCR 			(*(volatile u32*)(TIM5_BASE + TIM2345_SMCR))
#define TIM5_DIER 			(*(volatile u32*)(TIM5_BASE + TIM2345_DIER))
#define TIM5_SR 			(*(volatile u32*)(TIM5_BASE + TIM2345_SR))
#define TIM5_EGR 			(*(volatile u32*)(TIM5_BASE + TIM2345_EGR))
#define TIM5_CCMR1 			(*(volatile u32*)(TIM5_BASE + TIM2345_CCMR1))
#define TIM5_CCMR2 			(*(volatile u32*)(TIM5_BASE + TIM2345_CCMR2))
#define TIM5_CCER 			(*(volatile u32*)(TIM5_BASE + TIM2345_CCER))
#define TIM5_CNT 			(*(volatile u32*)(TIM5_BASE + TIM2345_CNT))
#define TIM5_PSC 			(*(volatile u32*)(TIM5_BASE + TIM2345_PSC))
#define TIM5_ARR 			(*(volatile u32*)(TIM5_BASE + TIM2345_ARR))
#define TIM5_CCR1 			(*(volatile u32*)(TIM5_BASE + TIM2345_CCR1))
#define TIM5_CCR2 			(*(volatile u32*)(TIM5_BASE + TIM2345_CCR2))
#define TIM5_CCR3 			(*(volatile u32*)(TIM5_BASE + TIM2345_CCR3))
#define TIM5_CCR4 			(*(volatile u32*)(TIM5_BASE + TIM2345_CCR4))
#define TIM5_DCR 			(*(volatile u32*)(TIM5_BASE + TIM2345_DCR))
#define TIM5_DMAR 			(*(volatile u32*)(TIM5_BASE + TIM2345_DMAR))