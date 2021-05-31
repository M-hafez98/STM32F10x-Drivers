/***********************************************************************************************************/
/* Auther		: Mohammed Hafez																		   */
/* Date 		: 29 Aug 2020																			   */
/* Version		: 01																					   */
/***********************************************************************************************************/
#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

typedef struct{
	volatile u32 IMR;
	volatile u32 EMR;
	volatile u32 RTSR;
	volatile u32 FTSR;
	volatile u32 SWIER;
	volatile u32 PR;
}EXTI_e;

#define EXTI 	((volatile EXTI_e*)(0x40010400))



#endif