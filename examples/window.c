#define MINIGFX_IMPLEMENTATION
#include "../include/minigfx.h"

int main()
{
    mgfx_CreateWindow(1024, 600, "Basic Window in minigfx");
    mgfx_font font = mgfx_LoadFont("resources/font.ttf");

    while (!mgfx_WindowCloses()) {
        mgfx_StartDrawing();
        mgfx_ClearTo(MGFX_WHITE);
        mgfx_DrawText(font, "Hey! Your first window!", 10.0, 10.0, 30.0, MGFX_DARKGRAY);
        mgfx_StopDrawing();
    }

    mgfx_CloseWindow();
    return 0;
}
