#ifndef SYSTICK_PRIVATE_H
#define SYSTICK_PRIVATE_H





#define AHB_DEVIDED_BY_8    0
#define AHB_DEVIDED_BY_1    1

#define ENABLE_INTERRUPT	1
#define DISABLE_INTERRUPT	0

#define ENABLE				1
#define DISABLE				0


typedef struct
{
	volatile u32 CTRL;
	volatile u32 LOAD;
	volatile u32 VAL;
	volatile u32 CALIB;
}SYSTICK_t;

#define SYSTICK    ((volatile SYSTICK_t*)0xE000E010)


#define CTRL_ENABLE          0
#define CTRL_TICKINT         1
#define CTRL_CLKSOURCE       2
#define CTRL_COUNTFLAG       16







#endif
