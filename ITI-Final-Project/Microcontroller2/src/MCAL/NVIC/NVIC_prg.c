/*

 * NVIC_prg.c
 *
 *  Created on: Aug 14, 2023
 *      Author: dabou
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "NVIC_int.h"
#include "NVIC_prv.h"

static u32 G_u32GroupConfg;

/*used to enable interrupt*/
void MNVIC_vEnableInterruptPeripheral(u8 A_u8IntId )
{
	NVIC->ISER[A_u8IntId/32] = 1<<(A_u8IntId %32);
}

/*used to disable interrupt*/
void MNVIC_vDisableInterruptPeripheral(u8 A_u8IntId )
{
	NVIC->ICER[A_u8IntId/32] = 1<<(A_u8IntId %32);
}

/*used for testing sw interrupt*/
void MNVIC_vSetPending(u8 A_u8IntId )
{
	NVIC->ISPR[A_u8IntId/32] = 1<<(A_u8IntId %32);
}

/**/
void MNVIC_vClearPending(u8 A_u8IntId )
{
	NVIC->ICPR[A_u8IntId/32] = 1<<(A_u8IntId %32);
}

/*to check*/
u8 MNVIC_u8GetActive(u8 A_u8IntId )
{
	return GET_BIT(NVIC->IABR[A_u8IntId / 32],(A_u8IntId % 32));
}

/*determine how many group and subPriority do i have*/
void MNVIC_vSetPriorityCfg(u8 A_u8Group)
{
	G_u32GroupConfg = PASSWORD_TOWRITE_TO_AIRCR | (A_u8Group <<8);

	SCB->AIRCR =  G_u32GroupConfg;
}

/**/
void MNVIC_vSetPriority(s8 A_s8IntId , u8 A_u8GroupPriority,u8 A_u8SubPriority)
{
	/*local variable containing the configuration of the priorities */
	u32 L_u32GroupPriority = (SCB->AIRCR & 0x00007000) >> 8;
	/*configure group priority and SubPriority*/
	L_u32GroupPriority = A_u8SubPriority | (A_u8GroupPriority << (L_u32GroupPriority - 3));

	if(A_s8IntId < 0 )
	{
		if(A_s8IntId == NVIC_USAGE_FAULT ||
				A_s8IntId == NVIC_BUS_FAULT ||
				A_s8IntId == NVIC_MEM_MANAGE_FAULT )
		{
			A_s8IntId += 3;
			SCB->SHPR1 &= ~ ( (0x7) << ( 8 *A_s8IntId + 4 ) );
			SCB->SHPR1 |= L_u32GroupPriority << ( 8 *A_s8IntId + 4 );

		}
		else if(A_s8IntId == NVIC_SVCALL)
		{

			A_s8IntId += 7;
			SCB->SHPR2 &= ~ ( (0x7) << ( 8 *A_s8IntId + 4 ) );
			SCB->SHPR2 |= L_u32GroupPriority << ( 8 *A_s8IntId + 4 );
		}
		else if (A_s8IntId == NVIC_PendSV || A_s8IntId == NVIC_SYSTICK)
		{

			A_s8IntId += 8;
			SCB->SHPR3 &= ~ ( (0x7) << ( 8 *A_s8IntId + 4 ) );
			SCB->SHPR3 |= L_u32GroupPriority << ( 8 *A_s8IntId + 4 );
		}


	}
	else if(A_s8IntId >= 0 )
	{

		NVIC->IPR[A_s8IntId]= L_u32GroupPriority << 4;
	}

}



