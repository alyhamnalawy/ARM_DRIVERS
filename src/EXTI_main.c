///*
// * EXTI_main.c
// *
// *  Created on: May 22, 2023
// *      Author: Ali Ehab
// */
//
//#include "../include/STD_TYPES.h"
//#include "../include/BIT_MATH.h"
//
//#include "../include/RCC_interface.h"
//#include "../include/GPIO_interface.h"
//#include "../include/NVIC_interface.h"
//
//#include "../include/EXTI_interface.h"
//#include "../include/EXTI_private.h"
//#include "../include/EXTI_config.h"
//
//void Toggle_LED(void);
//void main(void)
//{
//	MRCC_voidinit();
//	MRCC_voidEnablePeripherlClock(RCC_AHB1,GPIOA_PORT);
//	GPIO_voidSetPinMode(GPIOA_PORT,PIN_0,INPUT);
//	GPIO_voidSetPullType(GPIOA_PORT,PIN_0,PULL_UP);
//	MNVIC_voidInit();
//	MNVIC_voidEnablePeripheralInterrupt(MNVIC_EXTI0);
//	MEXTI_voidChangeSenseMode(MEXTI_LINE0,MEXTI_FALLING_EDGE);
//	MEXTI_voidSetCallBack(MEXTI_LINE0,&Toggle_LED);
//	MEXTI_voidEnableInterrupt(MEXTI_LINE0);
//
//
//	while(1);
//}
//
//void Toggle_LED(void)
//{
//	asm ("NOP");
//}
