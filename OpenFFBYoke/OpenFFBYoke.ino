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

cQuadEncoder YokeEnc;
//Encoder YokeEncX(0,1);

//--------------------------------------- Globals --------------------------------------------------------

long turnX, turnY;


// The setup() function runs once each time the micro-controller starts
void setup()
{
	DEBUG_SERIAL.begin(115200);

	// init encoder 
	YokeEnc.Init(0,0,false);//ROTATION_MID - brWheelFFB.offset);
}

// Add the main program code into the continuous loop() function
void loop()
{
	long position = YokeEnc.ReadX();
	if(position != turnX){
		DEBUG_SERIAL.print("X : ");
		DEBUG_SERIAL.println(position);
		turnX = position;
	}
	position = YokeEnc.ReadY();
	if(position != turnY){
		DEBUG_SERIAL.print("Y : ");
		DEBUG_SERIAL.println(position);
		turnY = position;
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
		}
	}
	//delay(1000);

}
