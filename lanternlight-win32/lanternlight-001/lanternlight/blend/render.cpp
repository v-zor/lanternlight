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
#include "render.h"
#include<string>
#include<iostream>

Renderer::
Renderer():
    _root(new osg::Group())
{
    create_scene1();
}

Renderer::
~Renderer(){}

void Renderer::
create_scene1(){

	std::cout << "creating scene 1"<< std::endl;
    osg::Node * model = osgDB::readNodeFile("../lanternlight/data/starthing.obj.data");
    std::cout << "node file"<<std::endl;
    if(!model){
        throw std::string("Error! Could not load node file.");
    }
    
    std::cout << "creating scene 1.2"<< std::endl;
    osg::PositionAttitudeTransform * model_pat = new osg::PositionAttitudeTransform();
    
    model_pat->setPosition(
        //         x, y, z
        osg::Vec3d(0, 0, -20)
    );
    
    model_pat->addChild(model);
    
    _root->addChild(model_pat);
    std::cout << "creating scene 1 finished."<< std::endl;
}
