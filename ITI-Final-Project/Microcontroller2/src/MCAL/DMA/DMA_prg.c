/*
 * DMA_prg.c
 *
 *  Created on: Sep 11, 2023
 *      Author: LENOVO
 */


#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"



#include"DMA_int.h"
#include"DMA_priv.h"


static void (*Call_Back[8])(void);

void MDMA_vInit(u8 A_u8StreamId,DMA_MemMap_t* DMAx)
{
	/* disable of DMA bec the CR register can be written only when En=0  */
	CLR_BIT(DMAx->S[A_u8StreamId].CR,0);
	/*select channel (default ch0)*/
	/*priority level*/
	SET_BIT(DMAx->S[A_u8StreamId].CR,17);
	SET_BIT(DMAx->S[A_u8StreamId].CR,16);
	/*MSIZE (WE CHOSE WORD)*/
	SET_BIT(DMAx->S[A_u8StreamId].CR,14);
	/*PSIZE*/
	SET_BIT(DMAx->S[A_u8StreamId].CR,12);
	/*memory increment mode & peripheral*/
	SET_BIT(DMAx->S[A_u8StreamId].CR,10);
	SET_BIT(DMAx->S[A_u8StreamId].CR,9);
	/*circular mode*/
	CLR_BIT(DMAx->S[A_u8StreamId].CR,8);
	/*Data Transfer Direction*/
	SET_BIT(DMAx->S[A_u8StreamId].CR,7);
	CLR_BIT(DMAx->S[A_u8StreamId].CR,6);
	/*Enable transfer complete interrupt*/
	SET_BIT(DMAx->S[A_u8StreamId].CR,4);
	/*FIFO Selection*/
	SET_BIT(DMAx->S[A_u8StreamId].FCR,1);
	SET_BIT(DMAx->S[A_u8StreamId].FCR,0);
	/*Disable Direct Mode*/
	SET_BIT(DMAx->S[A_u8StreamId].FCR,2);

}

void MDMA_vSetAddress(u8 A_u8StreamId,DMA_MemMap_t* DMAx,u32 A_u32SourceAddress,u32 A_u32DestinationAddress,u32 A_u32Length)
{
	DMAx->S[A_u8StreamId].NDTR=A_u32Length;
	DMAx->S[A_u8StreamId].PAR=A_u32SourceAddress;
	DMAx->S[A_u8StreamId].M0AR=A_u32DestinationAddress;
}

void MDMA_vStreamEnable(u8 A_u8StreamId,DMA_MemMap_t* DMAx)
{
	SET_BIT(DMAx->S[A_u8StreamId].CR,0);
}

void MDMA_vStreamDisable(u8 A_u8StreamId,DMA_MemMap_t* DMAx)
{
	CLR_BIT(DMAx->S[A_u8StreamId].CR,0);
}

/* function to clear flags since I use 1 interrupt so I clear only one flag*/
void MDMA_vClearCH0Flag(DMA_MemMap_t* DMAx)
{
	SET_BIT(DMAx->LIFCR,5);
}

void MDMA_SetCallBack(u8 A_u8StreamId , void (*ptr)(void))
{
	Call_Back[A_u8StreamId]=ptr;
}

void DMA2_Stream0_IRQHandler(void)
{
  /*clear flag*/
	MDMA_vClearCH0Flag(DMA2);
	if(Call_Back[0]!=0)
	{
		Call_Back[0]();
	}
}
