/*
 * GPIO_prg.c
 *
 *  Created on: Aug 9, 2023
 *      Author: dabou
 */


#include "../../LIB/BIT_MATH.h"

#include "GPIO_int.h"
#include "GPIO_prv.h"
#include "GPIO_prv.h"


/*mode*/
void MGPIO_vSetPinMode(u8 A_u8PortId,u8 A_u8PinNo,u8 A_u8Mode)
{

	if(A_u8PinNo <16 && A_u8Mode<4 )
	{
		switch (A_u8PortId)
		{
		case GPIO_PORTA :
			GPIOA->MODER &=  ~ ((0x03) << (A_u8PinNo * 2));
			GPIOA->MODER |=   ( A_u8Mode << (A_u8PinNo * 2));
			break;
		case GPIO_PORTB :
			GPIOB->MODER &=  ~ ((0x03) << (A_u8PinNo * 2));
			GPIOB->MODER |=   ( A_u8Mode << (A_u8PinNo * 2));
			break;
		case GPIO_PORTC :
			GPIOC->MODER &=  ~ ((0x03) << (A_u8PinNo * 2));
			GPIOC->MODER |=   ( A_u8Mode << (A_u8PinNo * 2));
			break;

		}
	}


}

/*output type PushPull or Drain*/
void MGPIO_vPinOutputType(u8 A_u8PortId,u8 A_u8PinNo,u8 A_u8OutType)
{

	if (A_u8OutType == GPIO_OUTPUTTYPE_PUSHPULL )
	{
		switch(A_u8PortId)
		{
		case GPIO_PORTA :
			CLR_BIT(GPIOA->OTYPER,A_u8PinNo);
			break;
		case GPIO_PORTB :
			CLR_BIT(GPIOB->OTYPER,A_u8PinNo);
			break;
		case GPIO_PORTC :
			CLR_BIT(GPIOC->OTYPER,A_u8PinNo);
			break;
		}
	}
	else if (A_u8OutType == GPIO_OUTPUTTYPE_OPENDRAIN)
	{
		switch(A_u8PortId)
		{
		case GPIO_PORTA :
			SET_BIT(GPIOA->OTYPER,A_u8PinNo);
			break;
		case GPIO_PORTB :
			SET_BIT(GPIOB->OTYPER,A_u8PinNo);
			break;
		case GPIO_PORTC :
			SET_BIT(GPIOC->OTYPER,A_u8PinNo);
			break;
		}
	}
	else
	{
		/*ERROR*/
	}

}

/*selecting max speed*/
void MGPIO_vSetPinOutputSpeed(u8 A_u8PortId,u8 A_u8PinNo,u8 A_u8OutSpeed)
{


	if(A_u8PinNo <16 && A_u8OutSpeed<4 )
	{
		switch (A_u8PortId)
		{
		case GPIO_PORTA :
			GPIOA->OSPEEDER &=  ~ ((0x03) << (A_u8PinNo * 2));
			GPIOA->OSPEEDER |=   ( A_u8OutSpeed << (A_u8PinNo * 2));
			break;
		case GPIO_PORTB :
			GPIOB->OSPEEDER &=  ~ ((0x03) << (A_u8PinNo * 2));
			GPIOB->OSPEEDER |=   ( A_u8OutSpeed << (A_u8PinNo * 2));
			break;
		case GPIO_PORTC :
			GPIOC->OSPEEDER &=  ~ ((0x03) << (A_u8PinNo * 2));
			GPIOC->OSPEEDER |=   ( A_u8OutSpeed << (A_u8PinNo * 2));
			break;

		}
	}



}

/*pull up or down resistance*/
void MGPIO_vSetPinInputPull(u8 A_u8PortId,u8 A_u8PinNo,u8 A_u8PullType)
{

	if(A_u8PinNo <16 && A_u8PullType<4 )
	{
		switch (A_u8PortId)
		{
		case GPIO_PORTA :
			GPIOA->PUPDR &=  ~ ((0x03) << (A_u8PinNo * 2));
			GPIOA->PUPDR |=   ( A_u8PullType << (A_u8PinNo * 2));
			break;
		case GPIO_PORTB :
			GPIOB->PUPDR &=  ~ ((0x03) << (A_u8PinNo * 2));
			GPIOB->PUPDR |=   ( A_u8PullType << (A_u8PinNo * 2));
			break;
		case GPIO_PORTC :
			GPIOC->PUPDR &=  ~ ((0x03) << (A_u8PinNo * 2));
			GPIOC->PUPDR |=   ( A_u8PullType << (A_u8PinNo * 2));
			break;

		}
	}

}

/*read pin*/
u8 MGPIO_u8GetPinValue(u8 A_u8PortId,u8 A_u8PinNo)
{

	u8 L_u8Return = 0;
	switch(A_u8PortId)
	{
	case GPIO_PORTA :
		L_u8Return = GET_BIT(GPIOA->IDR,A_u8PinNo);
		break;
	case GPIO_PORTB :
		L_u8Return = GET_BIT(GPIOB->IDR,A_u8PinNo);
		break;
	case GPIO_PORTC :
		L_u8Return = GET_BIT(GPIOC->IDR,A_u8PinNo);
		break;
	}
	return L_u8Return;
}

/*write pin*/
void MGPIO_vSetPinValue(u8 A_u8PortId,u8 A_u8PinNo,u8 A_u8PinValue)
{
	{
		switch (A_u8PortId)
		{
		case GPIO_PORTA :
			GPIOA->ODR &=  ~ ((1) << A_u8PinNo );
			GPIOA->ODR |=   ( A_u8PinValue << A_u8PinNo);
			break;
		case GPIO_PORTB :
			GPIOB->ODR &=  ~ ((1) << A_u8PinNo );
			GPIOB->ODR |=   ( A_u8PinValue << A_u8PinNo);
			break;
		case GPIO_PORTC :
			GPIOC->ODR &=  ~ ((1) << A_u8PinNo );
			GPIOC->ODR |=   ( A_u8PinValue << A_u8PinNo);
			break;

		}

	}
}
void MGPIO_vSetPortValue(u8 A_u8PortId,u8 A_u8PortValue)
{
	{
		switch (A_u8PortId)
		{
		case GPIO_PORTA :
			GPIOA->ODR = A_u8PortValue ;
			break;
		case GPIO_PORTB :
			GPIOB->ODR = A_u8PortValue ;
			break;
		case GPIO_PORTC :
			GPIOC->ODR = A_u8PortValue ;
			break;

		}

	}
}

/*Toogle Pin*/
void MGPIO_vTogglePinValue(u8 A_u8PortId,u8 A_u8PinNo)
{
	switch(A_u8PortId)
	{
	case GPIO_PORTA :
		TOG_BIT(GPIOA->ODR,A_u8PinNo);
		break;
	case GPIO_PORTB :
		TOG_BIT(GPIOB->ODR,A_u8PinNo);
		break;
	case GPIO_PORTC :
		TOG_BIT(GPIOC->ODR,A_u8PinNo);
		break;
	}
}

/*BSRR HELP in writing in 1 bit by only 1 instruction without masks*/

void MGPIO_vSetPinValueFast(u8 A_u8PortId,u8 A_u8PinNo,u8 A_u8PinValue)
{
	if (A_u8PinValue == LOW )
	{
		switch(A_u8PortId)
		{
		case GPIO_PORTA :
			SET_BIT(GPIOA->BSRR,A_u8PinNo << 16);
			break;
		case GPIO_PORTB :
			SET_BIT(GPIOB->BSRR,A_u8PinNo << 16);
			break;
		case GPIO_PORTC :
			SET_BIT(GPIOC->BSRR,A_u8PinNo << 16);
			break;
		}
	}
	else if (A_u8PinValue == HIGH)
	{
		switch(A_u8PortId)
		{
		case GPIO_PORTA :
			SET_BIT(GPIOA->BSRR,A_u8PinNo);
			break;
		case GPIO_PORTB :
			SET_BIT(GPIOB->BSRR,A_u8PinNo);
			break;
		case GPIO_PORTC :
			SET_BIT(GPIOC->BSRR,A_u8PinNo);
			break;
		}
	}
	else
	{
		/*ERROR*/
	}


}

/*Alternative Functions*/
void MGPIO_vSetAlternativeFunction(u8 A_u8PortId,u8 A_u8PinNo,u8 A_u8AltFun)
{
	switch(A_u8PortId)
	{
	case GPIO_PORTA :
		if(A_u8PinNo < 8 )
		{
			GPIOA->AFRL &= ~(0x07 << A_u8PinNo * 4 );
			GPIOA->AFRL |= (A_u8AltFun << A_u8PinNo * 4 );

		}
		else if (A_u8PinNo >= 8 && A_u8PinNo < 16  )
		{
			GPIOA->AFRL &= ~(0x07 << (A_u8PinNo - 8) * 4 );
			GPIOA->AFRL |= (A_u8AltFun << (A_u8PinNo - 8) * 4 );
		}
		break;
	case GPIO_PORTB :
		if(A_u8PinNo < 8 )
		{
			GPIOB->AFRL &= ~(0x07 << A_u8PinNo * 4 );
			GPIOB->AFRL |= (A_u8AltFun << A_u8PinNo * 4 );

		}
		else if (A_u8PinNo >= 8 && A_u8PinNo < 16  )
		{
			GPIOB->AFRL &= ~(0x07 << (A_u8PinNo - 8) * 4 );
			GPIOB->AFRL |= (A_u8AltFun << (A_u8PinNo - 8) * 4 );
		}
		break;
	case GPIO_PORTC :
		if(A_u8PinNo < 8 )
		{
			GPIOC->AFRL &= ~(0x07 << A_u8PinNo * 4 );
			GPIOC->AFRL |= (A_u8AltFun << A_u8PinNo * 4 );
		}
		else if (A_u8PinNo >= 8 && A_u8PinNo < 16  )
		{
			GPIOC->AFRL &= ~(0x07 << (A_u8PinNo - 8) * 4 );
			GPIOC->AFRL |= (A_u8AltFun << (A_u8PinNo - 8) * 4 );
		}
		break;
	}

}

/*lock pins*/

//void MGPIO_vSetLock(u8 A_u8PortId,u8 A_u8PinNo,u8 A_u8Lock)
//{
//
//
//}
//
