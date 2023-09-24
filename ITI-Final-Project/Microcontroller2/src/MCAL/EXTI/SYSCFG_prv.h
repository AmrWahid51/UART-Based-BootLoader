/*
 * SYSCFG_prv.h
 *
 *  Created on: Aug 16, 2023
 *      Author: dabou
 */

#ifndef MCAL_SYSCFG_SYSCFG_PRV_H_
#define MCAL_SYSCFG_SYSCFG_PRV_H_


#define SYSCFG_BASE_ADDR        0x40013800

typedef struct
{
	u32 MEMRMP;
	u32 PMC;
	u32 EXTICR[4];
	u32 CMPCR;

}SYSCFG_MemoryMap_t;

#define SYSCFG ((volatile SYSCFG_MemoryMap_t*) (SYSCFG_BASE_ADDR))



#endif /* MCAL_SYSCFG_SYSCFG_PRV_H_ */
