/*
 * xmega_protection.h
 *
 * Created: 6/21/2020 12:31:04 AM
 *  Author: Asus
 */ 


#ifndef XMEGA_PROTECTION_H_
#define XMEGA_PROTECTION_H_

#include <avr/io.h>

#define DISABLE_LPM_SPM_CCP()			CCP = 0x9D
#define DISABLE_IO_CCP()				CCP = 0xD8

#define IS_LPM_SPM_NOT_PROTECTED()		CCP & (1 << 1)
#define IS_IO_NOT_PROTECTED()			CCP & (1 << 0)

#endif /* XMEGA_PROTECTION_H_ */