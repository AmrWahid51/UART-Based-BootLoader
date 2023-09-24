/*
 * HEXPARSER_prg.c
 *
 *  Created on: Sep 13, 2023
 *      Author: dabou
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/FMI/FMI_int.h"

#include "HEXPARSER_int.h"

#define FLASH_BASE_ADDR  0x08000000  //sector0

//0x10 0b 0001 0000 ->> 16
//78 record type: (01) EOF or (04) High Part Address
// ":10 00 00 00 0000 0120 C502 0008 CB02 0008 CF02 0008 52"
//   012 3456 78 9


u8 Higher_Address = 0x0800;


static u8 HEXPARSER_u8AsciiToHex(u8 A_u8Ascii)
{
	u8 L_ReturnVal = 0;
	if(A_u8Ascii >= '0' && A_u8Ascii <= '9')
	{
		L_ReturnVal = A_u8Ascii - '0';
	}
	else if (A_u8Ascii >= 'A' && A_u8Ascii <= 'F')
	{
		L_ReturnVal = A_u8Ascii - 'A' + 10;
	}
	return L_ReturnVal;
}

// CC bit 1,2   size/2  CC = (CC_H <<4 ) | CC_L;
// Lower Address bit 3,4,5,6
// Address = Address | (Higher_Address <<4);
// Data in u16  u16 Buffer[100]; ,we know size from CC
// flash (address,array of data,count,size);

void HEXPARSER_vParseData(u8 A_pu8Data[])
{
	/*1- Character count*/
	u8 CC_L,CC_H,CC;
	CC_H = HEXPARSER_u8AsciiToHex(A_pu8Data[1]);
	CC_L = HEXPARSER_u8AsciiToHex(A_pu8Data[2]);
	u16 DataBuffer[50];
	u32 Address;
	u16 Address_L , digit0,digit1,digit2,digit3;
	CC = (CC_H << 4) | CC_L; //size of data(in byte)
	/*2- Lower Address*/
	digit0 = HEXPARSER_u8AsciiToHex(A_pu8Data[3]);
	digit1 = HEXPARSER_u8AsciiToHex(A_pu8Data[4]);
	digit2 = HEXPARSER_u8AsciiToHex(A_pu8Data[5]);
	digit3 = HEXPARSER_u8AsciiToHex(A_pu8Data[6]);
	Address_L = (digit0 << 12) | (digit1 << 8) | (digit2 << 4) | (digit3 << 0);
	Address = Address_L | ((u32)Higher_Address << 16);
	// 0000 0120 C502 0008 CB02 0008 CF02 0008 size = CC/2

	for (u8 i=0;i< (CC/2) ;i++)
	{
		digit0 = HEXPARSER_u8AsciiToHex(A_pu8Data[9 + 4 *i]);
		digit1 = HEXPARSER_u8AsciiToHex(A_pu8Data[10 + 4 *i]);
		digit2 = HEXPARSER_u8AsciiToHex(A_pu8Data[11 + 4 *i]);
		digit3 = HEXPARSER_u8AsciiToHex(A_pu8Data[12 + 4 *i]);
		DataBuffer[i] = (digit0 << 12) | (digit1 << 8) | (digit2 << 4) | (digit3 << 0);
	}
	MFMI_vFlashWrite(Address,DataBuffer,CC/2);


}
