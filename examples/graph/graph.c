#include "../../minigfx.h"
#include <math.h>

void Plot(int x, int y, mgfx_color color);
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
    mgfx_CreateWindow(width, height, "Graphs");
    int selected = 0;
	float step = 0.01;

    while (!mgfx_WindowCloses()) {
		if (mgfx_IsKeyPressed(KEY_UP)) {
			selected++;
		} else if (mgfx_IsKeyPressed(KEY_DOWN)) {
			selected--;
		}

		if (mgfx_IsKeyHeld(KEY_RIGHT)) {
			step += 0.001;
		} else if (mgfx_IsKeyHeld(KEY_LEFT)) {
			step -= 0.001;
		}

		// clamping checks
		if (selected <= 0) selected = 0;
		if (selected >= 10) selected = 10;

        mgfx_StartDrawing();
        
        mgfx_ClearTo(MGFX_BLACK);
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
        
        mgfx_StopDrawing();
    }

    mgfx_CloseWindow();
    return 0;
}

void Plot(int x, int y, mgfx_color color)
{
    mgfx_DrawPixel((offsetX-x), (offsetY-y), color);
}

void DrawXAxis()
{
    for (int x = -offsetX; x < offsetX; x += 5)
        Plot(x, 0, MGFX_YELLOW);
}

void DrawYAxis()
{
    for (int y = -offsetY; y < offsetY; y += 5)
        Plot(0, y, MGFX_YELLOW);
}

// Graphs
void YeqX(float a, float b)
{
    for (float x = -200.0; x < 200.0; x += 0.01) {
        float y = a*x + b;
        Plot(x, y, (mgfx_color){ 200, 200, 200, 255 });
    }
}

void GSqrt(int value)
{
	for (float x = -200.0; x < 200.0; x += 0.01) {
		float y = sqrt(x) * value;
		Plot(x, y, (mgfx_color){ 200, 200, 200, 255 });
	}
}

void YEqSinX(float a, float b, float step)
{
	for (float x = -400.0; x < 400.0; x += step) {
		float y = sin(a*x) * b * cos(1-x) + sin(a) * 50;
		Plot(x, y, (mgfx_color){ mgfx_RandomInt(0, 255), mgfx_RandomInt(0, 255), mgfx_RandomInt(0, 255), 255 });
	}
}

void TrigoTan(float step)
{
	for (float x = -400.0; x < 400.0; x += step) {
		float y = tan(x*345);
		Plot(x, y, (mgfx_color){ mgfx_RandomInt(0, 255), mgfx_RandomInt(0, 255), mgfx_RandomInt(0, 255), 255 });
	}
}
