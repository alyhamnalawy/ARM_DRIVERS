#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H


/*PORTS*/
#define GPIOA_PORT	0
#define GPIOB_PORT  1
#define GPIOC_PORT	2

/*PINS*/
#define PIN_0	0
#define PIN_1   1
#define PIN_2   2
#define PIN_3   3
#define PIN_4   4
#define PIN_5   5
#define PIN_6   6
#define PIN_7   7
#define PIN_8   8
#define PIN_9   9
#define PIN_10  10
#define PIN_11  11
#define PIN_12  12
#define PIN_13  13
#define PIN_14  14
#define PIN_15  15

/*MODES*/
#define INPUT      	 				 0
#define OUTPUT     					 1
#define ALTERNATIVE_FUNCTION       	 2
#define ANALOG     	 				 3

/*OUTPUT TYPES*/
#define PUSH_PULL    0
#define OPEN_DRAIN   1

/*SPEED MODES*/
#define SPEED_LOW       0
#define SPEED_MEDUIM    1
#define SPEED_HIGH      2
#define SPEED_VERY_HIGH 3

/*PULLUP/PULLDOWN REGISTER*/
#define INPUT_FLOAT  0
#define PULL_UP      1
#define PULL_DOWN    2
#define RESERVED	 3

/*OUTPUT DATA REGISTER*/
#define HIGH 	1
#define LOW	 	0

/*INPUT DATA REGSTER*/
#define LOW			0
#define HIGH		1

void GPIO_voidSetPinMode(u8 Copy_u8PortName,u16 Copy_u16PinNumber,u8 Copy_u8Mode);
void GPIO_voidSetPinOutputType(u8 Copy_u8PortName,u16 Copy_u16PinNumber,u8 Copy_u8OutputType);
void GPIO_voidSetPinOutputSpeed(u8 Copy_u8PortName,u16 Copy_u16PinNumber,u32 Copy_u8OutSpeed);
void GPIO_voidSetPullType(u8 Copy_u8PortName ,u16 Copy_u16PinNumber ,u8 Copy_u8PullType);
u8 	 GPIO_u8ReadData(u8 Copy_u8PortName,u16 Copy_u16PinNumber);
void GPIO_voidSetPinValue(u8 Copy_u8PortName,u16 Copy_u16PinNumber,u8 Copy_u8State);
void GPIO_voidSetReset(u8 Copy_u8PortName,u16 Copy_u16PinNumber,u8 Copy_u8State);

#endif
