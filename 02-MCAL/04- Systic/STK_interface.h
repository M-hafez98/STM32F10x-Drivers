/***********************************************************************************************************/
/* Auther		: Mohammed Hafez																		   */
/* Date 		: 26 Aug 2020																			   */
/* Version		: 01																					   */
/***********************************************************************************************************/
#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

/* Apply Clock Choice
   Disable interrupt and timer
 */
void MSTK_voidInit(void);
void MSTK_voidSetBusyWait(u32 Copy_u32Ticks);
void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (*ptr) (void));
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*ptr) (void));
void MSTK_voidStopSTK(void);
u32  MSTK_u32GetElapsedTime(void);
u32  MSTK_u32GetRemainedTime(void);



#endif