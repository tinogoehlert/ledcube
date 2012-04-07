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


/*
 * 		5x5 bitmaps packed in unsigned ints
 *
 */

#ifndef BITMAPS_H_
#define BITMAPS_H_

#include "Arduino.h"


uint32_t ascii_map[36] =
{
	15324974,14815398,32570911,		//0,1,2
	33062431,8682793,33061951,		//3,4,5
	33094719,17318431,33095231,		//6,7,8
	33062463,						//9
	18859332,16317999,32539711,		//A,B,C
	16303663,32570431,1113151,		//D,E,F
	33092671,18415153,14815374,		//G,H,I
	15254047,9604265,32539681,		//J,K,L
	18405233,18667121,15255086,		//M,N,O
	1113663,32810287,18153023,		//P,Q,R
	33061951,4329631,33080881,		//S,T,U
	4539953,18732593,18157905,		//V,W,X
	4329809,32575775				//Y,Z
};

/// SMILEYS

byte smiley_lol[25] =  {0,0,0,0,0,
						0,1,0,1,0,
						0,0,0,0,0,
						1,0,0,0,1,
						0,1,1,1,0};

/// MISK

byte quake_1[25] =     {0,1,0,1,0,
						1,0,1,0,1,
						1,0,0,0,1,
						0,1,0,1,0,
						0,0,1,0,0};


#endif /* BITMAPS_H_ */
