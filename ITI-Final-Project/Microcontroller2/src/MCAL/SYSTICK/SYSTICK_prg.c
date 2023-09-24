/*
 * SYSTICK_prg.c
 *
 *  Created on: Aug 17, 2023
 *      Author: dabou
 */

#include  "../../LIB/BIT_MATH.h"
#include  "../../LIB/STD_TYPES.h"

#include "SYSTICK_prv.h"
#include "SYSTICK_int.h"
#include "SYSTICK_cfg.h"

void (*G_vCallBack)(void) = NULL;
u8 Flag;

/*initialization of the systick timer*/
void MSTK_vInit(void)
{

	/*Clock Source*/
#if STK_CLK_SOURCE == STK_AHB
	SET_BIT(STK->CTRL,CLKSOURCE);
#elif STK_CLK_SOURCE == STK_AHB_PR_8
	CLR_BIT(STK->CTRL,CLKSOURCE);
#endif


	/*Interrupt Enable Disable*/
#if STK_INTERRUPT_EN == ENABLE
	SET_BIT(STK->CTRL,TICKINT);
#elif STK_INTERRUPT_EN == DISABLE
	CLR_BIT(STK->CTRL,TICKINT);
#endif
}

/**/
void MSTK_vStartTimer(void)
{
	SET_BIT(STK->CTRL,STK_ENABLE);
}
/**/
void MSTK_vStopTimer(void)
{
	/*1- reset timer */
	STK->VAL = 0; // RESET by writing any value
	CLR_BIT(STK->CTRL,STK_ENABLE);
}

/**/
void MSTK_vSetBusyWait(u32 A_u32Tick)
{
	/*1- reset timer */
	STK->VAL = 0; // RESET by writing any value
	/*2- load time value */
	STK->LOAD = A_u32Tick;
	/*3- start timer */
	MSTK_vStartTimer();
	/*4- pooling check*/
	while(GET_BIT(STK->CTRL,COUNTFLAG) != 1);
	/*5- stop timer*/
	MSTK_vStopTimer();
}

/**/
void MSTK_vSetInterval_Single(u32 A_u32Tick, void (*CallBackFunc)(void))
{
	/*0-set callback function*/
	G_vCallBack = CallBackFunc;
	Flag = SINGLE;
	/*1- reset timer */
	STK->VAL = 0; // RESET by writing any value
	/*2- load time value */
	STK->LOAD = A_u32Tick;
	/*3- start timer */
	MSTK_vStartTimer();
}

/**/
void MSTK_vSetInterval_Periodic(u32 A_u32Tick, void (*CallBackFunc)(void))
{
	/*0-set callback function*/
	G_vCallBack = CallBackFunc;
	Flag = PERIODC;
	/*1- reset timer */
	STK->VAL = 0; // RESET by writing any value
	/*2- load time value */
	STK->LOAD = A_u32Tick;
	/*3- start timer */
	MSTK_vStartTimer();
}

/**/
u32 MSTK_u32GetElapsedTime(void)
{
	return (STK->LOAD - STK->VAL);
}

/**/
u32 MSTK_u32GetRemainingTime(void)
{
	return (STK->VAL);
}

void Systick_Handler(void)
{
	u8 ClearFlag ;
	if(G_vCallBack != NULL)
	{
		G_vCallBack();
	}
	if(Flag == SINGLE)
	{
		Flag = PERIODC;
		MSTK_vStopTimer();
	}

	ClearFlag = GET_BIT(STK->CTRL,COUNTFLAG) ;
}

