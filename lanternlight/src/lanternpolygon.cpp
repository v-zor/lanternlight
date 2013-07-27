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
	currentn = 0;
}

LanternPolygon::~LanternPolygon()
{

}

int LanternPolygon::closestline(int entityx, int entityy)
{
	int min = INT_MAX;
	int i = 0;
	for (std::vector<Line*>::iterator vi = _lines->begin(); vi != _lines->end(); vi++, i++) {
		if ((*vi)->distance(entityx,entityy) < min)
			min = i;
	}
}

} //namespace lanternlight
