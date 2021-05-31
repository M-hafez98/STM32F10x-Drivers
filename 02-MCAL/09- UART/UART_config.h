/***********************************************************************************************************/
/* Auther		: Mohammed Hafez																		   */
/* Date 		: 14 May 2021																			   */
/* Version		: 01																					   */
/***********************************************************************************************************/
#ifndef UART_CONFIG_H
#define UART_CONFIG_H

/*8 bits = 1 , 9 bits = 0*/
#define UART_DATA_LENGTH_8BITS	1
/* 1 stop bit = 1, 2 stop bits = 0*/
#define UART_STOP_1BIT			1
/* baud rate spees: 9600, 115200,.. */
#define UART_BAUD_RATE 			115200
/*PCLK1 Frequency*/
#define F_PCLK1					8000000



#endif