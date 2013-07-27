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
#include "player.h"
#include "line2array.h"
#include "ImgSys.h"

namespace lanternlight
{

Player::Player(int xx, int yy)
{
	_x = xx;
	_y = yy;
	bessie::image::ImgSys imgsys;
	imgsys.load("./pics/tile1grass.bmp",&_surface);
	_movepointsn = 0;
	_moving = 0;
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

		_x = (*_movepoints)[_movepointsn]->get_x();
		_y = (*_movepoints)[_movepointsn]->get_y();
		_movepointsn++;
	}
}

void Player::draw(SDL_Surface *screen)
{
	SDL_Rect r;
	r.x = _x;
	r.y = _y;
	r.w = 800;//FIX
	r.h = 600;
	SDL_BlitSurface(_surface, NULL,screen,&r);
}

} //namespace lanternlight
