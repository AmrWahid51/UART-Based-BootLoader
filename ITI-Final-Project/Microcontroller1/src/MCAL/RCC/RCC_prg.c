/*
 * RCC_prg.c
 *
 *  Created on: Aug 16, 2022
 *      Author: DELL
 */
#include "../../LIB/STD_TYPES.h"

#include "../../LIB/BIT_MATH.h"

#include "RCC_cfg.h"
#include "RCC_int.h"
#include "RCC_prv.h"


void  MRCC_vInit(void)
{
	u16 L_u16PLLOut =0;
	/*1- CSS (ON/OFF) */
#if RCC_CLOCK_SECURITY_SYSTEM_ENABLE==ENABLE
	SET_BIT(RCC->CR,CSSON);
#warning "Please check if the HSE is stable if not please disable CSS" // you enable the CLOCK_SECURITY_SYSTEM(CSS) are you sure the HSE is enable and stable
#else
	CLR_BIT(RCC->CR,CSSON);
#endif

	/* 3-Select clock switch (HSI/HSE/PLL)*/
	// CFGR	 clock configuration register
#if  RCC_SELECT_SYSTEM_CLOCK==RCC_HSE
	CLR_BIT(RCC->CFGR,SW1);
	SET_BIT(RCC->CFGR,SW0);
#elif  RCC_SELECT_SYSTEM_CLOCK==RCC_PLL
	SET_BIT(RCC->CFGR,SW1);
	CLR_BIT(RCC->CFGR,SW0);
#elif RCC_SELECT_SYSTEM_CLOCK==RCC_HSI
	CLR_BIT(RCC->CFGR,SW0);
	CLR_BIT(RCC->CFGR,SW1);
#else
         #error "select correct choice for SYSTEM_CLOCK"
#endif
	/*4- Buses prescaler*/
	/*1-AHB_PS*/
#if (RCC_AHB_PS <=15)
	RCC->CFGR &= ~((0b1111)<<4);
	RCC->CFGR |= ((RCC_AHB_PS)<<4);
#else
#error "please choose the right AHB_PS"
#endif
	/*2- APB1_PS*/
#if (RCC_APB1_PS <=7)
	RCC->CFGR &= ~((0b111)<<10);
	RCC->CFGR |= ((RCC_APB1_PS)<<10);
#else
#error "please choose the right APB1_PS"
#endif
	/*3-APB2_PS */
#if (RCC_APB2_PS <=7)
	RCC->CFGR &= ~((0b111)<<13);
	RCC->CFGR |= ((RCC_APB2_PS)<<13);
#else
#error "please choose the right APB2_PS"
#endif
	/*5-PLL configuration*/

#if RCC_PLL_ENABLE==ENABLE
#if RCC_PLL_SOURCE==RCC_HSE
	SET_BIT(RCC->PLLCFGR,PLLSRC);
#else       //with HSI
	CLR_BIT(RCC->PLLCFGR,PLLSRC);
#endif

	/*
	 * know  the rang  of***
   1- PLLN   from  192UL  to 432UL
   2- PLLM   from  2UL    to 63UL
   3- PLLP   2,4,6,8
	 */
#if ((RCC_NO_PLLM >=2 && RCC_NO_PLLM<=63))
	//PLLM
	RCC->PLLCFGR &= ~((0b111111)<<PLLM0);//clear
	RCC->PLLCFGR |=((RCC_NO_PLLM)<<PLLM0);
#else
#error "The RCC_NO_PLLM OUT OF THE RINGE PLEASE SELECT suitable NUMBER "
#endif
#if ((RCC_NO_PLLN >=129 && RCC_NO_PLLN<=432))
	//PLLN
	RCC->PLLCFGR &= ~((0x1FF)<<PLLN0);
	RCC->PLLCFGR |=((RCC_NO_PLLN)<<PLLN0);
#else
#error "The RCC_NO_PLLN OUT OF THE RINGE PLEASE SELECT suitable NUMBER "
#endif
#if ((RCC_NO_PLLP >=0  && RCC_NO_PLLMP <=2))
	//PLLP
	RCC->PLLCFGR &= ~((0b11)<<PLLP0);
	RCC->PLLCFGR |=((RCC_NO_PLLP)<<PLLP0);
#else
#error "The RCC_NO_PLLP OUT OF THE RINGE PLEASE SELECT suitable NUMBER "
#endif

#if ((RCC_NO_PLLQ >=2  && RCC_NO_PLLMQ <=15))
	//PLLP
	RCC->PLLCFGR &= ~((0b1111)<<PLLQ0);
	RCC->PLLCFGR |=((RCC_NO_PLLQ)<<PLLQ0);
#else
#error "The RCC_NO_PLLP OUT OF THE RINGE PLEASE SELECT suitable NUMBER "
#endif
#endif
	/*6-Enable the selected clock (HSI ON /HSE ON)*/
#if  RCC_HSE_ENABLE == ENABLE
	/*2- HSE_BYP (option of HSE) */
#if RCC_HSE_MODE==RCC_EXTERNAL_OSC
	SET_BIT(RCC->CR,HSEBYP);
#else
	CLR_BIT(RCC->CR,HSEBYP);
#endif
	SET_BIT(RCC->CR , HSEON);
	while(GET_BIT(RCC->CR,HSERDY)!=1);
#endif
	/*enable HSI*/
#if  RCC_HSI_ENABLE == ENABLE
	SET_BIT(RCC->CR,HSION);
	while(GET_BIT(RCC->CR,HSIRDY)!=1);
#else
	CLR_BIT(RCC->CR,HSION);
#endif
	/*enable PLL*/
#if RCC_PLL_ENABLE==ENABLE
	SET_BIT(RCC->CR,PLLON);
	while(GET_BIT(RCC->CR,PLLRDY)!=1);
#else
	CLR_BIT(RCC->CR,PLLON);
#endif
}
void MRCC_vEnableClock(bus_type A_BusId , u8 A_u8PeripheralId )
{
	switch(A_BusId)
	{
	case RCC_AHB1 :
		SET_BIT(RCC->AHB1ENR,A_u8PeripheralId);
		break ;
	case RCC_AHB2:
		SET_BIT(RCC->AHB2ENR,A_u8PeripheralId);
		break ;
	case RCC_APB1 :
		SET_BIT(RCC->APB1ENR,A_u8PeripheralId);
		break ;
	case RCC_APB2 :
		SET_BIT(RCC->APB2ENR,A_u8PeripheralId);
		break;
	case RCC_AHB1LP :
		SET_BIT(RCC->AHB1LPENR,A_u8PeripheralId);
		break ;
	case RCC_AHB2LP :
		SET_BIT(RCC->AHB2LPENR,A_u8PeripheralId);
		break ;
	case RCC_APB1LP :
		SET_BIT(RCC->APB1LPENR,A_u8PeripheralId);
		break;
	case RCC_APB2LP :
		SET_BIT(RCC->APB2LPENR,A_u8PeripheralId);
		break;

	}
}
void MRCC_vDisableClock(bus_type A_BusId , u8 A_u8PeripheralId)
{
	switch(A_BusId)
	{
	case RCC_AHB1 :
		CLR_BIT(RCC->AHB1ENR,A_u8PeripheralId);
		break ;
	case RCC_AHB2:
		CLR_BIT(RCC->AHB2ENR,A_u8PeripheralId);
		break ;
	case RCC_APB1 :
		CLR_BIT(RCC->APB1ENR,A_u8PeripheralId);
		break ;
	case RCC_APB2 :
		CLR_BIT(RCC->APB2ENR,A_u8PeripheralId);
		break;
	case RCC_AHB1LP :
		CLR_BIT(RCC->AHB1LPENR,A_u8PeripheralId);
		break ;
	case RCC_AHB2LP :
		CLR_BIT(RCC->AHB2LPENR,A_u8PeripheralId);
		break ;
	case RCC_APB1LP :
		CLR_BIT(RCC->APB1LPENR,A_u8PeripheralId);
		break;
	case RCC_APB2LP :
		CLR_BIT(RCC->APB2LPENR,A_u8PeripheralId);
		break;

	}
}

