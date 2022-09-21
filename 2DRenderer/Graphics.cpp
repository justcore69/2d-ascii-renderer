#include "Graphics.h"
#include "2DRenderer.h"

void Graphics::drawRect(vec2 pos, vec2 scale)
{
    for (int y = pos.y; y < pos.y + scale.y; y++)
    {
        for (int x = pos.x * 2; x < pos.x * 2 + scale.x * 2; x++)
        {
            vec2 pix = vec2(x, y);
            light_pixels.push_back(pix);
        }
    }
}

Graphics graphics;


