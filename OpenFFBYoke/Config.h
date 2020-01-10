#ifndef _CONFIG_H_
#define _CONFIG_H_

//------------------------------------- Options ----------------------------------------------------------

#define USE_PWM						// PWM output for drive torque input
#define USE_QUADRATURE_ENCODER		// Position Quadrature encoder
#define CALIBRATE_AT_INIT	1

#define DEBUG_SERIAL Serial // for debug serial

#define DEBUG_L // Debug for debug

//------------------------------------- Pins -------------------------------------------------------------

#define LED_PIN				13

#define	PWM_PIN				9 
#define	DIR_PIN				10
#define	REVERSE_DIR_PIN		11

//------------------------------------- Helpers -----------------------------------------------------
/*
#define	LCSYNC_LED_HIGH()		//digitalWriteFast(LCSYNC_LED_PIN,HIGH)
#define	LCSYNC_LED_LOW()		//digitalWriteFast(LCSYNC_LED_PIN,LOW)
#define	SYNC_LED_HIGH()			//digitalWriteFast(SYNC_LED_PIN,HIGH)
#define	SYNC_LED_LOW()			//digitalWriteFast(SYNC_LED_PIN,LOW)
*/
//------------------------------------- EEPROM Config -----------------------------------------------------

/*
#define PARAM_ADDR_VERSION			0
#define PARAM_ADDR_OFFSET			4
#define PARAM_ADDR_MAX_ROTATION		8

#define VERSION		0x00000005

#define GetParam(m_offset,m_data)	getParam((m_offset),(u8*)&(m_data),sizeof(m_data))
#define SetParam(m_offset,m_data)	setParam((m_offset),(u8*)&(m_data),sizeof(m_data))

//void SetDefaultConfig();
//u32 ReadEEPROMConfig();
*/
//------------------------------------- Main Config -----------------------------------------------------

#define CONTROL_FPS		500
#define CONTROL_PERIOD	2000

#define SEND_PERIOD		4000

#define CONFIG_SERIAL_PERIOD 50000

//------------------------------------- FFB Config -----------------------------------------------------

f32 configDamperGain = 1.0;		//ok
f32 configFrictionGain = 1.0;	//OK
f32 configConstantGain = 1.0;	//OK
f32 configSineGain = 1.0f;		//OK
f32 configSpringGain = 1.0f;	//OK
f32 configInertiaGain = 1.0f;	//OK
f32 configGeneralGain = 1.0f;	//OK
f32 configCenterGain = 1.0f;	//OK
f32 configStopGain = 1.0f;	//OK

int MM_MIN_MOTOR_TORQUE=200;
int MM_MAX_MOTOR_TORQUE=400;

#endif // _CONFIG_H_
