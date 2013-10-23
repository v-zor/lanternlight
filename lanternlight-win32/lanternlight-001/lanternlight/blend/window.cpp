/*
# Copyright (C) Johan Ceuppens 2010--2013
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
#include "window.h"
////////////////////////////////////////////////////////////////////////////////
Window::
Window():
    _module_registry(NULL),
	_scene_view(NULL),
	_global_camera(NULL)
{
////////////////////////////////////////////////////////////////////////////////
//SDL Initialization

    if(SDL_Init(SDL_INIT_VIDEO)){
        string error("Error: SDL Could not be initialized: ");
        error += SDL_GetError();
        throw error;
    }
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    if(!SDL_SetVideoMode(640, 480, 0, SDL_OPENGL)){
        string error("Error: SDL Could not create Video Surface.");
        error += SDL_GetError();
        throw error;
    }
////////////////////////////////////////////////////////////////////////////////
//OSG Initialization

	_scene_view = new osgUtil::SceneView();
	_scene_view->setDefaults();
	_scene_view->setComputeNearFarMode(osgUtil::CullVisitor::DO_NOT_COMPUTE_NEAR_FAR);
	
    _global_camera = _scene_view->getCamera();
	_global_camera->setViewport(0, 0, 640, 480);
	_global_camera->setProjectionMatrixAsPerspective(
	   45.0,
	   _global_camera->getViewport()->aspectRatio(),
	   0.1,
	   1000.0
	   );
	_global_camera->setClearColor(osg::Vec4(0.2, 0.2, 0.4, 0.0));
	_scene_view->init();
}
////////////////////////////////////////////////////////////////////////////////
Window::
~Window(){
    SDL_Quit();
}
////////////////////////////////////////////////////////////////////////////////
void Window::
set_module_registry(Module_Registry& registry){
    _module_registry = &registry;
}
////////////////////////////////////////////////////////////////////////////////
void Window::
draw(){
	_scene_view->update(); 
	_scene_view->cull(); 
	_scene_view->draw();
}
////////////////////////////////////////////////////////////////////////////////
void Window::
attach(Scene& scene){
    scene.attach(*_scene_view.get());
}
////////////////////////////////////////////////////////////////////////////////
