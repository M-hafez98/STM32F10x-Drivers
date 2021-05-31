/***********************************************************************************************************/
/* Auther		: Mohammed Hafez																		   */
/* Date 		: 8 Aug 2020																			   */
/* Version		: 01																					   */
/***********************************************************************************************************/
 
/*library files inclusion*/
//#include "STD_TYPES.h"
//#include "BIT_MATH.h"

/*lower layer files inclusion*/


/*driver files inclusion*/
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId){

	/*argument validation*/
	if(Copy_u8PerId <= 31){
		switch(Copy_u8BusId){
			case RCC_AHB	:	SET_BIT(RCC_AHBENR	, Copy_u8PerId);	break;  
			case RCC_APB1	: 	SET_BIT(RCC_APB1ENR	, Copy_u8PerId);	break;
			case RCC_APB2	:	SET_BIT(RCC_APB2ENR	, Copy_u8PerId);	break;
			default			: 	#error("inavlid clock bus")				break;
		}
	}
	else{
		#error("peripheral id is greater than 31");
	}
}

void RCC_voidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId){

	/*argument validation*/
	if(Copy_u8PerId <= 31){
		switch(Copy_u8BusId){
			case RCC_AHB	:	CLR_BIT(RCC_AHBENR	, Copy_u8PerId);	break;  
			case RCC_APB1	: 	CLR_BIT(RCC_APB1ENR	, Copy_u8PerId);	break;
			case RCC_APB2	:	CLR_BIT(RCC_APB2ENR	, Copy_u8PerId);	break;
			//default			: 	/*return error*/						break;
		}
	}
	else{
		/*return error*/
	}
}

void RCC_voidInitSystemClock(void){
	RCC_CR   = 0x00080080; // All clock sources are disable, trim value is the default, bypass is off and CCS is on
	RCC_CFGR = 0x00000000; // HSI is selected, PLL multiplier is 2, and NO MCO

	#if SYSTEM_CLOCK == RCC_HSI_SYSTEM_CLOCK_SELECTION
		SET_BIT(RCC_CR, RCC_HSI_ON_SHIFT);
		while(!((RCC_CR & 0x00000002) == 0x00000002));
		RCC_CR |= RCC_TRIM_CALIBRATION_VALUE << RCC_TRIM_CALIBRATION_SHIFT;
		RCC_CR &= ~(~RCC_TRIM_CALIBRATION_VALUE << RCC_TRIM_CALIBRATION_SHIFT);
		RCC_CFGR |= RCC_HSI_SELECTION_VALUE << RCC_SYSTEM_CLOCK_SWITCH_SHIFT;
		RCC_CFGR &= ~(~RCC_HSI_SELECTION_VALUE << RCC_SYSTEM_CLOCK_SWITCH_SHIFT);
	#elif SYSTEM_CLOCK == RCC_HSE_SYSTEM_CLOCK_SELECTION
		#if HSE_CLOCK_SOURCE == RCC_HSE_RC_CLOCK_SELECTION
			SET_BIT(RCC_CR, RCC_HSE_BYPASS_SHIFT);
		#else
			CLR_BIT(RCC_CR, RCC_HSE_BYPASS_SHIFT);
		#endif
		SET_BIT(RCC_CR, RCC_HSE_ON_SHIFT);
 		while(!((RCC_CR & 0x00020000) == 0x00020000));
 		RCC_CFGR |= RCC_HSE_SELECTION_VALUE << RCC_SYSTEM_CLOCK_SWITCH_SHIFT;
		RCC_CFGR &= ~(~RCC_HSE_SELECTION_VALUE << RCC_SYSTEM_CLOCK_SWITCH_SHIFT);
	#elif SYSTEM_CLOCK == RCC_PLL_SYSTEM_CLOCK_SELECTION
		RCC_CFGR |= RCC_PLL_MULTIPLICATION_FACTOR << RCC_PLL_MULTIPLICATION_FACTOR_SHIFT;
 		RCC_CFGR &= ~(~RCC_PLL_MULTIPLICATION_FACTOR << RCC_PLL_MULTIPLICATION_FACTOR_SHIFT);
 		#if RCC_PLL_CLOCK_SOURCE == RCC_PLL_HSE_BY_TWO_SOURCE_SELECTION
			SET_BIT(RCC_CFGR, RCC_PLL_HSE_DIVIDER_SHIFT);
		#elif RCC_PLL_CLOCK_SOURCE == RCC_PLL_HSE_SOURCE_SELECTION
			SET_BIT(RCC_CFGR, RCC_PLL_CLOCK_ENTRY_SELECTION_SHIFT);
		#elif RCC_PLL_CLOCK_SOURCE ==
			CLR_BIT(RCC_CFGR, RCC_PLL_CLOCK_ENTRY_SELECTION_SHIFT);
		#else
			#error("not valid PLL input")
		#endif
 		SET_BIT(RCC_CR, RCC_PLL_ON_SHIFT);
 		while(!((RCC_CR & 0x02000000) == 0x02000000));
 	#else
 		#error("not valid system clock input")
	#endif

}