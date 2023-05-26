/*
 * DotMatrix_program.c
 *
 *  Created on: May 10, 2023
 *      Author: Ali Ehab
 */

#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"
#include "../include/GPIO_interface.h"
#include "../include/SysTick_interface.h"
#include "../include/DotMatrix_interface.h"
#include "../include/DotMatrix_private.h"
#include "../include/DotMatrix_config.h"



void HDotMatrix_voidInit(void)
{
	u8 i;
	MSYSTICK_voidEnable();
	for (i=0;i<=7;i++)
	{
		GPIO_voidSetPinMode(COL_DATA_PORT,i,OUTPUT);
		GPIO_voidSetPinOutputType(COL_DATA_PORT,i,PUSH_PULL);
		GPIO_voidSetPinOutputSpeed(COL_DATA_PORT,i,SPEED_LOW);
		GPIO_voidSetPullType(COL_DATA_PORT,i,PULL_UP);
		GPIO_voidSetPinValue(COL_DATA_PORT,i,HIGH);
	}
	for (i=0;i<=7;i++)
	{
		GPIO_voidSetPinMode(ROW_DATA_PORT,i,OUTPUT);
		GPIO_voidSetPinOutputType(ROW_DATA_PORT,i,PUSH_PULL);
		GPIO_voidSetPinOutputSpeed(ROW_DATA_PORT,i,SPEED_LOW);
		GPIO_voidSetPullType(ROW_DATA_PORT,i,PULL_UP);
	}

}
void HDotMatrix_voidDisplay(u8*Copy_pu8Data)
{
	u8 Local_u8RowIterator=0,Local_u8ColumnIterator;
	while (Copy_pu8Data[Local_u8RowIterator]!='\n')
	{
		for (Local_u8ColumnIterator=0;Local_u8ColumnIterator<=7;Local_u8ColumnIterator++)
		{
			GPIO_voidSetPinValue(COL_DATA_PORT, Local_u8ColumnIterator, LOW);
			GPIO_voidSetPinValue(COL_DATA_PORT, Local_u8ColumnIterator, HIGH);
		}
		GPIO_voidSetPinValue(COL_DATA_PORT,Local_u8ColumnIterator,LOW);
		MSYSTICK_voidSetBusyWait(2500);//2.5ms
		Local_u8RowIterator++;
	}
}





