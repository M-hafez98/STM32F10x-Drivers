#include "stm32f10x.h"                  // Device header
#include "stdlib.h"
#include "gbio_driver.h"


void gbio_conf_pin_mode( GPIO_TypeDef* GPIOx, uint16_t pin_no, uint16_t mode )
{
	
	if (pin_no <= GPIO_PIN_6)
	{
		GPIOx->CRL |= mode << pin_no;
	}
	else
	{
		GPIOx->CRH |= mode << pin_no;
	}
	
}
	
uint8_t gbio_read_pin( GPIO_TypeDef* GPIOx, uint16_t pin_no )
{
	static uint8_t value;
	value = (GPIOx->IDR >> pin_no) & (0x0001);
}

void gbio_write_pin ( GPIO_TypeDef* GPIOx, uint16_t pin_no, uint8_t val )
{
	if(val)
	{
		GPIOx->ODR |= val << pin_no;
	}
	else
	{
		GPIOx->ODR &= val << pin_no;
	}
}
void gbio_reset_pin ( GPIO_TypeDef* GPIOx, uint16_t pin_no)
{
	GPIOx->BRR |= 1 << pin_no;
}