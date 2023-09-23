/*
 * FMI_prv.h
 *
 *  Created on: Sep 13, 2023
 *      Author: dabou
 */

#ifndef MCAL_FMI_FMI_PRV_H_
#define MCAL_FMI_FMI_PRV_H_

/*AHB1 Bus */
#define FMI_BASE_ADDRESS     0x40023C00

typedef struct
{
	volatile u32 ACR;
	volatile u32 KEYR;
	volatile u32 OPTKEYR;
	volatile u32 SR;
	volatile u32 CR;
	volatile u32 OPTCR;

}FMI_MemMap_t;

#define FLASH ((volatile FMI_MemMap_t*)(FMI_BASE_ADDRESS))

#define BSY                 16
#define FLASH_KEYR1         0x45670123
#define FLASH_KEYR2			0xCDEF89AB
#define LOCK                31
#define SER					1
#define STRT                16
#define EOP                 0
#define PG                  0
#endif /* MCAL_FMI_FMI_PRV_H_ */
