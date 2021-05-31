/***********************************************************************************************************/
/* Auther		: Mohammed Hafez																		   */
/* Date 		: 21 Sep 2020																			   */
/* Version		: 01																					   */
/***********************************************************************************************************/
#ifndef TFT_PRIVATE_H
#define TFT_PRIVATE_H

#define TFT_SLEEP_OUT_CMD				0x11 /*to turn off sleep out mode*/
#define TFT_COLOR_MODE_CMD				0x3A
#define TFT_COLOR_PARAMETER				0x05 /*for RGB 565*/
#define TFT_DISPLAY_ON_CMD				0x29
#define TFT_ROW_ADDRESS_SET_CMD			0x2B
#define TFT_COLUMN_ADDRESS_SET_CMD		0x2A






static void HTFT_voidWriteCommand(u8 Copy_u8Command);
static void HTFT_voidWriteData(u8 Copy_u8Data);



#endif
