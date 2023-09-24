#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

#include "HEXFile.h" // the .h file containing an array with the HEX file

#include "MCAL/RCC/RCC_int.h"
#include "MCAL/GPIO/GPIO_int.h"
#include "MCAL/UART/UART_int.h"
#include "MCAL/SYSTICK/SYSTICK_int.h"


void main(void)
{
	/*RCC Init*/
	MRCC_vInit();
	MRCC_vEnableClock(RCC_AHB1,RCC_EN_GPIOA);
	MRCC_vEnableClock(RCC_APB1,RCC_EN_UART2);
	/*Test Pin Init*/
	////////////////////////////////////////////////////
	MGPIO_vSetPinMode(GPIO_PORTA,GPIO_PIN0,GPIO_MODE_OUTPUT);
	MGPIO_vPinOutputType(GPIO_PORTA,GPIO_PIN0,GPIO_OUTPUTTYPE_PUSHPULL);
	MGPIO_vSetPinOutputSpeed(GPIO_PORTA,GPIO_PIN0,GPIO_OUTPUT_SPEED_LOW);
	/*PINS Init for UART*/
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
	//////////////////////////////////////////////////////
	u8 i = 0,j = 0,Flag = 1;
	while(Flag)
	{
		/*For loop to loop on every record of the HEX file*/
		for(i = 0 ; i<NO_RECORDS ; i++)
		{
			/*While Loop to loop on every byte of each record till the null*/
			while(HEX_arr [i][j] != '\0')
			{

				MSUART_vTransmitByteSynch(USART2,HEX_arr [i][j]); //transmitting every byte of each record
				j++;
			}

			MGPIO_vTogglePinValue(GPIO_PORTA,GPIO_PIN0); // used to test that the Hex file is being sent through the UART Successfully
			MSUART_vTransmitByteSynch(USART2,'\0'); // sending the null at the end of each record
			j = 0;
			while(MUSART_u8ReceiveByteSynchBlocking(USART2) != 'K'); // waiting for the ack from UC2 to send the next record
		}
		Flag = 0; // down flag to 0 to exit project upon sending the HEX file
	}
}
