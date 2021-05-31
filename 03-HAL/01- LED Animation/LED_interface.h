/***********************************************************************************************************/
/* Auther		: Mohammed Hafez																		   */
/* Date 		: 4 Sep 2020																			   */
/* Version		: 01																					   */
/***********************************************************************************************************/

##ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

void HLED_voidLEDArrayInit(GPIO_e* GPIOx, u8* Ref_u8Pins, u8 Copy_u8PinsSize, u8 Copy_u8PinConfig);
void HLED_voidStartLEDAnimation(GPIO_e* GPIOx, u8* Ref_u8Pins, u8 Copy_u8PinsSize, u32 Copy_u32FlashTime);







#endif