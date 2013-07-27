/*
# Copyright (C) Johan Ceuppens 2013
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
#include <SDL/SDL.h>
#include<iostream>
#include "util.h"
#include "lanternpolygon.h"

namespace lanternlight
{

LanternPolygon::LanternPolygon() : Polygon()
{
	_currentn = -1;
}

LanternPolygon::~LanternPolygon()
{

}

int LanternPolygon::initclosestline(int entityx, int entityy)
{
	int min = INT_MAX;
	int index = 0;
	for (std::vector<Line<LineType> *>::iterator vi = _lines->begin(); vi != _lines->end(); vi++, index++) {
		if ((*vi)->distance(entityx,entityy) < min)
			min = (*vi)->distance(entityx, entityy);
			_currentn = index;
	}

	if (min == INT_MAX)
		return -1;
	else
		return _currentn;

}

/*
 * NOTE : 
 * 
 * Note that this function rotates and does not need a double linked list
 * the normal _to_ the current line can be over 90/180/270 degrees,
 * thus the change in current line can be made
 */
int LanternPolygon::go(int entityx, int entityy)
{

	Line<LineType> *currentline = (*_lines)[_currentn];

	Line<LineType> *ln1 = new Line<LineType>(currentline->get_x1(), currentline->get_y1(),
				entityx, entityy);
	Line<LineType> *ln2 = new Line<LineType>(currentline->get_x2(), currentline->get_y2(),
				entityx, entityy);

	//FIX dynamic_cast
	switch(currentline->quadrant()) {
	case LEFTLINE:{
		switch (ln1->quadrant()) {
		case LEFTLINE:{
			++_currentn %= _lines->size();
			break;
		}
		break;
	}
	}
	case RIGHTLINE: 
	case UPLINE: 
	case DOWNLINE: 
	default:
		break;
	}

/*****
	Line<LineType> *currentline = (*_lines)[_currentn];

	if (entityx > currentline->get_x2() && entityy > currentline->get_y2()) {
		++_currentn %= _lines->size();
	} else if (entityx > currentline->get_x2() && entityy > currentline->get_y1()) {

			

	} else if (entityx < currentline->get_x1() && entityy < currentline->get_y1()) {
		--_currentn %= _lines->size();
	}

	return _currentn;
******/

	return 0;

}

} //namespace lanternlight
