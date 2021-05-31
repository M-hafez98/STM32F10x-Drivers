/***********************************************************************************************************/
/* Auther		: Mohammed Hafez																		   */
/* Date 		: 21 Sep 2020																			   */
/* Version		: 01																					   */
/***********************************************************************************************************/
#ifndef TFT_CONFIG_H
#define TFT_CONFIG_H

/* write connection of pins in TFT to MCU in port,pin pair  */
#define TFT_SCL_PIN		GPIOA,5
#define TFT_SDA_PIN 	GPIOA,7
#define TFT_DC_PIN 		GPIOA,1 /* DC = Data / Command Pin */
#define TFT_RST_PIN 	GPIOA,4

/*Column Address Set, start address is 2-bytes and end address is 2-bytes*/
#define TFT_COLUMN_START_PARAMETER1		0x00
#define TFT_COLUMN_START_PARAMETER2		0x00
#define TFT_COLUMN_END_PARAMETER3		0x00
#define TFT_COLUMN_END_PARAMETER4		0x80
	
/* Row Address Set, start address is 2-bytes and end address is 2-bytes*/
#define TFT_ROW_START_PARAMETER1		0x00
#define TFT_ROW_START_PARAMETER2		0x00
#define TFT_ROW_END_PARAMETER3			0x00
#define TFT_ROW_END_PARAMETER4			0x80


#endif
