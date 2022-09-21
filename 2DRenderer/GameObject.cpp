#include<chrono>
#include<thread>

#include "GameObject.h"
#include "2DRenderer.h"
#include "Graphics.h"

GameObject::GameObject(string _name, string _spr, vec2 _pos, vec2 _scale)
{
	name = _name;
	sprite = _spr;
	position = _pos;
	scale = _scale;
	
	all_objects.push_back(*this);

	drawSelf();
}

void GameObject::drawSelf()
{
	if(sprite == "rect") graphics.drawRect(position, scale);
}

void GameObject::move(vec2 dir)
{
	position += dir;
}

