#define MINIGFX_IMPLEMENTATION
#include "../minigfx.h"
#include <stdio.h>

int main()
{
    Mini_InitWindow(1024, 600, "Basic keyboard input in minigfx");

    while (!Mini_WindowCloses()) {
        if (Mini_IsKeyPressed(KEY_P)) printf("Key P was pressed\n");
        if (Mini_IsKeyHeld(KEY_H)) printf("Key H was pressed\n");

        Mini_StartDrawing();
        Mini_ClearTo(WHITE);
        Mini_EndDrawing();
    }

    Mini_CloseWindow();
    return 0;
}