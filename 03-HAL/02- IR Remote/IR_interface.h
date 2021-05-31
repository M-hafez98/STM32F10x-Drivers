/***********************************************************************************************************/
/* Auther		: Mohammed Hafez																		   */
/* Date 		: 5 Sep 2020																			   */
/* Version		: 01																					   */
/***********************************************************************************************************/

#ifndef IR_INTERFACE_h
#define IR_INTERFACE_h

#define STK_TIME_INTERVAL 50000
/*this function do:
	* configure the pin as floating input
	* selects the EXTI line
	* enable the interrupt of EXTI line
	* set EXTI callback function
*/
void HIR_voidInitIR(GPIO_e* GPIOx, u8 Copy_u8PinNum, u8 Copy_u8EXTILine, void(*Ref_EXTICallback)(void));
/*callback function of EXTI*/
void HIR_voidGetFrame(void);
/*get the address from the frame*/
u8 HIR_u8GetAddress(void);
/*get the data from the frame*/
u8 HIR_u8GetData(void);
/*take action based on the data*/
void HIR_voidTakeAction(u8 Copy_u8RemoteData);




#endif
