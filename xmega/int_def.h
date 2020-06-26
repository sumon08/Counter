/*
 * int_def.h
 *
 * Created: 6/24/2020 11:07:31 PM
 *  Author: Asus
 */ 


#ifndef INT_DEF_H_
#define INT_DEF_H_



typedef struct
{
	struct
	{
		reg8_t LOLVLEX : 1;
		reg8_t MEDLVLEX : 1;
		reg8_t HILVLEX : 1;
		reg8_t RES : 4;
		reg8_t NMIEX : 1;
	}STATUS;
	
	reg8_t INTPRI;
	
	struct 
	{
		reg8_t LOLVLEN : 1;
		reg8_t MEDLVLEN : 1;
		reg8_t HILVLEN : 1;
		reg8_t RES : 3;
		reg8_t IVSEL : 1;
		reg8_t RREN : 1;
	}CTRL;
	
}Pmic_t;




#define INTERUPT_LEVEL_OFF		0x00
#define INTERUPT_LEVEL_LO		0x01
#define INTERUPT_LEVEL_MED		0x02
#define INTERUPT_LEVEL_HI		0x03


#define PMIC		(*((Pmic_t *) 0x00A0))

#endif /* INT_DEF_H_ */