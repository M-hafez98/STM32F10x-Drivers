/***********************************************************************************************************/
/* Auther		: Mohammed Hafez																		   */
/* Date 		: 14 May 2021																			   */
/* Version		: 01																					   */
/***********************************************************************************************************/
#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

void MUART_voidInit(void);
void MUART_voidSendSynch(u8*, u8);
u8 MUART_u8RecieveSynch(void);

void MUART_voidSendAsynch(u8);
u8* MUART_u8RecieveAsynch(void);


#endif