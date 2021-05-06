#define MINIGFX_IMPLEMENTATION
#include "../minigfx.h"

int main()
{
    mgfx_CreateWindow(1024, 600, "Basic keyboard input in minigfx");
    Rectangle rec = (Rectangle){ 1024/2-64/2, 600/2-64/2, 64, 64 };
    int font = mgfx_LoadFont("font.ttf");

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
        mgfx_ClearTo(WHITE);
        mgfx_DrawRectangleRec(rec, RED);
        mgfx_DrawText(font, "Hold WASD keys to move", 10.0, 10.0, 40.0, DARKGRAY);
        mgfx_StopDrawing();
    }

    mgfx_CloseWindow();
    return 0;
}