/*
 * FMI_prg.c
 *
 *  Created on: Sep 13, 2023
 *      Author: dabou
 */

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "FMI_prv.h"
#include "FMI_int.h"
#include "FMI_cfg.h"

void MFMI_vEraseAppArea(void)
{
	for(u8 i = START_SECTOR;i<END_SECTOR+1;i++)
	{
		MFMI_vSectorErase(i);
	}
}
void MFMI_vSectorErase(u8 A_u8SectorNumber)
{
	/*1-wait for flash not busy*/
	while(GET_BIT(FLASH->SR,BSY));
	/*2-unlock flash CR  using keys*/
	if(GET_BIT(FLASH->CR,LOCK) == 1)
	{
		FLASH->KEYR = FLASH_KEYR1;
		FLASH->KEYR = FLASH_KEYR2;
	}
	/*3-Select erase sector*/
	FLASH->CR &= ((u32) (0b1111<<3));
	FLASH->CR |= ((u32) (A_u8SectorNumber <<3));
	/*4-Activate Sector Erase*/
	SET_BIT(FLASH->CR,SER);
	/*5-Start Erasing*/
	SET_BIT(FLASH->CR,STRT);
	/*6-wait for busy flag*/
	while(GET_BIT(FLASH->SR,BSY));
	/*7- clear EOP Flag*/
	SET_BIT(FLASH->SR,EOP);
	/*8-de-Activate Sector Erase*/
	CLR_BIT(FLASH->CR,SER);


}
void MFMI_vFlashWrite(u32 A_u32Address,u16 *A_pu16Datau16,u16 A_u16Length)
{

	/*1-wait for flash not busy*/
	while(GET_BIT(FLASH->SR,BSY));
	/*2-unlock flash CR using keys*/
	if(GET_BIT(FLASH->CR,LOCK) == 1)
	{
		FLASH->KEYR = FLASH_KEYR1;
		FLASH->KEYR = FLASH_KEYR2;
	}
	/*3-select element size*/
	FLASH->CR &= ((u32) ((0b11) << 8));
	FLASH->CR |= ((u32) ((FLASH_PROG_16BIT)<< 8));
	/*4- activating Program Mode*/
	SET_BIT(FLASH->CR,PG);
	/*5- Writing Data array on flash address*/
	for(u16 i=0;i<A_u16Length;i++)
	{
		*((volatile u16*)(A_u32Address)) = A_pu16Datau16[i];
		A_u32Address += 2;
		/*6-wait for busy flag*/
		while(GET_BIT(FLASH->SR,BSY));
		/*7- clear EOP Flag*/
		SET_BIT(FLASH->SR,EOP);
	}
	SET_BIT(FLASH->SR,PG);
}

