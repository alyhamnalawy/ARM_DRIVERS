#ifndef SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H


void MSYSTICK_voidInit(void);
void MSYSTICK_voidInterruptEnable(void);
void MSYSTICK_voidInterruptDisable(void);
void MSYSTICK_voidEnable(void);
void MSYSTICK_voidDisable(void);
u32 MSYSTICK_voidGetElapsedTime(void);
u32 MSYSTICK_voidGetRemainingTime(void);
void MSYSTICK_voidSetBusyWait(u32 Copy_u32TicksWaiting);
void MSYSTICK_voidResetSystick(void);
void MSYSTICK_voidSetSingleInterval(u32 Copy_u32Ticks, void (*NotificationFunction)(void));
void MSYSTICK_voidSetPeriodicInterval(u32 Copy_u32Ticks, void (*NotificationFunction)(void));






#endif
