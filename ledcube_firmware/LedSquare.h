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
