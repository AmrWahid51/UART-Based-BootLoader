/*
 * SPI_prg.c
 *
 *  Created on: Sep 9, 2023
 *      Author: LENOVO
 */

#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"../GPIO/GPIO_int.h"

#include"SPI_priv.h"
#include"SPI_cfg.h"
#include"SPI_int.h"


void MSPI_vInit(SPI_MemMap_t* SPIx)
{
	SET_BIT(SPIx->CR1,CPHA);
	SET_BIT(SPIx->CR1,CPOL);

	/*MASTER SELECTION*/
	SET_BIT(SPIx->CR1,MSTR); //MASTER CONFIGURATION

	/* SELSECT BAUDRATE*/
	SPIx->CR1 &= ~ ((0b111)<<3);

	SPIx->CR1 |=((SPI_BAUDRATE)<<3);


	SET_BIT(SPIx->CR1,LSBFIRST); // LSB Transmit first

	CLR_BIT(SPIx->CR1,DFF);  //8_BIT FRAME

	/* ENABLE SPI */
	SET_BIT(SPIx->CR1,SPE);


	/*MOSI*/
	MGPIO_vSetPinMode(GPIO_PORTA,GPIO_PIN7,GPIO_MODE_ALT);
	MGPIO_vPinOutputType(GPIO_PORTA,GPIO_PIN7,GPIO_OUTPUTTYPE_PUSHPULL);
	MGPIO_vSetAlternativeFunction(GPIO_PORTA,GPIO_PIN7,GPIO_AF5);


	/* MISO*/
	MGPIO_vSetPinMode(GPIO_PORTA,GPIO_PIN6,GPIO_MODE_ALT);
	MGPIO_vPinOutputType(GPIO_PORTA,GPIO_PIN6,GPIO_OUTPUTTYPE_PUSHPULL);
	MGPIO_vSetAlternativeFunction(GPIO_PORTA,GPIO_PIN6,GPIO_AF5);

	/*SCK*/
	MGPIO_vSetPinMode(GPIO_PORTA,GPIO_PIN5,GPIO_MODE_ALT);
	MGPIO_vPinOutputType(GPIO_PORTA,GPIO_PIN5,GPIO_OUTPUTTYPE_PUSHPULL);
	MGPIO_vSetAlternativeFunction(GPIO_PORTA,GPIO_PIN5,GPIO_AF5);


}


u16 MSPI_u16Tranceive(u16 A_u16Data,SPI_MemMap_t* SPIx)
{
	SPIx->DR= A_u16Data;

	while(GET_BIT(SPIx->SR,BSY)==1);

	return SPIx->DR;



}





