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
#ifndef PLAYER_H
#define PLAYER_H

#include <SDL/SDL.h>
#include<iostream>
#include "line2array.h"

namespace lanternlight
{

class Player
{
	public:
	Player(int xx, int yy);
	virtual ~Player();

	void setmoving(int b);
	void moveto(int xx, int yy);
	void update();
	void draw(SDL_Surface *screen);

	protected:
		int _x, _y, _dk;
		int _moving;
		// a vector containing the line points  for moving over
		//that line
		std::vector<bessie::line2arrayPoint*> *_movepoints;
		int _movepointsn;
		SDL_Surface *_surface;
};	

}//namespace lanternlight
#endif
