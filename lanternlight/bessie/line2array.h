/*
# Copyright (C) Johan Ceuppens 2010-2013
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
#ifndef RM_LINE2DRAW2_H
#define RM_LINE2DRAW2_H

#include <SDL.h>
#include<vector>

namespace bessie
{

class line2arrayPoint
{
	public:
	line2arrayPoint(int xx, int yy) { _x = xx; _y = yy; }
	virtual ~line2arrayPoint() {}

	int get_x() { return _x; }
	int get_y() { return _y; }

	private:
	int _x,_y;
};

std::vector<line2arrayPoint*> *line2array(int *x1, int *y1, int *x2, int *y2);

void line2array1Func(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed); 
void line2array2Func(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed); 
void line2array3Func(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed); 
void line2array4Func(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed); 
void line2array5Func(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed); 
void line2array6Func(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed); 
void line2array7Func(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed); 
void line2array8Func(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed); 
void line2arrayVerticalFunc(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed);


}//namespace bessie

#endif
