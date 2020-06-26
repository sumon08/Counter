/*
 * usart_def.h
 *
 * Created: 6/24/2020 1:12:53 AM
 *  Author: Asus
 */ 


#ifndef USART_DEF_H_
#define USART_DEF_H_

#include "compilar.h"



typedef struct
{
	union
	{
		reg8_t TXB;
		reg8_t RXB;
	}DATA;
	
	struct
	{
		reg8_t RXB0 : 1;
		reg8_t RES : 1;
		reg8_t PERR : 1;
		reg8_t BUFOVF : 1;
		reg8_t FERR : 1;
		reg8_t DREIF : 1;
		reg8_t TXCIF : 1;
		reg8_t RXCIF : 1;
	}STATUS;
	
	reg8_t RESERVED;
	
	struct 
	{
		reg8_t DREINTLVL : 2;
		reg8_t TXCINTLVL : 2;
		reg8_t RXCINTLVL : 2;
	}CTRLA;
	
	struct 
	{
		reg8_t TXB8 : 1;
		reg8_t MPCM : 1;
		reg8_t CLK2X : 1;
		reg8_t TXEN : 1;
		reg8_t RXEN : 1;
	}CTRLB;
	
	struct
	{
		reg8_t CHSIZE : 3;
		reg8_t SBMODE : 1;
		reg8_t PMODE : 2;
		reg8_t CMODE : 2;
	}CTRLB;
	
	struct
	{
		reg16_t BAUD : 12;
		reg16_t BSCALE : 4;
	}BAUDCTRL;
	
}Usart_t;



#define USART_CTRLC_CMODE_ASYNCHRONOUS		0x00
#define USART_CTRLC_CMODE_SYNCHRONOUS		0x01
#define USART_CTRLC_CMODE_IRCOM				0x02
#define USART_CTRLC_CMODE_MSPI				0x03



#define USART_CTRLC_PMODE_DISABLED			0x00
#define USART_CTRLC_PMODE_EVEN				0x00
#define USART_CTRLC_PMODE_ODD				0x00


#define USART_CTRLC_CHSIZE_5BIT				0x00
#define USART_CTRLC_CHSIZE_6BIT				0x01
#define USART_CTRLC_CHSIZE_7BIT				0x02
#define USART_CTRLC_CHSIZE_8BIT				0x03
#define USART_CTRLC_CHSIZE_9BIT				0x07



#define USARTC0				(*((Usart_t *) 0x08A0))
#define USARTC1				(*((Usart_t *) 0x08B0))
#define USARTD0				(*((Usart_t *) 0x09A0))
#define USARTD1				(*((Usart_t *) 0x09B0))
#define USARTE0				(*((Usart_t *) 0x0AA0))

#endif /* USART_DEF_H_ */