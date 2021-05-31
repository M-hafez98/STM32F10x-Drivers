/***********************************************************************************************************/
/* Auther		: Mohammed Hafez																		   */
/* Date 		: 4 Sep 2020																			   */
/* Version		: 01																					   */
/***********************************************************************************************************/
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#define EXTI_RISING_EDGE_TRIGGER			0
#define EXTI_FALLING_EDGE_TRIGGER			1
#define EXTI_RISING_FALLING_EDGE_TRIGGER	2


void MEXTI_voidEXTIInit			(u8 Copy_u8EXTILine, u8 Copy_u8EXTISenseMode, void (*EXTI_CallBackPtr) (void));
void MEXTI_voidEnableEXTILine	(u8 Copy_u8EXTILine);
void MEXTI_voidDisableEXTILine	(u8 Copy_u8EXTILine);
void MEXTI_voidSetTriggerEdge	(u8 Copy_u8EXTISenseMode);
void MEXTI_voidClearPendingFlag (u8 Copy_u8EXTILine);
void MEXTI_voidSelectEXTIPin	(u8 Copy_u8PinNum);

#endif
