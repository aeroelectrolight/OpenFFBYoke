#ifndef _QUAD_ENCODER_H
#define _QUAD_ENCODER_H


// for arduino leonardo
#define QUAD_ENC1_PIN_A		0
#define QUAD_ENC1_PIN_B		1
#define QUAD_ENC2_PIN_A		2
#define QUAD_ENC2_PIN_B		3

#define	ROTATION_DEG	900	
#define	CPR				3960	// 4*990
#define MAX_ENCODER_ROTATION 9900
int ROTATION_MAX = MAX_ENCODER_ROTATION;
#define	ROTATION_MID	(ROTATION_MAX>>1)

//-----------------------------------------------------------------------------------------------

class cQuadEncoder
{
public:
	void Init (s32 positionX, s32 positionY ,b8 pullups = false);
	s32 ReadX ();
	s32 ReadY ();
	void WriteX (s32 pos);
	void WriteY (s32 pos);
	void UpdateX ();
	void UpdateY ();

private:
// 	volatile b8 mIndexFound;
// 	volatile u8 mLastState;
// 	volatile s32 mPosition;
};

extern cQuadEncoder gQuadEncoder;

#endif // _QUAD_ENCODER_H
