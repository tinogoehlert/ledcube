/*
 * LedSquare.h
 *
 *  Created on: 26.03.2012
 *      Author: pueppi
 */

#ifndef LEDSQUARE_H_
#define LEDSQUARE_H_

class LedSquare {
public:
	LedSquare();
	virtual ~LedSquare();
	static void displaycenter(int z);
	static void displaysmall(int z);
	static void displaybig(int z);
};

#endif /* LEDSQUARE_H_ */
