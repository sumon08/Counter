/*
 * gpio_def.h
 *
 * Created: 6/23/2020 10:25:54 PM
 *  Author: Asus
 */ 


#ifndef GPIO_DEF_H_
#define GPIO_DEF_H_

#include "compilar.h"

typedef struct 
{
	reg8_t Bit0 : 1;
	reg8_t Bit1 : 1;
	reg8_t Bit2 : 1;
	reg8_t Bit3 : 1;
	reg8_t Bit4 : 1;
	reg8_t Bit5 : 1;
	reg8_t Bit6 : 1;
	reg8_t Bit7 : 1;
}Port_t;

typedef struct
{
	reg8_t ISC : 3;
	reg8_t OPC : 3;
	reg8_t INVEN : 1;
	reg8_t SRLEN : 1;
}PINnCTRL;

typedef struct
{
	Port_t DIR;
	Port_t DIRSET;
	Port_t DIRCLR;
	Port_t DIRTGL;
	Port_t OUT;
	Port_t OUTSET;
	Port_t OUTCLR;
	Port_t OUTTGL;
	Port_t IN;
	struct
	{
		reg8_t INT0LVL : 2;
		reg8_t INT1LVL : 2;
	}INTCTRL;
	
	Port_t INT0MASK;
	Port_t INT1MASK;
	struct
	{
		reg8_t INT0IF : 1;
		reg8_t INT1IF : 1;
	}INTFLAGS;
	
	reg8_t RESERVED1;
	
	struct
	{
		reg8_t TC0A : 1;
		reg8_t TC0B : 1;
		reg8_t TC0C : 1;
		reg8_t TC0D : 1;
		reg8_t USART0 : 1;
		reg8_t SPI : 1;		
	}REMAP;
	
	reg8_t RESERVED2;
	
	PINnCTRL PIN0CTRL;
	PINnCTRL PIN1CTRL;
	PINnCTRL PIN2CTRL;
	PINnCTRL PIN3CTRL;
	PINnCTRL PIN4CTRL;
	PINnCTRL PIN5CTRL;
	PINnCTRL PIN6CTRL;
	PINnCTRL PIN7CTRL;
}Gpio_t;


#define GPIO_PINNCTRL_ISC_BOTHEDGES			0x00
#define GPIO_PINNCTRL_ISC_RISING			0x01
#define GPIO_PINNCTRL_ISC_FALLING			0x02
#define GPIO_PINNCTRL_ISC_LEVEL				0x03
#define GPIO_PINNCTRL_ISC_INTPUT_DISABLE	0x07


#define GPIO_PINNCTRL_OPC_TOTEM				0x00
#define GPIO_PINNCTRL_OPC_BUSKEEPER			0x01
#define GPIO_PINNCTRL_OPC_PULLDOWN			0x02
#define GPIO_PINNCTRL_OPC_PULLUP			0x03
#define GPIO_PINNCTRL_OPC_WIREDOR			0x04
#define GPIO_PINNCTRL_OPC_WIREDAND			0x05
#define GPIO_PINNCTRL_OPC_WIREDORPULL		0x06
#define GPIO_PINNCTRL_OPC_WIREDANDPULL		0x07



#define PORTA			(*(Gpio_t *) 0x0600)
#define PORTB			(*(Gpio_t *) 0x0620)
#define PORTC			(*(Gpio_t *) 0x0640)
#define PORTD			(*(Gpio_t *) 0x0660)
#define PORTE			(*(Gpio_t *) 0x0680)
#define PORTR			(*(Gpio_t *) 0x07E0)

#endif /* GPIO_DEF_H_ */