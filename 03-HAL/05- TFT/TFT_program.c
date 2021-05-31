/***********************************************************************************************************/
/* Auther		: Mohammed Hafez																		   */
/* Date 		: 21 Sep 2020																			   */
/* Version		: 01																					   */
/***********************************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "SPI_interface.h"
#include "STK_interface.h"
#include "TFT_interface.h"
#include "TFT_private.h"
#include "TFT_config.h"
#include "img.h"


void HTFT_voidInit(void){
	/*reset pulse*/
	MGPIO_voidSetPinValue(TFT_RST_PIN, 1);
	MSTK_voidSetBusyWait(100);
	MGPIO_voidSetPinValue(TFT_RST_PIN, 0);
	MSTK_voidSetBusyWait(1);
	MGPIO_voidSetPinValue(TFT_RST_PIN, 1);
	MSTK_voidSetBusyWait(100);
	MGPIO_voidSetPinValue(TFT_RST_PIN, 0);
	MSTK_voidSetBusyWait(100);
	MGPIO_voidSetPinValue(TFT_RST_PIN, 1);
	MSTK_voidSetBusyWait(120000);
	/*turn off sleep out cmd*/
	HTFT_voidWriteCommand(TFT_SLEEP_OUT_CMD);
	/*wait 150 ms*/
	MSTK_voidSetBusyWait(150000);
	/*turn on color mode*/
	HTFT_voidWriteCommand(TFT_COLOR_MODE_CMD);
	/*choose RGP565 standard*/
	HTFT_voidWriteData(TFT_COLOR_PARAMETER);
	/*turn on display*/
	HTFT_voidWriteCommand(TFT_DISPLAY_ON_CMD);
}
void HTFT_voidDrawImg(const u16 * img){
	u16 i;
	/*set column ranges*/
	HTFT_voidWriteCommand(TFT_COLUMN_ADDRESS_SET_CMD);
	HTFT_voidWriteData(TFT_COLUMN_START_PARAMETER1);
	HTFT_voidWriteData(TFT_COLUMN_START_PARAMETER2);
	HTFT_voidWriteData(TFT_COLUMN_END_PARAMETER3);
	HTFT_voidWriteData(TFT_COLUMN_END_PARAMETER4);
	/*set row ranges*/
	HTFT_voidWriteCommand(TFT_ROW_ADDRESS_SET_CMD);
	HTFT_voidWriteData(TFT_ROW_START_PARAMETER1);
	HTFT_voidWriteData(TFT_ROW_START_PARAMETER2);
	HTFT_voidWriteData(TFT_ROW_END_PARAMETER3);
	HTFT_voidWriteData(TFT_ROW_END_PARAMETER4);

	for(i=0;i<16384;i++){
		HTFT_voidWriteData(img[i] >> 8);
		HTFT_voidWriteData(img[i] & 0x00FF);
	}
}

static void HTFT_voidWriteCommand(u8 Copy_u8Command){
	/*force DC pin to low*/
	MGPIO_voidSetPinValue(TFT_DC_PIN, 0);
	/*send command through SPI*/
	MSPI_voidWriteDataSynch(Copy_u8Command);
}
static void HTFT_voidWriteData(u8 Copy_u8Data){
	/*force DC pin to high*/
	MGPIO_voidSetPinValue(TFT_DC_PIN, 1);
	/*send command through SPI*/
	MSPI_voidWriteDataSynch(Copy_u8Data);
}
