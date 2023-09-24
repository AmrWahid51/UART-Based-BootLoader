/*
 * EXTI_prv.h
 *
 *  Created on: Aug 16, 2023
 *      Author: dabou
 */

#ifndef MCAL_EXTI_EXTI_PRV_H_
#define MCAL_EXTI_EXTI_PRV_H_

#define EXTI_BASE_ADDR        0x40013C00

typedef struct
{

	u32 IMR;
	u32 EMR;
	u32 RTSR;
	u32 FTSR;
	u32 SWIER;
	u32 PR;
}EXTI_MemoryMap_t;

#define EXTI ((volatile EXTI_MemoryMap_t*) (EXTI_BASE_ADDR))


#endif /* MCAL_EXTI_EXTI_PRV_H_ */
