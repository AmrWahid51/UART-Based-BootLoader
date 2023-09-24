/*
. * RCC_prv.h
 *
 *  Created on: Aug 16, 2022
 *      Author: Bahgat Mahmoud
 */

#ifndef MCAL_RCC_RCC_PRV_H_
#define MCAL_RCC_RCC_PRV_H_

typedef struct
{
	u32 CR ;//4byte    0
	u32 PLLCFGR ;//4byte   5
	u32 CFGR ; // 9
	u32 CIR ;  // 13
	u32 AHB1RSTR ; //17
	u32 AHB2RSTR ; //21
	u32 resrved1 ;//resurved must be work this served
	u32 resrved2 ;
	u32 APB1RSTR ;
	u32 APB2RSTR ;
	u32 resrved3 ;
	u32 resrved4 ;
	u32 AHB1ENR  ;
	u32 AHB2ENR  ;
	u32 resrved5 ;
	u32 resrved6 ;

	u32 APB1ENR  ;
	u32 APB2ENR  ;
	u32 resrved7 ;
	u32 resrved8 ;

	u32 AHB1LPENR  ;
	u32 AHB2LPENR  ;
	u32 resrved9 ;
	u32 resrved10 ;

	u32 APB1LPENR  ;
	u32 APB2LPENR  ;
	u32 resrved11 ;
	u32 resrved12 ;

	u32 BDCR  ;
	u32 CSR  ;
	u32 resrved13 ;
	u32 resrved14 ;

	u32 SSCGR  ;
	u32 PLLI2SCFGR  ;
	u32 DCKCFGR ;

}RCC_MemMap_t;

#define  RCC_BASE_ADDRESS       0x40023800

#define   RCC     ((volatile RCC_MemMap_t*)(RCC_BASE_ADDRESS))


/*
 the bit of  CR REGISTER:
 */
#define  PLLON      24
#define  PLLRDY     25     //flag Read only

#define  CSSON      19

#define  HSION       0
#define  HSIRDY      1     //flag Read only

#define  HSEON      16
#define  HSERDY     17     //flag Read only
#define  HSEBYP     18
/*
 the bit of CFGR register
 */
//System clock switch status (Flag) read only
#define    SWS0    2   //System clock switch status (Flag) read only
#define    SWS1    3   //System clock switch status (Flag)

//System clock switch control
#define    SW0     0
#define    SW1     1
/*
 the bit of PLLCFGR register
 */
#define  PLLSRC      22  // to used the PLL with external or internal
#define  PLLM0        0
#define  PLLN0        6
#define  PLLP0        16
#define  PLLQ0        24 // 24 to 27
#define RTCPRE     16   // 16 to 20

#define  ENABLE      1
#define  DISABLE     0

#define  RCC_HSI         1
#define  RCC_HSE         2
#define  RCC_PLL         3

#define  RCC_PLLP_2          0b00
#define  RCC_PLLP_4          0b01
#define  RCC_PLLP_6          0b10
#define  RCC_PLLP_8          0b11

#define  RCC_USE_PLL_WITH_HSI      0
#define  RCC_USE_PLL_WITH_HSE      1

#define  SYSCLK_PS_1        0b0000
#define  SYSCLK_PS_2        0b1000
#define  SYSCLK_PS_4        0b1001
#define  SYSCLK_PS_8        0b1010
#define  SYSCLK_PS_16       0b1011
#define  SYSCLK_PS_64       0b1100
#define  SYSCLK_PS_128      0b1101
#define  SYSCLK_PS_256      0b1110
#define  SYSCLK_PS_512      0b1111

#define  AHB_PS_1        0b000   //0
#define  AHB_PS_2        0b100    //4
#define  AHB_PS_4        0b101
#define  AHB_PS_8        0b110
#define  AHB_PS_16       0b111    //7


enum {
	RESERVED1,
	RESERVED2,
	HSE_PS_2,
	HSE_PS_3,
	HSE_PS_4,
	HSE_PS_5,
	HSE_PS_6,
	HSE_PS_7,
	HSE_PS_8,
	HSE_PS_9,
	HSE_PS_10,
	HSE_PS_11,
	HSE_PS_12,
	HSE_PS_13,
	HSE_PS_14,
	HSE_PS_15,
	HSE_PS_16,
	HSE_PS_17,
	HSE_PS_18,
	HSE_PS_19,
	HSE_PS_20,
	HSE_PS_21,
	HSE_PS_22,
	HSE_PS_23,
	HSE_PS_24,
	HSE_PS_25,
	HSE_PS_26,
	HSE_PS_27,
	HSE_PS_28,
	HSE_PS_29,
	HSE_PS_30,
	HSE_PS_31
};

/*define frequancy of HSI is 16 MHZ*/
#define F_HSI 16000000UL

/*define frequancy of HSE is 25 MHZ*/
#define F_HSE 25000000UL

#if   RCC_SELECT_SYSTEM_CLOCK == RCC_HSI
      #define F_SYSTEM  F_HSI
#elif RCC_SELECT_SYSTEM_CLOCK == RCC_HSE
      #define F_SYSTEM  F_HSE
#endif


#endif /* MCAL_RCC_RCC_PRV_H_ */
