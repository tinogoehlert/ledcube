/*
 * Effect.cpp
 *
 *  Created on: 30.03.2012
 *      Author: pueppi
 */



#include "Effect.h"
#include "bitmaps.h"
#include "LedCube.h"
#include "LedSquare.h"

byte anim_rotate[4][5] = {
		{2,2,2,2,2},
		{4,3,2,1,0},
		{2,2,2,2,2},
		{0,1,2,3,4}
};

Effect Effect1;

Effect::Effect() {
	this->_milli  = 100;
}

Effect::~Effect() {

}

void Effect::setmod(byte mod)
{
	switch(this->_mod){
		case MOD_ROTATE:
			_framecount = 5;
			break;
		case MOD_SLIDE:
			_framecount = 5;
			break;
		default:
			_framecount = 5;
			break;
		}

	this->_mod = mod;
}

void Effect::debug(byte number, byte z)
{
	LedCube::plane(z);
	LedCube::transfer(number);
}

void Effect::debug(byte x, byte y, byte z)
{
	LedCube::setpixel(x,y,z);
}

void Effect::setspeed(unsigned int t)
{
	this->_milli  = t;
}
void Effect::drawstring(const char* str,byte len)
{
	unsigned int milli = this->_milli + 1;
	unsigned long t = millis();

	for(byte i = 0;i<len;i++){
		for(_frame=0; _frame < _framecount; t = millis(), _frame++){
				while(millis() < t + milli){
				if(str[i] == ' '){
					LedCube::clear();
					continue;
				}
				if(str[i] > 47 && str[i] < 58){
					render_matrix(ascii_map[str[i]-48]);
					continue;
				}else if(str[i] > 64 && str[i] < 91){
					render_matrix(ascii_map[str[i]-55]);
					continue;
				}
			}
		}
	}
}

void Effect::render_matrix(uint32_t matrix)
{
	switch(this->_mod){
	case MOD_ROTATE:
		this->renderfunc_rotate(matrix);
		break;
	case MOD_SLIDE:
		this->renderfunc_slide(matrix);
		break;
	default:
		break;
	}
}

void Effect::renderfunc_slide(uint32_t matrix)
{
	byte i = 0,z=4;
		for(;i<CUBESIZE;i++,z--){
			byte x=CUBESIZE;
			while(x>0){
				if(BIT(matrix,((x-1)+(i*CUBESIZE))) == 1)
					LedCube::setpixel((x-1),_frame,z);
				x--;
			}
		}
}

void Effect::renderfunc_rotate(uint32_t matrix)
{
	byte i = 0,z=4;
	switch(_frame){
	case 0:
		for(;i<CUBESIZE;i++,z--){
				if(BIT(matrix,(4+(i*CUBESIZE))) == 1)
					LedCube::setpixel(4,2,z);
				if(BIT(matrix,(3+(i*CUBESIZE))) == 1)
					LedCube::setpixel(3,2,z);
				if(BIT(matrix,(2+(i*CUBESIZE))) == 1)
					LedCube::setpixel(2,2,z);
				if(BIT(matrix,(1+(i*CUBESIZE))) == 1)
					LedCube::setpixel(1,2,z);
				if(BIT(matrix,(0+(i*CUBESIZE))) == 1)
					LedCube::setpixel(0,2,z);
			}
		break;
	case 1:
		for(;i<CUBESIZE;i++,z--){
				if(BIT(matrix,(4+(i*CUBESIZE))) == 1)
					LedCube::setpixel(4,4,z);
				if(BIT(matrix,(3+(i*CUBESIZE))) == 1)
					LedCube::setpixel(3,3,z);
				if(BIT(matrix,(2+(i*CUBESIZE))) == 1)
					LedCube::setpixel(2,2,z);
				if(BIT(matrix,(1+(i*CUBESIZE))) == 1)
					LedCube::setpixel(1,1,z);
				if(BIT(matrix,(0+(i*CUBESIZE))) == 1)
					LedCube::setpixel(0,0,z);
			}
		break;
	case 2:
		for(;i<CUBESIZE;i++,z--){
				if(BIT(matrix,(4+(i*CUBESIZE))) == 1)
					LedCube::setpixel(2,4,z);
				if(BIT(matrix,(3+(i*CUBESIZE))) == 1)
					LedCube::setpixel(2,3,z);
				if(BIT(matrix,(2+(i*CUBESIZE))) == 1)
					LedCube::setpixel(2,2,z);
				if(BIT(matrix,(1+(i*CUBESIZE))) == 1)
					LedCube::setpixel(2,1,z);
				if(BIT(matrix,(0+(i*CUBESIZE))) == 1)
					LedCube::setpixel(2,0,z);
			}
		break;
	case 3:
		for(;i<CUBESIZE;i++,z--){
				if(BIT(matrix,(4+(i*CUBESIZE))) == 1)
					LedCube::setpixel(4,0,z);
				if(BIT(matrix,(3+(i*CUBESIZE))) == 1)
					LedCube::setpixel(3,1,z);
				if(BIT(matrix,(2+(i*CUBESIZE))) == 1)
					LedCube::setpixel(2,2,z);
				if(BIT(matrix,(1+(i*CUBESIZE))) == 1)
					LedCube::setpixel(1,3,z);
				if(BIT(matrix,(0+(i*CUBESIZE))) == 1)
					LedCube::setpixel(0,4,z);
			}
		break;
	case 4:
		for(;i<CUBESIZE;i++,z--){
				if(BIT(matrix,(4+(i*CUBESIZE))) == 1)
					LedCube::setpixel(0,2,z);
				if(BIT(matrix,(3+(i*CUBESIZE))) == 1)
					LedCube::setpixel(1,2,z);
				if(BIT(matrix,(2+(i*CUBESIZE))) == 1)
					LedCube::setpixel(2,2,z);
				if(BIT(matrix,(1+(i*CUBESIZE))) == 1)
					LedCube::setpixel(3,2,z);
				if(BIT(matrix,(0+(i*CUBESIZE))) == 1)
					LedCube::setpixel(4,2,z);
			}
		break;
	}

}

void Effect::renderfunc_explode(uint32_t matrix)
{

}

void Effect::smiley()
{
	unsigned int milli = this->_milli + 1;
	unsigned long t = millis();

	for(byte y=0; y < CUBESIZE; t = millis(), y++){
	    while(millis() < t + milli){
	 		LedCube::draw(smiley_lol,y,this->_mod);
		}
	}
}

void Effect::heartbeat()
{
	unsigned int milli = this->_milli + 1;
	unsigned long t = millis();

	for(byte y=0; y < CUBESIZE; t = millis(), y++){
	    while(millis() < t + milli){
	 		LedCube::draw(quake_1,y,0);
		}
	}
}

void Effect::custom(byte* data)
{
	unsigned int milli = this->_milli + 1;
	unsigned long t = millis();

	for(byte y=0; y < CUBESIZE; t = millis(), y++){
	    while(millis() < t + milli){
	 		LedCube::draw(data,y,0);
		}
	}
}

void Effect::infinitesquare()
{
	unsigned long t = millis();
	int i;
	for(i = 0; true ;t = millis(), i++){
		unsigned int milli = this->_milli + 1;
	    while(millis() < t + milli){
	    	LedSquare::displaycenter(((i+2)%LEDS_PER_ROW));
	    	LedSquare::displaysmall(((i+1)%LEDS_PER_ROW));
	    	LedSquare::displaybig(((i  )%LEDS_PER_ROW));
	    }
	}
}



void Effect::bounce()
{
	  unsigned int milli = this->_milli + 1;

	   unsigned long t = millis();

	  for(int z = -2; z < LEDS_PER_ROW; t = millis(), z++){
	     while(millis() < t + milli){
	       LedSquare::displaycenter(constrain(z+2, 0, 4));
	       LedSquare::displaysmall(constrain(z+1, 0, 4));
	       LedSquare::displaybig(constrain(z  , 0, 4));
	     }
	  }

	  t = millis();
	  for(int z = 4; z > -3; t = millis(), z--){
	     while(millis() < t + milli){
	    	 LedSquare::displaybig(constrain(z+2, 0, 4));
	    	 LedSquare::displaysmall(constrain(z+1, 0, 4));
	    	 LedSquare::displaycenter(constrain(z  , 0, 4));
	     }
	  }
}

void Effect::rand()
{
	LedCube::plane(random(5));
	LedCube::transfer(random(25));
	delay(this->_milli);
}

void Effect::bubbles()
{
	byte x = random(5),y=random(5);
	for(byte z=0;z<5;z++){
			LedCube::setpixel(x,y,z);
			if(this->_milli > 1)
				delay(this->_milli/2);
	}
	delay(this->_milli);
}
