/***********************************************************************************************************/
/* Auther		: Mohammed Hafez																		   */
/* Date 		: 5 Sep 2020																			   */
/* Version		: 01																					   */
/***********************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "RCC_interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"
#include "EXTI_interface.h"
#include "IR_interface.h"

static u8 startFalg = 0;
static u8 u8EdgeCounter = 0;
static u32 u32timeOfBits[40] = {0};
static u8 u8Address;
static u8 u8Data;

/*this function do:
	* configure the pin as floating input
	* selects the EXTI line
	* enable the interrupt of EXTI line
	* set EXTI callback function
*/
void HIR_voidInitIR(GPIO_e* GPIOx, u8 Copy_u8PinNum, u8 Copy_u8EXTILine, void(*Ref_EXTICallback)(void)){
	MGPIO_voidInit(GPIOA,0,INPUT_FLOAT);
	MEXTI_voidEXTIInit(Copy_u8EXTILine,EXTI_RISING_FALLING_EDGE_TRIGGER,Ref_EXTICallback);
	MNVIC_voidEnableInterrupt(Copy_u8EXTILine);
	MSTK_voidInit();

}

void HIR_voidGetFrame(void){
	/*start STK timer*/
	if(startFalg == 0){
		MSTK_voidSetIntervalSingle(STK_TIME_INTERVAL,HIR_voidTakeAction);
		startFalg = 1;
	}
	else{
		u32timeOfBits[u8EdgeCounter++] = MSTK_u32GetElapsedTime();
		MSTK_voidSetIntervalSingle(STK_TIME_INTERVAL,HIR_voidTakeAction);
	}

}

/*get the address from the frame*/
u8 HIR_u8GetAddress(void){
	u8 i;
		/*Address Section Extraction*/
		for(i=1;i<9;i++){
			/*logical zero*/
			if(u32timeOfBits[i]>=1000 && u32timeOfBits[i]<=1200){
				CLR_BIT(u8Address,i-1);
			}
			/*logical one*/
			else{
				SET_BIT(u8Address,i-1);
			}
		}
		return u8Address;
}
/*get the data from the frame*/
u8 HIR_u8GetData(void){
	u8 i;
	for(i=17;i<25;i++){
		/*logical zero*/
		if(u32timeOfBits[i]>=1000 && u32timeOfBits[i]<=1200){
			CLR_BIT(u8Data,i-17);
		}
		/*logical one*/
		else{
			SET_BIT(u8Data,i-17);
		}
	}
	return u8Data;
}
/*take action based on the data*/
void HIR_voidTakeAction(u8 Copy_u8RemoteData){
	u8 u8DataValue = HIR_u8GetData();
	/*Action*/

	/*End Of Action*/

	/*reset start values*/
	u8EdgeCounter = 0;
	startFalg = 0;
}
