# UART-Based-BootLoader
Sending an Application Hex Code Through UART and Flashing it on the Flash Memory by the Bootloader
# Used Hardware:
* STM32F401CC Microcontroller
* LEDS
* Virtual Terminal
# Project on Proteus:
![image](https://github.com/AmrWahid51/UART-Based-BootLoader/assets/145209640/c5befeb3-696a-44eb-879d-91b1f85dd2ab)
# Drivers Used:
1st Microcontroller:
 * RCC
 * GPIO
 * UART
   
2nd Microcontroller:
 * RCC
 * GPIO
 * UART
 * SYSTICK
 * FLASH
 * HEXAPARSER
 * BOOTLOADER APP

# HEX Code Description:
It is simply a code which toggle a Led on pin1 PortA
