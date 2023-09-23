/*
 * RCC_cfg.h
 *
 *  Created on: Aug 16, 2022
 *      Author: Bahgat Mahmoud
 */

#ifndef MCAL_RCC_RCC_CFG_H_
#define MCAL_RCC_RCC_CFG_H_
/*
 * OPTIONS:
     1-       RCC_HSI        //0
     2-       RCC_HSE        //1
     3-       RCC_PLL        //2
 */
#define RCC_SELECT_SYSTEM_CLOCK        RCC_HSE // 16M
/*
 options:
   1- ENABLE     //1
   2- DISABLE    //0
 */
#define   RCC_HSE_ENABLE    ENABLE
#define   RCC_HSI_ENABLE    DISABLE
#define   RCC_PLL_ENABLE    DISABLE
/*
 * Option:
 *
 *    1- SYSCLK_PS_1
 *    2- SYSCLK_PS_2
 *    3- SYSCLK_PS_4
 *    4- SYSCLK_PS_8
 *    5- SYSCLK_PS_16
 *    6- SYSCLK_PS_64
 *    7- SYSCLK_PS_128
 *    8- SYSCLK_PS_256
 *    9- SYSCLK_PS_512
 */
#define  RCC_AHB_PS   SYSCLK_PS_1 // AHB = 8MHZ
/*
 * Option:
 *  RCC_APB1_PS   AHB_PS_?
 *  RCC_APB2_PS   AHB_PS_?
 *    1- AHB_PS_1
 *    2- AHB_PS_2
 *    3- AHB_PS_4
 *    4- AHB_PS_8
 *    5- AHB_PS_16
 */
/*
 Caution: The software has to set these bits correctly not to exceed 42 MHz on this domain.
The clocks are divided with the new prescaler factor from 1 to 16 AHB cycles after
PPRE1 write.
 */
#define  RCC_APB1_PS   AHB_PS_1
/*
 * Caution: The software has to set these bits correctly not to exceed 84 MHz on this domain.
The clocks are divided with the new prescaler factor from 1 to 16 AHB cycles after
PPRE2 write
 */
#define  RCC_APB2_PS   AHB_PS_1
/*
 * Options: HSE_PS_X
 * where X is equal to
 *   the Range 2UL To  31UL
 */
#define  RCC_RTC_PS        2UL

/*
 * CSS
 * Clock security system ON (Clock detector ON if HSE oscillator is stable, OFF if not)
   CLOCK detector
 options:
   1- ENABLE     //1
   2- DISABLE    //0
 */
#define   RCC_CLOCK_SECURITY_SYSTEM_ENABLE    DISABLE

/*
  OPtions: default ==RCC_CRYSTAL_OSC
     1- RCC_CRYSTAL_OSC
     2- RCC_EXTERNAL_OSC
 */
#define   RCC_HSE_MODE     RCC_CRYSTAL_OSC

/*
 * page 105
 * if you enable PLL
 * determine you  output Frequency F
 * F(VCO)=F(PLL(input)) * (PLLN/PLLM)
 * F(PLLout) =  F(VCO)/PLLP
 * F(PLLout) =  F(PLL(input)) *PLLN)) / (PLLP*PLLM)
 * must be   value between  1 to 84MHZ
  please  be careful  when choose the  (PLLN) & (PLLM) & (PLLP)
   know  the rang  of***
   1- PLLN   from  192UL  to 432UL
   2- PLLM   from  2UL    to 63UL
   3- PLLP   2,4,6,8
 */
#define  RCC_NO_PLLN       192UL
#define  RCC_NO_PLLM       63UL
#define  RCC_NO_PLLP       RCC_PLLP_2
/*
if use USB
The USB OTG FS requires a 48 MHz clock to work correctly.
The SDIO and the
random number generator need a frequency
lower than or equal to 48 MHz to work
correctly.
 4- PLLQ   from 2 to 15
 */
#define  RCC_NO_PLLQ       2

#define  RCC_PLLP_OUTPUT     8000000UL    //to cheek your value
/*
 * if you enable PLL
 * options: RCC_X
 * where X
       HSI        //internal clock default
       HSE        //external clock
 */
#define  RCC_PLL_SOURCE     RCC_HSI


/*OUT PIN MCO1 & MCO2*/
#endif /* MCAL_RCC_RCC_CFG_H_ */
