/*
 * SSD_program.c
 *
 *  Created on: May 12, 2023
 *      Author: Ali Ehab
 */
#include "../include/BIT_MATH.h"
#include "../include/STD_TYPES.h"
#include "../include/GPIO_interface.h"

#include "../include/SSD_interface.h"
#include "../include/SSD_private.h"
#include "../include/SSD_config.h"


void HSsd_VoidInit(void)
{
	u8 Local_u8Iterator;
	for (Local_u8Iterator=0;Local_u8Iterator<=6;Local_u8Iterator++)
	{
		GPIO_voidSetPinMode(SSD_DATA_PORT,Local_u8Iterator,OUTPUT);
		GPIO_voidSetPinOutputType(SSD_DATA_PORT,Local_u8Iterator,PUSH_PULL);
		GPIO_voidSetPinOutputSpeed(SSD_DATA_PORT,Local_u8Iterator,SPEED_LOW);
		GPIO_voidSetPullType(SSD_DATA_PORT,Local_u8Iterator,PULL_UP);
		GPIO_voidSetPinValue(SSD_DATA_PORT,Local_u8Iterator,LOW);
	}
}
void HSsd_VoidDisplay(u8 Copy_u8Data)
{
	u8 Local_u8Iterator;
	switch(Copy_u8Data)
	{
	case 0 :

		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_A,HIGH);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_B,HIGH);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_C,HIGH);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_D,HIGH);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_E,HIGH);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_F,HIGH);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_G,LOW);
		break;
	case 1 :
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_A,LOW);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_B,HIGH);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_C,HIGH);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_D,LOW);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_E,LOW);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_F,LOW);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_G,LOW);
		break;
	case 2 :
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_A,HIGH);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_B,HIGH);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_C,LOW);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_D,HIGH);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_E,HIGH);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_F,LOW);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_G,HIGH);
		break;
	case 3 :
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_A,HIGH);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_B,HIGH);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_C,HIGH);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_D,HIGH);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_E,LOW);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_F,LOW);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_G,HIGH);
		break;
	case 4 :
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_A,LOW);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_B,HIGH);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_C,HIGH);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_D,LOW);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_E,LOW);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_F,HIGH);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_G,HIGH);
		break;
	case 5 :
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_A,HIGH);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_B,LOW);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_C,HIGH);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_D,HIGH);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_E,LOW);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_F,HIGH);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_G,HIGH);
		break;
	case 6 :
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_A,HIGH);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_B,LOW);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_C,HIGH);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_D,HIGH);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_E,HIGH);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_F,HIGH);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_G,HIGH);
		break;
	case 7 :
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_A,HIGH);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_B,HIGH);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_C,HIGH);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_D,LOW);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_E,LOW);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_F,HIGH);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_G,LOW);
		break;
	case 8 :
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_A,HIGH);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_B,HIGH);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_C,HIGH);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_D,HIGH);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_E,HIGH);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_F,HIGH);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_G,HIGH);
		break;
	case 9 :
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_A,HIGH);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_B,HIGH);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_C,HIGH);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_D,HIGH);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_E,LOW);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_F,HIGH);
		GPIO_voidSetPinValue(SSD_DATA_PORT,SSD_LED_G,HIGH);
		break;
	default:
		for (Local_u8Iterator=0;Local_u8Iterator<=6;Local_u8Iterator++)
		{
			GPIO_voidSetPinValue(SSD_DATA_PORT,Local_u8Iterator,LOW);
		}
		break;
	}
}


