/*
 * SPI_int.h
 *
 *  Created on: Sep 9, 2023
 *      Author: LENOVO
 */

#ifndef MCAL_SPI_SPI_INT_H_
#define MCAL_SPI_SPI_INT_H_



#define   SPI1_BASE_ADD     0x40013000
#define   SPI2_BASE_ADD     0x40013400
#define   SPI3_BASE_ADD     0x40003C00
#define   SPI4_BASE_ADD     0x4000 3800

typedef struct
{
	u32 CR1;
	u32 CR2;
	u32 SR;
	u32 DR;
	u32 CRCPR;
	u32 RXCRCR;
	u32 TXCRCR;
	u32 I2SCFGR;
	u32 I2SPR;
} SPI_MemMap_t;

#define   SPI1      ((volatile SPI_MemMap_t*)(SPI1_BASE_ADD))
#define   SPI2      ((volatile SPI_MemMap_t*)(SPI2_BASE_ADD))
#define   SPI3      ((volatile SPI_MemMap_t*)(SPI3_BASE_ADD))
#define   SPI4      ((volatile SPI_MemMap_t*)(SPI4_BASE_ADD))


void MSPI_vInit(SPI_MemMap_t* SPIx);

/*
 * function to check the SPI
 */
u16 MSPI_u16Tranceive(u16 A_u16Data,SPI_MemMap_t* SPIx);





#endif /* MCAL_SPI_SPI_INT_H_ */
