#define MINIGFX_IMPLEMENTATION
#include "../minigfx.h"

int main()
{
    mgfx_CreateWindow(1024, 600, "Basic keyboard input in minigfx");
    mgfx_rec rec = (mgfx_rec){ 1024/2-64/2, 600/2-64/2, 64, 64 };
    mgfx_font font = mgfx_LoadFont("resources/font.ttf");

    while (!mgfx_WindowCloses()) {
        if (mgfx_IsKeyHeld(KEY_W)) {
            rec.y -= 4;
        }

        if (mgfx_IsKeyHeld(KEY_A)) {
            rec.x -= 4;
        }

        if (mgfx_IsKeyHeld(KEY_S)) {
            rec.y += 4;
        }

        if (mgfx_IsKeyHeld(KEY_D)) {
            rec.x += 4;
        }

        mgfx_StartDrawing();
        mgfx_ClearTo(MGFX_WHITE);
        mgfx_DrawRectangleRec(rec, MGFX_RED);
        mgfx_DrawText(font, "Hold WASD keys to move", 10.0, 10.0, 40.0, MGFX_DARKGRAY);
        mgfx_StopDrawing();
    }

    mgfx_CloseWindow();
    return 0;
}