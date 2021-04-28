#define MINIGFX_IMPLEMENTATION
#include "minigfx.h"

int main()
{
    Mini_InitWindow(1024, 600, "Basic Window in minigfx");

    while (!Mini_WindowCloses()) {
        Mini_StartDrawing();
        
        Mini_EndDrawing();
    }

    Mini_CloseWindow();
    return 0;
}