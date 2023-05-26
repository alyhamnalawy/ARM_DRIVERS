#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H


/*0x4002 3800*/
//#define RCC_BASE_aADDRESS	0x40023800
//#define RCC_CR *((volatile u32 *)(RCC_BASE_aADDRESS+0x00)) //rcc control register
typedef struct
{
	volatile u32 CR;
	volatile u32 PLLCFGR;
	volatile u32 CFGR;
	volatile u32 CIR;
	volatile u32 AHB1RSTR;
	volatile u32 AHB2RSTR;
	volatile u32 RESERVED1[2];
	volatile u32 APB1RSTR;
	volatile u32 APB2RSTR;
	volatile u32 RESERVED2[2];
	volatile u32 AHB1ENR;
	volatile u32 AHB2ENR;
	volatile u32 RESERVED3[2];
	volatile u32 APB1ENR;
	volatile u32 APB2ENR;
	volatile u32 RESERVED4[2];
	volatile u32 APB1LPENR;
	volatile u32 APB2LPENR;
	volatile u32 RESERVED5[2];
	volatile u32 BDCR;
	volatile u32 CSR;
	volatile u32 RESERVED6[2];
	volatile u32 SSCGR;
	volatile u32 PLLI2SCFGR;
	volatile u32 DCKCFGR;
}RCC_t;
#define RCC ((volatile RCC_t *)0x40023800)

#define system_clock_not_divided	0
#define system_clock_divided_by_2	1
#define system_clock_divided_by_4	2
#define system_clock_divided_by_8	3
#define system_clock_divided_by_16	4
#define system_clock_divided_by_64	5
#define system_clock_divided_by_128	6
#define system_clock_divided_by_256	7
#define system_clock_divided_by_512	8

#define AHB_clock_not_divided	0
#define AHB_clock_divided_by_2	1
#define AHB_clock_divided_by_4	2
#define AHB_clock_divided_by_8	3
#define AHB_clock_divided_by_16	4





#endif
