


#include "../include/BIT_MATH.h"
#include "../include/STD_TYPES.h"

#include "SYSTICK_interface.h"
#include "SYSTICK_config.h"
#include "SYSTICK_private.h"

static void (*pvCallBackFunction)(void) = NULL;
static u8 PERIODIC_INTERVAL;
static u8 SINGLE_INTERVAL;
static u8 Global_u8IntervalFlag;

void MSYSTICK_voidInit(void)
{
    /* Select systick clock source */
    #if     SYSTICK_CLOCK_SOURCE == AHB_DEVIDED_BY_8
        CLR_BIT((SYSTICK->CTRL), CTRL_CLKSOURCE);
    #elif   SYSTICK_CLOCK_SOURCE == AHB_DEVIDED_BY_1
        SET_BIT((SYSTICK->CTRL), CTRL_CLKSOURCE);
    #else
        #error "SYSTICK SYSTICK_CLOCK_SOURCE, Configuration Error"
    #endif

    /* Enable/Disable systick Interrupt */
    #if     SYSTICK_INTERRUPT == ENABLE_INTERRUPT
        SET_BIT((SYSTICK->CTRL), CTRL_TICKINT);
    #elif   SYSTICK_INTERRUPT == DISABLE_INTERRUPT
        CLR_BIT((SYSTICK->CTRL), CTRL_TICKINT);
    #else
        #error "SYSTICK SYSTICK_INTERRUPT, Configuration Error"
    #endif

    /* Enable/Disable systick */
    #if     SYSTICK_ENABLE == ENABLE
        SET_BIT((SYSTICK->CTRL), CTRL_ENABLE);
    #elif   SYSTICK_ENABLE == DISABLE
        CLR_BIT((SYSTICK->CTRL), CTRL_ENABLE);
    #else
        #error "SYSTICK SYSTICK_ENABLE, Configuration Error"
    #endif
}

void MSYSTICK_voidInterruptEnable(void)
{
    SET_BIT((SYSTICK->CTRL), CTRL_TICKINT);
}

void MSYSTICK_voidInterruptDisable(void)
{
    CLR_BIT((SYSTICK->CTRL), CTRL_TICKINT);
}

void MSYSTICK_voidEnable(void)
{
    SET_BIT((SYSTICK->CTRL), CTRL_ENABLE);
}

void MSYSTICK_voidDisable(void)
{
    CLR_BIT((SYSTICK->CTRL), CTRL_ENABLE);
}

u32 MSYSTICK_voidGetElapsedTime(void)
{
    u32 Local_u32ElapsedTime;
    Local_u32ElapsedTime = (SYSTICK->LOAD) - (SYSTICK->VAL);
    return Local_u32ElapsedTime;
}

u32 MSYSTICK_voidGetRemainingTime(void)
{
    u32 Local_u32RemainingTime;
    Local_u32RemainingTime = (SYSTICK->VAL);
    return Local_u32RemainingTime;
}

void MSYSTICK_voidSetBusyWait(u32 Copy_u32TicksWaiting)
{
    (SYSTICK->LOAD) =  (Copy_u32TicksWaiting);
    while(GET_BIT((SYSTICK->CTRL), CTRL_COUNTFLAG) == 0);
    (SYSTICK->VAL) = 0;
}

void MSYSTICK_voidResetSystick(void)
{
    (SYSTICK->VAL) = 0;
}
void MSYSTICK_voidSetSingleInterval(u32 Copy_u32Ticks, void (*NotificationFunction)(void))
{
	CLR_BIT(SYSTICK -> CTRL, 0);
	SYSTICK -> VAL = 0;
	SYSTICK -> LOAD = Copy_u32Ticks;
	pvCallBackFunction = NotificationFunction;
	Global_u8IntervalFlag = SINGLE_INTERVAL;
	SET_BIT(SYSTICK -> CTRL, 1);
	SET_BIT(SYSTICK -> CTRL, 0);
}
void MSYSTICK_voidSetPeriodicInterval(u32 Copy_u32Ticks, void (*NotificationFunction)(void))
{

	SYSTICK -> LOAD = Copy_u32Ticks;

	pvCallBackFunction = NotificationFunction;
	Global_u8IntervalFlag = PERIODIC_INTERVAL;
	SET_BIT(SYSTICK -> CTRL, 1);
	SET_BIT(SYSTICK -> CTRL, 0);
}
void MSysTick_Handler(void)
{
	u32 Local_u32TempVar;
	if(Global_u8IntervalFlag == SINGLE_INTERVAL)
	{
		SYSTICK->LOAD = 0;
		SYSTICK->VAL = 0;
		CLR_BIT(SYSTICK->CTRL, 0);
	}
	if(pvCallBackFunction != NULL)
	{
		pvCallBackFunction();
	}
	Local_u32TempVar = GET_BIT(SYSTICK->CTRL, 16);
}
