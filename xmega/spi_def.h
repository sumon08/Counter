/*
 * spi_dev.h
 *
 * Created: 6/24/2020 10:39:40 PM
 *  Author: Asus
 */ 


#ifndef SPI_DEV_H_
#define SPI_DEV_H_

#include "compilar.h"


typedef struct
{
	struct
	{
		reg8_t PRESCALER : 2;
		reg8_t MODE : 2;
		reg8_t MASTER : 1;
		reg8_t DORD : 1;
		reg8_t ENABLE : 1;
		reg8_t CLK2X : 1;
	}CTRL;
	
	struct
	{
		reg8_t INTLVL : 2;
	}INTCTRL;
	
	struct 
	{
		reg8_t RES : 6;
		reg8_t WRCOL : 1;
		reg8_t IF : 1;
	};
	
	reg8_t DATA;
}Spi_t;


#define SPI_CTRL_MODE_0					0x00	//Rising sample,  Falling setup
#define SPI_CTRL_MODE_1					0x01	//Rising setup, Falling sample
#define SPI_CTRL_MODE_2					0x02	//Falling sample, Rising setup
#define SPI_CTRL_MODE_3					0x03	//Falling setup, Rising sample


#define SPI_CTRL_PRESCALER_00			0x00
#define SPI_CTRL_PRESCALER_01			0x01
#define SPI_CTRL_PRESCALER_10			0x02
#define SPI_CTRL_PRESCALER_11			0x03	


#define SPIC		(*((Spi_t *) 0x08C0))
#define SPID		(*((Spi_t *) 0x09C0))

#endif /* SPI_DEV_H_ */