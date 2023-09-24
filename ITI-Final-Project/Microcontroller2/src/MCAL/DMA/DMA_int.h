/*
 * DMA_int.h
 *
 *  Created on: Sep 11, 2023
 *      Author: LENOVO
 */

#ifndef MCAL_DMA_DMA_INT_H_
#define MCAL_DMA_DMA_INT_H_

#include"DMA_priv.h"

#define     DMA2_BASE_ADD       0x40026400
#define     DMA1_BASE_ADD       0x40026000

enum
{
	stream0,
	stream1,
	stream2,
	stream3,
	stream4,
	stream5,
	stream6,
	stream7,
};

/* */
void MDMA_vInit(u8 A_u8StreamId,DMA_MemMap_t* DMAx);

void MDMA_vSetAddress(u8 A_u8StreamId,DMA_MemMap_t* DMAx,u32 A_u32SourceAddress,u32 A_u32DestinationAddress,u32 A_u32Length);
/*Start*/
void MDMA_vStreamEnable(u8 A_u8StreamId,DMA_MemMap_t* DMAx);

void MDMA_vStreamDisable(u8 A_u8StreamId,DMA_MemMap_t* DMAx);

void MDMA_vClearCH0Flag(DMA_MemMap_t* DMAx);

void MDMA_SetCallBack(u8 A_u8StreamId , void (*ptr)(void));


#endif /* MCAL_DMA_DMA_INT_H_ */
