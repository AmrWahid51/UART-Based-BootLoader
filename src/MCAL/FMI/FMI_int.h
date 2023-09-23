/*
 * FMI_int.h
 *
 *  Created on: Sep 13, 2023
 *      Author: dabou
 */

#ifndef MCAL_FMI_FMI_INT_H_
#define MCAL_FMI_FMI_INT_H_

enum{
	SECTOR0,
	SECTOR1,
	SECTOR2,
	SECTOR3,
	SECTOR4,
	SECTOR5,
	SECTOR6,
};
void MFMI_vEraseAppArea(void);
void MFMI_vSectorErase(u8 A_u8SectorNumber);
void MFMI_vFlashWrite(u32 A_u32Address,u16 *A_pu16Datau16,u16 A_u16Length);


#endif /* MCAL_FMI_FMI_INT_H_ */
