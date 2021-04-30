#define MINIGFX_IMPLEMENTATION
#include "../minigfx.h"

int main()
{
    MiniGFX_CreateWindow(1024, 600, "Basic Window in minigfx");

    while (!MiniGFX_WindowCloses()) {
        MiniGFX_StartDrawing();
        MiniGFX_ClearTo(WHITE);
        MiniGFX_StopDrawing();
    }

    MiniGFX_CloseWindow();
    return 0;
}