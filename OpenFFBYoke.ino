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

#include "Config.h"
#include "QuadEncoder.h"
//#define ENCODER_OPTIMIZE_INTERRUPTS
//#include <Encoder.h>


//----------------------------------------- Options -------------------------------------------------------

cQuadEncoder YokeEncX;
//Encoder YokeEncX(0,1);

//--------------------------------------- Globals --------------------------------------------------------

s32 turn;
long position  = -999;

// The setup() function runs once each time the micro-controller starts
void setup()
{
	DEBUG_SERIAL.begin(115200);

	// init encoder 
	YokeEncX.Init(0,false);//ROTATION_MID - brWheelFFB.offset);
	//YokeEncX.write(0);
}

// Add the main program code into the continuous loop() function
void loop()
{
	turn = YokeEncX.Read();
	if(turn != position){
		DEBUG_SERIAL.println(turn);
		position = turn;
	}
	
	//delay(1000);

}

/*
Encoder knobLeft(5, 6);
Encoder knobRight(0, 1);

//   avoid using pins with LEDs attached

void setup() {
	Serial.begin(9600);
	Serial.println("TwoKnobs Encoder Test:");
}

long positionLeft  = -999;
long positionRight = -999;

void loop() {
	long newLeft, newRight;
	newLeft = knobLeft.read();
	newRight = knobRight.read();
	if (newLeft != positionLeft || newRight != positionRight) {
		Serial.print("Left = ");
		Serial.print(newLeft);
		Serial.print(", Right = ");
		Serial.print(newRight);
		Serial.println();
		positionLeft = newLeft;
		positionRight = newRight;
	}
	// if a character is sent from the serial monitor,
	// reset both back to zero.
	if (Serial.available()) {
		Serial.read();
		Serial.println("Reset both knobs to zero");
		knobLeft.write(0);
		knobRight.write(0);
	}
}
*/