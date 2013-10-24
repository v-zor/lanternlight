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
#ifndef OSGWINDOW_H
#define OSGWINDOW_H

#include "SDL.h"
#include <string>
using std::string;

#include "../include/osg/CameraNode"
#include "../include/osgUtil/SceneView"

namespace blend
{
namespace window
{

class Window{
public:
    Window();
    ~Window();

    void draw();
    
private:
    
    //OSG Objects - a scene view, and a camera that goes with this scene
    osg::ref_ptr<osgUtil::SceneView> _scene_view;
    osg::ref_ptr<osg::CameraNode>    _global_camera;

    Window(const Window& window);
    const Window& operator=(const Window& window);
};

}
}

#endif
