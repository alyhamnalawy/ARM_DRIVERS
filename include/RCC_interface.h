#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H


#define RCC_AHB1 0
#define RCC_AHB2 1
#define RCC_APB1 2
#define RCC_APB2 3

#define RCC_GPIOA 0
#define RCC_GPIOB 1
#define RCC_GPIOC 2

#define AHB1RSTR_GPIOARST        0
#define AHB1RSTR_GPIOBRST        1
#define AHB1RSTR_GPIOCRST        2
#define AHB1RSTR_GPIODRST        3
#define AHB1RSTR_GPIOERST        4
#define AHB1RSTR_GPIOHRST        7

#define AHB1ENR_GPIOAEN         0
#define AHB1ENR_GPIOBEN         1
#define AHB1ENR_GPIOCEN         2
#define AHB1ENR_GPIODEN         3
#define AHB1ENR_GPIOEEN         4
#define AHB1ENR_GPIOHEN         7

#define AHB1LPENR_GPIOALPEN     0
#define AHB1LPENR_GPIOBLPEN     1
#define AHB1LPENR_GPIOCLPEN     2
#define AHB1LPENR_GPIODLPEN     3
#define AHB1LPENR_GPIOELPEN     4
#define AHB1LPENR_GPIOHLPEN     7

void MRCC_voidinit(void);

void MRCC_voidEnablePeripherlClock(u8 Copy_u8PeripheralBus,u8 Copy_u8PeripheralID);

void MRCC_voidDisablePeripherlClock(u8 Copy_u8PeripheralBus,u8 Copy_u8PeripheralID);


#endif
