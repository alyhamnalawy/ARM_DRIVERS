#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H



#define MEXTI_RISING_EDGE  0
#define MEXTI_FALLING_EDGE 1
#define MEXTI_ON_CHANGE    2


#define MEXTI_LINE0			0


/***************APIS****************/
void MEXTI_voidinit(void);
void MEXTI_voidEnableInterrupt(u8 Copy_u8EXTILine);
void MEXTI_voidDisableInterrupt(u8 Copy_u8EXTILine);
void MEXTI_voidChangeSenseMode(u8 Copy_u8EXTILine,u8 Copy_u8SenseSignal);
void MEXTI_voidSetCallBack(u8 Copy_u8EXTILine,void (*PVNotificationfunction)(void));


#endif
