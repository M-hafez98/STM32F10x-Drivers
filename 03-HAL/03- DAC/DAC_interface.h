/***********************************************************************************************************/
/* Auther		: Mohammed Hafez																		   */
/* Date 		: 8 Sep 2020																			   */
/* Version		: 01																					   */
/***********************************************************************************************************/


#ifndef DAC_INTERFACE_H
#define DAC_INTERFACE_H

void HDAC_voidInit(GPIO_e* GPIOx, u8 * Ref_pins, void(*STKCallback)(void));
void HDAC_voidSetDACOutput(void);




#endif