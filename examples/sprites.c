#define MINIGFX_IMPLEMENTATION
#include "../minigfx.h"

int main()
{
    MiniGFX_CreateWindow(1024, 600, "Loading sprites in minigfx");
    Sprite image = MiniGFX_LoadSprite("../resources/header.png");
	float scale = 1.0f;

    while (!MiniGFX_WindowCloses()) {
		if (MiniGFX_IsKeyHeld(KEY_UP)) {
			scale += 0.001;
		} else if (MiniGFX_IsKeyHeld(KEY_DOWN)) {
			scale -= 0.001;
		}

        MiniGFX_StartDrawing();
        MiniGFX_ClearTo(BLACK);
        MiniGFX_DrawSprite(image, -150, 70, scale, WHITE);
        MiniGFX_StopDrawing();
    }

    MiniGFX_UnloadSprite(image);
    MiniGFX_CloseWindow();
    return 0;
}
