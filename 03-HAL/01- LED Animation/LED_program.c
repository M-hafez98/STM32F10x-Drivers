/***********************************************************************************************************/
/* Auther		: Mohammed Hafez																		   */
/* Date 		: 4 Sep 2020																			   */
/* Version		: 01																					   */
/***********************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "RCC_interface.h"
#include "LED_interface.h"

void HLED_voidLEDArrayInit(GPIO_e* GPIOx, u8* Ref_u8Pins, u8 Copy_u8PinsSize, u8 Copy_u8PinConfig){
	u8 i;
	switch(GPIOx){
		case GPIOA: RCC_voidEnableClock(RCC_APB2, GPIOA_ID) break;
		case GPIOB: RCC_voidEnableClock(RCC_APB2, GPIOB_ID) break;
		case GPIOC: RCC_voidEnableClock(RCC_APB2, GPIOC_ID) break;
		default   : #error();
	}
	for(i=0;i<Copy_u8PinsSize;i++){
		MGPIO_voidInit(GPIOx, Ref_u8Pins[i], Copy_u8PinConfig);
	}
}
void HLED_voidStartLEDAnimation(GPIO_e* GPIOx, u8* Ref_u8Pins, u8 Copy_u8PinsSize, u32 Copy_u32FlashTime){
	static u8 i;
	for(i=0;i<Copy_u8PinsSize;i++){
		MGPIO_voidSetPinValue(GPIOx,Ref_u8Pins[i],1);
		MSTK_voidSetBusyWait(Copy_u32FlashTime);
		MGPIO_voidSetPinValue(GPIOx,Ref_u8Pins[i],0);
	}
	i-=1;
	while(i != 0){
		i--;
		MGPIO_voidSetPinValue(GPIOx,Ref_u8Pins[i],1);
		MSTK_voidSetBusyWait(Copy_u32FlashTime);
		MGPIO_voidSetPinValue(GPIOx,Ref_u8Pins[i],0);
	}
}