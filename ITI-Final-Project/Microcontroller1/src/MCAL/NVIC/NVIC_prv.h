/*
 * NVIC_prv.h
 *
 *  Created on: Aug 14, 2023
 *      Author: dabou
 */

#ifndef MCAL_NVIC_NVIC_PRV_H_
#define MCAL_NVIC_NVIC_PRV_H_

#define   NVIC_BASE_ADDR      0xE000E100

typedef struct
{
	u32 ISER[8];
	u32 reserved1[24];
	u32 ICER[8];
	u32 reserved2[24];
	u32 ISPR[8];
	u32 reserved3[24];
	u32 ICPR[8];
	u32 reserved4[24];
	u32 IABR[8];
	u32 reserved5[56];
	u8 IPR[128];


}NVIC_MemoryMap_t;

#define NVIC   ((volatile NVIC_MemoryMap_t*) (NVIC_BASE_ADDR))



#define   SCB_BASE_ADDR      0xE000ED00

typedef struct
{
	volatile u32 CPUID;
	volatile u32 CSR;
	volatile u32 VTOR;
	volatile u32 AIRCR;
	volatile u32 SCR;
	volatile u32 CCR;
	volatile u32 SHPR1;
	volatile u32 SHPR2;
	volatile u32 SHPR3;
	volatile u32 SHCSR;
	volatile u32 CFSR;
	volatile u32 HFSR;
	volatile u32 reserved;
	volatile u32 MMAR;
	volatile u32 BFAR;
	volatile u32 AFSR;
}SCB_MemoryMap_t;


#define SCB   ((volatile SCB_MemoryMap_t*) (SCB_BASE_ADDR))

#define PASSWORD_TOWRITE_TO_AIRCR             0x05FA0000
#define BASE_ADDR_GROUP_PRIORITY              0x05FA0300



#endif /* MCAL_NVIC_NVIC_PRV_H_ */
