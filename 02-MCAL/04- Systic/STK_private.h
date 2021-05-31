/***********************************************************************************************************/
/* Auther		: Mohammed Hafez																		   */
/* Date 		: 26 Aug 2020																			   */
/* Version		: 01																					   */
/***********************************************************************************************************/
#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

/* STK Registers */
#define STK_CTRL 	*((volatile u32*)(0xE000E010))
#define STK_LOAD 	*((volatile u32*)(0xE000E010+0x04))
#define STK_VAL  	*((volatile u32*)(0xE000E010+0x08))
#define STK_CALIB   *((volatile u32*)(0xE000E010+0x0C))

/* Clock Sources for STK */
#define PROCESSOR_CLK 			0
#define PROCESSOR_CLK_DIV_BY_8  1
#define STK_SINGLE_MODE			2
#define STK_PERIODIC_MODE		3


#endif
