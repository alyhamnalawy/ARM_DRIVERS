///*
// * IR.c
// *
// *  Created on: May 26, 2023
// *      Author: Ali Ehab
// */
//
//
//
//
//#include "../include/STD_TYPES.h"
//#include "../include/BIT_MATH.h"
//
//#include "../include/RCC_interface.h"
//#include "../include/GPIO_interface.h"
//#include "../include/SysTick_interface.h"
//#include "../include/NVIC_interface.h"
//#include "../include/EXTI_interface.h"
//
//void APP_GetFrame(void);
//void APP_TakeAction(void);
//void APP_voidPlay(void);
//
//
//u8  APP_u8StartEdgeFlag = 0;
//u32 APP_u32ReceivedFrame[50] = {0};
//u8  APP_u8EdgeCounter = 0;
//u8 App_u8ButtonData = 0;
//
//void main(void)
//{
//	MRCC_voidinit();
//	MRCC_voidEnablePeripherlClock(RCC_AHB1, RCC_GPIOA);
//
//	/*Set The A0 Pin To Be Input (EXTI0)*/
//	GPIO_voidSetPinMode(GPIOA_PORT, PIN_0, INPUT);
//	/*Set The A0 Pin To Be Pullup Up*/
//	GPIO_voidSetPullType(GPIOA_PORT, PIN_0, PULL_UP);
//
//	/*Initialize STK*/
//	MSYSTICK_voidInit();
//
//	/*Setup EXTI Line 0*/
//	MEXTI_voidinit();
//	MEXTI_voidChangeSenseMode(MEXTI_LINE0, MEXTI_FALLING_EDGE);
//	MEXTI_voidSetCallBack(MEXTI_LINE0, &APP_GetFrame);
//	MEXTI_voidEnableInterrupt(MEXTI_LINE0);
//
//	/*Initialize NVIC*/
//	MNVIC_voidInit();
//	/*Enable EXTI Peripheral In NVIC*/
//	MNVIC_voidEnablePeripheralInterrupt(MNVIC_EXTI0);
//	while(1)
//	{
//		APP_voidPlay();
//	}
//}
//
//void APP_GetFrame(void)
//{
//	if(APP_u8StartEdgeFlag == 0)
//	{
//		MSYSTICK_voidSetSingleInterval(1000000, &APP_TakeAction);
//		APP_u8StartEdgeFlag = 1;
//	}
//	else
//	{
//		/*Get the counted time*/
//		APP_u32ReceivedFrame[APP_u8EdgeCounter] = MSYSTICK_voidGetElapsedTime();
//		/*Reset The Timer, Set PreLoad Value*/
//		MSYSTICK_voidSetSingleInterval(1000000, &APP_TakeAction);
//		/*Increment Edge Counter*/
//		APP_u8EdgeCounter++;
//	}
//}
//void APP_TakeAction(void)
//{
//	u8 Local_u8LoopCounter = 0;
//	for(Local_u8LoopCounter = 0; Local_u8LoopCounter < 8; Local_u8LoopCounter++)
//	{
//		if((APP_u32ReceivedFrame[17+Local_u8LoopCounter] >= 1000) &&
//				(APP_u32ReceivedFrame[17+Local_u8LoopCounter] <= 1500))
//		{
//			CLR_BIT(App_u8ButtonData, Local_u8LoopCounter);
//		}
//		else
//		{
//			SET_BIT(App_u8ButtonData, Local_u8LoopCounter);
//		}
//	}
//	APP_u8StartEdgeFlag = 0;
//	APP_u8EdgeCounter = 0;
//}
//
//void APP_voidPlay(void)
//{
//	switch(App_u8ButtonData)
//	{
//	case 24:
//		asm("NOP");
//		break;
//	case 69:
//		asm("NOP");
//		break;
//	}
//}
