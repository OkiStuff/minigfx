// A port of Imageview made by laurenloco
// Originally made with raylib

#define MINIGFX_IMPLEMENTATION
#include "../../minigfx.h"

mgfx_sprite image;

int main(int argc, char *argv[])
{
    mgfx_CreateWindow(1920, 1080, "Imageview");
    mgfx_LoadSprite(&image, argv[1]);
    int font = mgfx_LoadFont("/usr/share/fonts/ubuntu/UbuntuMono-R.ttf");

    while (!mgfx_WindowCloses()) {
        mgfx_StartDrawing();
        mgfx_DrawSprite(&image,
                           mgfx_GetWindowWidth()/2-image.width/2,
                           mgfx_GetWindowHeight()/2-image.height/2,
                           1.0f, MGFX_WHITE);
	    mgfx_DrawText(font, "minigfx imageview demo", 10, 10, 40, MGFX_WHITE);
        mgfx_StopDrawing();
    }

    mgfx_UnloadSprite(&image);
    mgfx_CloseWindow();
    return 0;
}
