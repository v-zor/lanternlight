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
#ifndef _DRAW_H_
#define _DRAW_H_

#include <SDL/SDL.h>

/*
NOTE: maker sure putpixel does not go beyond the screen surf
*/

namespace bessie
{

int putpixel(SDL_Surface *surface, int x, int y, Uint32 pixel);


}//namespace bessie
#endif
