#pragma once
#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_

#include<string>
#include<glm/glm.hpp>
#include<glm/vec2.hpp>

using namespace std;
using namespace glm;

class GameObject
{
public:

	int id;
	string name;
	string sprite;
	vec2 position;
	vec2 scale;

	GameObject(string _name, string _spr, vec2 _pos, vec2 _scale);

	void drawSelf();

	void move(vec2 dir);
};

#endif
