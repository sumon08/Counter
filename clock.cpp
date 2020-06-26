/*
 * clock.c
 *
 * Created: 6/20/2020 1:54:30 PM
 *  Author: Asus
 */ 


#include "xmega/clock_def.h"
#include "clock.h"
#include "xmega_protection.h"
#include "config.h"


volatile uint8_t cpu_frequency = 0;

void InitClock()
{
	uint8_t mult_factor = 0;
	uint8_t osc_ready = 0;
	
	OSCILLATOR.XOSCCTRL.FRQRANGE = OSCILLATOR_XOSCCTRL_FRQRANGE_2TO9;
	OSCILLATOR.XOSCCTRL.XOCSEL = OSCILLATOR_XOSCCTRL_XOSCSEL_XTAL_16KCLK;
	OSCILLATOR.XOSCFAIL.PLLFDEN = 1;
	OSCILLATOR.XOSCFAIL.XOSCFDEN = 1;
	
	OSCILLATOR.CTRL.XOSCEN = 1;
	
	
	
	uint16_t count = 0xFFFF;
	while(count -- )
	{
		if (OSCILLATOR.STATUS.XOSCRDY == 1)
		{
			mult_factor = 96/F_XOSC;
			osc_ready = 1;
			break;
		}
	}
	
	if (osc_ready == 1)
	{
		OSCILLATOR.PLLCTRL.PLLSRC = OSCILLATOR_PLLCTRL_PLLSRC_XOSC;
		OSCILLATOR.PLLCTRL.PLLFAC = mult_factor;
		OSCILLATOR.CTRL.PLLEN = 1;
		
		count = 0xFFFF;
		while(count--)
		{
			if (OSCILLATOR.STATUS.PLLRDY == 1)
			{
				osc_ready = 2;
				break;
			}
		}
	}
	
	if(osc_ready == 2)
	{
		DISABLE_IO_CCP();
		CLOCK.PSCTRL.PSADIV = CLOCK_PSCTRL_PSADIV_1;
		CLOCK.PSCTRL.PSBCDIV = CLOCK_PSCTRL_PSBCDIV_2_2;
		DISABLE_IO_CCP();
		CLOCK.CTRL.SCLKSEL = CLOCK_CTRL_SCLKSEL_PLL;  
		cpu_frequency = 24;
	}
	else
	{
		OSCILLATOR.CTRL.RC32MEN = 1;
		count = 0xFFFF;
		while(count--)
		{
			if (OSCILLATOR.STATUS.RC32MRDY == 1)
			{
				DISABLE_IO_CCP();
				CLOCK.PSCTRL.PSADIV = CLOCK_PSCTRL_PSADIV_1;
				CLOCK.PSCTRL.PSBCDIV = CLOCK_PSCTRL_PSBCDIV_1_1;
				
				DISABLE_IO_CCP();
				CLOCK.CTRL.SCLKSEL = CLOCK_CTRL_SCLKSEL_RC32MHZ;
				break;
			}
		}
	}
	 
	
	
}