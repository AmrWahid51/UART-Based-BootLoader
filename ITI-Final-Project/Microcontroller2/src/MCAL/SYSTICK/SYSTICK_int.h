/*
 * SYSTICK_int.h
 *
 *  Created on: Aug 17, 2023
 *      Author: dabou
 */

#ifndef MCAL_SYSTICK_SYSTICK_INT_H_
#define MCAL_SYSTICK_SYSTICK_INT_H_

/*initialization of the systick timer*/
void MSTK_vInit(void);

/**/
void MSTK_vStartTimer(void);

/**/
void MSTK_vStopTimer(void);

/**/
void MSTK_vSetBusyWait(u32 A_u32Tick);

/**/
void MSTK_vSetInterval_Single(u32 A_u32Tick, void (*CallBackFunc)(void));

/**/
void MSTK_vSetInterval_Periodic(u32 A_u32Tick, void (*CallBackFunc)(void));

/**/
u32 MSTK_u32GetElapsedTime(void);

/**/
u32 MSTK_u32GetRemainingTime(void);




#endif /* MCAL_SYSTICK_SYSTICK_INT_H_ */
