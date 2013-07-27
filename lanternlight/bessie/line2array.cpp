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
#include "line2array.h"
#include<iostream>
#include<cmath>

/*
NOTE: x2 must be bigger than x1 !
*/

namespace bessie
{


std::vector<line2arrayPoint*> *line2array(int *x1, int *y1, int *x2, int *y2)
{

	std::vector<line2arrayPoint*> *pointsvec = new std::vector<line2arrayPoint*>;



	if ((*x1 >= 800 || *x2 >= 800 || *y1 >= 600 || *y2 >= 600)
		|| 
		(*x1 >= 800 || *x2 >= 800 || *y1 >= 600 || *y2 >= 600)) 
	{
		std::cout<<"line2array : pixel offset out of range"<<std::endl;
		return NULL;
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
    line2arrayVerticalFunc(x1,y1,&xnum,&ynum,deltax,deltay,1);
  }
  
	
			

  if (deltax >= 0 && deltay >= 0) {
    if (fabs(static_cast<double>(deltax)) >= fabs(static_cast<double>(deltay))) {
      //y = y1;
      ynum = deltax / 2;
      //      for (x = x1; x <= x2; x++)
      //return new TargetedBulletEntity(vec, bulletspeed, x1, y1, bboxvec, xnum, ynum, deltax, deltay, new ShootQuadrant1Func());
	   while ( *x2 >= *x1 ) {
				line2array1Func(x1,y1,&xnum,&ynum,deltax,deltay,1);
				pointsvec->push_back(new line2arrayPoint(*x1,*y1));

			}
	}
    else {
      //x = x1;
      xnum = deltay / 2;
      //return new TargetedBulletEntity(vec, bulletspeed,x1, y1, bboxvec, xnum, ynum, deltax, deltay, new ShootQuadrant2Func());
      //for (y = y1; y <= y2; y++)
	   while ( *y2 >= *y1 ) {
				line2array2Func(x1,y1,&xnum,&ynum,deltax,deltay,1);
				pointsvec->push_back(new line2arrayPoint(*x1,*y1));
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
				line2array3Func(x1,y1,&xnum,&ynum,deltax,deltay,1);
				pointsvec->push_back(new line2arrayPoint(*x1,*y1));
			}
	
	}
    else {
      //x = x1;
      xnum = deltay / 2;
      //for (y = y1; y <= y2; y++)
      //return new TargetedBulletEntity(vec, bulletspeed,x1, y1, bboxvec,xnum, ynum, deltax, deltay, new ShootQuadrant4Func());
		while ( *y2 >= *y1 ) {
				line2array4Func(x1,y1,&xnum,&ynum,deltax,deltay,1);
				pointsvec->push_back(new line2arrayPoint(*x1,*y1));
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
				line2array5Func(x1,y1,&xnum,&ynum,deltax,deltay,1);
				pointsvec->push_back(new line2arrayPoint(*x1,*y1));
			}
    }
    else {
      //x = x1;
      xnum = -deltay / 2;
      //for (y = y1; y >= y2; y--)
      //return new TargetedBulletEntity(vec, bulletspeed,x1, y1, bboxvec,xnum, ynum, deltax, deltay, new ShootQuadrant6Func());
	while ( *y2 >= *y1 ) {
				line2array6Func(x1,y1,&xnum,&ynum,deltax,deltay,1);
				pointsvec->push_back(new line2arrayPoint(*x1,*y1));
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
				line2array7Func(x1,y1,&xnum,&ynum,deltax,deltay,1);
				pointsvec->push_back(new line2arrayPoint(*x1,*y1));
			}
     }
     else {
       //x = x1;
       xnum = -deltay / 2;
       //for (y = y1; y >= y2; y--)
       //return new TargetedBulletEntity(vec, bulletspeed, x1, y1, bboxvec,xnum, ynum, deltax, deltay, new ShootQuadrant8Func());
     while ( *y2 >= *y1 ) {
				line2array7Func(x1,y1,&xnum,&ynum,deltax,deltay,1);
				pointsvec->push_back(new line2arrayPoint(*x1,*y1));
			}
	 }
  }


	return pointsvec;

}


void line2array1Func(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed) {
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
void line2array2Func(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed) {
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
void line2array3Func(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed) {
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

void line2array4Func(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed) {
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

void line2array5Func(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed) {
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

void line2array6Func(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed) {
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

void line2array7Func(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed) {
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

void line2array8Func(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed) {
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

void line2arrayVerticalFunc(int *x, int *y, int *xnum, int *ynum, int deltax, int deltay, int speed) {
  //for (int i = 0; i < speed; i++) {
    *y += *ynum;
  //}
  //*y += SCROLLSPEED;
}


}//namespace bessie
