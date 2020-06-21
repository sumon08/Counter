/*
 * clock_dev.h
 *
 * Created: 6/21/2020 11:21:40 PM
 *  Author: Asus
 */ 


#ifndef CLOCK_DEV_H_
#define CLOCK_DEV_H_

#include "compilar.h"




typedef struct
{
	struct 
	{
		reg8_t RC2MEN : 1;
		reg8_t RC32MEN : 1;
		reg8_t RC32KEN : 1;
		reg8_t XOSCEN : 1;
		reg8_t PLLEN : 1;
		reg8_t CTR_RSERVED : 3;
	}CTRL;
	
	struct
	{
		reg8_t RC2MRDY : 1;
		reg8_t RC32RDY : 1;
		reg8_t RC32KEN : 1;
		reg8_t XOSCRDY : 1;
		reg8_t PLLRDY : 1;
		reg8_t STATUS_RSERVED : 3;
	}STATUS;
	
	struct
	{
		reg8_t XOCSEL : 3;
		reg8_t OSCPWR : 1;
		reg8_t X32KLPM : 1;
		reg8_t FRQRANGE : 3;
	}XOSCCTRL;
	
	struct 
	{
		reg8_t XOSCFDEN : 1;
		reg8_t XOSCFDIF : 1;
		reg8_t PLLFDEN : 1;
		reg8_t PLLFDIF : 1;
	}XOSCFAIL;
	
	reg8_t RC32KCAL;
	
	struct
	{
		reg8_t PLLFAC : 5;
		reg8_t PLLDIV : 1;
		reg8_t PLLSRC : 2;
	}PLLCTRL;
	
	struct
	{
		reg8_t 	RC2MCREF : 1;
		reg8_t RC32MCREF : 2;
	}DFLLCTRL;
}Oscillator_t;




typedef struct
{
	struct
	{
		reg8_t SCLKSEL : 2;
	}CTRL;
	
	struct
	{
		reg8_t PSBCDIV : 2;
		reg8_t PSADIV : 5;
	}PSCTRL;
	
	struct 
	{
		reg8_t LOCK : 1;
	}LOCK;
	
	struct
	{
		reg8_t RTCEN : 1;
		reg8_t RTCSRC : 3;
	}RTCCTRL;
	
	struct 
	{
		reg8_t USBSEN : 1;
		reg8_t USBSRC : 2;
		reg8_t USBPSDIV : 3;
	}USBCTRL;
}Clock_t;


//Clock CTRL setting
#define CLOCK_CTRL_SCLKSEL_RC2MHZ					0x00
#define CLOCK_CTRL_SCLKSEL_RC32MHZ					0x01
#define CLOCK_CTRL_SCLKSEL_RC32KHZ					0x02
#define CLOCK_CTRL_SCLKSEL_XOSC						0x03
#define CLOCK_CTRL_SCLKSEL_PLL						0x04



#define CLOCK_PSCTRL_PSBCDIV_1_1					0x00
#define CLOCK_PSCTRL_PSBCDIV_1_2					0x01
#define CLOCK_PSCTRL_PSBCDIV_4_1					0x02
#define CLOCK_PSCTRL_PSBCDIV_2_2					0x03



#define CLOCK_PSCTRL_PSADIV_1						0x00
#define CLOCK_PSCTRL_PSADIV_2						0x01
#define CLOCK_PSCTRL_PSADIV_4						0x03
#define CLOCK_PSCTRL_PSADIV_8						0x05
#define CLOCK_PSCTRL_PSADIV_16						0x07
#define CLOCK_PSCTRL_PSADIV_32						0x09
#define CLOCK_PSCTRL_PSADIV_64						0x0B
#define CLOCK_PSCTRL_PSADIV_128						0x0D
#define CLOCK_PSCTRL_PSADIV_256						0x0F
#define CLOCK_PSCTRL_PSADIV_512						0x11



#define CLOCK_RTCCTRL_RTCSRC_ULP					0x00
#define CLOCK_RTCCTRL_RTCSRC_TOSC					0x01
#define CLOCK_RTCCTRL_RTCSRC_RCOSC					0x02
#define CLOCK_RTCCTRL_RTCSRC_TOSC32					0x05
#define CLOCK_RTCCTRL_RTCSRC_RCOSC32				0x06
#define CLOCK_RTCCTRL_RTCSRC_EXTCLK					0x07

#define CLOCK_USBCTRL_USBSRC_PLL					0x00
#define CLOCK_USBCTRL_USBSRC_RC32M					0x01


#define CLOCK_USBCTRL_USBPSDIV_1					0x00
#define CLOCK_USBCTRL_USBPSDIV_2					0x01
#define CLOCK_USBCTRL_USBPSDIV_4					0x02
#define CLOCK_USBCTRL_USBPSDIV_8					0x03
#define CLOCK_USBCTRL_USBPSDIV_16					0x04
#define CLOCK_USBCTRL_USBPSDIV_32					0x05



#define OSCILLATOR_XOSCCTRL_XOSCSEL_EXTCLK			0x00
#define OSCILLATOR_XOSCCTRL_XOSCSEL_32KHZ			0x02
#define OSCILLATOR_XOSCCTRL_XOSCSEL_XTAL_256CLK		0x03
#define OSCILLATOR_XOSCCTRL_XOSCSEL_XTAL_1KCLK		0x07
#define OSCILLATOR_XOSCCTRL_XOSCSEL_XTAL_16KCLK		0x0B


#define OSCILLATOR_XOSCCTRL_FRQRANGE_04TO2			0x00
#define OSCILLATOR_XOSCCTRL_FRQRANGE_2TO9			0x01
#define OSCILLATOR_XOSCCTRL_FRQRANGE_9TO12			0x02
#define OSCILLATOR_XOSCCTRL_FRQRANGE_12TO16			0x03


#define OSCILLATOR_PLLCTRL_PLLSRC_RC2M				0x00
#define OSCILLATOR_PLLCTRL_PLLSRC_RC32M				0x02
#define OSCILLATOR_PLLCTRL_PLLSRC_XOSC				0x03


#define OSCILLATOR_DFLLCTRL_RC32MCREF_RC32K			0x00
#define OSCILLATOR_DFLLCTRL_RC32MCREF_XOSC32		0x01
#define OSCILLATOR_DFLLCTRL_RC32MCREF_USBSOF		0x02



#define OSCILLATOR									(*((Oscillator_t *) 0x0050))
#define CLOCK										(*((Clock_t *) 0x0040))

#endif /* CLOCK_DEV_H_ */