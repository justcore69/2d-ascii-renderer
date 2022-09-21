#include<chrono>
#include<thread>

#include "GameObject.h"
#include "2DRenderer.h"
#include "Graphics.h"

GameObject::GameObject(string _name, vec2 _pos, vec2 _scale)
{
	name = _name;
	position = _pos;
	scale = _scale;
	
	drawSelf(position, scale);
}

void GameObject::move(vec2 dir)
{
	position += dir;
}

using namespace std;

void drawSelf(vec2 _pos, vec2 _scale) 
{
	/*for (int t = 0; t < 1000000; t++)
	{
		graphics.drawRect(_pos, _scale);
		this_thread::sleep_for(32ms);
	}*/
}
