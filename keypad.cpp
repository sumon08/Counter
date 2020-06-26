/*
 * keypad.c
 *
 * Created: 6/26/2020 4:40:12 PM
 *  Author: Asus
 */ 


#include "keypad.h"


#include "xmega/gpio_def.h"

#define BUTTON_START_STOP			PORTD.IN.Bit2
#define BUTTON_ENTER				PORTD.IN.Bit4
#define BUTTON_UP					PORTD.IN.Bit5
#define BUTTON_DOWN					PORTD.IN.Bit3

#define BUTTON_START_STOP_DIR		PORTD.DIRCLR.Bit2
#define BUTTON_ENTER_DIR			PORTD.DIRCLR.Bit4
#define BUTTON_UP_DIR				PORTD.DIRCLR.Bit5
#define BUTTON_DOWN_DIR				PORTD.DIRCLR.Bit3

typedef enum
{
	BUTTON_STATE_UNKNOWN,
	BUTTON_PRESSING,
	BUTTON_PRESSED,
	BUTTON_RELEASING,
	BUTTON_RELEASED
}ButtonState;

typedef enum 
{
	KEY_MESSAGE_UNKNOWN,
	KEY_MESSAGE_ENTER_SETTING,
	KEY_MESSAGE_ENTER,
	KEY_MESSAGE_START_STOP,
	KEY_MESSAGE_UP,
	KEY_MESSAGE_DOWN
}KeyMessage;

typedef struct
{
	ButtonState state;
	uint16_t time_pressed;
}Button;

void InitKeypad()
{
	BUTTON_START_STOP_DIR = 1;
	BUTTON_ENTER_DIR = 1;
	BUTTON_UP_DIR = 1;
	BUTTON_DOWN_DIR = 1;
	
	
}

void KeypadHandler()
{
	if(BUTTON_START_STOP == 0)
	{
		if()
	}
}