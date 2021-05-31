/***********************************************************************************************************/
/* Auther		: Mohammed Hafez																		   */
/* Date 		: 8 Aug 2020																			   */
/* Version		: 01																					   */
/***********************************************************************************************************/

#ifndef RCC_PRIVATE_H
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H 

/* Registers Definitions */
#define RCC_CR			*((u32*)0x40021000+0x00)
#define RCC_CFGR 		*((u32*)0x40021000+0x04)
#define RCC_CIR 		*((u32*)0x40021000+0x08)
#define RCC_APB2RSTR 	*((u32*)0x40021000+0x0C)
#define RCC_APB1RSTR 	*((u32*)0x40021000+0x10)
#define RCC_AHBENR 		*((u32*)0x40021000+0x14)
#define RCC_APB2ENR 	*((u32*)0x40021000+0x18)
#define RCC_APB1ENR 	*((u32*)0x40021000+0x1C)
#define RCC_BDCR	 	*((u32*)0x40021000+0x20)
#define RCC_CSR		 	*((u32*)0x40021000+0x24)

/* system clock sources */
#define RCC_HSI_SYSTEM_CLOCK_SELECTION 		0
#define RCC_HSE_SYSTEM_CLOCK_SELECTION 		1
#define RCC_PLL_SYSTEM_CLOCK_SELECTION 		2

/* HSE clock sources */
#define RCC_HSE_RC_CLOCK_SELECTION 			0
#define RCC_HSE_CRYSTAL_CLOCK_SELECTION 	1

/* PLL clock sources */
#define RCC_PLL_HSE_SOURCE_SELECTION 		0
#define RCC_PLL_HSE_BY_TWO_SOURCE_SELECTION 1
#define RCC_PLL_HSI_BY_TWO_SOURCE_SELECTION 2

/* PLL multiplication factor */
#define RCC_PLL_CLOCK_MULT_BY_2  0x0
#define RCC_PLL_CLOCK_MULT_BY_3  0x1
#define RCC_PLL_CLOCK_MULT_BY_4  0x2
#define RCC_PLL_CLOCK_MULT_BY_5  0x3
#define RCC_PLL_CLOCK_MULT_BY_6  0x4
#define RCC_PLL_CLOCK_MULT_BY_7  0x5
#define RCC_PLL_CLOCK_MULT_BY_8  0x6
#define RCC_PLL_CLOCK_MULT_BY_9  0x7
#define RCC_PLL_CLOCK_MULT_BY_10 0x8
#define RCC_PLL_CLOCK_MULT_BY_11 0x9
#define RCC_PLL_CLOCK_MULT_BY_12 0xA
#define RCC_PLL_CLOCK_MULT_BY_13 0xB
#define RCC_PLL_CLOCK_MULT_BY_14 0xC
#define RCC_PLL_CLOCK_MULT_BY_15 0xD
#define RCC_PLL_CLOCK_MULT_BY_16 0xE




#endif