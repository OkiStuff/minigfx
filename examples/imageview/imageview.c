// A port of Imageview made by laurenloco
// Originally made with raylib

#define MINIGFX_IMPLEMENTATION
#include "../../minigfx.h"

Sprite image;

int main(int argc, char *argv[])
{
    MiniGFX_CreateWindow(1920, 1080, "Imageview");
    MiniGFX_LoadSprite(&image, argv[1]);
    int font = MiniGFX_LoadFont("/usr/share/fonts/ubuntu/UbuntuMono-R.ttf");

    while (!MiniGFX_WindowCloses()) {
        MiniGFX_StartDrawing();
        MiniGFX_DrawSprite(&image,
                           MiniGFX_GetWindowWidth()/2-image.width/2,
                           MiniGFX_GetWindowHeight()/2-image.height/2,
                           1.0f, WHITE);
	MiniGFX_DrawText(font, "minigfx imageview demo", 10, 10, 40, WHITE);
        MiniGFX_StopDrawing();
    }

    MiniGFX_UnloadSprite(&image);
    MiniGFX_CloseWindow();
    return 0;
}
