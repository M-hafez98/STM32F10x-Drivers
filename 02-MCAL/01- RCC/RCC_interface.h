/***********************************************************************************************************/
/* Auther		: Mohammed Hafez																		   */
/* Date 		: 8 Aug 2020																			   */
/* Version		: 01																					   */
/***********************************************************************************************************/

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

/*Macros*/
#define RCC_AHB 	0
#define RCC_APB1	1
#define RCC_APB2	2


/*functions prorotypes*/
void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);
void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId)
void RCC_voidInitSystemClock(void);



#endif