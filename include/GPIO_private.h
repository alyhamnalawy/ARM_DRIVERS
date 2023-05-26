#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H


typedef struct{
	 volatile u32 MODER;
	 volatile u32 OTYPER;
	 volatile u32 OSPEEDR;
	 volatile u32 PUPDR;
	 volatile u32 IDR;
	 volatile u32 ODR;
	 volatile u32 BSRR;
	 volatile u32 LCKR;
	 volatile u32 AFRL;
	 volatile u32 AFRH;
}GPIO_t;

#define  GPIOA_BASE_ADDRESS      0x40020000
#define  GPIOB_BASE_ADDRESS      0x40020400
#define  GPIOC_BASE_ADDRESS      0x40020800

#define GPIOA    ((GPIO_t *)GPIOA_BASE_ADDRESS)
#define GPIOB    ((GPIO_t *)GPIOB_BASE_ADDRESS)
#define GPIOC    ((GPIO_t *)GPIOC_BASE_ADDRESS)


#endif
