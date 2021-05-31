/***********************************************************************************************************/
/* Auther		: Mohammed Hafez																		   */
/* Date 		: 26 Sep 2020																			   */
/* Version		: 01																					   */
/***********************************************************************************************************/

#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H

#define BIDIR_DATA_MODE		TWO_LINE
#define DATA_FRAME_FORMAT	BIT_DFF_8
#define NSS_MASTER_MODE		SOFTWARE_SLAVE_SELECT
#define DATA_DIRECTION		MSB_FIRST
#define SPI_MODE			MASTER
#define CLK_POLARITY		IDLE_ONE
#define CLK_PHASE			WRITE_READ
#define TX_RX_MODE			FULL_DUPLEX

baud_rate_t baudRate = PCLK_BY_2;


#endif
