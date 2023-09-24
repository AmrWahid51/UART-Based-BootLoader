/*
 * UART_prg.c
 *
 *  Created on: Sep 10, 2023
 *      Author: dabou
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include"UART_prv.h"
#include"UART_cfg.h"
#include"UART_int.h"


void (*MUSART1_CallBack) (void) = NULL;
void (*MUSART2_CallBack) (void) = NULL;
void (*MUSART6_CallBack) (void) = NULL;

void MUSART1_vSetCallBack(void (*ptr) (void) )
{
	MUSART1_CallBack = ptr;
}
void MUSART2_vSetCallBack(void (*ptr) (void) )
{
	MUSART2_CallBack = ptr;
}
void MUSART6_vSetCallBack(void (*ptr) (void) )
{
	MUSART6_CallBack = ptr;
}

void USART1_IRQHandler(void)
{
	/*Reset Flag Register*/
	USART1->SR = 0;
	if (MUSART1_CallBack != NULL)
	{
		MUSART1_CallBack();
	}
}
void USART2_IRQHandler(void)
{
	/*Reset Flag Register*/
	USART2->SR = 0;
	if (MUSART2_CallBack != NULL)
	{
		MUSART2_CallBack();
	}
}
void USART6_IRQHandler(void)
{
	/*Reset Flag Register*/
	USART6->SR = 0;
	if (MUSART6_CallBack != NULL)
	{
		MUSART6_CallBack();
	}
}

void MUSART_vInit(USART_InitType *A_InitStruct,USART_MemMap_t *USARTx)
{
	USARTx->CR1 = 0;
	switch(A_InitStruct->OverSampling)
	{
	case USART_OVER_SAMPLING_16:
		USARTx->BRR = UART_BRR_SAMPLING16(__PCLK__,A_InitStruct->BaudRate);
		break;
	case USART_OVER_SAMPLING_8:
		USARTx->BRR = UART_BRR_SAMPLING8(__PCLK__,A_InitStruct->BaudRate);
		break;
	}

	USARTx->CR1 = (A_InitStruct->OverSampling <<MUSART_CR1_OVER8_BIT)|
			(A_InitStruct->DataWidth <<MUSART_CR1_M_BIT) |
			(A_InitStruct->Parity_Enable <<MUSART_CR1_PCE_BIT)|
			(A_InitStruct->Parity_Selection <<MUSART_CR1_PS_BIT);
	switch(A_InitStruct->TransferDirection)
	{
	case USART_TX_ONLY: SET_BIT(USARTx->CR1,MUSART_CR1_TE_BIT); break;
	case USART_RX_ONLY: SET_BIT(USARTx->CR1,MUSART_CR1_RE_BIT); break;
	case USART_TX_RX: SET_BIT(USARTx->CR1,MUSART_CR1_RE_BIT);
	SET_BIT(USARTx->CR1,MUSART_CR1_TE_BIT);   break;
	}
	USARTx->SR = 0;

}
void MSUART_Enable(USART_MemMap_t *USARTx)
{
	SET_BIT(USARTx->CR1,MUSART_CR1_UE_BIT);
}
void MSUART_Disable(USART_MemMap_t *USARTx)
{
	CLR_BIT(USARTx->CR1,MUSART_CR1_UE_BIT);
}

u8 MSUART_u8TransmitByteAsynch(USART_MemMap_t *USARTx,u8 A_u8Byte)
{
	if(GET_BIT(USARTx->SR,MUSART_SR_TXE_BIT) == 1)
	{
		USARTx->DR = A_u8Byte;
		return 0;
	}
	else return 1;
}
void MSUART_vTransmitByteSynch(USART_MemMap_t *USARTx,u8 A_u8Byte)
{
	//	/*this is for extra safety */
	//	while(GET_BIT(USARTx->SR,MUSART_SR_TXE_BIT) == 0);
	USARTx->DR = A_u8Byte;
	while(GET_BIT(USARTx->SR,MUSART_SR_TC_BIT) == 0);
	/*clear the complete transfer flag*/
	CLR_BIT(USARTx->SR,MUSART_SR_TC_BIT);
}

void MSUART_vTransmitString(USART_MemMap_t *USARTx,u8 *A_ptru8String)
{
	u8 L_u8Iterator = 0;
	while(A_ptru8String[L_u8Iterator] != '\0')
	{
		MSUART_vTransmitByteSynch(USARTx,A_ptru8String[L_u8Iterator]);
		L_u8Iterator++;
	}
}

u8 MUSART_u8ReceiveByteSynchNonBlocking(USART_MemMap_t *USARTx)
{
	u8 L_u8Data = 0;
	u32 L_u32TimeOut = 0;
	while(GET_BIT(USARTx->SR,MUSART_SR_RXNE_BIT)== 0 && L_u32TimeOut < THERESHOLD_VALUE )
	{
		L_u32TimeOut++;
	}
	if(L_u32TimeOut == THERESHOLD_VALUE )
	{
		L_u8Data = TIMEOUT;
	}
	else
	{
		L_u8Data = USARTx->DR;
	}
	return L_u8Data;
}

u8 MUSART_u8ReceiveByteAsynch_(USART_MemMap_t *USARTx, u8 *ptr)
{
	u8 Status = 1;
	while(GET_BIT(USARTx->SR,MUSART_SR_RXNE_BIT)== 0);
	*ptr = USARTx->DR;
	return Status;
}

u8 MUSART_u8ReceiveByteSynchBlocking(USART_MemMap_t *USARTx )
{
	u8 L_u8Data = 0;
	while(GET_BIT(USARTx->SR,MUSART_SR_RXNE_BIT)== 0);
	L_u8Data = USARTx->DR;
	return L_u8Data;
}
void MUSART_ptrReceiveStringSynchNonBlocking(USART_MemMap_t *USARTx ,char A_u8str[] ,u32 A_u32Size )
{
	u32 L_u32Iterator = 0;
	while(L_u32Iterator <A_u32Size)
	{
		A_u8str[L_u32Iterator] = MUSART_u8ReceiveByteSynchBlocking(USARTx);
		if(A_u8str[L_u32Iterator] == '\n' || A_u8str[L_u32Iterator] == '\r')
		{
			A_u8str[L_u32Iterator] = '\0';
			break;
		}
	}
	A_u8str[A_u32Size-1] = '\0';
}

void MUSART_RxIntSetStatus(USART_MemMap_t *USARTx, u8 A_u8Status)
{
	switch(A_u8Status)
	{
	case ENABLE  : SET_BIT(USARTx->CR1,MUSART_CR1_RXNEIE_BIT); break;
	case DISABLE : CLR_BIT(USARTx->CR1,MUSART_CR1_RXNEIE_BIT); break;
	}
}
void MUSART_voidClearFlags(USART_MemMap_t *USARTx)
{
	USARTx->SR = 0;

}
u8 MUSART_u8ReadDataRegister(USART_MemMap_t *USARTx)
{
	return USARTx->DR;
}


