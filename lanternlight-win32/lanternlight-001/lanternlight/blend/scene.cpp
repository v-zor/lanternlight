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
#include "scene.h"

#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
Scene::
Scene():
    _module_registry(NULL),
    _root(new osg::Group())
{
    create_scene();
}
////////////////////////////////////////////////////////////////////////////////
Scene::
~Scene(){}
////////////////////////////////////////////////////////////////////////////////
void Scene::
attach(osgUtil::SceneView& sceneview){
    sceneview.setSceneData(_root);
}
////////////////////////////////////////////////////////////////////////////////
void Scene::
create_scene(){

    /*
        Load up a custom model from a file and stick in a generic node. osgDB
        has the ability to import many different formats of external models, so
        the files need not end with the '.obj' suffix.
        
        
    */
    osg::Node * model = osgDB::readNodeFile("data/starthing.obj");
    
    //If the model did not load (NULL pointer), we don't need to continue further
    if(!model){
        throw string("Error! Could not load node file.");
    }
    
    /*
        Create an osg::PositionAttitudeTransform to position the model in front 
        of the camera. By default, the loaded model would be at (0, 0, 0), which 
        is the same position as the camera. Thus, if we do not reposition the model, 
        the camera will be inside of the loaded model. Not good. We stick 
        this 20 unites in the negative z direction (away from us).
    */
    osg::PositionAttitudeTransform * model_pat = new osg::PositionAttitudeTransform();
    
    model_pat->setPosition(
        //         x, y, z
        osg::Vec3d(0, 0, -20)
    );
    
    /*
        To apply the transformation of the PAT, we must add the custom model 
        node as a child. In fact, if we had 10 models attached to the PAT, 
        they would all be affected by the transformation.    
    */
    model_pat->addChild(model);
    
    /*
        Now that we have the model as a child of the PAT, we can treat the PAT
        as if it were the actual model. As per last tutorial, we now add the
        'model' to the group of possible models. Then the group will be attached
        to the scene graph via the attach() function of this class.
    */
    _root->addChild(model_pat);
}
////////////////////////////////////////////////////////////////////////////////
void Scene::
set_module_registry(Module_Registry& registry){
    _module_registry = &registry;
}
////////////////////////////////////////////////////////////////////////////////
