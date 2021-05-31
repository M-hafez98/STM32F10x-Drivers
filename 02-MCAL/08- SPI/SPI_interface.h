/***********************************************************************************************************/
/* Auther		: Mohammed Hafez																		   */
/* Date 		: 26 Sep 2020																			   */
/* Version		: 01																					   */
/***********************************************************************************************************/

#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

/*user selection options for the required SPI*/
#define SPI1		1
#define SPI2		2
#define SPI3		3

/*clock bits number in RCC Registers of SPI peripherals*/
#define SPI1_ID		12	
#define SPI2_ID		14	
#define SPI3_ID		15	

void MSPI_voidInit(u8 Copy_u8SPINumber);
void MSPI_voidWriteDataSynch(u8 Copy_u8Data);
void MSPI_voidWriteDataAsynch(u8 Copy_u8Data, void (*SPICallBack)(void));






#endif
