#include <stdint.h>
#ifndef __STM32F10x_H
#define __STM32F10x_H
#include "stm32f10x.h"  // Device header
#endif

#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H
#endif

/*** functions prototypes ***/
void gbio_conf_pin_mode( GPIO_TypeDef* GPIOx, uint16_t pin_no, uint16_t mode );
uint8_t gbio_read_pin( GPIO_TypeDef* GPIOx, uint16_t pin_no );
void gbio_write_pin ( GPIO_TypeDef* GPIOx, uint16_t pin_no, uint8_t val );
void gbio_reset_pin ( GPIO_TypeDef* GPIOx, uint16_t pin_no);

/**** Macros for GPIO pins modes configuration ****/

#define GPIO_PIN_INPUT_MODE 												( (uint32_t) 0x00 )
#define GPIO_PIN_FLOATING_INPUT_MODE 								( (uint32_t) 0x01 )
#define GPIO_PIN_PULL_INPUT_MODE 										( (uint32_t) 0x10 )
#define GPIO_PIN_OUTPUT_MODE_PUSH_PULL							( (uint32_t) 0x00 )
#define GPIO_PIN_OUTPUT_MODE_OPEN_DRAIN							( (uint32_t) 0x01 )
#define GPIO_PIN_ALT_OUTPUT_PUSH_PULL_MODE					( (uint32_t) 0x10 )
#define GPIO_PIN_ALT_OUTPUT_OPEN_DRAIN_MODE					( (uint32_t) 0x11 )
#define GPIO_PIN_OUTPUT_MODE_10MHZ									( (uint32_t) 0x01 )
#define GPIO_PIN_OUTPUT_MODE_2MHZ										( (uint32_t) 0x10 )
#define GPIO_PIN_OUTPUT_MODE_50MHZ									( (uint32_t) 0x11 )
#define GPIO_PIN_ANALOG_MODE												( (uint32_t) 0x00 )

/*** Marcos for pin numpers ***/
#define GPIO_PIN_1																	1
#define GPIO_PIN_2																	2
#define GPIO_PIN_3																	3
#define GPIO_PIN_4																	4
#define GPIO_PIN_5																	5
#define GPIO_PIN_6																	6
#define GPIO_PIN_7																	7
#define GPIO_PIN_8																	8
#define GPIO_PIN_9																	9
#define GPIO_PIN_10																	10
#define GPIO_PIN_11																	11
#define GPIO_PIN_12																	12
#define GPIO_PIN_13																	13
#define GPIO_PIN_14																	14
#define GPIO_PIN_15																	15
#define GPIO_PIN_16																	16

/**** RCC configuration macros for GPIOs ports enabling clock ****/

#define RCC_GPIOA_CLK_ENABLE() (RCC->APB2ENR |= (1<<2))
#define RCC_GPIOB_CLK_ENABLE() (RCC->APB2ENR |= (1<<3))
#define RCC_GPIOC_CLK_ENABLE() (RCC->APB2ENR |= (1<<4))
#define RCC_GPIOD_CLK_ENABLE() (RCC->APB2ENR |= (1<<5))
#define RCC_GPIOE_CLK_ENABLE() (RCC->APB2ENR |= (1<<6))
#define RCC_GPIOF_CLK_ENABLE() (RCC->APB2ENR |= (1<<7))
#define RCC_GPIOG_CLK_ENABLE() (RCC->APB2ENR |= (1<<8))

typedef struct{
	uint32_t pin; // specifies pin number to be configured
	uint32_t mode; // specifies mode of operation
	uint32_t speed; // specifies output speed 
	uint32_t alternate;
}gbio_pin_config_t;

