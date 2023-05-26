#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H


typedef struct{
	u32 volatile IMR;
	u32 volatile EMR;
	u32 volatile RTSR;
	u32 volatile FTSR;
	u32 volatile SWIER;
	u32 volatile PR;
}EXTI_t;

#define MEXTI 		((volatile EXTI_t*)0x40013C00)
#define SYSCFG_CRI  *(volatile u32(0x40013808))

#endif
