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
#ifndef SCENE
#define SCENE
#include "../include/osgUtil/SceneView"
#include "../include/osg/Group""
/*
    New OSG Includes:
    
    osgDB/ReadFile - parses external resource files and imports the model/texture
                     data as an osg::Node.
                     
    osg/PositionAttitudeTransform - A transformation node specifically designed
                                    to translate (move) and set the attitude (rotation) 
                                    of other nodes in the scene graph.
*/
#include "../include/osgDB/ReadFile"
#include "../include/osg/PositionAttitudeTransform"

#include "module_registry.h"
class Module_Registry;
class Scene{
public:
    Scene();
    ~Scene();
    void attach(osgUtil::SceneView& sceneview);
    void set_module_registry(Module_Registry& registry);
private:
    Module_Registry * _module_registry;
    void create_scene();
    
    /*
        osg::Group node that will group any geometry nodes we may have in the
        scene. In this case, we're actually inserting a osg::PositionAttitudeTransform
        into this group, and the user model as an osg::Node into the PAT.
        
        Group -> PAT -> User Model
    */
    osg::Group *         _root;
};
#endif
