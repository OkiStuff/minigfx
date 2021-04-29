#define MINIGFX_IMPLEMENTATION
#include "../minigfx.h"

int main()
{
    MiniGFX_CreateWindow(1024, 600, "Loading sprites in minigfx");
    Sprite image = MiniGFX_LoadSprite("../resources/header.png");

    while (!MiniGFX_WindowCloses()) {
        MiniGFX_StartDrawing();
        MiniGFX_ClearTo(BLACK);
        MiniGFX_DrawSprite(image, -150, 70, 1.0, WHITE);
        MiniGFX_EndDrawing();
    }

    MiniGFX_UnloadSprite(image);
    MiniGFX_CloseWindow();
    return 0;
}