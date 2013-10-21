/*
# Copyright (C) Johan Ceuppens 2013
# Redistribution and use in source and binary forms are permitted
# provided that the above copyright notice and this paragraph are
# duplicated in all such forms and that any documentation,
# advertising materials, and other materials related to such
# distribution and use acknowledge that the software was developed
# by the silverhawk.  The name of the
# silverhawk may not be used to endorse or promote products derived
# from this software without specific prior written permission.
# THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
# IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.

# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 2 of the License, or
# (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef LINE_H
#define LINE_H

#include <SDL/SDL.h>
#include "line2array.h"

namespace lanternlight
{

class Point
{
	public:
		Point(int xx, int yy) { _x = xx; _y = yy; }
		int _x, _y;
};

enum LINETYPE { QUADRANT1LINE = 100, QUADRANT2LINE = 200, QUADRANT3LINE = 300, QUADRANT4LINE = 400, NOLINE = 500,}; 

class LineType
{
	public:
		LINETYPE _id;

	LINETYPE operator()() { return _id; }

};

template<typename S>
class Line
{
	public:
	Line(int x1, int y1, int x2, int y2);
	virtual ~Line();
	Point *norm();
	///float norm();
	float crossproduct(Line *ln);
	float distance(int entityx, int entityy);

	int get_x1() { return _x1; }
	int get_y1() { return _y1; }
	int get_x2() { return _x2; }
	int get_y2() { return _y2; }

	LINETYPE quadrant();

	protected:

	private:
	LineType _linetype;
	int _x1,_y1,_x2,_y2;
};	

}//namespace lanternlight
#endif
