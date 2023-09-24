/*
 * SYSTICK_prv.h
 *
 *  Created on: Aug 17, 2023
 *      Author: dabou
 */

#ifndef MCAL_SYSTICK_SYSTICK_PRV_H_
#define MCAL_SYSTICK_SYSTICK_PRV_H_

#define STK_BASE_ADDR         0xE000E010

typedef struct
{
	volatile u32 CTRL;
	volatile u32 LOAD;
	volatile u32 VAL;
	volatile u32 CALIB;

}STK_MemoryMap_t;

#define STK  ((volatile STK_MemoryMap_t*) (STK_BASE_ADDR))

#define COUNTFLAG             16
#define CLKSOURCE             2
#define TICKINT               1
#define STK_ENABLE            0

#define STK_AHB           1
#define STK_AHB_PR_8      2

#define ENABLE            1
#define DISABLE           0

#define SINGLE    0
#define PERIODC   1






#endif /* MCAL_SYSTICK_SYSTICK_PRV_H_ */
