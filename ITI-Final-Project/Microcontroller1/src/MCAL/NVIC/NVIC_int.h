/*
 * NVIC_int.h
 *
 *  Created on: Aug 14, 2023
 *      Author: dabou
 */

#ifndef MCAL_NVIC_NVIC_INT_H_
#define MCAL_NVIC_NVIC_INT_H_

/*used to enable interrupt*/
void MNVIC_vEnableInterruptPeripheral(u8 A_u8IntId );

/*used to disable interrupt*/
void MNVIC_vDisableInterruptPeripheral(u8 A_u8IntId );

/*used for testing sw interrupt*/
void MNVIC_vSetPending(u8 A_u8IntId );

/**/
void MNVIC_vClearPending(u8 A_u8IntId );

/*to check*/
u8 MNVIC_u8GetActive(u8 A_u8IntId );

/**/
void MNVIC_vSetPriorityCfg(u8 A_u8Group);

/**/
void MNVIC_vSetPriority(s8 A_s8IntId , u8 A_u8GroupPriority,u8 A_u8SubPriority);

/**/
#define NVIC_SYSTICK                 -5
#define NVIC_PendSV                  -6

#define NVIC_SVCALL                  -4

#define NVIC_USAGE_FAULT             -1
#define NVIC_BUS_FAULT               -2
#define NVIC_MEM_MANAGE_FAULT        -3


/*to assign number of groups and subpriorities*/
#define PRIORITY_16GROUP           0b011  //3
#define PRIORITY_8GROUP            0b100  //4
#define PRIORITY_4GROUP            0b101  //5
#define PRIORITY_2GROUP            0b110  //6
#define PRIORITY_1GROUP            0b111  //7

/*The Vector Table*/
#define NVIC_WWDG                		         	   0
#define NVIC_EXTI16               	           		   1
#define NVIC_EXTI21                  	   		       2
#define NVIC_EXTI22                    		 		   3
#define NVIC_FLASH                  				   4
#define NVIC_RCC                   					   5
#define NVIC_EXTI0                     				   6
#define NVIC_EXTI1                    				   7
#define NVIC_EXTI2                      	 		   8
#define NVIC_EXTI3                      		 	   9
#define NVIC_EXTI4                		 		      10
#define NVIC_DMA1_Stream0         		              11
#define NVIC_DMA1_Stream1           		          12
#define NVIC_DMA1_Stream2         		              13
#define NVIC_DMA1_Stream3           		          14
#define NVIC_DMA1_Stream4          		              15
#define NVIC_DMA1_Stream5          		              16
#define NVIC_DMA1_Stream6               		      17
#define NVIC_ADC                  		   		      18
#define NVIC_EXTI9_5                      			  23
#define NVIC_TIM1_BRK_TIM9         		    	      24
#define NVIC_TIM1_UP_TIM10               		      25
#define NVIC_TIM1_TRG_COM_TIM11                       26
#define NVIC_TIM1_CC          		      		      27
#define NVIC_TIM2                  					  28
#define NVIC_TIM3                   				  29
#define NVIC_TIM4                  			  		  30
#define NVIC_I2C1_EV                   				  31
#define NVIC_I2C1_ER                   		  		  32
#define NVIC_I2C2_EV                       			  33
#define NVIC_I2C2_ER                    	 		  34
#define NVIC_SPI_1                    				  35
#define NVIC_SPI_2                  				  36
#define NVIC_USART_1                    	 		  37
#define NVIC_USART_2                   		 		  38





#endif /* MCAL_NVIC_NVIC_INT_H_ */
