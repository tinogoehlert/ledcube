/*
 * Effect.h
 *
 *  Created on: 30.03.2012
 *      Author: pueppi
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
};

extern Effect Effect1;

#endif /* EFFECT_H_ */
