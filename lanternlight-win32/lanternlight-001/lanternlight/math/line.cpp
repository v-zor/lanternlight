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
#include "../include/SDL.h"
#include<iostream>
#include<cmath>
#include "polygon.h"
#include "line.h"

namespace lanternlight
{

template<typename S>
Line<S>::Line(int x1, int y1, int x2, int y2)
{
	_x1 = x1;
	_y1 = y1;
	_x2 = x2;
	_y2 = y2;

	_linetype->set(quadrant());
}

template<typename S>
Line<S>::~Line()
{}


template<typename S>
LineType::LINETYPE Line<S>::quadrant()
{
	//FIX calculate quadrant from x1,y1 and x2,y2
	//left upper lines for collide, first quadrant
	if (_x1 <= _x2 && _y1 <= _y2)
		return LineType::QUADRANT1LINE;
	//right upper lines for collide, second quadrant
	if (_x1 <= _x2 && _y1 >= _y2)
		return LineType::QUADRANT2LINE;
	//right down lines for collide, third quadrant
	if (_x1 >= _x2 && _y1 <= _y2)
		return LineType::QUADRANT3LINE;
	//left down lines for collide, fourth quadrant
	if (_x1 >= _x2 && _y1 >= _y2)
		return LineType::QUADRANT4LINE;

	return LineType::NOLINE;
}

template<typename S>
Point *Line<S>::norm()
{
	int dx = _x2 - _x1;
	int dy = _y2 - _y1;

	//normals are :
	//-dx, dy and dx, -dy
	return (new Point(dx,dy));
}

/****
template<typename S>
float Line<S>::norm()
{
	return std::sqrt((_x2 + _x1) * (_x2 + _x1) + (_y2 + _y1) * (_y2 + _y1));
}
****/
template<typename S>
float Line<S>::crossproduct(Line *ln)
{
	/////////return (this->norm()  * ln->norm() * sin(3.14152829/2));
	return 0.0;//FIX
}

template<typename S>
float Line<S>::distance(int entityx, int entityy)
{
	//FIX normal to line
	return 100;	

}

template class Line<LineType *>;

} //namespace lanternlight
