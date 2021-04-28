#define MINIGFX_IMPLEMENTATION
#include "../minigfx.h"

int main()
{
    MiniGFX_InitWindow(1024, 600, "Basic keyboard input in minigfx");
    Rectangle rec = (Rectangle){ 1024/2-64/2, 600/2-64/2, 64, 64 };

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
        MiniGFX_EndDrawing();
    }

    MiniGFX_CloseWindow();
    return 0;
}