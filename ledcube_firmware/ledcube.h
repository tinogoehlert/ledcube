/*
===========================================================================

ledcube_firm GPL Source Code
Copyright (C) 2012 Tino G�hlert, cmdrkeen.net.

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

#ifndef LEDCUBE_H_
#define LEDCUBE_H_

#include "Arduino.h"

//cube constants
#define CUBESIZE 5
#define DECODER_BITS 5
#define LEDS_PER_ROW 5

//decoder enable
#define pEN 12

// pins to decoders for anodes
#define p0 4
#define p1 3
#define p2 2
#define p3 6
#define p4 5

// pins for cathode control
#define Z0 11
#define Z1 10
#define Z2 9
#define Z3 8
#define Z4 7

//potentiometer pin, for delay
#define POT_PIN A0

//PCB utility jumpers
#define j1 A5
#define j2 A4
#define j3 A3
#define j4 A2
#define j5 A1

#define HIGH 0x1
#define LOW  0x0

#define BIT(target,bit) ((target & (1UL << bit)) >> bit)

class LedCube
{
public:
	LedCube();
	~LedCube();

	//primitives
	static void init();
	static void transfer(int num);
	static void plane(byte z);
	static void clear();
	static void setpixel(byte x,byte y);
	static void setpixel(byte x,byte y,byte z);
	static void draw(byte* matrix,byte j, byte mod);
private:
	static byte frame;
};

#endif /* LEDS_H_ */
