![](./resources/header.png)

# minigfx
Small graphics library made in C

## Intended to be:
- Simple to understand
- Intuitive
- Fun to use

## Features
- Creating windows easily
- Managing OpenGL easily
- Draw and manage shapes (pixels, rectangles and circles)
- Draw and manage images
- Usable for a variety of things; not just games! (check examples/graph as an example)

## Dependencies
OpenGL, GLFW

## Compiling a minigfx application
minigfx requires OpenGL. Here's a basic compilation command in Unix-like systems (where supported)
```
$ gcc main.c -lGL -lglfw -lm
```

## minigfx example application
You will need one file on your project: **minigfx.h**
```
#define MINIGFX_IMPLEMENTATION
#include "minigfx.h"

int main()
{
    MiniGFX_CreateWindow(1024, 600, "Basic Window in minigfx");

    while (!MiniGFX_WindowCloses()) {
        MiniGFX_StartDrawing();
        MiniGFX_ClearTo(WHITE);
        MiniGFX_EndDrawing();
    }

    MiniGFX_CloseWindow();
    return 0;
}
```
