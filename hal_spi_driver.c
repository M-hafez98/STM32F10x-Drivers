#include "hal_spi_driver.h"

void spi_mode_configration(SPI_TypeDef* spi, uint8_t m){
	if (m == MASTER_SEL){
		spi->CR1 |= SPI_CR1_MSTR;
	}
	else{
		spi->CR1 &= ~(SPI_CR1_MSTR);
	}
}

void spi_set_clk_polarity_phase(SPI_TypeDef* spi, uint8_t pol, uint8_t phase){
	if(pol == CLOCK_HIGH_IDLE_STATE){
		spi->CR1 |= SPI_CR1_CPOL;
	}
	else{
		spi->CR1 &= ~SPI_CR1_CPOL;
	}
	if(phase == DATA_CAPTURE_SECOND_EDGE){
		spi->CR1 |= SPI_CR1_CPHA;
	}
	else{
		spi->CR1 &= ~SPI_CR1_CPHA;
	}
}

void spi_set_clk_frequency(SPI_TypeDef* spi, baud_rate_sel_e br){
	if(br == PRE_SCALER_2){
		spi->CR1 &= ~SPI_CR1_BR;
	}
	else if(br == PRE_SCALER_256){
		spi->CR1 |= SPI_CR1_BR;
	}
	else{
		spi->CR1 |= br << 4;
	}
}

void spi_set_data_size_direction(SPI_TypeDef* spi, uint8_t size, uint8_t dir){
	if(size == DATA_FRAME_FORMAT_16BIT){
		spi->CR1 |= SPI_CR1_DFF;
	}
	else{
		spi->CR1 &= ~SPI_CR1_DFF;
	}
	if(dir == LSB_FIRST){
		spi->CR1 |= SPI_CR1_LSBFIRST;
	}
	else{
		spi->CR1 &= ~SPI_CR1_LSBFIRST;
	}
}

void spi_config_nss_pin(SPI_TypeDef* spi, uint8_t s, uint8_t m){
	if(s == SOFTWARE_SLAVE_MANAGE && m == SLAVE_SEL){
		spi->CR1 |= SPI_CR1_SSM;
		spi->CR1 &= ~SPI_CR1_SSI; // to pull nss pin down to low
	}
	else if(s == SOFTWARE_SLAVE_MANAGE && m == MASTER_SEL){
		spi->CR1 |= SPI_CR1_SSM | SPI_CR1_SSI; // to pull nss pin up to high in case of master mode
	}
	else{
		spi->CR1 &= ~SPI_CR1_SSM;
	}
}

void spi_enable(SPI_TypeDef* spi){
	spi->CR1 |= SPI_CR1_SPE;
}

void spi_disable(SPI_TypeDef* spi){
	spi->CR1 &= ~SPI_CR1_SPE;
}

void spi_TxE_enable_interrupt(SPI_TypeDef* spi){
	spi->CR2 |= SPI_CR2_TXEIE;
}

void spi_TxE_disable_interrupt(SPI_TypeDef* spi){
	spi->CR2 &= ~SPI_CR2_TXEIE;
}

void spi_RxNE_enable_interrupt(SPI_TypeDef* spi){
	spi->CR2 |= SPI_CR2_RXNEIE;
}

void spi_RxNE_disable_interrupt(SPI_TypeDef* spi){
	spi->CR2 &= ~SPI_CR2_RXNEIE;
}

void spi_master_Tx(spi_handle_t* s, uint16_t* tx_buffer, uint16_t length){
	s->pTx = tx_buffer; // buffer is the address that contains the data to be transmitted
	s->Tx_size = length;
	s->Tx_count = length;
	spi_enable(s->spi);
	spi_TxE_enable_interrupt(s->spi); // the interrupt handler will handle the transmisiion process
}

void spi_master_Rx(spi_handle_t* s, uint16_t* rx_buffer, uint16_t length){
	s->pTx = rx_buffer; // dummy data
	s->Tx_size = length;
	s->Tx_count = length;
	
	s->pRx = rx_buffer;
	s->Rx_size = length;
	s->Rx_count = length;
	
	spi_enable(s->spi);
	spi_TxE_enable_interrupt(s->spi);
	spi_RxNE_enable_interrupt(s->spi);
}

void spi_slave_Tx(spi_handle_t* s, uint16_t* tx_buffer, uint16_t length){
	uint16_t rxVal;
	s->pRx = tx_buffer; // dummy data
	s->Rx_size = length;
	s->Rx_count = length;
	s->pTx = tx_buffer;
	s->Tx_size = length;
	s->Tx_count = length;
	spi_enable(s->spi);
	rxVal = s->spi->DR;
	spi_TxE_enable_interrupt(s->spi);
	spi_RxNE_enable_interrupt(s->spi);
}

void spi_slave_Rx(spi_handle_t* s, uint16_t* rx_buffer, uint16_t length){
	uint16_t rxVal;
	s->pRx = rx_buffer;
	s->Rx_size = length;
	s->Rx_count = length;
	spi_enable(s->spi);
	rxVal = s->spi->DR;
	spi_RxNE_enable_interrupt(s->spi);
}

void spi_irq_habdler(spi_handle_t* spi_handler){
	uint8_t state1;
	uint8_t state2;
	state1 = (spi_handler->spi->CR2) & SPI_CR2_RXNEIE;// this is enabled by the programmer
	state2 = (spi_handler->spi->SR) & SPI_SR_RXNE; // this is enabled by the cpu (hardware)
	if(state1 && state2){
		// handle the Rx data
		void spi_handle_rx_data(spi_handle_t* spi_handler);
	}
	state1 = spi_handler->spi->CR2 & SPI_CR2_TXEIE;
	state2 = spi_handler->spi->SR & SPI_SR_TXE; // this is enabled by the cpu
	if(state1 && state2){
		// handle the Tx data
		void spi_handle_tx_data(spi_handle_t* spi_handler);
	}
}

void spi_handle_tx_data(spi_handle_t* handler){
	if(handler->s.data_size == DATA_FRAME_FORMAT_8BIT){
		handler->spi->DR = *(handler->pTx);
		handler->Tx_count--; // one byte is transmitted
	}
	else{
		handler->spi->DR = *(handler->pTx);
		handler->Tx_count -= 2; // two bytes are transmitted
	}
}

void spi_handle_rx_data(spi_handle_t* handler){
	if(handler->s.data_size == DATA_FRAME_FORMAT_8BIT){
		*(handler->pRx) = handler->spi->DR;
		handler->Rx_count--;
	}
	else{
		*(handler->pRx) = handler->spi->DR;
		handler->Rx_count -= 2;
	}
}