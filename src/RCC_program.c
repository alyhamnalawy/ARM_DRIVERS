/*
 * RCC_program.c
 *
 *  Created on: May 1, 2023
 *      Author: Ali Ehab
 */

#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/RCC_interface.h"
#include "../include/RCC_private.h"
#include "../include/RCC_config.h"

void MRCC_voidinit(void)
{
#if CPU_CLK_SOURCE==HSI
	/*ENABLE HSI*/
	SET_BIT(RCC->CR,0);
	/*SELCT HSI AS CPU CLOCK*/
	CLR_BIT(RCC->CFGR,0);
	CLR_BIT(RCC->CFGR,1);
#elif CPU_CLK_SOURCE==HSE
	/*ENABLE HSE*/
	SET_BIT(RCC->CR,16);
	/*SELCT HSE AS CPU CLOCK*/
	SET_BIT(RCC->CFGR,0);
	CLR_BIT(RCC->CFGR,1);
#elif CPU_CLK_SOURCE==PLL
#if PLL_SOURCE==HSI
	/*ENABLE HSI*/
	SET_BIT(RCC->CR,0);
	/*SELECT HSI AS PLL CLOCK*/
	CLR_BIT(RCC->PLLCFGR,22);
	/*ENABLE PLL*/
	SET_BIT(RCC->CR,24);
	/*SELCT PLL AS CPU CLOCK*/
	CLR_BIT(RCC->CFGR,0);
	SET_BIT(RCC->CFGR,1);

#elif PLL_SOURCE==HSE
	/*ENABLE HSE*/
	SET_BIT(RCC->CR,16);
	/*SELECT HSE AS PLL CLOCK*/
	SET_BIT(RCC->PLLCFGR,22);
	/*ENABLE PLL*/
	SET_BIT(RCC->CR,24);
	/*SELCT PLL AS CPU CLOCK*/
	CLR_BIT(RCC->CFGR,0);
	SET_BIT(RCC->CFGR,1);
#else
#error("CPU CPU_CLK_SOURCE CONFIG ERROR")
#endif
#else
#error("CPU CPU_CLK_SOURCE CONFIG ERROR")
#endif
#if AHB_CLOCK_SELCT == system_clock_divided_by_2
	SET_BIT(RCC->CFGR,7);
	CLR_BIT(RCC->CFGR,6);
	CLR_BIT(RCC->CFGR,5);
	CLR_BIT(RCC->CFGR,4);
#elif AHB_CLOCK_SELCT==system_clock_divided_by_4
	SET_BIT(RCC->CFGR,7);
	CLR_BIT(RCC->CFGR,6);
	CLR_BIT(RCC->CFGR,5);
	SET_BIT(RCC->CFGR,4);
#elif AHB_CLOCK_SELCT==system_clock_divided_by_8
	SET_BIT(RCC->CFGR,7);
	CLR_BIT(RCC->CFGR,6);
	SET_BIT(RCC->CFGR,5);
	CLR_BIT(RCC->CFGR,4);
#endif
#if APB1_CLOCK_SELECT==AHB_clock_divided_by_2
	SET_BIT(RCC->CFGR,12);
	CLR_BIT(RCC->CFGR,11);
	CLR_BIT(RCC->CFGR,10);
#elif APB1_CLOCK_SELECT==AHB_clock_divided_by_4
	SET_BIT(RCC->CFGR,12);
	CLR_BIT(RCC->CFGR,11);
	SET_BIT(RCC->CFGR,10);
#elif APB1_CLOCK_SELECT==AHB_clock_divided_by_8
	SET_BIT(RCC->CFGR,12);
	SET_BIT(RCC->CFGR,11);
	CLR_BIT(RCC->CFGR,10);
#endif
}


void MRCC_voidEnablePeripherlClock(u8 Copy_u8PeripheralBus,u8 Copy_u8PeripheralID)
{
	switch(Copy_u8PeripheralBus)
	{
	case RCC_AHB1:
		SET_BIT(RCC->AHB1ENR,Copy_u8PeripheralID);
		break;
	case RCC_AHB2:
		SET_BIT(RCC->AHB2ENR,Copy_u8PeripheralID);
		break;
	case RCC_APB1:
		SET_BIT(RCC->APB1ENR,Copy_u8PeripheralID);
		break;
	case RCC_APB2:
		SET_BIT(RCC->APB1ENR,Copy_u8PeripheralID);
		break;
	default:
		break;
	}
}
void MRCC_voidDisablePeripherlClock(u8 Copy_u8PeripheralBus,u8 Copy_u8PeripheralID)
{
	switch(Copy_u8PeripheralBus)
	{
	case RCC_AHB1:
		CLR_BIT(RCC->AHB1ENR,Copy_u8PeripheralID);
		break;
	case RCC_AHB2:
		CLR_BIT(RCC->AHB2ENR,Copy_u8PeripheralID);
		break;
	case RCC_APB1:
		CLR_BIT(RCC->APB1ENR,Copy_u8PeripheralID);
		break;
	case RCC_APB2:
		CLR_BIT(RCC->APB1ENR,Copy_u8PeripheralID);
		break;
	default:
		break;
	}
}





