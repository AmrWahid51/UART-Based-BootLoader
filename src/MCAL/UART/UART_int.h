/*
 * UART_int.h
 *
 *  Created on: Sep 10, 2023
 *      Author: dabou
 */

#ifndef MCAL_UART_UART_INT_H_
#define MCAL_UART_UART_INT_H_


#define USART1_BASE_ADDRESS      (0x40011000)
#define USART6_BASE_ADDRESS      (0x40011400)
#define USART2_BASE_ADDRESS      (0x40004400)

typedef struct{
	u32 SR;
	u32 DR;
	u32 BRR;
	u32 CR1;
	u32 CR2;
	u32 CR3;
	u32 GTPR;

}USART_MemMap_t;

#define USART1   (( USART_MemMap_t*) (USART1_BASE_ADDRESS))
#define USART2   (( USART_MemMap_t*) (USART2_BASE_ADDRESS))
#define USART6   (( USART_MemMap_t*) (USART6_BASE_ADDRESS))

/*
 * Struct made to pass to the Init Function.
 * */
typedef struct{

	u32 BaudRate;
	u8 DataWidth;
	u8 StopBits;
	u8 Parity_Enable;
	u8 Parity_Selection;
	u8 TransferDirection;
	u8 OverSampling;

}USART_InitType;

/*
 * Defines
 * */
#define USART_OVER_SAMPLING_16    0
#define USART_OVER_SAMPLING_8     1

#define USART_TX_ONLY             0
#define USART_RX_ONLY             1
#define USART_TX_RX               2

#define USART_EVEN_PARITY         0
#define USART_ODD_PARITY          1

#define USART_MODE_8BIT		      0
#define USART_MODE_9BIT		      1

#define USART_STOP_BIT_1	      0
#define USART_STOP_BIT_0_5	      1
#define USART_STOP_BIT_2	      2
#define USART_STOP_BIT_1_5	      3

#define ENABLE	    1
#define DISABLE  	0

void MUSART_vInit(USART_InitType *A_InitStruct,USART_MemMap_t *USARTx);
void MSUART_Enable(USART_MemMap_t *USARTx);
void MSUART_Disable(USART_MemMap_t *USARTx);

u8 MSUART_u8TransmitByteAsynch(USART_MemMap_t *USARTx,u8 A_u8Byte);
void MSUART_vTransmitByteSynch(USART_MemMap_t *USARTx,u8 A_u8Byte);

void MSUART_vTransmitString(USART_MemMap_t *USARTx,u8 *A_ptru8String);


u8 MUSART_u8ReceiveByteSynchNonBlocking(USART_MemMap_t *USARTx);
void MUSART_ptrReceiveStringSynchNonBlocking(USART_MemMap_t *USARTx ,char A_u8str[] ,u32 A_u32Size );
u8 MUSART_u8ReceiveByteSynchBlocking(USART_MemMap_t *USARTx );
u8 MUSART_u8ReceiveByteAsynch_(USART_MemMap_t *USARTx, u8 *ptr);

void MUSART_RxIntSetStatus(USART_MemMap_t *USARTx, u8 A_u8Status);
void MUSART_voidClearFlags(USART_MemMap_t *USARTx);
u8 MUSART_u8ReadDataRegister(USART_MemMap_t *USARTx);

void MUSART1_vSetCallBack(void (*ptr) (void) );
void MUSART2_vSetCallBack(void (*ptr) (void) );
void MUSART6_vSetCallBack(void (*ptr) (void) );



#endif /* MCAL_UART_UART_INT_H_ */
