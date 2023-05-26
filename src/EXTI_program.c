/*
 * EXTI_program.c
 *
 *  Created on: May 22, 2023
 *      Author: Ali Ehab
 */

#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/EXTI_interface.h"
#include "../include/EXTI_private.h"
#include "../include/EXTI_config.h"

static void (*pvCallBack[16])(void)={{NULL}};

void MEXTI_voidinit(void)
{

}
void MEXTI_voidEnableInterrupt(u8 Copy_u8EXTILine)
{
	if(Copy_u8EXTILine<=15)
	{
		SET_BIT(MEXTI->IMR,Copy_u8EXTILine);
	}
	else
	{
		//DO NOTHING
	}

}
void MEXTI_voidDisableInterrupt(u8 Copy_u8EXTILine)
{
	if(Copy_u8EXTILine<=15)
	{
		CLR_BIT(MEXTI->IMR,Copy_u8EXTILine);
	}
	else
	{
		//DO NOTHING
	}

}

void MEXTI_voidChangeSenseMode(u8 Copy_u8EXTILine,u8 Copy_u8SenseSignal)
{
	switch(Copy_u8SenseSignal)
	{
	case MEXTI_RISING_EDGE:
		CLR_BIT(MEXTI-> FTSR, Copy_u8EXTILine);
		SET_BIT(MEXTI-> RTSR, Copy_u8EXTILine);
		break;
	case MEXTI_FALLING_EDGE:
		CLR_BIT(MEXTI-> RTSR, Copy_u8EXTILine);
		SET_BIT(MEXTI-> FTSR, Copy_u8EXTILine);
		break;
	case MEXTI_ON_CHANGE:
		SET_BIT(MEXTI-> RTSR, Copy_u8EXTILine);
		SET_BIT(MEXTI-> FTSR, Copy_u8EXTILine);
		break;
	}
}
void MEXTI_voidSetCallBack(u8 Copy_u8EXTILine,void (*PVNotificationfunction)(void))
{
	if(Copy_u8EXTILine>15)
	{
		return;
	}
	else
	{
		pvCallBack[Copy_u8EXTILine]=PVNotificationfunction;
	}

}

void EXT0_IRQHandler(void)
{
	if(pvCallBack[0]!=NULL)
	{
		pvCallBack[0]();
	}
	SET_BIT(MEXTI->PR,0);
}
