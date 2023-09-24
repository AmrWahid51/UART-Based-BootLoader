/*
 * RCC_int.h
 *  Created on: Aug 16, 2022
 *      Author: Bahgat Mahmoud
 */
#ifndef MCAL_RCC_RCC_INT_H_
#define MCAL_RCC_RCC_INT_H_

typedef enum{
	RCC_AHB1=1,
	RCC_AHB2,
	RCC_APB1,
	RCC_APB2,
	RCC_AHB1LP,
	RCC_AHB2LP,
	RCC_APB1LP,
	RCC_APB2LP
}bus_type;
////////////////////////////////////////////////////////////////
/*define peripheral of (RCC_AHB1) bus*/
#define RCC_EN_GPIOA  0
#define RCC_EN_GPIOB  1
#define RCC_EN_GPIOC  2
#define RCC_EN_GPIOD  3
#define RCC_EN_GPIOE  4
#define RCC_EN_GPIOH  7

#define RCC_EN_CRC  12    // CRC clock enable

#define RCC_EN_FLITF   15
#define RCC_EN_SRAM1   16

#define RCC_EN_DMA1  21
#define RCC_EN_DMA2  21
///////////////////////////////////////////////////////////////
/*define peripheral (RCC_AHB2) or (RCC_AHB2LP)*/
#define RCC_EN_OTGFS     7   //USB OTG FS clock enable
/////////////////////////////////////////////////////////////
/*define peripheral (RCC_APB1 or RCC_APB1LP) */
#define RCC_EN_TIM2   0
#define RCC_EN_TIM3   1
#define RCC_EN_TIM4   2
#define RCC_EN_TIM5   3

#define RCC_EN_WWDG   11  //: Window watchdog clock enable

#define RCC_EN_SPI2   14
#define RCC_EN_SPI3   15     ////

#define RCC_EN_UART2  17

#define RCC_EN_I2C1   21
#define RCC_EN_I2C2   22
#define RCC_EN_I2C3   23

#define RCC_EN_PWR    28   //: Power interface clock enable
//////////////////////////////////////////////////////////////
/*RCC_APB2 or RCC_APB2LP*/
#define RCC_EN_TIM1   0
#define RCC_EN_UART1  4
#define RCC_EN_UART6  5

#define RCC_EN_ADC1   8

#define RCC_EN_SDIO   11
#define RCC_EN_SPI1   12
#define RCC_EN_SPI4   13

#define RCC_EN_SYSCFG   14

#define RCC_EN_TIM9     16
#define RCC_EN_TIM10    17
#define RCC_EN_TIM11    18
/*AHB1LP*/
#define RCC_EN_FLITFPLEN 15
////////////////////////////////////////////////////////////////
/**
	Function Name        : MRCC_vInit
	Function Returns     : void
	Function Arguments   : void
	Function Description : initialize the  RCC Peripheral
*/
void MRCC_vInit(void);
/**
	Function Name        : MRCC_vEnableClock
	Function Returns     : void
	Function Arguments   : bus_type A_BusId , u8 A_u8PeripheralId
	Function Description : Enable the selected Peripheral
*/
void MRCC_vEnableClock(bus_type A_BusId , u8 A_u8PeripheralId );
/**
	Function Name        : MRCC_vDisableClock
	Function Returns     : void
	Function Arguments   : u32 A_u32BusId, u32 A_u32PeripheralId
	Function Description : Disable the selected Peripheral
*/
void MRCC_vDisableClock(bus_type A_BusId , u8 A_u8PeripheralId);
////////////////////////////////////////////////////////////////

//void MRCC_vSetClockSource(u8 A_u8ClkSource);
//void MRCC_vSetCLKStatus(u8 A_u8ClkSource , u8 A_u8Statuse);
//void MRCC_vSetBusesPrescaler(bus_type  A_BusId , u8 A_u8Prescaler);
//void MRCC_vSetPLLFactors();
//u8   MRCC_u8CheckClockReady(u8 A_u8ClkSource);
#endif /* MCAL_RCC_RCC_INT_H_ */
