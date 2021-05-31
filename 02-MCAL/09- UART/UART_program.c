/***********************************************************************************************************/
/* Auther		: Mohammed Hafez																		   */
/* Date 		: 14 May 2021																			   */
/* Version		: 01																					   */
/***********************************************************************************************************/
/* includes for other MCAL/HAL headers */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"

/* includes for UART headers */
#include "UART_interface.h"
#include "UART_config.h"
#include "UART_private.h"


void MUART_voidInit(void){
	float Local_floatBaudRVal;
	/*Enable CLK for UART2*/
	RCC_voidEnableClock(RCC_APB1,17);
	/*Set Baud Rate Register Value*/
	Local_floatBaudRVal = F_PCLK1 / (16*UART_BAUD_RATE);
	UART2->BRR = (Local_floatBaudRVal - ((u8)Local_floatBaudRVal))*16;
	UART2->BRR |= ((u8)Local_floatBaudRVal) << 4;
	/*8 Word Length*/
	CLR_BIT(UART2->CR1,12);
	/*No Parity*/
	CLR_BIT(UART2->CR1,10);
	/*One Stop Bit*/
	CLR_BIT(UART2->CR2,12);
	CLR_BIT(UART2->CR2,13);
	/*Enable UART2*/
	SET_BIT(UART2->CR1,13);
	/*Enable RX interrupt*/
	SET_BIT(UART2->CR1,5);
}

void MUART_voidSendSynch(u8* pu8Data, u8 Copy_u8Size){
	u8 Local_u8Counter;
	/*enable transmission*/
	SET_BIT(UART2->CR1,3);
	/*enable reception*/
	SET_BIT(UART2->CR1,2);
	for(Local_u8Counter=0; Local_u8Counter<Copy_u8Size; Local_u8Counter++){
		UART2->DR = pu8Data[Local_u8Counter];
		while(!((UART2->SR) >> 6) & 1);
		CLR_BIT(UART2->SR,6);
	}
	/*disable transmission*/
	CLR_BIT(UART2->CR1,3);
}

u8* MUART_u8RecieveAsynch(void){
	u8 i = 0;
	u8* pu8_RecPacket;
	*(pu8_RecPacket+i) = UART2->DR;
	if(*(pu8_RecPacket + i++) == '\r'){
		CLR_BIT(UART2->CR1,5);
		CLR_BIT(UART2->CR1,2);
		return pu8_RecPacket;
	}
}


void USART2_IRQHandler(void){
	if( UART2->SR & 0x10 ){
		MUART_u8RecieveAsynch();
	}
}