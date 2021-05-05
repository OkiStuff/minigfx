#define MINIGFX_IMPLEMENTATION
#include "../minigfx.h"

int main()
{
    MiniGFX_CreateWindow(1024, 600, "Basic keyboard input in minigfx");
    Rectangle rec = (Rectangle){ 1024/2-64/2, 600/2-64/2, 64, 64 };
    int font = MiniGFX_LoadFont("font.ttf");

    while (!MiniGFX_WindowCloses()) {
        if (MiniGFX_IsKeyHeld(KEY_W)) {
            rec.y -= 4;
        }

        if (MiniGFX_IsKeyHeld(KEY_A)) {
            rec.x -= 4;
        }

        if (MiniGFX_IsKeyHeld(KEY_S)) {
            rec.y += 4;
        }

        if (MiniGFX_IsKeyHeld(KEY_D)) {
            rec.x += 4;
        }

        MiniGFX_StartDrawing();
        MiniGFX_ClearTo(WHITE);
        MiniGFX_DrawRectangleRec(rec, RED);
        MiniGFX_DrawText(font, "Hold WASD keys to move", 10.0, 10.0, 40.0, DARKGRAY);
        MiniGFX_StopDrawing();
    }

    MiniGFX_CloseWindow();
    return 0;
}