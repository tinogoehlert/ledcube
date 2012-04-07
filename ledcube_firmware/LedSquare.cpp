/*
 * LedSquare.cpp
 *
 *  Created on: 26.03.2012
 *      Author: pueppi
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
