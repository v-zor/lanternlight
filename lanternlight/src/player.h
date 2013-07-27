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
		int _x, _y;
		int _moving;
		// a vector containing the line points  for moving over
		//that line
		std::vector<bessie::line2arrayPoint*> *_movepoints;
		int _movepointsn;
		SDL_Surface *_surface;
};	

}//namespace lanternlight
#endif
