/***********************************************************************************************************/
/* Auther		: Mohammed Hafez																		   */
/* Date 		: 19 Sep 2020																			   */
/* Version		: 02																					   */
/***********************************************************************************************************/

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H


/*Macros*/
#define GPIOA_PORT					5
#define GPIOB_PORT					6
#define GPIOC_PORT					7

#define GPIOA_ID 					2
#define GPIOB_ID 					3
#define GPIOC_ID 					4

#define INPUT_FLOAT					0b0100
#define INPUT_PULL_UP_DOWN 			0b1000	
#define INPUT_ANALOG	  			0b0000

#define GP_OUTPUT_PUSH_PULL_10MHZ  	0b0001
#define GP_OUTPUT_PUSH_PULL_2MHZ  	0b0010
#define GP_OUTPUT_PUSH_PULL_50MHZ  	0b0011

#define GP_OUTPUT_OPEN_DRAIN_10MHZ 	0b0101
#define GP_OUTPUT_OPEN_DRAIN_2MHZ 	0b0110
#define GP_OUTPUT_OPEN_DRAIN_50MHZ 	0b0111





/* function prototypes */
void MGPIO_voidInit(u8 Copy_u8Port, u8 Copy_u8pinNum, u8 Copy_u8pinMode);
u8 MGPIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8pinNum);
u16 MGPIO_u16GetPortValue(u8 Copy_u8Port);
void MGPIO_voidSetPinValue(u8 Copy_u8Port,u8 Copy_u8pinNum, u8 Copy_u8Value);
void MGPIO_voidSetPortValue(u8 Copy_u8Port, u16 Copy_u16Value);
void MGPIO_voidClearPort(u8 Copy_u8Port);


#endif
