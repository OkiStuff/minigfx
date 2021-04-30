#define MINIGFX_IMPLEMENTATION
#include "../../minigfx.h"
#include <math.h>

void Plot(int x, int y, Color color);
void DrawXAxis();
void DrawYAxis();

// Graphs
void YeqX(float a, float b);

// Variables
const int width = 800;
const int height = 600;

const int offsetX = width/2;
const int offsetY = height/2;

int main()
{
    MiniGFX_CreateWindow(width, height, "Graphs");

    while (!MiniGFX_WindowCloses()) {
        MiniGFX_StartDrawing();
        
        MiniGFX_ClearTo(BLACK);
        DrawXAxis();
        DrawYAxis();
        YeqX(3, 5);
        YeqX(-3, 5);
        
        MiniGFX_StopDrawing();
    }

    MiniGFX_CloseWindow();
    return 0;
}

void Plot(int x, int y, Color color)
{
    MiniGFX_DrawPixel((offsetX-x), (offsetY-y), color);
}

void DrawXAxis()
{
    for (int x = -offsetX; x < offsetX; x += 5)
        Plot(x, 0, YELLOW);
}

void DrawYAxis()
{
    for (int y = -offsetY; y < offsetY; y += 5)
        Plot(0, y, YELLOW);
}

// Graphs
void YeqX(float a, float b)
{
    for (float x = -200.0; x < 200.0; x += 0.01) {
        float y = a*x + b;
        Plot(x, y, (Color){ 200, 200, 200, 255 });
    }
}