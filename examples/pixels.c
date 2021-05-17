#define MINIGFX_IMPLEMENTATION
#include "../include/minigfx.h"

int main()
{
    const int screenWidth = 1024;
    const int screenHeight = 600;
    mgfx_CreateWindow(screenWidth, screenHeight, "Lots of pixels in minigfx");

    while (!mgfx_WindowCloses()) {
        mgfx_StartDrawing();
        mgfx_ClearTo(MGFX_WHITE);

        for (int x = 0; x < screenWidth; x++)
            for (int y = 0; y < screenHeight; y++) {
                mgfx_color color = (mgfx_color){ mgfx_RandomInt(0, 255), mgfx_RandomInt(0, 255), mgfx_RandomInt(0, 255), 255 };
                mgfx_DrawPixel(x, y, color);
            }
        
        mgfx_StopDrawing();
    }

    mgfx_CloseWindow();
    return 0;
}