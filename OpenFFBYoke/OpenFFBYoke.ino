/*
    Name:       OpenFFBYoke
    Created:	09/01/2020 13:52:58
    Author:     Ludovic Mercet 
	
	an Force Feedback Yoke base on Force Feedback Wheel firmware
	hardware : Arduino Leonardo
	
	Copyright 2015  Etienne Saint-Paul  (esaintpaul [at] gameseed [dot] fr)
	Copyright 2017  Fernando Igor  (fernandoigor [at] msn [dot] com)
	Copyright 2020  Ludovic Mercet

Permission to use, copy, modify, distribute, and sell this
software and its documentation for any purpose is hereby granted
without fee, provided that the above copyright notice appear in
all copies and that both that the copyright notice and this
permission notice and warranty disclaimer appear in supporting
documentation, and that the name of the author not be used in
advertising or publicity pertaining to distribution of the
software without specific, written prior permission.

The author disclaim all warranties with regard to this
software, including all implied warranties of merchantability
and fitness.  In no event shall the author be liable for any
special, indirect or consequential damages or any damages
whatsoever resulting from loss of use, data or profits, whether
in an action of contract, negligence or other tortious action,
arising out of or in connection with the use or performance of
this software.
*/

#include "ffb.h"
#include "ffb_pro.h"

#include "Config.h"
#include "QuadEncoder.h"

#include <USBDesc.h>

u32 now_micros = micros();

//----------------------------------------- Options -------------------------------------------------------

cQuadEncoder YokeEnc;

//--------------------------------------- Globals --------------------------------------------------------

cFFB gFFB;
BRFFB brWheelFFB;

//long ailerons, elevator;
u32 last_refresh;
s16 ailerons,elevator,trimAilerons,trimElevator, buttons;


// The setup() function runs once each time the micro-controller starts
void setup()
{
	DEBUG_SERIAL.begin(115200);
	while (!Serial) {
		; // wait for serial port to connect. Needed for native USB 
	}
	// init encoder 
	YokeEnc.Init(0,0,false);//
	// init pwm
	InitPWM();
	setPWM(0,false);
	
	last_refresh = micros();
}

// Add the main program code into the continuous loop() function
void loop()
{
	now_micros = micros();
	
	if ((now_micros - last_refresh) >= CONTROL_PERIOD){
		//
		last_refresh = now_micros;
		//
		long position = YokeEnc.ReadX();
		if(position != ailerons){
			DEBUG_SERIAL.print("X : ");
			DEBUG_SERIAL.println(position);
			ailerons = position;
		}
		position = YokeEnc.ReadY();
		if(position != elevator){
			DEBUG_SERIAL.print("Y : ");
			DEBUG_SERIAL.println(position);
			elevator = position;
		}
		elevator = constrain(elevator,0,4000);
		SendInputReport((s16)ailerons, (u16)elevator, (u16)trimAilerons, (u16)trimElevator, (u16)buttons);
		//test pwm
		setPWMDir(ailerons,false);
	}
		
	if (DEBUG_SERIAL.available())
	{
		u8 c = DEBUG_SERIAL.read();
		switch(c){
			case 'X':
				YokeEnc.WriteX(0);
				break;
			case 'Y':
				YokeEnc.WriteY(0);
				break;
			case 't':
				YokeEnc.WriteX(0);
				break;
			case 'r':
				YokeEnc.WriteY(0);
				break;
		}
	}
}
