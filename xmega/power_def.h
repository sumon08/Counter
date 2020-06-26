/*
 * power_dev.h
 *
 * Created: 6/23/2020 9:31:48 AM
 *  Author: Asus
 */ 


#ifndef POWER_DEV_H_
#define POWER_DEV_H_


typedef struct
{
	reg8_t SEN : 1;
	reg8_t SMODE : 3;
}Sleep_t;


typedef struct
{
	struct
	{
		reg8_t DMA			: 1;
		reg8_t EVSYS		: 1;
		reg8_t RTC			: 1;
		reg8_t EBI			: 1;
		reg8_t AES			: 1;
		reg8_t RES			: 1;
		reg8_t USB			: 1;
	}PRGEN;
	
	
	struct 
	{
		reg8_t AC			: 1;
		reg8_t ADC			: 1;
		reg8_t DAC			: 1;
	}PRPA;
	
	struct
	{
		reg8_t AC			: 1;
		reg8_t ADC			: 1;
		reg8_t DAC			: 1;
	}PRPB;
	
	struct
	{
		reg8_t TC0			: 1;
		reg8_t TC1			: 1;
		reg8_t HIRES		: 1;
		reg8_t SPI			: 1;
		reg8_t USART0		: 1;
		reg8_t USART1		: 1;
		reg8_t TWI			: 1;
	}PRPC;
	
	struct
	{
		reg8_t TC0			: 1;
		reg8_t TC1			: 1;
		reg8_t HIRES		: 1;
		reg8_t SPI			: 1;
		reg8_t USART0		: 1;
		reg8_t USART1		: 1;
		reg8_t TWI			: 1;
	}PRPD;
	
	struct
	{
		reg8_t TC0			: 1;
		reg8_t TC1			: 1;
		reg8_t HIRES		: 1;
		reg8_t SPI			: 1;
		reg8_t USART0		: 1;
		reg8_t USART1		: 1;
		reg8_t TWI			: 1;
	}PRPE;
	
	struct
	{
		reg8_t TC0			: 1;
		reg8_t TC1			: 1;
		reg8_t HIRES		: 1;
		reg8_t SPI			: 1;
		reg8_t USART0		: 1;
		reg8_t USART1		: 1;
		reg8_t TWI			: 1;
	}PRPF;
	
}PowerReduction_t;



#define SLEEP_CTRL_SMODE_IDLE		0x00
#define SLEEP_CTRL_SMODE_PDOWN		0x02
#define SLEEP_CTRL_SMODE_PSAVE		0x03
#define SLEEP_CTRL_SMODE_STDBY		0x06
#define SLEEP_CTRL_SMODE_ESTDBY		0x07


#ifdef SLEEP
#undef SLEEP
#endif
#define SLEEP		 (*((Sleep_t *) 0x0048))

#ifdef POWER
#undef POWER
#endif // POWER

#define POWER		(*((PowerReduction_t *) 0x0070))

#endif /* POWER_DEV_H_ */