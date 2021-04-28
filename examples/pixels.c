#define MINIGFX_IMPLEMENTATION
#include "../minigfx.h"

int main()
{
    const int screenWidth = 1024;
    const int screenHeight = 600;
    MiniGFX_InitWindow(screenWidth, screenHeight, "Lots of pixels in minigfx");

    while (!MiniGFX_WindowCloses()) {
        MiniGFX_StartDrawing();
        MiniGFX_ClearTo(WHITE);

        for (int x = 0; x < screenWidth; x++)
            for (int y = 0; y < screenHeight; y++) {
                Color color = (Color){ rand()%255, rand()%255, rand()%255, 255 };
                MiniGFX_DrawPixel(x, y, color);
            }
        
        MiniGFX_EndDrawing();
    }

    MiniGFX_CloseWindow();
    return 0;
}