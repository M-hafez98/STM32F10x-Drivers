/***********************************************************************************************************/
/* Auther		: Mohammed Hafez																		   */
/* Date 		: 26 Sep 2020																			   */
/* Version		: 01																					   */
/***********************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"



void MSPI_voidInit(u8 Copy_u8SPINumber){
	baud_rate_t BR = baudRate;
	
	if(Copy_u8SPINumber == SPI1){
		SPIx = SPI_1;
	}
	else if(Copy_u8SPINumber == SPI2){
		SPIx = SPI_2;
	}
	else{
		SPIx = SPI_3;
	}
	
	/*disable SPI*/
	CLR_BIT(SPIx->SPI_CR1, 6);
	
	#if BIDIR_DATA_MODE == TWO_LINE
		CLR_BIT(SPIx->SPI_CR1, 15);
		CLR_BIT(SPIx->SPI_CR1, 14);
	#else
		SET_BIT(SPIx->SPI_CR1, 15);
	#endif
		/*no CRC check*/
	CLR_BIT(SPIx->SPI_CR1, 13);
	CLR_BIT(SPIx->SPI_CR1, 12);
	#if DATA_FRAME_FORMAT == BIT_DFF_8
		CLR_BIT(SPIx->SPI_CR1, 11);
	#else
		SET_BIT(SPIx->SPI_CR1, 11);
	#endif
	#if TX_RX_MODE == FULL_DUPLEX
		CLR_BIT(SPIx->SPI_CR1, 10);
	#else
		SET_BIT(SPIx->SPI_CR1, 10);
	#endif
	#if NSS_MASTER_MODE == SOFTWARE_SLAVE_SELECT
	/*NSS is not use and connected to Vcc*/
		SET_BIT(SPIx->SPI_CR1, 9); 
		SET_BIT(SPIx->SPI_CR1, 8);
	#endif
	#if DATA_DIRECTION == MSB_FIRST
		CLR_BIT(SPIx->SPI_CR1, 7);
	#else
		SET_BIT(SPIx->SPI_CR1, 7);
	#endif
	SPIx->SPI_CR1 |= (BR << 3);
	SPIx->SPI_CR1 &= ~( (~BR) << 3 );
	#if SPI_MODE == MASTER
		SET_BIT(SPIx->SPI_CR1, 2);
	#else
		CLR_BIT(SPIx->SPI_CR1, 2);
	#endif
	#if CLK_POLARITY == IDLE_ONE
		CLR_BIT(SPIx->SPI_CR1, 1);
	#else
		SET_BIT(SPIx->SPI_CR1, 1);
	#endif
	#if CLK_PHASE == WRITE_READ
		SET_BIT(SPIx->SPI_CR1, 0);
	#else
		CLR_BIT(SPIx->SPI_CR1, 0);
	#endif
}

void MSPI_voidWriteDataSynch(u8 Copy_u8Data){
	/*load transmission buffer*/
	SPIx->SPI_DR = Copy_u8Data;
	/*SPI enable*/
	SET_BIT(SPIx->SPI_CR1, 6);
	/*wait till transmission finishes*/
	while(!(SPIx->SPI_SR & 0x02));
}

void MSPI_voidWriteDataAsynch(u8 Copy_u8Data, void (*SPICallBack)(void)){
	/*load transmission buffer*/
	SPIx->SPI_DR = Copy_u8Data;
	/*SPI Transmission Interrupt Enable*/
	SET_BIT(SPIx->SPI_CR2, 7);
	/*set callback function*/
	PcallBack = SPICallBack;
	/*SPI enable*/
	SET_BIT(SPIx->SPI_CR1, 6);
}

void SPI1_IRQHandler(void){
	/*disable interrupt*/
	CLR_BIT(SPIx->SPI_CR2, 7);
	/*disable SPI*/
	CLR_BIT(SPIx->SPI_CR1, 6);
	/*callback function call*/
	PcallBack();
}
