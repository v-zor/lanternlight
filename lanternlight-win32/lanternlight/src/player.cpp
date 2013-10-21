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
#include "player.h"
#include "../bessie/line2array.h"
#include "../bessie/ImgSys.h"

namespace lanternlight
{

Player::Player(int xx, int yy)
{
	_x = xx;
	_y = yy;
	bessie::image::ImgSys imgsys;
	//FIX imgsys.load("./pics/tile1grass.bmp",&_surface);
	_movepointsn = 0;
	_moving = 0;

	_dk = 6;

}

Player::~Player()
{}

void Player::setmoving(int b)
{
	_moving = b;
	_movepointsn = 0;
}

void Player::moveto(int xx, int yy)
{
	_movepoints = bessie::line2array(&_x,&_y,&xx,&yy);
}

void Player::update()
{
	if (_moving) {
		if (_movepointsn >= _movepoints->size()) {
			setmoving(0);
			return;
		}

		//FIX _x = (*_movepoints)[_movepointsn]->get_x();
		//FIX _y = (*_movepoints)[_movepointsn]->get_y();
		_movepointsn+=_dk;
	}
}
/***FIX
void Player::draw(SDL_Surface *screen)
{
	SDL_Rect r;
	r.x = _x;
	r.y = _y;
	r.w = 800;//FIX
	r.h = 600;
	//FIX SDL_BlitSurface(_surface, NULL,screen,&r);
}
***/
} //namespace lanternlight
