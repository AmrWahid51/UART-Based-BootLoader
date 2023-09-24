#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"


#include "MCAL/RCC/RCC_int.h"
#include "MCAL/UART/UART_int.h"
#include "MCAL/SYSTICK/SYSTICK_int.h"
#include "MCAL/GPIO/GPIO_int.h"
#include "MCAL/FMI/FMI_int.h"
#include "APP/HEXPARSER/HEXPARSER_int.h"

/*vector table offset found in SCB it must take the 1st 4 bytes of the required address*/
#define SCB_VTOR     *((volatile u32*) (0xE000ED00 +0x08))
u8 Flag = 1; // used to enter BootLoader only once

typedef void (*APP_Call) (void);
APP_Call APP;

/*The APP function used to call the app that we are flashing used the bootloader*/

void APP_vTest(void)
{
	MSTK_vStopTimer();
//	MGPIO_vSetPinValue(GPIO_PORTA,GPIO_PIN0,HIGH); //used for testing
	Flag = 0;
	SCB_VTOR = 0x08004000;
	APP = *(APP_Call*)(0x08004004); //startupCode for app
	APP();// APP
}

/**/
void main(void)
{
	/*RCC Init*/
	MRCC_vInit();
	MRCC_vEnableClock(RCC_AHB1,RCC_EN_GPIOA);
	MRCC_vEnableClock(RCC_APB1,RCC_EN_UART2);
	MRCC_vEnableClock(RCC_AHB1LP,RCC_EN_FLITFPLEN);
//	/*Test Pin Init*/
//	/////////////////////////////////////////////////////////
//	MGPIO_vSetPinMode(GPIO_PORTA,GPIO_PIN0,GPIO_MODE_OUTPUT);
//	MGPIO_vPinOutputType(GPIO_PORTA,GPIO_PIN0,GPIO_OUTPUTTYPE_PUSHPULL);
//	MGPIO_vSetPinOutputSpeed(GPIO_PORTA,GPIO_PIN0,GPIO_OUTPUT_SPEED_LOW);
	/*UART Pins Init */
	/////////////////////////////////////////////////////////////
	MGPIO_vSetPinMode(GPIO_PORTA,GPIO_PIN2,GPIO_MODE_ALT);
	MGPIO_vPinOutputType(GPIO_PORTA,GPIO_PIN2,GPIO_OUTPUTTYPE_PUSHPULL);
	MGPIO_vSetPinOutputSpeed(GPIO_PORTA,GPIO_PIN2,GPIO_OUTPUT_SPEED_LOW);
	MGPIO_vSetAlternativeFunction(GPIO_PORTA,GPIO_PIN2,GPIO_AF7);
	//////////////////////////////////////////////////////////
	MGPIO_vSetPinMode(GPIO_PORTA,GPIO_PIN3,GPIO_MODE_ALT);
	MGPIO_vPinOutputType(GPIO_PORTA,GPIO_PIN3,GPIO_OUTPUTTYPE_PUSHPULL);
	MGPIO_vSetPinOutputSpeed(GPIO_PORTA,GPIO_PIN3,GPIO_OUTPUT_SPEED_LOW);
	MGPIO_vSetAlternativeFunction(GPIO_PORTA,GPIO_PIN3,GPIO_AF7);
	///////////////////////////////////////////////////////////
	/*UART Init*/
	USART_InitType x = {9600,USART_MODE_8BIT,USART_STOP_BIT_1,DISABLE,DISABLE,USART_TX_RX,USART_OVER_SAMPLING_8};
	MUSART_vInit(&x,USART2);
	MSUART_Enable(USART2);
	//////////////////////////////////////////
	/*SysTick Timer*/
	MSTK_vInit();
	MSTK_vSetInterval_Periodic(15000000,APP_vTest);//if no hexfile was sent for 15seconds will go to the app directly
	///////////////////////////////////////////////
	u8 ReceiveBuffer[100];//empty array to receive the HexCode and sent it to the flash
	u8 L_u8RecStatus; //status flag (1) if the uart received data
	u8 i = 0;
	u8 eraseFlag = 1; // flag used to erase the flash only 1 time after reset
	////////////////////////////////////////////////////
	while(Flag)
	{
		/*BootLoader Code*/

		L_u8RecStatus = MUSART_u8ReceiveByteAsynch_(USART2,&ReceiveBuffer[i]);
		//ReceiveBuffer[i] = MUSART_u8ReceiveByteSynchBlocking(USART2); //another way to receive data
		if(L_u8RecStatus)
		{
			MSTK_vStopTimer(); //stop the timer for in interrupt till finishing the transferring process
			if(ReceiveBuffer[i] == '\0')
			{
				if(eraseFlag)
				{
					eraseFlag = 0;
					MFMI_vEraseAppArea(); // function called to erase sectors of the flash for the hex file
				}
				HEXPARSER_vParseData(ReceiveBuffer);//sending HEX Record to the flash
				MSUART_vTransmitByteSynch(USART2,'K'); // ack
				i = 0; //i = 0 to begin to fill the array again from the begining
			}
			else
			{
				i++;
			}
			if(ReceiveBuffer[7] == '0' && ReceiveBuffer[8] == '1' && ReceiveBuffer[11] == '\0' ) // indication of eof and end of last record
			{

				APP_vTest(); //at the end of the sent hex file call the app function
			}


		}
	}
}
