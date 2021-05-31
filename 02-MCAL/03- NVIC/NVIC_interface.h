/***********************************************************************************************************/
/* Auther		: Mohammed Hafez																		   */
/* Date 		: 28 Aug 2020																			   */
/* Version		: 01																					   */
/***********************************************************************************************************/


#ifndef NVIC_INTERFACE
#define NVIC_INTERFACE

void MNVIC_voidEnableInterrupt  (u8 Copy_u8IntNum);
void MNVIC_voidDisableInterrupt (u8 Copy_u8IntNum);
void MNVIC_voidSetPendingFlag 	(u8 Copy_u8IntNum);
void MNVIC_voidClearPendingFlag (u8 Copy_u8IntNum);
u8 	 MNVIC_u8GetActiveFlag  	(u8 Copy_u8IntNum);


#endif