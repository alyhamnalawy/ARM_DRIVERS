///*
//x * SysTick_main.c
// *
// *  Created on: May 9, 2023
// *      Author: Ali Ehab
// */
//#include "../include/BIT_MATH.h"
//#include "../include/STD_TYPES.h"
//
//#include "../include/RCC_interface.h"
//#include "../include/GPIO_interface.h"
//#include "../include/SysTick_interface.h"
//
//
//void main(void)
//{
//	MRCC_voidinit();
//	MSYSTICK_voidEnable();
//	MRCC_voidEnablePeripherlClock(RCC_AHB1,RCC_GPIOA);
//	GPIO_voidSetPinMode(GPIOA_PORT,PIN_0,OUTPUT);
//	GPIO_voidSetPinOutputSpeed(GPIOA_PORT,PIN_0,SPEED_LOW);
//	GPIO_voidSetPinOutputType(GPIOA_PORT,PIN_0,PUSH_PULL);
//
//	while(1)
//	{
//		GPIO_voidSetPinValue(GPIOA_PORT,PIN_0,LOW);
//		MSYSTICK_voidSetBusyWait(1000);
//		GPIO_voidSetPinValue(GPIOA_PORT,PIN_0,HIGH);
//		MSYSTICK_voidSetBusyWait(1000);
//	}
//}
