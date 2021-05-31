/***********************************************************************************************************/
/* Auther		: Mohammed Hafez																		   */
/* Date 		: 19 Sep 2020																			   */
/* Version		: 02																					   */
/***********************************************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "GPIO_config.h"
#include "GPIO_private.h"


void MGPIO_voidInit(u8 Copy_u8Port, u8 Copy_u8pinNum, u8 Copy_u8pinMode){
	GPIO_e* GPIOx;
	if(Copy_u8Port == GPIOA_PORT){
		GPIOx = GPIOA;
	}
	else if(Copy_u8Port == GPIOB_PORT){
		GPIOx = GPIOB;
	}
	else{
		GPIOx = GPIOC;
	}

	if(Copy_u8pinNum <= 7){
		GPIOx->CRL |= (Copy_u8pinMode << (Copy_u8pinNum*4));
		GPIOx->CRL &= ~((~Copy_u8pinMode) << (Copy_u8pinNum*4));
	}
	else{
		GPIOx->CRH |= (Copy_u8pinMode << ((Copy_u8pinNum-8)*4));
		GPIOx->CRH &= ~((~Copy_u8pinMode) << ((Copy_u8pinNum-8)*4));
	}
}


u8 MGPIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8pinNum){
	GPIO_e* GPIOx;
	if(Copy_u8Port == GPIOA_PORT){
		GPIOx = GPIOA;
	}
	else if(Copy_u8Port == GPIOB_PORT){
		GPIOx = GPIOB;
	}
	else{
		GPIOx = GPIOC;
	}
	return GET_BIT(GPIOx->IDR,Copy_u8pinNum);
}

u16 MGPIO_u16GetPortValue(u8 Copy_u8Port){
	GPIO_e* GPIOx;
	if(Copy_u8Port == GPIOA_PORT){
		GPIOx = GPIOA;
	}
	else if(Copy_u8Port == GPIOB_PORT){
		GPIOx = GPIOB;
	}
	else{
		GPIOx = GPIOC;
	}
	return GPIOx->IDR;
}

void MGPIO_voidSetPinValue(u8 Copy_u8Port,u8 Copy_u8pinNum, u8 Copy_u8Value){
	GPIO_e* GPIOx;
	if(Copy_u8Port == GPIOA_PORT){
		GPIOx = GPIOA;
	}
	else if(Copy_u8Port == GPIOB_PORT){
		GPIOx = GPIOB;
	}
	else{
		GPIOx = GPIOC;
	}

	if(Copy_u8Value == 1){
		GPIOx->BSRR = (1 << Copy_u8pinNum);	
	}
	else{
		GPIOx->BRR = (1 << Copy_u8pinNum);
	}
	
}

void MGPIO_voidSetPortValue(u8 Copy_u8Port, u16 Copy_u16Value){
	GPIO_e* GPIOx;
	if(Copy_u8Port == GPIOA_PORT){
		GPIOx = GPIOA;
	}
	else if(Copy_u8Port == GPIOB_PORT){
		GPIOx = GPIOB;
	}
	else{
		GPIOx = GPIOC;
	}

	if(Copy_u16Value == 0xFFFF){
		GPIOx->BSRR = Copy_u16Value;
	}
	else{
		GPIOx->ODR = Copy_u16Value;
	}
	
}

void MGPIO_voidClearPort(u8 Copy_u8Port){
	GPIO_e* GPIOx;
	if(Copy_u8Port == GPIOA_PORT){
		GPIOx = GPIOA;
	}
	else if(Copy_u8Port == GPIOB_PORT){
		GPIOx = GPIOB;
	}
	else{
		GPIOx = GPIOC;
	}

	GPIOx->BRR = 0xFFFF;
}
