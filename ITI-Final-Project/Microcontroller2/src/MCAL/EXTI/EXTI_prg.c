/*
 * EXTI_prg.c
 *
 *  Created on: Aug 16, 2023
 *      Author: dabou
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "EXTI_int.h"
#include "EXTI_prv.h"
#include "SYSCFG_prv.h"

void (*G_CallBack) (void) = NULL;
void MEXTI_vEnableLine(u8 A_u8Line, u8 A_u8Trigger)
{
	if(A_u8Line < 16)
	{
		SET_BIT(EXTI->IMR,A_u8Line);
		switch (A_u8Trigger)
		{
		case EXTI_RISING:
			SET_BIT(EXTI->RTSR,A_u8Line);
			CLR_BIT(EXTI->FTSR,A_u8Line);
			break;
		case EXTI_FALLING:
			SET_BIT(EXTI->FTSR,A_u8Line);
			CLR_BIT(EXTI->RTSR,A_u8Line);
			break;
		case EXTI_ONCHANGE:
			SET_BIT(EXTI->RTSR,A_u8Line);
			SET_BIT(EXTI->FTSR,A_u8Line);
			break;
		}
	}
}
void MEXTI_vDisableLine(u8 A_u8Line)
{
	if(A_u8Line < 16)
	{
		SET_BIT(EXTI->IMR,A_u8Line);
	}
}
void MEXTI_vSetTrigger(u8 A_u8Line, u8 A_u8Trigger)
{
	if(A_u8Line < 16)
	{
		switch (A_u8Trigger)
		{
		case EXTI_RISING:
			SET_BIT(EXTI->RTSR,A_u8Line);
			CLR_BIT(EXTI->FTSR,A_u8Line);
			break;
		case EXTI_FALLING:
			SET_BIT(EXTI->FTSR,A_u8Line);
			CLR_BIT(EXTI->RTSR,A_u8Line);
			break;
		case EXTI_ONCHANGE:
			SET_BIT(EXTI->RTSR,A_u8Line);
			SET_BIT(EXTI->FTSR,A_u8Line);
			break;
		}
	}
}
void MEXTI_vSoftwareTrigger(u8 A_u8Line)
{
	SET_BIT(EXTI->SWIER,A_u8Line);
}
void MEXTI_vClearFlag(u8 A_u8Line)
{
	SET_BIT(EXTI->PR,A_u8Line);
}

void MEXTI_vSetCallBack (u8 A_u8Line, void (*A_Ptr))
{
	G_CallBack = A_Ptr;
}
void  EXTI0_IRQHandler (void)
{
	MEXTI_vClearFlag(EXTI_LINE0);
	if(G_CallBack != NULL)
	{
		G_CallBack();
	}
}
/*SYSCFG FUNCTION*/
void MSYSCFG_vSelectePortPin(u8 A_u8Line, u8 A_u8Data)
{
	SYSCFG->EXTICR[A_u8Line / 4] = A_u8Data << ( (A_u8Line % 4) * 4 );
}

