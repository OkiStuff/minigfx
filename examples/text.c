#define MINIGFX_IMPLEMENTATION
#include "../minigfx.h"

int main()
{
    mgfx_CreateWindow(1024, 600, "Displaying text in minigfx");
    mgfx_font fontNormal = mgfx_LoadFont("resources/font.ttf");
    mgfx_font fontJapanese = mgfx_LoadFont("resources/font-japan.ttf");

    while (!mgfx_WindowCloses()) {
        // Be careful with overexploiting some of these values...

        mgfx_StartDrawing();
        mgfx_ClearTo(MGFX_GRAY);
        mgfx_DrawText(fontNormal, "Some normal text over here...", 10, 10, 50, MGFX_BLACK);
        mgfx_DrawTextBlurred(fontNormal, "Some blurry text over there...", 10, 70, 9, 50, MGFX_BLACK);
        mgfx_DrawTextShadow(fontNormal, "Anyway look at this shadow!!", 400, 140, MGFX_BLACK, 100, 50, MGFX_WHITE);
        mgfx_DrawText(fontJapanese, "なんで今日本人なの？", 230, 340, 40, MGFX_BLACK);
        mgfx_DrawText(fontNormal, "Small text!", 100, 200, 30, MGFX_PINK);
        mgfx_DrawTextBlurred(fontNormal, "Big text!", 560, 340, 8, 120, MGFX_RED);
        
        mgfx_DrawText(fontNormal, "minigfx sure is fun!", 10, 540, 50, MGFX_BLACK);
        mgfx_StopDrawing();
    }

    mgfx_CloseWindow();
    return 0;
}