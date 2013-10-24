/*
# Copyright (C) Johan Ceuppens 2010-2013
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
#include "osgWindow.h"

namespace blend
{
namespace osgwindow
{
////////////////////////////////////////////////////////////////////////////////
osgWindow::
osgWindow(int w, int h):
	_scene_view(NULL),         //Initialize our two new data members
	_global_camera(NULL),
	_screen(NULL)//,
//	_screenr(NULL)
{
////////////////////////////////////////////////////////////////////////////////
//SDL Initialization

    if(SDL_Init(SDL_INIT_VIDEO)){
        string error("Error: SDL Could not be initialized: ");
        error += SDL_GetError();
        throw error;
    }
    
    /*
        Now we must setup the video rendering mode. Unlike the first tutorial,
        we use OpenGL via OSG libraries for our rendering system. OSG translates
        all scene graph data into low level OpenGL API calls, and then SDL will
        draw this OpenGL data.
        
        Must first set the rendering attributes of the SDL/GL interface. 
        In this case, we want to enable double buffering for an increase in 
        rendering efficiency.
	*/
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	
	/*
	   Note here that we change the video mode type to SDL_OPENGL, instead of
	   SDL_HWSURFACE. This tells SDL to expect 3D data from OpenGL calls instead
	   of 2D blitting. Without this, nothing would be drawn on screen.
    */
	_screen = new bessie::image::Surface<SDL_Surface *>(SDL_SetVideoMode(w, h, 0, SDL_OPENGL));

    if(!_screen->get()) {
        string error("Error: SDL Could not create Video Surface.");
        error += SDL_GetError();
        throw error;
    }

	_screenr = new SDL_Rect;
	_screenr->x = 0;
	_screenr->y = 0;
	_screenr->w = w;//FIX
	_screenr->h = h;

////////////////////////////////////////////////////////////////////////////////
//OSG Initialization
    /*
        Setup the OSG SceneView. A SceneView is an object that encompasses all
        aspects of a scene, such as the camera, geometry, lights, and more. For
        us, it is the topmost structure to which we attach other osg objects.
        
        The default sceneview is pretty bare... it contains no lighting, geometry,
        or any other fancy stuff. However, it does create an osg::CameraNode for
        us, which we will manipulate later in the file.
    */
	_scene_view = new osgUtil::SceneView();
	
	/*
	   Set the scene to have default lighting/color values.
	*/
	_scene_view->setDefaults();
	
	/*
	   Optional optimization function to control face culling. Do not cull objects
	   outside of our viewing range.
	*/
	_scene_view->setComputeNearFarMode(osgUtil::CullVisitor::DO_NOT_COMPUTE_NEAR_FAR);
	
    ////////////////////////////////////////////////////////////////////////////
    /*
        Setup the global OSG camera. Use the default found within our scene view.
    */
	 _global_camera = _scene_view->getCamera();
	 
	/*
	   Set the dimensions of the viewport. In other words, define the viewing
	   area as defined by a rectangle.
	   
	   Param 1 - x
	   Param 2 - y
	   Param 3 - width
	   Param 4 - height
	   
	   Note that x and y define the starting coordinates offset from the lower
	   lefthand corner of the osgWindow. (0, 0) means start AT the corner. Any
	   other value will move the viewport starting coordinates away from this
	   corner towards the middle of the screen. The last two parameters define 
	   the size of the viewport.
	*/
	_global_camera->setViewport(0, 0, 640, 480);
	
	/*
	   Setting the camera as a perspective matrix. This means our camera view
	   will contain the typical perspective properties, such as depth and
	   skewing/stretching of objects around the edges of the osgWindow.
	*/
	_global_camera->setProjectionMatrixAsPerspective(
	   45.0,       //Field of view angle - controls level of perspective
	   _global_camera->getViewport()->aspectRatio(),    //Aspect Ratio of the perspective
	               /*
	                   ZNear/Far control object drawing on the Z axis,
	                   (towards/away from viewer). Between these two ranges,
	                   objects are drawn. Outside of these ranges, the objects
	                   will not be drawn.
	               */
	   0.1,        //ZNear - The closest to the camera an object may be drawn
	   1000.0      //ZFar - Furthest distance from the camera an object may be drawn.
	   );
	
    /*
        Set the clear (background) color for this camera node. In this case, we
        create a light blue background. 
        
        If this is not set explicitly, the default clear color is black. 
        
        However, if SceneView->setDefaults() is called, the camera held by the SceneView
        will have the internal camera clear color set to, oddly enough, the same
        values as below. In the case of the above, we're using the internal
        camera, thus this setting of the clear color is redundant. If we wanted
        to change the color to green, then this would be warranted.
    */
	_global_camera->setClearColor(osg::Vec4(
	   0.2,       //Red
	   0.2,       //Green
	   0.4,       //Blue
	   0.0        //Opacity/alpha
	   ));
    

    /*
        Finally Initialize our scene view. This tells the scene to update it's
        internal data to reflect any changes in children.
    */
	_scene_view->init();
}
////////////////////////////////////////////////////////////////////////////////
osgWindow::
~osgWindow(){
    SDL_Quit();
}
////////////////////////////////////////////////////////////////////////////////
/*void osgWindow::
set_module_registry(Module_Registry& registry){
    _module_registry = &registry;
}*/
////////////////////////////////////////////////////////////////////////////////
void osgWindow::
draw(){
    //Update the scene view data
	_scene_view->update(); 
	
	//Perform culling of the scene for speed
	_scene_view->cull(); 
	
	//Draw the scene data to OpenGL buffers.
	_scene_view->draw();
}
////////////////////////////////////////////////////////////////////////////////

int osgWindow::draw(bessie::image::Surface<SDL_Surface *> *surface)
{
//blend::osgwindow::osgWindow window;

//	bessie::image::Surface<SDL_Surface *> blanksurface;
//	blanksurface.load(std::string(GAMEFILEROOT) + std::string("../lanternlight/pics/tile1grass.bmp"));

		SDL_BlitSurface(surface->get(), NULL,_screen->get(),_screenr);
		//player.update();
		//player.draw(screen);
		//SDL_Flip(screen);
	//}
	return 0;
}

/*


SDL_Rect screenr;
screenr.x = 0;
screenr.y = 0;
screenr.w = 800;//FIX
screenr.h = 600;


bool terminate  = false;
while (!terminate)
{
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
	switch(e.type){
	case SDL_QUIT:
		terminate = true;
		break;
	case SDL_MOUSEBUTTONDOWN:{
		int xx,yy;
		//FIX SDL_GetMouseState(&xx,&yy);
		//bessie::line2array(&x1,&y1,&x2,&y2);
		//player.moveto(xx,yy);
		//player.setmoving(1);
		break;
	}
	case SDL_MOUSEBUTTONUP:{
		//player.setmoving(0);
		break;
	}
	}
	}*/
}
}
