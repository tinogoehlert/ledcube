/*
===========================================================================

ledcube_firm GPL Source Code
Copyright (C) 2012 Tino Göhlert, cmdrkeen.net.

This file is part of the ledcube_firm Source Code.

ledcube_firm is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

ledcube_firm Source Code is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with ledcube_firm Source Code.  If not, see <http://www.gnu.org/licenses/>.

===========================================================================
*/

#include "Arduino.h"
#include "ledcube.h"


#define MICRO 30

unsigned int decoderPins[] = {p0, p1, p2, p3, p4};
unsigned int cathodePins[] = {Z0, Z1, Z2, Z3, Z4};

LedCube::LedCube()
{

}

LedCube::~LedCube()
{

}

void LedCube::init()
{
	for(int i =0; i < DECODER_BITS; i++){
		pinMode(decoderPins[i], OUTPUT);
		digitalWrite(decoderPins[i], LOW);
	}
	for(int i = 0; i < LEDS_PER_ROW; i++){
		pinMode(cathodePins[i], OUTPUT);
		digitalWrite(cathodePins[i], LOW);
	}

	//enable decoders
	pinMode(pEN, OUTPUT);
	digitalWrite(pEN, HIGH);
}

void LedCube::transfer(int num)
{
	  int weight=1,pin=0;
	  num = constrain(num, 0, 24);

	  for(; pin < DECODER_BITS; weight*=2, pin++)
	    digitalWrite(decoderPins[pin] ,(num & weight) >> pin);

	  delayMicroseconds(MICRO);
}

void LedCube::draw(byte* matrix,byte y, byte mod)
{
	byte i = 0,z=4;
	for(;i<CUBESIZE;i++,z--){
		if(matrix[0+(i*CUBESIZE)] == 1)
			LedCube::setpixel(4,y,z);
		if(matrix[1+(i*CUBESIZE)] == 1)
			LedCube::setpixel(3,y,z);
		if(matrix[2+(i*CUBESIZE)] == 1)
			LedCube::setpixel(2,y,z);
		if(matrix[3+(i*CUBESIZE)] == 1)
			LedCube::setpixel(1,y,z);
		if(matrix[4+(i*CUBESIZE)] == 1)
			LedCube::setpixel(0,y,z);
	}
}

void LedCube::plane(byte z)
{
	int i = 0;
	  for(; i < LEDS_PER_ROW; i++){
	    if(i == z || z >= LEDS_PER_ROW){
	      digitalWrite(cathodePins[i], HIGH);
	    }else{
	       digitalWrite(cathodePins[i], LOW);
	    }
	  }
}

void LedCube::clear()
{
	int i = 0;
	  for(; i < LEDS_PER_ROW; i++){
	       digitalWrite(cathodePins[i], LOW);
	       transfer(0);

	  }
}

void LedCube::setpixel(byte x,byte y)
{
	transfer((y * LEDS_PER_ROW) + x);
}

void LedCube::setpixel(byte x,byte y,byte z)
{
	plane(z);
	transfer((y * LEDS_PER_ROW) + x);
}
