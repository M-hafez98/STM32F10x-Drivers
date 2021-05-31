/***********************************************************************************************************/
/* Auther		: Mohammed Hafez																		   */
/* Date 		: 19 Sep 2020																			   */
/* Version		: 01																					   */
/***********************************************************************************************************/

/*
	set the configuration as port,pin
	options:
		for port: GPIOx_PORT
		for pins: 0 to 15 for Port A and B
*/

#define HSTP_SERIAL_PIN			GPIOA_PORT,0
#define HSTP_SHIFT_CLOCK_PIN	GPIOA_PORT,1
#define HSTP_STORE_CLOCK_PIN	GPIOA_PORT,2

/* set time in us */

#define HSTP_CLOCK_TIME	1
