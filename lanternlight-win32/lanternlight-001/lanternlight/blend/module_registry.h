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
#ifndef MODULE_REGISTRY_H
#define MODULE_REGISTRY_H

#include "window.h"
#include "scene.h"
class Window;
class Scene;
class Module_Registry{
public:
    Module_Registry();
    ~Module_Registry();
    
    void register_window(Window& window);
    Window * get_window();
    
    void register_scene(Scene& scene);
    Scene * get_scene();
private:
    Window * _window;
    Scene * _scene;
    
    Module_Registry(const Module_Registry& registry);
    Module_Registry& operator=(const Module_Registry& registry);
};
#endif
