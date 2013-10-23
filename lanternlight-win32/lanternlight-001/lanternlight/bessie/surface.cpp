/*
# Copyright (C) Johan Ceuppens 2010--2013
# Redistribution and use in source and binary forms are permitted
# provided that the above copyright notice and this paragraph are
# duplicated in all such forms and that any documentation,
# advertising materials, and other materials related to such
# distribution and use acknowledge that the software was developed
# by the Johan Ceuppens.  The name of the
# Johan Ceuppens may not be used to endorse or promote products derived
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
#include "surface.h"
#include "util.h"

#include <iostream>

namespace bessie
{
namespace image
{

template<typename S>
Surface<S>::Surface()
{
	_surface = NULL;
}

template<typename S>
Surface<S>::~Surface()
{
	//FIX if (_surface != NULL) ;
}

template<typename S>
int Surface<S>::load(string filename)
{
	if ( !filename.length() ) { _surface = NULL; return(-1); }
	filein(filename);
	return 0;
}

template<typename S>
int Surface<S>::filein(string filename)
{
	S ts = SDL_LoadBMP(filename.c_str());
	_surface = SDL_DisplayFormat(ts);
	SDL_FreeSurface(ts);
	std::cout<<"filen="<<filename.c_str()<<std::endl;
	//FIX SDL_SetColorKey (_surface,SDL_SRCCOLORKEY,_colorkey);
	return 0;
}

template<typename S>
S& Surface<S>::get()
{
	return _surface;
}

template class Surface<SDL_Surface *>;
}
}
