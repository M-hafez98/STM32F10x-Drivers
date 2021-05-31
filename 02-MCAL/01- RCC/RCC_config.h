/***********************************************************************************************************/
/* Auther		: Mohammed Hafez																		   */
/* Date 		: 9 Aug 2020																			   */
/* Version		: 01																					   */
/***********************************************************************************************************/

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

/*macros definitions*/

/* Options:  RCC_HSI_SYSTEM_CLOCK_SELECTION
			 RCC_HSE_SYSTEM_CLOCK_SELECTION
			 RCC_PLL_SYSTEM_CLOCK_SELECTION
*/
#define SYSTEM_CLCOK 	 					RCC_HSE_SYSTEM_CLOCK_SELECTION

#if SYSTEM_CLCOK == RCC_HSE_SYSTEM_CLOCK_SELECTION
/* Options:  RCC_HSE_RC_CLOCK_SELECTION
			 RCC_HSE_CRYSTAL_CLOCK_SELECTION
*/
#define HSE_CLOCK_SOURCE 					RCC_HSE_CRYSTAL_CLOCK_SELECTION
#endif

 /*NOTE: this option is avaialbe only if PLL is enabled*/
#if SYSTEM_CLCOK == RCC_PLL_SYSTEM_CLOCK_SELECTION
/* Options:  RCC_PLL_HSE_SOURCE_SELECTION
			 RCC_PLL_HSE_BY_TWO_SOURCE_SELECTION
			 RCC_PLL_HSI_BY_TWO_SOURCE_SELECTION
*/
#define RCC_PLL_CLOCK_SOURCE 				RCC_PLL_HSE_SOURCE_SELECTION
#define RCC_PLL_MULTIPLICATION_FACTOR_SHIFT	18
/* Options:  RCC_PLL_CLOCK_MULT_BY_x, where x is 2:16 */
#define RCC_PLL_MULTIPLICATION_FACTOR		RCC_PLL_CLOCK_MULT_BY_2
#endif
		

#define RCC_HSI_ON_SHIFT					0
#define RCC_HSE_ON_SHIFT					16
#define RCC_PLL_ON_SHIFT					24

#define	RCC_SYSTEM_CLOCK_SWITCH_SHIFT		0
#define RCC_HSI_SWITCH_SELECTION_VALUE 		00
#define RCC_HSE_SWITCH_SELECTION_VALUE		01
#define RCC_PLL_SWITCH_SELECTION_VALUE 		10

#define RCC_HSE_BYPASS_SHIFT	 			18
#define RCC_PLL_HSE_DIVIDER_SHIFT 			17
#define RCC_PLL_CLOCK_ENTRY_SELECTION_SHIFT	16

#define RCC_TRIM_CALIBRATION_SHIFT			4
#define RCC_TRIM_CALIBRATION_VALUE			0x10





#endif