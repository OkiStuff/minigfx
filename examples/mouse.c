#define MINIGFX_IMPLEMENTATION
#include "../minigfx.h"

int main()
{
    mgfx_CreateWindow(1024, 600, "Mouse input in minigfx");
    Circle circle = (Circle){ mgfx_GetMouseX(), mgfx_GetMouseY(), 30.0 };
    Color circleColor = RED;
    int font = mgfx_LoadFont("font.ttf");

    while (!mgfx_WindowCloses()) {
        circle.x = mgfx_GetMouseX();
        circle.y = mgfx_GetMouseY();

        if (mgfx_IsMouseButtonPressed(MOUSE_LEFT)) {
            circleColor = RED;
        } else if (mgfx_IsMouseButtonPressed(MOUSE_RIGHT)) {
            circleColor = BLUE;
        } else if (mgfx_IsMouseButtonPressed(MOUSE_MIDDLE)) {
            circleColor = YELLOW;
        }

        mgfx_StartDrawing();
        mgfx_ClearTo(WHITE);
        mgfx_DrawCircleC(circle, circleColor);
        mgfx_DrawText(font, "Click the different mouse buttons to change the circle's color", 10.0, 10.0, 40.0, DARKGRAY);
        mgfx_StopDrawing();
    }

    mgfx_CloseWindow();
    return 0;
}