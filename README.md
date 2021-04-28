# minigfx
Small graphics library made in C

## Objective
To make it really simple to develop OpenGL applications. Inspired by raylib.

## Dependencies
OpenGL, GLFW

## Compiling a minigfx application
minigfx requires OpenGL. Here's a basic compilation command in Unix-like systems (where supported)
```
$ gcc main.c -lGL -lglfw
```

## minigfx example application
You will need one file on your project: **minigfx.h**
```
#define MINIGFX_IMPLEMENTATION
#include "minigfx.h"

int main()
{
    Mini_InitWindow(1024, 600, "Basic Window in minigfx");

    while (!Mini_WindowCloses()) {
        Mini_StartDrawing();
        Mini_ClearTo(WHITE);
        Mini_EndDrawing();
    }

    Mini_CloseWindow();
    return 0;
}
```