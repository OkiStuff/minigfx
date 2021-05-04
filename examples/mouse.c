#define MINIGFX_IMPLEMENTATION
#include "../minigfx.h"
#include <stdio.h>

int main()
{
    MiniGFX_CreateWindow(1024, 600, "Mouse input in minigfx");
    Circle circle = (Circle){ MiniGFX_GetMouseX(), MiniGFX_GetMouseY(), 30.0 };
    Color circleColor = RED;
    int font = MiniGFX_LoadFont("font.ttf");

    while (!MiniGFX_WindowCloses()) {
        circle.x = MiniGFX_GetMouseX();
        circle.y = MiniGFX_GetMouseY();

        if (MiniGFX_IsMouseButtonPressed(MOUSE_LEFT)) {
            circleColor = RED;
        } else if (MiniGFX_IsMouseButtonPressed(MOUSE_RIGHT)) {
            circleColor = BLUE;
        } else if (MiniGFX_IsMouseButtonPressed(MOUSE_MIDDLE)) {
            circleColor = YELLOW;
        }

        MiniGFX_StartDrawing();
        MiniGFX_ClearTo(WHITE);
        MiniGFX_DrawCircleC(circle, circleColor);
        MiniGFX_DrawText(font, "Click the different mouse buttons to change the circle's color", 10.0, 10.0, 40.0, DARKGRAY);
        MiniGFX_StopDrawing();
    }

    MiniGFX_CloseWindow();
    return 0;
}