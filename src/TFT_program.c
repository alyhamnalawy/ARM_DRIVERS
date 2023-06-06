/*
 * TFT_program.c
 *
 *  Created on: Jun 4, 2023
 *      Author: Ali Ehab
 */
#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/GPIO_interface.h"
#include "../include/SysTick_interface.h"
#include "../include/SPI_interface.h"

#include "../include/TFT_interface.h"
#include "../include/TFT_private.h"
#include "../include/TFT_config.h"

void HTFT_voidInit(void)
{
    GPIO_voidSetPinMode(HTFT_A0_PORT_PIN, OUTPUT); // PA0 A0
    GPIO_voidSetPinMode(HTFT_CS_PORT_PIN, OUTPUT); // PA1 CS
    GPIO_voidSetPinMode(HTFT_RST_PORT_PIN, OUTPUT); // PA1 CS

    GPIO_voidSetPinSpeed(HTFT_A0_PORT_PIN, SPEED_LOW);
	GPIO_voidSetPinSpeed(HTFT_CS_PORT_PIN, SPEED_LOW);
	GPIO_voidSetPinSpeed(HTFT_RST_PORT_PIN, SPEED_LOW);

    /*Hardware Reseting*/
    GPIO_voidSetPinValue(HTFT_RST_PORT_PIN, HIGH);
    MSTK_voidSetBusyWait(100);
    GPIO_voidSetPinValue(HTFT_RST_PORT_PIN, LOW);
    MSTK_voidSetBusyWait(1);
    GPIO_voidSetPinValue(HTFT_RST_PORT_PIN, HIGH);
    MSTK_voidSetBusyWait(100);
    GPIO_voidSetPinValue(HTFT_RST_PORT_PIN, LOW);
    MSTK_voidSetBusyWait(100);
    GPIO_voidSetPinValue(HTFT_RST_PORT_PIN, HIGH);
    MSTK_voidSetBusyWait(120000);

    HTFT_voidSendCommand(SLPOUT_CMD);
    MSTK_voidSetBusyWait(150000);
    HTFT_voidSendCommand(COLMOD_CMD);
    HTFT_voidSendData(0x05);
    HTFT_voidSendCommand(DISPON_CMD);

}

static void HTFT_voidSendCommand(u8 Copy_u8Command)
{
    u8 Local_u8Dummy;
    GPIO_voidSetPinValue(HTFT_A0_PORT_PIN, LOW);
    MSPI_u8TrancieveSynchronous(Copy_u8Command, &Local_u8Dummy);
}


static void HTFT_voidSendData(u8 Copy_u8Data)
{
    u8 Local_u8Dummy;
    GPIO_voidSetPinValue(HTFT_A0_PORT_PIN, HIGH);
    MSPI_u8TrancieveSynchronous(Copy_u8Data, &Local_u8Dummy);
}

void HTFT_voidDisplayImage(u16 * Copy_pu16Image)
{
    /*Send Set X - Y Coordinates */
	HTFT_voidSetWindow(0, 127, 0, 159);
    /*Send Write RAM Command*/
    HTFT_voidSendCommand(0x2C);
    u16 Local_u16LoopCounter;
    u8 Local_u8Data = 0;
    for(Local_u16LoopCounter=0;Local_u16LoopCounter<=20480;Local_u16LoopCounter++)
    {
    	Local_u8Data=Copy_pu16Image[Local_u16LoopCounter]>>8;
    	HTFT_voidSendData(Local_u8Data);
    	Local_u8Data=(u8)Copy_pu16Image[Local_u16LoopCounter];
    	HTFT_voidSendData(Local_u8Data);

    }
}

void HTFT_voidSetWindow(u8 Copy_u8X0, u8 Copy_u8X1, u8 Copy_u8Y0, u8 Copy_u8Y1)
{
    /*Send Set X Address Command*/
    HTFT_voidSendCommand(0x2A);
    HTFT_voidSendData(0);
    HTFT_voidSendData(Copy_u8X0);
    HTFT_voidSendData(0);
    HTFT_voidSendData(Copy_u8X1);
    /*Send Set Y Address Command*/
    HTFT_voidSendCommand(0x2B);
    HTFT_voidSendData(0);
    HTFT_voidSendData(Copy_u8Y0);
    HTFT_voidSendData(0);
    HTFT_voidSendData(Copy_u8Y1);
}

