/*
 * HLEDMatrix_program.c
 *
 *  Created on: Jun 2, 2023
 *      Author: Ali Ehab
 */
#include "../include/BIT_MATH.h"
#include "../include/STD_TYPES.h"
#include "../include/GPIO_INTERFACE.h"
#include "../include/RCC_INTERFACE.h"


#include "../include/HLEDMatrix_INTERFACE.h"
#include "../include/HLEDMatrix_PRIVATE.h"
#include "../include/HLEDMatrix_CONFIG.h"


void HLedMatrix_voidInit (void)
{
	GPIO_voidSetPinMode(GPIOA_PORT,LED_MATRIX_ROW0_PIN, OUTPUT);
    GPIO_voidSetPinMode(GPIOA_PORT,LED_MATRIX_ROW1_PIN, OUTPUT);
    GPIO_voidSetPinMode(GPIOA_PORT,LED_MATRIX_ROW2_PIN, OUTPUT);
    GPIO_voidSetPinMode(GPIOA_PORT,LED_MATRIX_ROW3_PIN, OUTPUT);
    GPIO_voidSetPinMode(GPIOA_PORT,LED_MATRIX_ROW4_PIN, OUTPUT);
    GPIO_voidSetPinMode(GPIOA_PORT,LED_MATRIX_ROW5_PIN, OUTPUT);
    GPIO_voidSetPinMode(GPIOA_PORT,LED_MATRIX_ROW6_PIN, OUTPUT);
    GPIO_voidSetPinMode(GPIOA_PORT,LED_MATRIX_ROW7_PIN, OUTPUT);


    GPIO_voidSetPinMode(GPIOB_PORT,LED_MATRIX_COL0_PIN, OUTPUT);
    GPIO_voidSetPinMode(GPIOB_PORT,LED_MATRIX_COL1_PIN, OUTPUT);
    GPIO_voidSetPinMode(GPIOB_PORT,LED_MATRIX_COL2_PIN, OUTPUT);
    GPIO_voidSetPinMode(GPIOB_PORT,LED_MATRIX_COL3_PIN, OUTPUT);
    GPIO_voidSetPinMode(GPIOB_PORT,LED_MATRIX_COL4_PIN, OUTPUT);
    GPIO_voidSetPinMode(GPIOB_PORT,LED_MATRIX_COL5_PIN, OUTPUT);
    GPIO_voidSetPinMode(GPIOB_PORT,LED_MATRIX_COL6_PIN, OUTPUT);
    GPIO_voidSetPinMode(GPIOB_PORT,LED_MATRIX_COL7_PIN, OUTPUT);


    GPIO_voidSetPinOutputType(GPIOA_PORT,LED_MATRIX_ROW0_PIN, PULL_UP);
    GPIO_voidSetPinOutputType(GPIOA_PORT,LED_MATRIX_ROW1_PIN, PULL_UP);
    GPIO_voidSetPinOutputType(GPIOA_PORT,LED_MATRIX_ROW2_PIN, PULL_UP);
    GPIO_voidSetPinOutputType(GPIOA_PORT,LED_MATRIX_ROW3_PIN, PULL_UP);
    GPIO_voidSetPinOutputType(GPIOA_PORT,LED_MATRIX_ROW4_PIN, PULL_UP);
    GPIO_voidSetPinOutputType(GPIOA_PORT,LED_MATRIX_ROW5_PIN, PULL_UP);
    GPIO_voidSetPinOutputType(GPIOA_PORT,LED_MATRIX_ROW6_PIN, PULL_UP);
    GPIO_voidSetPinOutputType(GPIOA_PORT,LED_MATRIX_ROW7_PIN, PULL_UP);


    GPIO_voidSetPinOutputType(GPIOB_PORT,LED_MATRIX_COL0_PIN, PULL_UP);
    GPIO_voidSetPinOutputType(GPIOB_PORT,LED_MATRIX_COL1_PIN, PULL_UP);
    GPIO_voidSetPinOutputType(GPIOB_PORT,LED_MATRIX_COL2_PIN, PULL_UP);
    GPIO_voidSetPinOutputType(GPIOB_PORT,LED_MATRIX_COL3_PIN, PULL_UP);
    GPIO_voidSetPinOutputType(GPIOB_PORT,LED_MATRIX_COL4_PIN, PULL_UP);
    GPIO_voidSetPinOutputType(GPIOB_PORT,LED_MATRIX_COL5_PIN, PULL_UP);
    GPIO_voidSetPinOutputType(GPIOB_PORT,LED_MATRIX_COL6_PIN, PULL_UP);
    GPIO_voidSetPinOutputType(GPIOB_PORT,LED_MATRIX_COL7_PIN, PULL_UP);

    GPIO_voidSetPinOutputSpeed(GPIOA_PORT,LED_MATRIX_ROW0_PIN,SPEED_LOW);
    GPIO_voidSetPinOutputSpeed(GPIOA_PORT,LED_MATRIX_ROW1_PIN,SPEED_LOW);
    GPIO_voidSetPinOutputSpeed(GPIOA_PORT,LED_MATRIX_ROW2_PIN,SPEED_LOW);
    GPIO_voidSetPinOutputSpeed(GPIOA_PORT,LED_MATRIX_ROW3_PIN,SPEED_LOW);
    GPIO_voidSetPinOutputSpeed(GPIOA_PORT,LED_MATRIX_ROW4_PIN,SPEED_LOW);
    GPIO_voidSetPinOutputSpeed(GPIOA_PORT,LED_MATRIX_ROW5_PIN,SPEED_LOW);
    GPIO_voidSetPinOutputSpeed(GPIOA_PORT,LED_MATRIX_ROW6_PIN,SPEED_LOW);
    GPIO_voidSetPinOutputSpeed(GPIOA_PORT,LED_MATRIX_ROW7_PIN,SPEED_LOW);

    GPIO_voidSetPinOutputSpeed(GPIOB_PORT,LED_MATRIX_COL0_PIN,SPEED_LOW);
    GPIO_voidSetPinOutputSpeed(GPIOB_PORT,LED_MATRIX_COL1_PIN,SPEED_LOW);
    GPIO_voidSetPinOutputSpeed(GPIOB_PORT,LED_MATRIX_COL2_PIN,SPEED_LOW);
    GPIO_voidSetPinOutputSpeed(GPIOB_PORT,LED_MATRIX_COL3_PIN,SPEED_LOW);
    GPIO_voidSetPinOutputSpeed(GPIOB_PORT,LED_MATRIX_COL4_PIN,SPEED_LOW);
    GPIO_voidSetPinOutputSpeed(GPIOB_PORT,LED_MATRIX_COL5_PIN,SPEED_LOW);
    GPIO_voidSetPinOutputSpeed(GPIOB_PORT,LED_MATRIX_COL6_PIN,SPEED_LOW);
    GPIO_voidSetPinOutputSpeed(GPIOB_PORT,LED_MATRIX_COL7_PIN,SPEED_LOW);
}

void HLedMatrix_voidDisplay (u8 Copy_u8Data , u8 Copy_u8ActivePortNumber , u8 Copy_u8ActivePinNumber)
{
   u8 Local_u8Data ;
    /*deactivate all cols*/

    GPIO_voidSetPinValue(GPIOB_PORT,LED_MATRIX_COL0_PIN, HIGH);
    GPIO_voidSetPinValue(GPIOB_PORT,LED_MATRIX_COL1_PIN, HIGH );
    GPIO_voidSetPinValue(GPIOB_PORT,LED_MATRIX_COL2_PIN, HIGH);
    GPIO_voidSetPinValue(GPIOB_PORT,LED_MATRIX_COL3_PIN, HIGH);
    GPIO_voidSetPinValue(GPIOB_PORT,LED_MATRIX_COL4_PIN, HIGH);
    GPIO_voidSetPinValue(GPIOB_PORT,LED_MATRIX_COL5_PIN, HIGH);
    GPIO_voidSetPinValue(GPIOB_PORT,LED_MATRIX_COL6_PIN, HIGH);
    GPIO_voidSetPinValue(GPIOB_PORT,LED_MATRIX_COL7_PIN, HIGH);


   /*write data on rows*/
  Local_u8Data = GET_BIT(Copy_u8Data ,0);
  GPIO_voidSetPinValue (GPIOA_PORT,LED_MATRIX_ROW0_PIN,Local_u8Data);
  Local_u8Data = GET_BIT(Copy_u8Data ,1);
  GPIO_voidSetPinValue (GPIOA_PORT,LED_MATRIX_ROW1_PIN,Local_u8Data);
  Local_u8Data = GET_BIT(Copy_u8Data ,2);
  GPIO_voidSetPinValue (GPIOA_PORT,LED_MATRIX_ROW2_PIN,Local_u8Data);
  Local_u8Data = GET_BIT(Copy_u8Data ,3);
  GPIO_voidSetPinValue (GPIOA_PORT,LED_MATRIX_ROW3_PIN,Local_u8Data);
  Local_u8Data = GET_BIT(Copy_u8Data ,4);
  GPIO_voidSetPinValue (GPIOA_PORT,LED_MATRIX_ROW4_PIN,Local_u8Data);
  Local_u8Data = GET_BIT(Copy_u8Data ,5);
  GPIO_voidSetPinValue (GPIOA_PORT,LED_MATRIX_ROW5_PIN,Local_u8Data);
  Local_u8Data = GET_BIT(Copy_u8Data ,6);
  GPIO_voidSetPinValue (GPIOA_PORT,LED_MATRIX_ROW6_PIN,Local_u8Data);
  Local_u8Data = GET_BIT(Copy_u8Data ,7);
  GPIO_voidSetPinValue (GPIOA_PORT,LED_MATRIX_ROW7_PIN,Local_u8Data);

  GPIO_voidSetPinValue (Copy_u8ActivePortNumber , Copy_u8ActivePinNumber , LOW);
  MSYSTICK_voidSetBusyWait(2500);

}
