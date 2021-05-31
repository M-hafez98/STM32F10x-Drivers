/***********************************************************************************************************/
/* Auther		: Mohammed Hafez																		   */
/* Date 		: 19 Sep 2020																			   */
/* Version		: 01																					   */
/***********************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STP_interface.h"

void HSTP_voidSendDataOutput(u8 Copy_u8Data){
	u8 u8DataBit;
	s8 s8BitPos;
	for(s8BitPos = 7;s8BitPos >= 0;s8BitPos--){
		u8DataBit = GET_BIT(Copy_u8Data,s8Counter);
		
		MGPIO_voidSetPinValue(HSTP_SERIAL_PIN,u8DataBit);
		
		MGPIO_voidSetPinValue(HSTP_SHIFT_CLOCK_PIN,1);
		MSTK_voidSetBusyWait(HSTP_CLOCK_TIME);
		MGPIO_voidSetPinValue(HSTP_SHIFT_CLOCK_PIN,0);
		MSTK_voidSetBusyWait(HSTP_CLOCK_TIME);
	}
	MGPIO_voidSetPinValue(HSTP_STORE_CLOCK_PIN,1);
	MSTK_voidSetBusyWait(HSTP_CLOCK_TIME);
	MGPIO_voidSetPinValue(HSTP_STORE_CLOCK_PIN,0);
	MSTK_voidSetBusyWait(HSTP_CLOCK_TIME);
}