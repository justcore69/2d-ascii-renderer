/*

// - Basic 2D ASCII renderer
// - Copyright (c) JustCore 2022
// - Free to commercial use
// - Thank you for using!

*/

#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include <glm/glm.hpp>
#include <glm/vec2.hpp>

#include"GameObject.h"
#include"2DRenderer.h"

using namespace std;
using namespace glm;

void space();
void renderFrame();

constexpr std::chrono::nanoseconds timestep(16ms);

int main()
{
    space();

    for (int t = 0; t < 1000000; t++) 
    {
        for (int i = 0; i < all_objects.size(); i++) 
        {
            all_objects[i].drawSelf();
        }

        renderFrame();

        this_thread::sleep_for(32ms);
    }
} 

vector<GameObject> all_objects;

void space() //Create objects here
{
    GameObject obj1("Rectangle", "rect", vec2(3, 3), vec2(5, 5));
}

vector<vec2> light_pixels;

void renderFrame() 
{
    const char REN_DARK = 176;
    const char REN_LIGHT = 178;

    const int SCREEN_W = 20*2;
    const int SCREEN_H = 20;

    string frame = "";

    for (int y = 0; y < SCREEN_H; y++) 
    {
        string line = "";

        for (int x = 0; x < SCREEN_W*2; x++)
        {
            bool is_light = false;
            for (int light = 0; light < light_pixels.size(); light++) 
            {
                if (x == light_pixels[light].x && y == light_pixels[light].y) 
                {
                    line.push_back(REN_LIGHT);
                    is_light = true;
                }
            }
            if (!is_light) 
            {
                line.push_back(REN_DARK);
            }
        }

        frame += line + '\n';
    }

    frame += "\n\n\n\n\n\n\n\n\n";

    cout << frame;
    frame.clear();
    light_pixels.clear();
}

