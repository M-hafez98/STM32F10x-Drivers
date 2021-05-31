/***********************************************************************************************************/
/* Auther		: Mohammed Hafez																		   */
/* Date 		: 28 Aug 2020																			   */
/* Version		: 01																					   */
/***********************************************************************************************************/

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"


void MNVIC_voidEnableInterrupt(u8 Copy_u8IntNum){
	if(Copy_u8IntNum <= 31){
		NVIC_ISER0 = (1<<Copy_u8IntNum);
	}
	else if(Copy_u8IntNum <= 63){
		NVIC_ISER1 = (1<<(Copy_u8IntNum-32));
	}
	else{
		error("not valid input");
	}
}

void MNVIC_voidDisableInterrupt(u8 Copy_u8IntNum){
	if(Copy_u8IntNum <= 31){
		NVIC_ICER0 = (1<<Copy_u8IntNum);
	}
	else if(Copy_u8IntNum <= 63){
		NVIC_ICER1 = (1<<(Copy_u8IntNum-32));
	}
	else{
		error("not valid input");
	}
}

void MNVIC_voidSetPendingFlag(u8 Copy_u8IntNum){
	if(Copy_u8IntNum <= 31){
		NVIC_ISPR0 = (1<<Copy_u8IntNum);
	}
	else if(Copy_u8IntNum <= 63){
		NVIC_ISPR1 = (1<<(Copy_u8IntNum-32));
	}
	else{
		error("not valid input");
	}
}

void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNum){
	if(Copy_u8IntNum <= 31){
		NVIC_ICPR0 = (1<<Copy_u8IntNum);
	}
	else if(Copy_u8IntNum <= 63){
		NVIC_ICPR1 = (1<<(Copy_u8IntNum-32));
	}
	else{
		error("not valid input");
	}
}

u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNum){
	if(Copy_u8IntNum <= 31){
		return GET_BIT(NVIC_IABR0, Copy_u8IntNum);
	}
	else if(Copy_u8IntNum <= 63){
		return GET_BIT(NVIC_IABR1, Copy_u8IntNum-32);
	}
	else{
		error("not valid input");
	}
}