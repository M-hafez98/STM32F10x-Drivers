/***********************************************************************************************************/
/* Auther		: Mohammed Hafez																		   */
/* Date 		: 2 Sep 2020																			   */
/* Version		: 01																					   */
/***********************************************************************************************************/

#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H


/* GPIO struct registers */
typedef struct{
	volatile u32 CRL;
	volatile u32 CRH;
	volatile u32 IDR;
	volatile u32 ODR;
	volatile u32 BSRR;
	volatile u32 BRR;
	volatile u32 LCKR;
}GPIO_e;

/* Ports Base Addresses */
#define GPIOA 	(( GPIO_e*)(0x40010800))
#define GPIOB 	(( GPIO_e*)(0x40010C00))
#define GPIOC 	(( GPIO_e*)(0x40011000))

#endif
