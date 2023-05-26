/*
 * GPIO_program.c
 *
 *  Created on: May 4, 2023
 *      Author: Ali Ehab
 */


#include "../include/BIT_MATH.h"
#include "../include/STD_TYPES.h"

#include "../include/GPIO_interface.h"
#include "../include/GPIO_private.h"
#include "../include/GPIO_config.h"

/*THIS FUNCTION IS USED TO SET THE MODE OF THE PIN*/
void GPIO_voidSetPinMode(u8 Copy_u8PortName,u16 Copy_u16PinNumber,u8 Copy_u8Mode)
{

	switch(Copy_u8PortName)
	{
	case GPIOA_PORT:
		/*THE TWO IS USED TO SHIFT THE BIT OF PINNUMBER
		BY ONE IN ORDER TO ALLOCATE THE CORRECT POSITION*/
		GPIOA->MODER|=(u32)(Copy_u8Mode<<(2*Copy_u16PinNumber));
		break;
	case GPIOB_PORT:
		GPIOB->MODER|=(u32)(Copy_u8Mode<<(2*Copy_u16PinNumber));
		break;
	case GPIOC_PORT:
		GPIOC->MODER|=(u32)(Copy_u8Mode<<(2*Copy_u16PinNumber));
		break;
	default:
		break;
	}
}
/*THIS FUNCTION IS USED TO SET THE OUTPUT MODE*/
void GPIO_voidSetPinOutputType(u8 Copy_u8PortName,u16 Copy_u16PinNumber,u8 Copy_u8OutputType)
{
	switch(Copy_u8PortName)
	{
	case GPIOA_PORT:
		GPIOA->OTYPER|=(u32)(Copy_u8OutputType<<(Copy_u16PinNumber));
		break;
	case GPIOB_PORT:
		GPIOB->OTYPER|=(u32)(Copy_u8OutputType<<(Copy_u16PinNumber));
		break;
	case GPIOC_PORT:
		GPIOC->OTYPER|=(u32)(Copy_u8OutputType<<(Copy_u16PinNumber));
		break;
	default:
		break;
	}
}
void GPIO_voidSetPinOutputSpeed(u8 Copy_u8PortName,u16 Copy_u16PinNumber,u32 Copy_u8OutSpeed)
{
	switch(Copy_u8PortName)
	{
	case GPIOA_PORT:
		GPIOA->OSPEEDR|=(u32)(Copy_u8OutSpeed<<(2*Copy_u16PinNumber));
		break;
	case GPIOB_PORT:
		GPIOB->OSPEEDR|=(u32)(Copy_u8OutSpeed<<(2*Copy_u16PinNumber));
		break;
	case GPIOC_PORT:
		GPIOC->OSPEEDR|=(u32)(Copy_u8OutSpeed<<(2*Copy_u16PinNumber));
		break;
	default:
		break;
	}
}
/*This Function Is Used To Set The PULL Resistor Connection State*/
void GPIO_voidSetPullType(u8 Copy_u8PortName ,u16 Copy_u16PinNumber,u8 Copy_u8PullType)
{
	switch(Copy_u8PortName)
	{
	case GPIOA_PORT:
		GPIOA->PUPDR|=(u32)(Copy_u8PullType<<(2*Copy_u16PinNumber));
		break;
	case GPIOB_PORT:
		GPIOB->PUPDR|=(u32)(Copy_u8PullType<<(2*Copy_u16PinNumber));
		break;
	case GPIOC_PORT:
		GPIOC->PUPDR|=(u32)(Copy_u8PullType<<(2*Copy_u16PinNumber));
		break;
	default:
		break;
	}
}
/*THIS FUNCTION RETURNS THE STATE IF THE PIN*/
u8 GPIO_u8ReadData(u8 Copy_u8PortName,u16 Copy_u16PinNumber)
{
	u8 Local_u8ReturnData = 0 ;
	switch(Copy_u8PortName)
	{
	case GPIOA_PORT:
		Local_u8ReturnData=GET_BIT(GPIOA->IDR,Copy_u16PinNumber);
		break;
	case GPIOB_PORT:
		Local_u8ReturnData=GET_BIT(GPIOB->IDR,Copy_u16PinNumber);
		break;
	case GPIOC_PORT:
		Local_u8ReturnData=GET_BIT(GPIOC->IDR,Copy_u16PinNumber);
		break;
	default:
		break;
	}
	return Local_u8ReturnData;
}
/*THIS FUNCTION WILL WRITE ON THE PIN*/
void GPIO_voidSetPinValue(u8 Copy_u8PortName,u16 Copy_u16PinNumber,u8 Copy_u8State)
{
	if(Copy_u8State==HIGH)
	{
		switch(Copy_u8PortName)
		{
		case GPIOA_PORT:SET_BIT(GPIOA->ODR,Copy_u16PinNumber); break;
		case GPIOB_PORT:SET_BIT(GPIOB->ODR,Copy_u16PinNumber); break;
		case GPIOC_PORT:SET_BIT(GPIOC->ODR,Copy_u16PinNumber); break;
		}
	}
	else
	{
		switch(Copy_u8PortName)
		{
		case GPIOA_PORT:CLR_BIT(GPIOA->ODR,Copy_u16PinNumber); break;
		case GPIOB_PORT:CLR_BIT(GPIOB->ODR,Copy_u16PinNumber); break;
		case GPIOC_PORT:CLR_BIT(GPIOC->ODR,Copy_u16PinNumber); break;
		}
	}
}
/*USING THE BSRR REGISTER WE WILL SET OR RESET THE PIN*/
void GPIO_voidSetReset(u8 Copy_u8PortName,u16 Copy_u16PinNumber,u8 Copy_u8State)
{
	if(Copy_u8State == HIGH)
	{
		switch (Copy_u8PortName)
		{
		case GPIOA_PORT:GPIOA->BSRR=(1<<Copy_u16PinNumber); break;
		case GPIOB_PORT:GPIOB->BSRR=(1<<Copy_u16PinNumber); break;
		case GPIOC_PORT:GPIOC->BSRR=(1<<Copy_u16PinNumber); break;
		}
	}
	else
	{
		Copy_u16PinNumber += 16;
		switch (Copy_u8PortName)
		{
		case GPIOA_PORT:GPIOA->BSRR=(1<<Copy_u16PinNumber); break;
		case GPIOB_PORT:GPIOB->BSRR=(1<<Copy_u16PinNumber); break;
		case GPIOC_PORT:GPIOC->BSRR=(1<<Copy_u16PinNumber); break;

		}
	}
}

