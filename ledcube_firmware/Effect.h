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

#ifndef EFFECT_H_
#define EFFECT_H_

#include <Arduino.h>

enum mod_e{
	MOD_SLIDE		= 0x21,
	MOD_ROTATE		= 0x22,
	MOD_SCROLL		= 0x23,
	MOD_DBG_COORD	= 0x24,
	MOD_DBG_NUMBER	= 0x25,
};


class Effect {
public:
	Effect();
	virtual ~Effect();
	void setspeed(unsigned int t);
	void setmod(byte mod);
	void render_matrix(uint32_t matrix);
	//effect functions
	void drawstring(const char* str,byte len);
	void smiley();
	void heartbeat();
	void infinitesquare();
	void bounce();
	void custom(byte* data);
	void rand();
	void music();
	void debug(byte number, byte z);
	void debug(byte x, byte y, byte z);
	void bubbles();
	/// render methods
	void renderfunc_rotate(uint32_t matrix);
	void renderfunc_slide(uint32_t matrix);
	void renderfunc_explode(uint32_t matrix);
private:
	/// attribs
	unsigned int _milli;
	byte		 _mod;
	byte		 _frame;
	byte		 _framecount;
	unsigned int _infiniteval;
	/// special audio stuff
	void getmic();
	void fft_generate();
	char _fft_img[128],_fft_data[128],_fft_last[64];
};

extern Effect Effect1;

#endif /* EFFECT_H_ */
