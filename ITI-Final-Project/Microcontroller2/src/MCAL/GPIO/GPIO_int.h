/*
 * GPIO_int.h
 *
 *  Created on: Aug 9, 2023
 *      Author: dabou
 */

#ifndef MCAL_GPIO_GPIO_INT_H_
#define MCAL_GPIO_GPIO_INT_H_

#include "../../LIB/STD_TYPES.h"

typedef struct{
	u8 mode;
	u8 out_type;
	u8 input_type;
	u8 speed;
	u8 A_u8Altfun ;
	u8 port ;
	u8 pin ;
}GPIO_cfg_t;

/*mode*/
void MGPIO_vSetPinMode(u8 A_u8PortId,u8 A_u8PinNo,u8 A_u8Mode);

/*output type PushPull or Drain*/
void MGPIO_vPinOutputType(u8 A_u8PortId,u8 A_u8PinNo,u8 A_u8OutType);

/*selecting max speed*/
void MGPIO_vSetPinOutputSpeed(u8 A_u8PortId,u8 A_u8PinNo,u8 A_u8OutSpeed);

/*pull up or down resistance*/
void MGPIO_vSetPinInputPull(u8 A_u8PortId,u8 A_u8PinNo,u8 A_u8PullType);

/*read pin*/
u8 MGPIO_u8GetPinValue(u8 A_u8PortId,u8 A_u8PinNo);

/*write pin*/
void MGPIO_vSetPinValue(u8 A_u8PortId,u8 A_u8PinNo,u8 A_u8PinValue);
/*write port*/
void MGPIO_vSetPortValue(u8 A_u8PortId,u8 A_u8PortValue);

/*Toogle Pin*/
void MGPIO_vTogglePinValue(u8 A_u8PortId,u8 A_u8PinNo);

/*BSRR HELP in writing in 1 bit by only 1 instruction without masks*/

void MGPIO_vSetPinValueFast(u8 A_u8PortId,u8 A_u8PinNo,u8 A_u8PinValue);

/*lock pins*/

void MGPIO_vSetLock(u8 A_u8PortId,u8 A_u8PinNo,u8 A_u8Lock);

/*Alternative Functions*/
void MGPIO_vSetAlternativeFunction(u8 A_u8PortId,u8 A_u8PinNo,u8 A_u8AltFun);


/*Ports Defines*/
#define GPIO_PORTA      0
#define GPIO_PORTB 		1
#define GPIO_PORTC 		2

/*Pins Defines*/
#define GPIO_PIN0           0
#define GPIO_PIN1		    1
#define GPIO_PIN2 		    2
#define GPIO_PIN3           3
#define GPIO_PIN4		    4
#define GPIO_PIN5 		    5
#define GPIO_PIN6           6
#define GPIO_PIN7		    7
#define GPIO_PIN8 		    8
#define GPIO_PIN9           9
#define GPIO_PIN10		    10
#define GPIO_PIN11		    11
#define GPIO_PIN12          12
#define GPIO_PIN13		    13
#define GPIO_PIN14		    14
#define GPIO_PIN15          15


/*modes*/
#define GPIO_MODE_INPUT       0
#define GPIO_MODE_OUTPUT      1
#define GPIO_MODE_ALT         2
#define GPIO_MODE_ANALOG      3

/*OutPut Types*/
#define GPIO_OUTPUTTYPE_OPENDRAIN        0
#define GPIO_OUTPUTTYPE_PUSHPULL         1

/*OUTput speed*/
#define GPIO_OUTPUT_SPEED_LOW               0
#define GPIO_OUTPUT_SPEED_MEDIUM            1
#define GPIO_OUTPUT_SPEED_HIGH              2
#define GPIO_OUTPUT_SPEED_VERYHIGH          3

/* INPUT TYPE */
#define GPIO_INPUTTYPE_NPUD           0
#define GPIO_INPUTTYPE_PU             1
#define GPIO_INPUTTYPE_PD             2

/*setting the pin value*/
#define HIGH           1
#define LOW            0

/*locking ports*/
#define GPIO_PIN_LOCKED        0
#define GPIO_PIN_UNLOCKED      1

/*Alternating Functions Register Pins*/
#define GPIO_AFRL0                0
#define GPIO_AFRL1                1
#define GPIO_AFRL2                2
#define GPIO_AFRL3                3
#define GPIO_AFRL4                4
#define GPIO_AFRL5                5
#define GPIO_AFRL6                6
#define GPIO_AFRL7                7

#define GPIO_AFRH8                8
#define GPIO_AFRH9                9
#define GPIO_AFRH10               10
#define GPIO_AFRH11               11
#define GPIO_AFRH12               12
#define GPIO_AFRH13               13
#define GPIO_AFRH14               14
#define GPIO_AFRH15               15

/*Alternating Functions types*/
#define GPIO_AF0               0
#define GPIO_AF1               1
#define GPIO_AF2               2
#define GPIO_AF3               3
#define GPIO_AF4               4
#define GPIO_AF5               5
#define GPIO_AF6               6
#define GPIO_AF7               7
#define GPIO_AF8               8
#define GPIO_AF9               9
#define GPIO_AF10              10
#define GPIO_AF11              11
#define GPIO_AF12              12
#define GPIO_AF13              13
#define GPIO_AF14              14
#define GPIO_AF15              15



#endif /* MCAL_GPIO_GPIO_INT_H_ */
