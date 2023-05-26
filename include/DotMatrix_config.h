#ifndef DotMatrix_CONFIG_H_
#define DotMatrix_CONFIG_H_

/***************SELECT_ROW_PINS************/
#define ROW_1              GPIO_PIN_0
#define ROW_2              GPIO_PIN_1
#define ROW_3              GPIO_PIN_2
#define ROW_4              GPIO_PIN_3
#define ROW_5              GPIO_PIN_4
#define ROW_6              GPIO_PIN_5
#define ROW_7              GPIO_PIN_6
#define ROW_8              GPIO_PIN_7
/***************SELECT_ROW_PORT_**********/
#define ROW_DATA_PORT                  GPIOB_PORT


/***************SELECT_COL_PINS***********/
#define COL_1              GPIO_PIN_0
#define COL_2              GPIO_PIN_1
#define COL_3              GPIO_PIN_2
#define COL_4              GPIO_PIN_3
#define COL_5              GPIO_PIN_4
#define COL_6              GPIO_PIN_5
#define COL_7              GPIO_PIN_6
#define COL_8              GPIO_PIN_7
/**************SELECT_COL_PORT_***********/
#define COL_DATA_PORT                   GPIOA_PORT

/* Select Operation Mode
*
* 1)  Col_Control
* 2)  Row_Control
*
*/
#define Operation_Mode   Col_Control

#endif /* DotMatrix_CONFIG_H_ */
