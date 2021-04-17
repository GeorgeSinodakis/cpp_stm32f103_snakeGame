#include <stdint.h>

typedef uint32_t u32;
typedef uint8_t  u8;

extern u32 _sidata, _sdata, _edata, _sbss, _ebss, _estack;

int main(void);
extern "C" void Reset_Handler(void);
extern "C" void Default_Handler(void);
extern "C" void __libc_init_array(void);

extern "C" void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void HardFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void MemManage_Handler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void BusFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void UsageFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void SVC_Handler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void DebugMon_Handler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void PendSV_Handler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void SysTick_Handler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void WWDG_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void PVD_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void TAMPER_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void RTC_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void FLASH_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void RCC_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void EXTI0_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void EXTI1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void EXTI2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void EXTI3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void EXTI4_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void DMA1_Channel1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void DMA1_Channel2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void DMA1_Channel3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void DMA1_Channel4_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void DMA1_Channel5_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void DMA1_Channel6_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void DMA1_Channel7_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void ADC1_2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void USB_HP_CAN_TX_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void USB_LP_CAN_RX0_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void CAN_RX1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void CAN_SCE_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void EXTI9_5_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void TIM1_BRK_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void TIM1_UP_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void TIM1_TRG_COM_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void TIM1_CC_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void TIM2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void TIM3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void TIM4_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void I2C1_EV_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void I2C1_ER_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void I2C2_EV_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void I2C2_ER_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void SPI1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void SPI2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void USART1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void USART2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void USART3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void EXTI15_10_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void RTCAlarm_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void TIM8_BRK_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void TIM8_UP_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void TIM8_TRG_COM_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void TIM8_CC_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void ADC3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void FSMC_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void SDIO_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void TIM5_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void SPI3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void UART4_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void UART5_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void TIM6_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void TIM7_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void DMA2_Channel1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void DMA2_Channel2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void DMA2_Channel3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
extern "C" void DMA2_Channel4_5_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));

extern "C" void Reset_Handler(void)
{
	//copy data section
	u8 *source = (u8*)&_sidata, *destination = (u8*)&_sdata;
	while (destination < (u8*)&_edata)
	{
		*destination++ = *source++;
	}

	//zero the bss section
	destination = (u8*)&_sbss;
	while (destination < (u8*)&_ebss)
	{
		*destination++ = 0;
	}

	asm ("bl __libc_init_array");

	asm ("bl main");

	while (1);
}

extern "C" void Default_Handler(void)
{
	while (1);
}

u32 vectors[] __attribute__((section(".isr_vector"))) = {
	(u32)&_estack,
	(u32)Reset_Handler,
	(u32)NMI_Handler,
	(u32)HardFault_Handler,
	(u32)MemManage_Handler,
	(u32)BusFault_Handler,
	(u32)UsageFault_Handler,
	(u32)0,
	(u32)0,
	(u32)0,
	(u32)0,
	(u32)SVC_Handler,
	(u32)DebugMon_Handler,
	(u32)0,
	(u32)PendSV_Handler,
	(u32)SysTick_Handler,
	(u32)WWDG_IRQHandler,
	(u32)PVD_IRQHandler,
	(u32)TAMPER_IRQHandler,
	(u32)RTC_IRQHandler,
	(u32)FLASH_IRQHandler,
	(u32)RCC_IRQHandler,
	(u32)EXTI0_IRQHandler,
	(u32)EXTI1_IRQHandler,
	(u32)EXTI2_IRQHandler,
	(u32)EXTI3_IRQHandler,
	(u32)EXTI4_IRQHandler,
	(u32)DMA1_Channel1_IRQHandler,
	(u32)DMA1_Channel2_IRQHandler,
	(u32)DMA1_Channel3_IRQHandler,
	(u32)DMA1_Channel4_IRQHandler,
	(u32)DMA1_Channel5_IRQHandler,
	(u32)DMA1_Channel6_IRQHandler,
	(u32)DMA1_Channel7_IRQHandler,
	(u32)ADC1_2_IRQHandler,
	(u32)USB_HP_CAN_TX_IRQHandler,
	(u32)USB_LP_CAN_RX0_IRQHandler,
	(u32)CAN_RX1_IRQHandler,
	(u32)CAN_SCE_IRQHandler,
	(u32)EXTI9_5_IRQHandler,
	(u32)TIM1_BRK_IRQHandler,
	(u32)TIM1_UP_IRQHandler,
	(u32)TIM1_TRG_COM_IRQHandler,
	(u32)TIM1_CC_IRQHandler,
	(u32)TIM2_IRQHandler,
	(u32)TIM3_IRQHandler,
	(u32)TIM4_IRQHandler,
	(u32)I2C1_EV_IRQHandler,
	(u32)I2C1_ER_IRQHandler,
	(u32)I2C2_EV_IRQHandler,
	(u32)I2C2_ER_IRQHandler,
	(u32)SPI1_IRQHandler,
	(u32)SPI2_IRQHandler,
	(u32)USART1_IRQHandler,
	(u32)USART2_IRQHandler,
	(u32)USART3_IRQHandler,
	(u32)EXTI15_10_IRQHandler,
	(u32)RTCAlarm_IRQHandler,
	(u32)0,
	(u32)TIM8_BRK_IRQHandler,
	(u32)TIM8_UP_IRQHandler,
	(u32)TIM8_TRG_COM_IRQHandler,
	(u32)TIM8_CC_IRQHandler,
	(u32)ADC3_IRQHandler,
	(u32)FSMC_IRQHandler,
	(u32)SDIO_IRQHandler,
	(u32)TIM5_IRQHandler,
	(u32)SPI3_IRQHandler,
	(u32)UART4_IRQHandler,
	(u32)UART5_IRQHandler,
	(u32)TIM6_IRQHandler,
	(u32)TIM7_IRQHandler,
	(u32)DMA2_Channel1_IRQHandler,
	(u32)DMA2_Channel2_IRQHandler,
	(u32)DMA2_Channel3_IRQHandler,
	(u32)DMA2_Channel4_5_IRQHandler
};
