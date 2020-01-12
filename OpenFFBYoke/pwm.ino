// L.mercet 12/01/2020
// use PWM timer1 on pin 9 and 10 OCR1A and OCR1B

#include "Config.h"
#include <digitalWriteFast.h>

#ifdef USE_PWM

void InitPWM ()
{
	// Define pinMode for the pins and set the frequency for timer1.
	pinMode(DIR_PINA,OUTPUT);
	pinMode(REVERSE_DIR_PINA, OUTPUT);
	pinMode(PWM_PINA,OUTPUT);
	pinMode(DIR_PINB,OUTPUT);
	pinMode(REVERSE_DIR_PINB, OUTPUT);
	pinMode(PWM_PINB,OUTPUT);

#if defined(__AVR_ATmega168__)|| defined(__AVR_ATmega328P__) || defined(__AVR_ATmega32U4__)
	// Timer 1 configuration : prescaler: clockI/O / 1
	// outputs enabled, phase-correct PWM, top of 400
	// PWM frequency calculation : 16MHz / 1 (prescaler) / 2 (phase-correct) / 1000 (top) = 8 kHz
	// PWM frequency calculation : 16MHz / 1 (prescaler) / 2 (phase-correct) / 400 (top) = 20 kHz
	TCCR1A = 0b10100000;
	TCCR1B = 0b00010001;//b00010001;
	ICR1 = MM_MAX_MOTOR;
#endif
}

void setPWMDir (s16 torque, bool pin)		// torque between -PWM_TOP and +PWM_TOP
{
	u8 dir = 1,rev = 0;

 	torque = -torque;
	if (torque < 0)
	{
		torque = -torque;
		dir = 0; 
		rev = 1;
	}
	if (pin)
	{
		OCR1A = constrain(torque,0,MM_MAX_MOTOR_TORQUE - 10);
		digitalWriteFast(DIR_PINA,dir);
		digitalWriteFast(REVERSE_DIR_PINA, rev);
	}else{
		OCR1B = constrain(torque,0,MM_MAX_MOTOR_TORQUE - 10);
		digitalWriteFast(DIR_PINB,dir);
		digitalWriteFast(REVERSE_DIR_PINB, rev);
	}
	//DEBUG_SERIAL.println(temp);
}

void setPWM (s16 torque, bool pin)		// torque between -PWM_TOP and +PWM_TOP
{
	//torque = (torque + MM_MAX_MOTOR_TORQUE) >> 1;
	torque = constrain(torque,0,MM_MAX_MOTOR_TORQUE - 10);
	if (pin){
		OCR1A = torque;
	}else{
		OCR1B = torque;
	}
	
}

#endif
