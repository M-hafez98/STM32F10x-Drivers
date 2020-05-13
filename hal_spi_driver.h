#ifndef _HAL_SPI_DRIVER_H

#define _HAL_SPI_DRIVER_H

#include "stm32f10x.h"
#include <stdlib.h>
#include <stdint.h>

/* bit definition for SPI CR1 configuration */
#define CLOCK_HIGH_IDLE_STATE			1
#define CLOCK_LOW_IDLE_STATE			0
#define DATA_CAPTURE_FIRST_EDGE		0
#define DATA_CAPTURE_SECOND_EDGE	1		
#define DATA_FRAME_FORMAT_8BIT		0
#define DATA_FRAME_FORMAT_16BIT		1
#define LSB_FIRST									1
#define MSB_FIRST									0
#define MASTER_SEL								1
#define SLAVE_SEL									0
#define SOFTWARE_SLAVE_MANAGE			1
#define HARDWARE_SLAVE_MANAGE			0
#define BIDIR_1_LINE_ENABLE				1
#define UNIDIR_2_LINE_ENABLE			0


/* SPI peripherals clock enable */
#define 	_HAL_SPI1_CLK_ENABLE() 	( RCC->APB2ENR |= (1<<12) )
#define 	_HAL_SPI2_CLK_ENABLE() 	( RCC->APB1ENR |= (1<<14) )
#define 	_HAL_SPI3_CLK_ENABLE() 	( RCC->APB1ENR |= (1<<15) )

/* baud-rate enumration */
typedef enum{
	PRE_SCALER_2 = 0x00,
	PRE_SCALER_4,
	PRE_SCALER_8,
	PRE_SCALER_16,
	PRE_SCALER_32,
	PRE_SCALER_64,
	PRE_SCALER_128,
	PRE_SCALER_256
}baud_rate_sel_e;

/* SPI configuration structure */
typedef struct{
	uint8_t clk_pol;
	uint8_t clk_phase;
	uint8_t clk_prescaler;
	uint8_t data_size;
	uint8_t data_direction;
	uint8_t spi_mode;
	uint8_t line_direction;
	uint8_t slave_manage;
	baud_rate_sel_e br;
}spi_config_t;
/* SPI data handling structure */
typedef struct{
	SPI_TypeDef* spi;
	spi_config_t s;
	uint16_t* pTx;
	uint8_t Tx_size; // this var takes the values of 1 for one byte and 2 for two bytes
	uint8_t Tx_count;
	uint16_t* pRx;
	uint8_t Rx_size;
	uint8_t Rx_count;
}spi_handle_t;
/* SPI configuration functions prototypes */
void spi_init(SPI_TypeDef*, spi_config_t);
void spi_master_Tx(spi_handle_t*, uint16_t*, uint16_t);
void spi_master_Rx(spi_handle_t*, uint16_t*, uint16_t);
void spi_slave_Tx(spi_handle_t*, uint16_t*, uint16_t);
void spi_slave_Rx(spi_handle_t*, uint16_t*, uint16_t);
/* SPI interrupt enable for transmission and reciption */
void spi_TxE_enable_interrupt(SPI_TypeDef*);
void spi_TxE_disable_interrupt(SPI_TypeDef*);
void spi_RxNE_enable_interrupt(SPI_TypeDef*);
void spi_RxNE_disable_interrupt(SPI_TypeDef*);
void spi_irq_habdler(spi_handle_t*);
void spi_handle_tx_data(spi_handle_t*);
void spi_handle_rx_data(spi_handle_t*);
/* spi initialization helper functions */
void spi_mode_configration(SPI_TypeDef*, uint8_t);
void spi_set_clk_polarity_phase(SPI_TypeDef*, uint8_t, uint8_t);
void spi_set_clk_frequency(SPI_TypeDef*, baud_rate_sel_e);
void spi_set_data_size_direction(SPI_TypeDef*, uint8_t, uint8_t);
void spi_config_nss_pin(SPI_TypeDef*, uint8_t, uint8_t);
void spi_enable(SPI_TypeDef*);
void spi_disable(SPI_TypeDef*);

#endif
