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

#include "osgblend.h"

namespace blend
{

template<typename SC, typename CAM>
osgBlend<SC,CAM>::osgBlend()
{
	_scene = new osgUtil::SceneView();
	_scene->setDefaults();
	_scene->setComputeNearFarMode(osgUtil::CullVisitor::DO_NOT_COMPUTE_NEAR_FAR);

    _camera = _scene->getCamera();
	_camera->setViewport(0, 0, 640, 480);
	_camera->setProjectionMatrixAsPerspective(
	   45.0,
	   _camera->getViewport()->aspectRatio(),
	   0.1,
	   1000.0
	   );
	_camera->setClearColor(osg::Vec4(0.2, 0.2, 0.4, 0.0));
	_scene->init();
}

template<typename SC, typename CAM>
void osgBlend<SC,CAM>::update()
{
	_scene->update();
	_scene->cull();
	_scene->draw();
}

template<typename SC, typename CAM>
void osgBlend<SC,CAM>::draw()
{
	SDL_GL_SwapBuffers();
}

template class osgBlend<osgUtil::SceneView *, osg::CameraNode *>;

}
