/*
# Copyright (C) Johan Ceuppens 2010-2013
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
#include"util.h"
#include<cmath>

namespace bessie
{
	
const char *cs(std::string s)
{
	return s.c_str();
}


int distanceint(int x1, int y1, int px, int py)
{

	return (int)(std::sqrt((px - x1)*(px - x1) + (py - y1)*(py - y1)));

}

}
