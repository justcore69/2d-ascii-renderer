#include <iostream>
#include <string>
#include <vector>
#include <glm/glm.hpp>
#include <glm/vec2.hpp>

using namespace std;
using namespace glm;

void renderFrame();
void drawGraphics();
void drawRect(vec2 pos, vec2 scale);

int main()
{
    drawGraphics();
    renderFrame();
}

void drawGraphics()
{
    drawRect(vec2(1, 1), vec2(5, 5));
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

    cout << frame;
    frame.clear();
    light_pixels.clear();
}

void drawRect(vec2 pos, vec2 scale) 
{
    for (int y = pos.y; y < pos.y + scale.y; y++)
    {
        for (int x = pos.x; x < pos.x + scale.x*2 ; x++)
        {
            vec2 pix = vec2(x, y);
            light_pixels.push_back(pix);
        }
    }
}

