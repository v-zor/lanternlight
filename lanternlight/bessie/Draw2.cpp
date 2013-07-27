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
#include "Draw2.h"
#include "Draw.h"
#include<iostream>
#include<cmath>
/*
NOTE: make sure putpixel does not go beyond the surf surf
*/

/*
NOTE: x2 must be bigger than x1 !
*/

namespace bessie
{



void swap(int *x1, int *x2) {
	int *tempx = x1;
	*x1 = *x2;
	*x2 = *tempx;
}

void drawline(SDL_Surface *surf, int *x1, int *y1, int *x2, int *y2, Uint32 color)
{

	if ((*x1 >= 800 || *x2 >= 800 || *y1 >= 600 || *y2 >= 600)
		|| 
		(*x1 >= 800 || *x2 >= 800 || *y1 >= 600 || *y2 >= 600)) 
	{
		std::cout<<"drawline : pixel offset out of range"<<std::endl;
		return;
	}

  int w = 20, h = 20;//--fixme width height constant

  /*if (*x1 > *x2) //FIXME
		swap(x1,x2);
  if (*y1 > *y2) //FIXME
		swap(y1,y2);
	*/
  int deltax = *x2-*x1;
  int deltay = *y2-*y1;
  
  int xnum = 0;
  int ynum = 0;

  //assert("Needs to be fixed" && deltax != 0);//--fixme
  if (deltax == 0) {
    std::cout << "EntityFactory deltax=0 - needs debugging"<<std::endl;
    //return new TargetedBulletEntity(vec, bulletspeed, x1, y1, bboxvec, 0, 1, 0, 0, new ShootVerticalFunc());
    drawVerticalFunc(x1,y1,&xnum,&ynum,deltax,deltay,1);
  }
  
	
			

  if (deltax >= 0 && deltay >= 0) {
    if (fabs(static_cast<double>(deltax)) >= fabs(static_cast<double>(deltay))) {
      //y = y1;
      ynum = deltax / 2;
      //      for (x = x1; x <= x2; x++)
      //return new TargetedBulletEntity(vec, bulletspeed, x1, y1, bboxvec, xnum, ynum, deltax, deltay, new ShootQuadrant1Func());
	   while ( *x2 >= *x1 ) {
				drawline1Func(x1,y1,&xnum,&ynum,deltax,deltay,1);
				putpixel(surf, *x1,*y1,color);
			}
	}
    else {
      //x = x1;
      xnum = deltay / 2;
      //return new TargetedBulletEntity(vec, bulletspeed,x1, y1, bboxvec, xnum, ynum, deltax, deltay, new ShootQuadrant2Func());
      //for (y = y1; y <= y2; y++)
	   while ( *y2 >= *y1 ) {
				drawline2Func(x1,y1,&xnum,&ynum,deltax,deltay,1);
				putpixel(surf, *x1,*y1,color);
			}
    }
  }
  else if (deltax < 0 && deltay >= 0) {
    if (fabs(static_cast<double>(deltax)) >= fabs(static_cast<double>(deltay))) {
      //y = y1;
      ynum = -deltax / 2;
      //      for (x = x1; x >= x2; x--)
      //return new TargetedBulletEntity(vec, bulletspeed,x1, y1, bboxvec,xnum, ynum, deltax, deltay, new ShootQuadrant3Func());
		while ( *x2 >= *x1 ) {
				drawline3Func(x1,y1,&xnum,&ynum,deltax,deltay,1);
				putpixel(surf, *x1,*y1,color);
			}
	
	}
    else {
      //x = x1;
      xnum = deltay / 2;
      //for (y = y1; y <= y2; y++)
      //return new TargetedBulletEntity(vec, bulletspeed,x1, y1, bboxvec,xnum, ynum, deltax, deltay, new ShootQuadrant4Func());
		while ( *y2 >= *y1 ) {
				drawline4Func(x1,y1,&xnum,&ynum,deltax,deltay,1);
				putpixel(surf, *x1,*y1,color);
			}
	}
  }
  else if (deltax >= 0 && deltay < 0) {
    if (fabs(static_cast<double>(deltax)) >= fabs(static_cast<double>(deltay))) {
      //y = y1;
      ynum = deltax / 2;
      //for (x = x1; x <= x2; x++)
      //return new TargetedBulletEntity(vec, bulletspeed,x1, y1, bboxvec,xnum, ynum, deltax, deltay, new ShootQuadrant5Func());
      while ( *x2 >= *x1 ) {
				drawline5Func(x1,y1,&xnum,&ynum,deltax,deltay,1);
				putpixel(surf, *x1,*y1,color);
			}
    }
    else {
      //x = x1;
      xnum = -deltay / 2;
      //for (y = y1; y >= y2; y--)
      //return new TargetedBulletEntity(vec, bulletspeed,x1, y1, bboxvec,xnum, ynum, deltax, deltay, new ShootQuadrant6Func());
	while ( *y2 >= *y1 ) {
				drawline6Func(x1,y1,&xnum,&ynum,deltax,deltay,1);
				putpixel(surf, *x1,*y1,color);
			}
    }
  }
  else if (deltax < 0 && deltay <0) {
     if (fabs(static_cast<double>(deltax)) >= fabs(static_cast<double>(deltay))) {
       // y = y1;
       ynum = -deltax / 2;
       //for (x = x1; x >= x2; x--)
       //return new TargetedBulletEntity(vec, bulletspeed,x1, y1, bboxvec,xnum, ynum, deltax, deltay, new ShootQuadrant7Func());
       while ( *x2 >= *x1 ) {
				drawline7Func(x1,y1,&xnum,&ynum,deltax,deltay,1);
				putpixel(surf, *x1,*y1,color);
			}
     }
     else {
       //x = x1;
       xnum = -deltay / 2;
       //for (y = y1; y >= y2; y--)
       //return new TargetedBulletEntity(vec, bulletspeed, x1, y1, bboxvec,xnum, ynum, deltax, deltay, new ShootQuadrant8Func());
     while ( *y2 >= *y1 ) {
				drawline7Func(x1,y1,&xnum,&ynum,deltax,deltay,1);
				putpixel(surf, *x1,*y1,color);
			}
	 }
  }
}

void drawlineold(SDL_Surface *surf, int *x1, int *y1, int *x2, int *y2, Uint32 color)
{

	int xnum = 0;
	int ynum = 0;

	int deltax = (*x2 - *x1);
	int deltay = (*y2 - *y1);

	if (deltax == 0) {
		std::cout << "impossible line rico" << std::endl;
		return;
	}
	
	double rico = deltay / deltax;//(*y2 - *y1) / (*x2 - *x1);
	std::cout<<"rico = %e\n"<<rico<<std::endl; 
	fprintf(stdout, "rico=%f", rico);
	if (rico > 0) {
		if (*y2 >= *y1) {
			if (*x1 > *x2)
				swap(x1,x2);
			
			//lower right
			while ( *x2 >= *x1 ) {
				drawline1Func(x1,y1,&xnum,&ynum,deltax,deltay,1);
				putpixel(surf, *x1,*y1,color);
			}
		} else if (*y2 < *y1) {
			//upper right
			while ( *x2 >= *x1 ) {
				drawline5Func(x1,y1,&xnum,&ynum,deltax,deltay,1);
				putpixel(surf, *x1,*y1,color);
			}
		}
	} else if (rico < 0) {
		if (*x1 < *x2)
				swap(x1,x2);

		if (*y2 >= *y1) {
			//lower left
			while ( *x2 <= *x1 ) {
				drawline1Func(x1,y1,&xnum,&ynum,deltax,deltay,1);
				putpixel(surf, *x1,*y1,color);
			}
		} else if (*y2 < *y1) {
			//upper left
			while ( *x2 <= *x1 ) {	
				drawline5Func(x1,y1,&xnum,&ynum,deltax,deltay,1);
				putpixel(surf, *x1,*y1,color);
			}
		}
	}
}

void drawline1Func(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed) {
  //for (int i = 0; i < speed; i++) {
    *x += 1;
    *ynum += deltay;
    if (*ynum >= deltax)
      {
	*ynum -= deltax;
	(*y)++;
  //    }
    
  }
  //*y += SCROLLSPEED;
}
void drawline2Func(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed) {
  //for (int i = 0; i < speed; i++) {
    *y += 1;
    *xnum += deltax;
    if (*xnum >= deltay)
      {
	*xnum -= deltay;
	(*x)++;
      }
  //}
  //*y += SCROLLSPEED;
}
void drawline3Func(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed) {
  //for (int i = 0; i < speed; i++) {
    *x -= 1;
    *ynum += deltay;
    if (*ynum >= -deltax)
      {
	*ynum -= -deltax;
	(*y)++;
      }
  //}
  //*y += SCROLLSPEED;
}

void drawline4Func(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed) {
  //for (int i = 0; i < speed; i++) {
    *y += 1;
    *xnum += -deltax;
    if (*xnum >= deltay)
      {
	*xnum -= deltay;
	(*x)--;
      }
  //}
  //*y += SCROLLSPEED;
}

void drawline5Func(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed) {
  //for (int i = 0; i < speed; i++) {
    *x += 1;
    *ynum += -deltay;
    if (*ynum >= deltax)
      {
	*ynum -= deltax;
	(*y)--;
      }
  //}
  //*y += SCROLLSPEED;
}

void drawline6Func(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed) {
  //for (int i = 0; i < speed; i++) {
    *y -= 1;
    *xnum += deltax;
    if (*xnum >= -deltay)
      {
	*xnum -= -deltay;
	(*x)++;
      }
  //}
  //*y += SCROLLSPEED;
}

void drawline7Func(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed) {
  //for (int i = 0; i < speed; i++) {
    *x -= 1;
    *ynum += -deltay;
    if (*ynum >= -deltax)
      {
	*ynum -= -deltax;
	(*y)--;
      }
  //}
  //*y += SCROLLSPEED;
}

void drawline8Func(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed) {
  //for (int i = 0; i < speed; i++) {
    *y -= 1;
    *xnum += -deltax;
    if (*xnum >= -deltay)
      {
	*xnum -= -deltay;
	(*x)--;
      }
    //}
  //*y += SCROLLSPEED;
}

void drawVerticalFunc(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed) {
  //for (int i = 0; i < speed; i++) {
    *y += *ynum;
  //}
  //*y += SCROLLSPEED;
}


}//namespace bessie
