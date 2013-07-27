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
#ifndef IMGSYS_H
#define IMGSYS_H

#include <SDL/SDL.h>
#include<string>
#include<map>
//#include<unistd.h>
namespace bessie
{
namespace image
{

using namespace std;

class ImgSys
{
	public:
		ImgSys() : _colorkey(0x000000) {}
		ImgSys(Uint32 colorkey) : _colorkey(colorkey) {}
		virtual ~ImgSys() {}

		int reload(string filename, SDL_Surface **surface);
		int load(string filename, SDL_Surface **surface);
		int load(string filename, map<std::string, SDL_Surface *> *surfaces);//FIXME map

		int set_colorkey(uint32_t ck) { _colorkey = ck; }


	protected:

	private:
		int filein(string filename, SDL_Surface **surface = NULL);		
	private:
		uint32_t _colorkey;

};

}
}


#endif
