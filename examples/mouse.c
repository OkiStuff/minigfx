#include "../minigfx.h"

int main()
{
    mgfx_CreateWindow(1024, 600, "Mouse input in minigfx");
    mgfx_circle circle = (mgfx_circle){ mgfx_GetMouseX(), mgfx_GetMouseY(), 30.0 };
    mgfx_color circleColor = MGFX_RED;
    mgfx_font font = mgfx_LoadFont("resources/font.ttf");

    while (!mgfx_WindowCloses()) {
        circle.x = mgfx_GetMouseX();
        circle.y = mgfx_GetMouseY();

        if (mgfx_IsMouseButtonPressed(MOUSE_LEFT)) {
            circleColor = MGFX_RED;
        } else if (mgfx_IsMouseButtonPressed(MOUSE_RIGHT)) {
            circleColor = MGFX_BLUE;
        } else if (mgfx_IsMouseButtonPressed(MOUSE_MIDDLE)) {
            circleColor = MGFX_YELLOW;
        }

        mgfx_StartDrawing();
        mgfx_ClearTo(MGFX_WHITE);
        mgfx_DrawCircleC(circle, circleColor);
        mgfx_DrawText(font, "Click the different mouse buttons to change the circle's color", 10.0, 10.0, 40.0, MGFX_DARKGRAY);
        mgfx_StopDrawing();
    }

    mgfx_CloseWindow();
    return 0;
}