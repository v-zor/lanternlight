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
#include <SDL/SDL.h>
#include<iostream>
#include "player.h"
#include "line2array.h"
#include "ImgSys.h"

int main(int argc, char *argv[])
{

	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Surface *screen = SDL_SetVideoMode(800,600,32,SDL_DOUBLEBUF|SDL_HWSURFACE);

	lanternlight::Player player(100,100);

	SDL_Surface *blanksurface;
	bessie::image::ImgSys imgsys;
	imgsys.set_colorkey(0xff);
	imgsys.load("./pics/blank-800x600.bmp", &blanksurface);
	SDL_Rect screenr;
	screenr.x = 0;
	screenr.y = 0;
	screenr.w = 800;//FIX
	screenr.h = 600;
	

	bool terminate  = false;
	while (!terminate)
	{
		SDL_Event e;
		while (SDL_PollEvent(&e)) {
		switch(e.type){
		case SDL_QUIT:
			terminate = true;
			break;
		case SDL_MOUSEBUTTONDOWN:{
			int xx,yy;
			SDL_GetMouseState(&xx,&yy);
			//bessie::line2array(&x1,&y1,&x2,&y2);
			player.moveto(xx,yy);
			player.setmoving(1);
			break;
		}
		case SDL_MOUSEBUTTONUP:{
			player.setmoving(0);
			break;
		}
		}
		}
		SDL_BlitSurface(blanksurface, NULL,screen,&screenr);
		player.update();	
		player.draw(screen);	
		SDL_Flip(screen);
	}

	return 0;
}

