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
#ifndef LINE_H
#define LINE_H

#include <SDL/SDL.h>

namespace lanternlight
{

class Line
{
	public:
	Line(int x1, int y1, int x2, int y2);
	virtual ~Line();
	float distance(int entityx, int entityy);

	protected:

	private:
	int _x1,_y1,_x2,_y2;
};	

}//namespace lanternlight
#endif
