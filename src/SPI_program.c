/******************************
 * 
 * Name: Aly Ehab.
 * Date: 31, May 2023
 * Version: V1
 * 
 * 
******************************/

#include "../include/STD_TYPES.h"
#include "../include/BIT_MATH.h"

#include "../include/SPI_interface.h"
#include "../include/SPI_private.h"
#include "../include/SPI_config.h"


void MSPI1_voidInit(void)
{
	GPIO_voidSetPinMode(GPIOA_PORT, PIN_7,OUTPUT); // PA7 MOSI
	GPIO_voidSetPinMode(GPIOA_PORT, PIN_5,OUTPUT);  // PA5 SCK

	GPIO_voidSetPinOutputSpeed(MSPI1_MOSI_PORTPIN, SPEED_LOW);
	GPIO_voidSetPinOutputSpeed(MSPI1_SCK_PORTPIN, SPEED_LOW);

	GPIO_voidSetAlternativeFunction(MSPI1_MOSI_PORTPIN, 5);
	GPIO_voidSetAlternativeFunction(MSPI1_SCK_PORTPIN, 5);

	GPIO_voidSetPinMode(GPIOA_PORT, PIN_4,OUTPUT);	// PA4 NSS
	GPIO_voidSetPullType(MSPI1_NSS_PORTPIN, PULL_UP);
	GPIO_voidSetAlternativeFunction(MSPI1_NSS_PORTPIN, 5);

    /*Set The CPHA = 1, Write of the leading edge */
    SPI1 -> CR1 = 0x0347;
}

u8 MSPI_u8TrancieveSynchronous(u8 Copy_u8Data, u8 * Copy_pu8ReceivedData)
{
    u8 Local_u8ReceivedData;
    SPI1 -> DR = Copy_u8Data;
    while(GET_BIT(SPI1 -> SR, 7) == 1);
    Local_u8ReceivedData = SPI1 -> DR;
    return Local_u8ReceivedData;
}
