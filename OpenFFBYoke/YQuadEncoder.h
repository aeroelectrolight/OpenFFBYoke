/* 
* QuadEncoder.h
*
* Created: 28/02/2020 21:25:04
* Author: ludom
*/


#ifndef __QUADENCODER_H__
#define __QUADENCODER_H__

#include <Arduino.h>

// Arduino Leonardo
#if defined(__AVR_ATmega32U4__) && !defined(CORE_TEENSY)
#define CORE_PIN0_INT		2
#define CORE_PIN1_INT		3
#define CORE_PIN2_INT		1
#define CORE_PIN3_INT		0
#endif

// for arduino leonardo
#define QUAD_ENC1_PIN_A		0
#define QUAD_ENC1_PIN_B		1
#define QUAD_ENC2_PIN_A		2
#define QUAD_ENC2_PIN_B		3

#define	ROTATION_DEG	900
#define	CPR				3960	// 4*990
#define MAX_ENCODER_ROTATION 3000
#define MAX_ENCODER_TRANSLATION 3000
int ROTATION_MAX = MAX_ENCODER_ROTATION;
#define	ROTATION_MID (ROTATION_MAX>>1)
int TRANSLATION_MAX = MAX_ENCODER_TRANSLATION;
#define	TRANSLATION_MID (TRANSLATION_MAX>>1)

class QuadEncoder
{
//variables
public:
	volatile b8 gIndexFoundX;
	volatile b8 gIndexFoundY;
	volatile u8 gLastStateX;
	volatile u8 gLastStateY;
	volatile s32 gPositionX;
	volatile s32 gPositionY;
protected:
private:

//functions
public:
	QuadEncoder();
	~QuadEncoder();
	void Init (s32 positionX, s32 positionY ,b8 pullups = false);
	s32 ReadX ();
	s32 ReadY ();
	void WriteX (s32 pos);
	void WriteY (s32 pos);
	void UpdateX ();
	void UpdateY ();
protected:
private:
	QuadEncoder( const QuadEncoder &c );
	QuadEncoder& operator=( const QuadEncoder &c );

}; //QuadEncoder

extern QuadEncoder gQuadEncoder;

#endif //__QUADENCODER_H__
