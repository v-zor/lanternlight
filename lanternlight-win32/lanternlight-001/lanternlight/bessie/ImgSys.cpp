/*
# Copyright (C) Johan Ceuppens 2010-2013
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
#include "ImgSys.h"
#include "util.h"

namespace bessie
{
namespace image
{

using namespace std;

int ImgSys::load(string filename, SDL_Surface **surface)
{
	if ( !filename.length() ) { *surface = NULL; return(-1); }
	if ( filein(filename, surface) && surface != NULL) { return(0); }
	//never reached.
	return -1;
}
/***
int ImgSys::load(string filename, map<std::string, SDL_Surface *> *surfaces)
{
	SDL_Surface *surface = (SDL_Surface *)0;
	if ( !filename.length() ) { delete surface; return(-1); } 
	if ( filein(filename, &surface) < 0 || surface == NULL ) { return(-1); }

	(*surfaces)[filename] = surface;
	//list<SDL_Surface *>::iterator vi;
	//for (vi = surfaces->begin(); vi != surfaces->end(); vi++)
	//	;

	//--vi;
	//memcpy ((*vi), surface, sizeof(surface));
			
	return 0;
}
***/
int ImgSys::reload(string filename, SDL_Surface **surface)
{
	if ( !*surface ) { SDL_FreeSurface(*surface); *surface = NULL; }
	filein(filename, surface);
	return(0);
}

int ImgSys::filein(string filename, SDL_Surface **surface)
{
	SDL_Surface *ts = SDL_LoadBMP(const_cast<char*>(bessie::cs(filename)));//cs returns c_str
	 *surface = SDL_DisplayFormat(ts);
	SDL_SetColorKey (*surface,SDL_SRCCOLORKEY,_colorkey);
	return(0);
}

}
}
