#define MINIGFX_IMPLEMENTATION
#include "../../minigfx.h"
#include <math.h>

void Plot(int x, int y, Color color);
void DrawXAxis();
void DrawYAxis();

// Graphs
void YeqX(float a, float b);
void GSqrt(int value);
void YEqSinX(float a, float b, float step);
void TrigoTan(float step);

// Variables
const int width = 800;
const int height = 600;

const int offsetX = width/2;
const int offsetY = height/2;

int main()
{
    MiniGFX_CreateWindow(width, height, "Graphs");
    int selected = 0;
	float step = 0.01;

    while (!MiniGFX_WindowCloses()) {
		if (MiniGFX_IsKeyPressed(KEY_UP)) {
			selected++;
		} else if (MiniGFX_IsKeyPressed(KEY_DOWN)) {
			selected--;
		}

		if (MiniGFX_IsKeyHeld(KEY_RIGHT)) {
			step += 0.001;
		} else if (MiniGFX_IsKeyHeld(KEY_LEFT)) {
			step -= 0.001;
		}

		// clamping checks
		if (selected <= 0) selected = 0;
		if (selected >= 10) selected = 10;

        MiniGFX_StartDrawing();
        
        MiniGFX_ClearTo(BLACK);
        DrawXAxis();
        DrawYAxis();

		switch (selected) {
		case 0:
        	YeqX(3, 5);
			break;
		case 1:
			GSqrt(10);
			break;
		case 2:
			YEqSinX(1, 50, 3);
			break;
		case 3:
			TrigoTan(step);
			break;
		default: break;
	}
        
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

void GSqrt(int value)
{
	for (float x = -200.0; x < 200.0; x += 0.01) {
		float y = sqrt(x) * value;
		Plot(x, y, (Color){ 200, 200, 200, 255 });
	}
}

void YEqSinX(float a, float b, float step)
{
	for (float x = -400.0; x < 400.0; x += step) {
		float y = sin(a*x) * b * cos(1-x) + sin(a) * 50;
		Plot(x, y, (Color){ MiniGFX_RandomInt(0, 255), MiniGFX_RandomInt(0, 255), MiniGFX_RandomInt(0, 255), 255 });
	}
}

void TrigoTan(float step)
{
	for (float x = -400.0; x < 400.0; x += step) {
		float y = tan(x*345);
		Plot(x, y, (Color){ MiniGFX_RandomInt(0, 255), MiniGFX_RandomInt(0, 255), MiniGFX_RandomInt(0, 255), 255 });
	}
}
