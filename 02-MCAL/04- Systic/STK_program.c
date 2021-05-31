/***********************************************************************************************************/
/* Auther		: Mohammed Hafez																		   */
/* Date 		: 26 Aug 2020																			   */
/* Version		: 01																					   */
/***********************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h" /*need to know the system clock*/
#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"

/* global variables for STK driver only */
static void (*CallBackSTKFunc) (void);
static u8 u8TimerMode;
//u32 systemClock;



void MSTK_voidInit(void){
	/* Set STK Clock Source */
	#if STK_CLK_SOURCE == PROCESSOR_CLK
		SET_BIT(STK_CTRL, 2);
	#elif STK_CLK_SOURCE == PROCESSOR_CLK_DIV_BY_8
		CLR_BIT(STK_CTRL, 2);
	#else
		#error("Not Valid Clock Source");
	#endif
	/* Disable STK */
	CLR_BIT(STK_CTRL, 0);
	/* Disable STK Interrupt */
	CLR_BIT(STK_CTRL, 1);
	/* Clear the count Flag */
	STK_VAL = 0;
}

void MSTK_voidSetBusyWait(u32 Copy_u32Ticks){
	if(Copy_u32Ticks <= 0x00FFFFFF){
		STK_LOAD = Copy_u32Ticks;
	}
	else{
		//#error("The ticks value is larger than 0x00FFFFFF");
	}
	/* Enable STK */
	SET_BIT(STK_CTRL, 0);
	while(!(STK_CTRL & (1<<16)));
	/* Disable STK */
	CLR_BIT(STK_CTRL, 0);
	/* Clear the count Flag */
	STK_VAL = 0;
}

void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (*ptr) (void)){
	if(Copy_u32Ticks <= 0xFFFFFF){
		STK_LOAD = Copy_u32Ticks;
	}
	else{
		//#error("The ticks value is larger than 0x00FFFFFF");
	}
	CallBackSTKFunc = ptr;
	/* Set STK Mode */
	u8TimerMode = STK_SINGLE_MODE;
	/* Enable Interrupt */
	SET_BIT(STK_CTRL, 1);
	/* Enable STK */
	SET_BIT(STK_CTRL, 0);
}

void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*ptr) (void)){
	if(Copy_u32Ticks <= 0xFFFFFF){
		STK_LOAD = Copy_u32Ticks-1;
	}
	else{
		//#error("The ticks value is larger than 0x00FFFFFF");
	}
	CallBackSTKFunc = ptr;
	/* Set STK Mode */
	u8TimerMode = STK_PERIODIC_MODE;
	/* Enable Interrupt */
	SET_BIT(STK_CTRL, 1);
	/* Enable STK */
	SET_BIT(STK_CTRL, 0);
}

void MSTK_voidStopSTK(void){
	/* Disable STK */
	CLR_BIT(STK_CTRL, 0);
	CLR_BIT(STK_CTRL, 1);
}

u32  MSTK_u32GetElapsedTime(void){
	//systemClock = MRCC_u32GetSysClk(); /*this func to be implemented in RCC driver*/
	#if STK_CLK_SOURCE == PROCESSOR_CLK
		return (STK_LOAD - STK_VAL);
	#else
		return (STK_LOAD - STK_VAL);
	#endif
}

u32  MSTK_u32GetRemainedTime(void){
	//systemClock = MRCC_u32GetSysClk(); /*this func to be implemented in RCC driver*/
	#if STK_CLK_SOURCE == PROCESSOR_CLK
		return STK_VAL;
	#else
		return STK_VAL;
	#endif
}

/* STK Interrupt Handeler */
void SysTick_Handler(void){
	if(u8TimerMode == STK_SINGLE_MODE){
		MSTK_voidStopSTK();
	}
	/* Clear the count Flag */
	STK_VAL = 0;
	CallBackSTKFunc();
}
