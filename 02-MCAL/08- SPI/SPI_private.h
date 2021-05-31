/***********************************************************************************************************/
/* Auther		: Mohammed Hafez																		   */
/* Date 		: 26 Sep 2020																			   */
/* Version		: 01																					   */
/***********************************************************************************************************/

#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

typedef struct{
	volatile u32 SPI_CR1;
	volatile u32 SPI_CR2;
	volatile u32 SPI_SR;
	volatile u32 SPI_DR;
	volatile u32 SPI_CRCPR;
	volatile u32 SPI_RXCRCR;
	volatile u32 SPI_TXCRCR;
}SPI_t;

typedef enum{
	PCLK_BY_2=0b000,
	PCLK_BY_4,
	PCLK_BY_8,
	PCLK_BY_16,
	PCLK_BY_32,
	PCLK_BY_64,
	PCLK_BY_128,
	PCLK_BY_256
}baud_rate_t;

SPI_t * SPIx;
static void (*PcallBack)(void);

#define SPI_1	((SPI_t *) 0x40013000)
#define SPI_2	((SPI_t *) 0x40003800)
#define SPI_3	((SPI_t *) 0x40003C00)


#define TWO_LINE				1

#define LSB_FIRST				2
#define MSB_FIRST				3

#define BIT_DFF_8				4
#define BIT_DFF_16				5

#define IDLE_ZERO				6
#define IDLE_ONE				7

#define WRITE_READ				8
#define READ_WRITE				9

#define SOFTWARE_SLAVE_SELECT	10
#define HARDWARE_SLAVE_SELECT	11

#define MASTER					12

#define FULL_DUPLEX				13

#endif
