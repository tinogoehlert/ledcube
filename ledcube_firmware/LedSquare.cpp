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

#include "LedSquare.h"
#include "LedCube.h"

LedSquare::LedSquare() {
	// TODO Auto-generated constructor stub

}

LedSquare::~LedSquare() {
	// TODO Auto-generated destructor stub
}

void LedSquare::displaycenter(int z){

  LedCube::plane(z);
  LedCube::transfer(12);
}

void LedSquare::displaysmall(int z){
  LedCube::plane(z);
  LedCube::transfer(6);
  LedCube::transfer(7);
  LedCube::transfer(8);

  LedCube::transfer(11);
  LedCube::transfer(13);

  LedCube::transfer(16);
  LedCube::transfer(17);
  LedCube::transfer(18);
}

void LedSquare::displaybig(int z){
  LedCube::plane(z);
  LedCube::setpixel(0, 0);
  LedCube::setpixel(1, 0);
  LedCube::setpixel(2, 0);
  LedCube::setpixel(3, 0);
  LedCube::setpixel(4, 0);
  LedCube::setpixel(4, 1);
  LedCube::setpixel(4, 2);
  LedCube::setpixel(4, 3);
  LedCube::setpixel(4, 4);
  LedCube::setpixel(0, 4);
  LedCube::setpixel(1, 4);
  LedCube::setpixel(2, 4);
  LedCube::setpixel(3, 4);
  LedCube::setpixel(0, 1);
  LedCube::setpixel(0, 2);
  LedCube::setpixel(0, 3);

}
