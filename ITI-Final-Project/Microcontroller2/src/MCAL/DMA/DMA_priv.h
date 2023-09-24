/*
 * DMA_priv.h
 *
 *  Created on: Sep 11, 2023
 *      Author: LENOVO
 */

#ifndef MCAL_DMA_DMA_PRIV_H_
#define MCAL_DMA_DMA_PRIV_H_


typedef struct
{
	u32 CR;
	u32 NDTR;
	u32 PAR;
	u32 M0AR;
	u32 M1AR;
	u32 FCR;
}DMA_Stream_t;

typedef struct
{
  u32  LISR;
  u32  HISR;
  u32  LIFCR;
  u32  HIFCR;
  //the rest of a registers each exist 8 times so we did this to
  DMA_Stream_t S[8];

}DMA_MemMap_t;

#define       DMA1       (volatile DMA_MemMap_t*)(DMA1_BASE_ADD )
#define       DMA2       (volatile DMA_MemMap_t*)(DMA2_BASE_ADD )





#endif /* MCAL_DMA_DMA_PRIV_H_ */
