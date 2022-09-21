#pragma once
#ifndef _GRAPHICS_H_
#define _GRAPHICS_H_

#include<glm/glm.hpp>
#include<glm/vec2.hpp>

using namespace std;
using namespace glm;

class Graphics
{
public:
    void drawRect(vec2 pos, vec2 scale);
};

extern Graphics graphics;

#endif


