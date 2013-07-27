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
#ifndef LANTERNPOLYGON_H
#define LANTERNPOLYGON_H

#include <SDL/SDL.h>
#include<vector>
#include "polygon.h"

namespace lanternlight
{

class LanternPolygon : public Polygon
{
	public:
	LanternPolygon();
	virtual ~LanternPolygon();
	int initclosestline(int entityx, int entityy);
	int go(int px, int py);

	protected:
	int _currentn;
	std::vector<Line<LineType> *>::iterator _linesiter;


};	

}//namespace lanternlight
#endif
