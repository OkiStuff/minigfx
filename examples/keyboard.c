#define MINIGFX_IMPLEMENTATION
#include "../minigfx.h"
#include <stdio.h>

int main()
{
    MiniGFX_InitWindow(1024, 600, "Basic keyboard input in minigfx");

    while (!MiniGFX_WindowCloses()) {
        if (MiniGFX_IsKeyPressed(KEY_P)) printf("Key P was pressed\n");
        if (MiniGFX_IsKeyHeld(KEY_H)) printf("Key H was pressed\n");

        MiniGFX_StartDrawing();
        MiniGFX_ClearTo(WHITE);
        MiniGFX_EndDrawing();
    }

    MiniGFX_CloseWindow();
    return 0;
}