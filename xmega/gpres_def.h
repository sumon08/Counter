/*
 * gpio.h
 *
 * Created: 6/23/2020 10:30:18 AM
 *  Author: Asus
 */ 


#ifndef GPRES_H_
#define GPRES_H_

#include "compilar.h"


typedef union
{
	struct
	{
		reg8_t Bit0 : 1;
		reg8_t Bit1 : 1;
		reg8_t Bit2 : 1;
		reg8_t Bit3 : 1;
		reg8_t Bit4 : 1;
		reg8_t Bit5 : 1;
		reg8_t Bit6 : 1;
		reg8_t Bit7 : 1;
	};
	uint8_t byte;
}Gpres_t;


#define GPRES0		(*(Gpres_t *) 0x00)
#define GPRES1		(*(Gpres_t *) 0x01)
#define GPRES2		(*(Gpres_t *) 0x02)
#define GPRES3		(*(Gpres_t *) 0x03)
#define GPRES4		(*(Gpres_t *) 0x04)
#define GPRES5		(*(Gpres_t *) 0x05)
#define GPRES6		(*(Gpres_t *) 0x06)
#define GPRES7		(*(Gpres_t *) 0x07)
#define GPRES8		(*(Gpres_t *) 0x08)
#define GPRES9		(*(Gpres_t *) 0x09)
#define GPRESA		(*(Gpres_t *) 0x0A)
#define GPRESB		(*(Gpres_t *) 0x0B)
#define GPRESC		(*(Gpres_t *) 0x0C)
#define GPRESD		(*(Gpres_t *) 0x0D)
#define GPRESE		(*(Gpres_t *) 0x0E)
#define GPRESF		(*(Gpres_t *) 0x0F)



#endif /* GPIO_H_ */