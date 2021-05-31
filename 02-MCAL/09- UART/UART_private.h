/***********************************************************************************************************/
/* Auther		: Mohammed Hafez																		   */
/* Date 		: 14 May 2021																			   */
/* Version		: 01																					   */
/***********************************************************************************************************/
#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

typedef struct{
	volatile u16 SR;
	u16  RESERVED0;
	volatile u16 DR;
	u16  RESERVED1;
	volatile u16 BRR;
	u16  RESERVED2;
	volatile u16 CR1;
	u16  RESERVED3;
	volatile u16 CR2;
	u16  RESERVED4;
	volatile u16 CR3;
	u16  RESERVED5;
	volatile u16 GTPR;
	u16  RESERVED6;
}UART_t;

#define UART1	((UART_t*)(0x40013800))
#define UART2	((UART_t*)(0x40004400))
#define UART3	((UART_t*)(0x40004800))
#define UART4	((UART_t*)(0x40004C00))
#define UART5	((UART_t*)(0x40005000))


#endif