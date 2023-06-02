/*******************************************************************
* AUTHOR  : Aly Ehab
* DATE	  : 25 May , 2023
* SWC 	  : LED MATRIX
* MC 	  : STM32F401X
* LAYER   : HAL
* VERSION : V1.0
********************************************************************/
#ifndef HLEDMATRIC_INTERFACE_H
#define HLEDMATRIC_INTERFACE_H

void HLedMatrix_voidInit(void);
void HLedMatrix_voidDisplay (u8 Copy_u8Data,u8 Copy_u8ActivePortNumber,u8 Copy_u8ActivePinNumber);

#endif
