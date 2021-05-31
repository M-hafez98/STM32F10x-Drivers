/***********************************************************************************************************/
/* Auther		: Mohammed Hafez																		   */
/* Date 		: 4 Sep 2020																			   */
/* Version		: 01																					   */
/***********************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXTI_config.h"
#include "EXTI_private.h"
#include "EXTI_interface.h"


/*global static variables for EXTI driver only*/
static void (*SetEXTICallBack) (void);
static u8 Global_u8EXTILine;

void MEXTI_voidEXTIInit(u8 Copy_u8EXTILine, u8 Copy_u8EXTISenseMode, void (*EXTI_CallBackPtr) (void)){
	Global_u8EXTILine = Copy_u8EXTILine;
	if(Copy_u8EXTILine <= 18){
		SET_BIT(EXTI->IMR, Copy_u8EXTILine);
	}
	else{
		//#error();
	}
	switch(Copy_u8EXTISenseMode){
		case EXTI_RISING_EDGE_TRIGGER 		 : SET_BIT(EXTI->RTSR,Copy_u8EXTILine); break;
		case EXTI_FALLING_EDGE_TRIGGER 		 : SET_BIT(EXTI->FTSR,Copy_u8EXTILine); break;
		case EXTI_RISING_FALLING_EDGE_TRIGGER: SET_BIT(EXTI->RTSR,Copy_u8EXTILine);
											   SET_BIT(EXTI->FTSR,Copy_u8EXTILine); break;
		default: CLR_BIT(EXTI->IMR, Copy_u8EXTILine);
	}
	SetEXTICallBack = EXTI_CallBackPtr;
}
void MEXTI_voidEnableEXTILine(u8 Copy_u8EXTILine){
	if(Copy_u8EXTILine <= 18){
		SET_BIT(EXTI->IMR, Copy_u8EXTILine);
	}
	else{
		//#error();
	}
}
void MEXTI_voidDisableEXTILine(u8 Copy_u8EXTILine){
	if(Copy_u8EXTILine <= 18){
		CLR_BIT(EXTI->IMR, Copy_u8EXTILine);
	}
	else{
		//#error();
	}
}
void MEXTI_voidSetTriggerEdge(u8 Copy_u8EXTISenseMode){
	switch(Copy_u8EXTISenseMode){
		case EXTI_RISING_EDGE_TRIGGER 		 : SET_BIT(EXTI->RTSR,Global_u8EXTILine); break;
		case EXTI_FALLING_EDGE_TRIGGER 		 : SET_BIT(EXTI->FTSR,Global_u8EXTILine); break;
		case EXTI_RISING_FALLING_EDGE_TRIGGER: SET_BIT(EXTI->RTSR,Global_u8EXTILine);
											   SET_BIT(EXTI->FTSR,Global_u8EXTILine); break;
		default: CLR_BIT(EXTI->IMR, Global_u8EXTILine);
	}
}

void MEXTI_voidClearPendingFlag(u8 Copy_u8EXTILine){
	if(Copy_u8EXTILine <= 18){
		CLR_BIT(EXTI->PR, Copy_u8EXTILine);
	}
	else{
		//#error();
	}
}

void EXTI0_IRQHandler(void){
	/*Clear Pending Flag*/
	CLR_BIT(EXTI->PR, Global_u8EXTILine);
	/*go to call back function*/
	SetEXTICallBack();
}
