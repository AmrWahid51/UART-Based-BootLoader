/*
 * EXTI_int.h
 *
 *  Created on: Aug 16, 2023
 *      Author: dabou
 */

#ifndef MCAL_EXTI_EXTI_INT_H_
#define MCAL_EXTI_EXTI_INT_H_

void MEXTI_vEnableLine(u8 A_u8Line, u8 A_u8Trigger);
void MEXTI_vDisableLine(u8 A_u8Line);
void MEXTI_vSetTrigger(u8 A_u8Line, u8 A_u8Trigger);
void MEXTI_vSoftwareTrigger(u8 A_u8Line);
void MEXTI_vClearFlag(u8 A_u8Line);
void MEXTI_vSetCallBack (u8 A_u8Line, void (*A_Ptr));


/*Interrupt trigger type*/
#define  EXTI_RISING         0
#define  EXTI_FALLING        1
#define  EXTI_ONCHANGE       2

/*Interrupt enable bits*/
#define EXTI_LINE0           0
#define EXTI_LINE1           1
#define EXTI_LINE2           2
#define EXTI_LINE3           3
#define EXTI_LINE4           4
#define EXTI_LINE5           5
#define EXTI_LINE6           6
#define EXTI_LINE7           7
#define EXTI_LINE8           8
#define EXTI_LINE9           9
#define EXTI_LINE10          10
#define EXTI_LINE11          11
#define EXTI_LINE12          12
#define EXTI_LINE13          13
#define EXTI_LINE14          14
#define EXTI_LINE15          15
///////////////////////////////////////////////////////////////////////////////////////
/*SYSCFG*/
void MSYSCFG_vSelectePortPin(u8 A_u8Line, u8 A_u8Data);

#endif /* MCAL_EXTI_EXTI_INT_H_ */
