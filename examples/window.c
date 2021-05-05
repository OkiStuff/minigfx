#define MINIGFX_IMPLEMENTATION
#include "../minigfx.h"

int main()
{
    MiniGFX_CreateWindow(1024, 600, "Basic Window in minigfx");
    int font = MiniGFX_LoadFont("font.ttf");

    while (!MiniGFX_WindowCloses()) {
        MiniGFX_StartDrawing();
        MiniGFX_ClearTo(WHITE);
        MiniGFX_DrawText(font, "Hey! Your first window!", 10.0, 10.0, 30.0, DARKGRAY);
        MiniGFX_StopDrawing();
    }

    MiniGFX_CloseWindow();
    return 0;
}
