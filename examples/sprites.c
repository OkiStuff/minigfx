#define MINIGFX_IMPLEMENTATION
#include "../minigfx.h"

int main()
{
    mgfx_CreateWindow(1024, 600, "Loading sprites in minigfx");
    mgfx_sprite image;
    
    mgfx_LoadSprite(&image, "../resources/header.png");
	float scale = 1.0f;

    while (!mgfx_WindowCloses()) {
		if (mgfx_IsKeyHeld(KEY_UP)) {
			scale += 0.001;
		} else if (mgfx_IsKeyHeld(KEY_DOWN)) {
			scale -= 0.001;
		}

        mgfx_StartDrawing();
        mgfx_ClearTo(MGFX_BLACK);
        mgfx_DrawSprite(&image, -150, 70, scale, MGFX_WHITE);
        mgfx_StopDrawing();
    }

    mgfx_UnloadSprite(&image);
    mgfx_CloseWindow();
    return 0;
}
