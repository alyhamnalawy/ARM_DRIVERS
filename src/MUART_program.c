/*
 * MUART_program.c
 *
 *  Created on: Jun 6, 2023
 *      Author: Ali Ehab
 */

#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/MUART_Interface.h"
#include "../include/MUART_Private.h"
#include "../include/MUART_Config.h"


void MUART_voidInit(void)
{
#if (UART1_USED == U_ENABLE)
	UART1_REG->BRR = UART1_BUAD_RATE;
	UART1_REG->CR2 |= (UART1_STOP_BITS << 12);
	UART1_REG->CR1.SBK = UART1_SEND_BREAK;
	UART1_REG->CR1.RE = UART1_RECEIVER;
	UART1_REG->CR1.TE = UART1_TRANSMITTER;
	UART1_REG->CR1.RXNEIE = UART1_RX_INT;
	UART1_REG->CR1.TCIE = UART1_T_COMP_INT;
	UART1_REG->CR1.PCE = UART1_PARITY_ENABLE;
	UART1_REG->CR1.PS = UART1_PARITY_MODE;
	UART1_REG->CR1.M = UART1_WORD_LEN;
	UART1_REG->CR1.OVER8	= UART1_OVER_SAMPLING;

#endif
}

void MUART_voidEnable(void)
{
	UART1_REG -> CR1.UE = 1;
}

void MUART_voidDisable(void)
{
	 UART1_REG -> CR1.UE = 0;
}


void MUART_u8SendData(u8* copy_u8Data, u8 copy_u8Len)
{

	UART_REG uhandler = MUART_GetHandler();
	for(u8 counter = 0; counter < copy_u8Len; counter++){
		uhandler ->DR = copy_u8Data[counter];
		while(!GET_BIT(uhandler->SR, 6));
	}

}


u8 MUART_u8ReadData(void)
{
	UART_REG uhandler = MUART_GetHandler();
	return (u8) uhandler->DR;
}


UART_REG MUART_GetHandler(void)
{
	UART_REG Local_UARTREGhandle= (UART_REG) UART1_BASE_ADRESS;
	Local_UARTREGhandle =  (UART_REG) UART1_BASE_ADRESS;
	return Local_UARTREGhandle;
}
