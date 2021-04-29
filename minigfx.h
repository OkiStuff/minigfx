#ifndef MINIGFX_H
#define MINIGFX_H

#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define STB_IMAGE_IMPLEMENTATION
#include "external/stb_image.h"

// ------- Types --------
typedef struct Color {
    unsigned int r;
    unsigned int g;
    unsigned int b;
    unsigned int a;
} Color;

typedef struct vec2d {
    float x, y;
} vec2d;

typedef struct Rectangle {
    float x, y;
    int w, h;
} Rectangle;

typedef struct Circle {
    int x, y;
    float radius;
} Circle;

typedef struct Sprite {
    unsigned int ID;
    int width, height;
} Sprite;

typedef unsigned char byte;

enum {
    KEY_NULL            = 0,
    // Alphanumeric keys
    KEY_APOSTROPHE      = 39,
    KEY_COMMA           = 44,
    KEY_MINUS           = 45,
    KEY_PERIOD          = 46,
    KEY_SLASH           = 47,
    KEY_ZERO            = 48,
    KEY_ONE             = 49,
    KEY_TWO             = 50,
    KEY_THREE           = 51,
    KEY_FOUR            = 52,
    KEY_FIVE            = 53,
    KEY_SIX             = 54,
    KEY_SEVEN           = 55,
    KEY_EIGHT           = 56,
    KEY_NINE            = 57,
    KEY_SEMICOLON       = 59,
    KEY_EQUAL           = 61,
    KEY_A               = 65,
    KEY_B               = 66,
    KEY_C               = 67,
    KEY_D               = 68,
    KEY_E               = 69,
    KEY_F               = 70,
    KEY_G               = 71,
    KEY_H               = 72,
    KEY_I               = 73,
    KEY_J               = 74,
    KEY_K               = 75,
    KEY_L               = 76,
    KEY_M               = 77,
    KEY_N               = 78,
    KEY_O               = 79,
    KEY_P               = 80,
    KEY_Q               = 81,
    KEY_R               = 82,
    KEY_S               = 83,
    KEY_T               = 84,
    KEY_U               = 85,
    KEY_V               = 86,
    KEY_W               = 87,
    KEY_X               = 88,
    KEY_Y               = 89,
    KEY_Z               = 90,

    // Function keys
    KEY_SPACE           = 32,
    KEY_ESCAPE          = 256,
    KEY_ENTER           = 257,
    KEY_TAB             = 258,
    KEY_BACKSPACE       = 259,
    KEY_INSERT          = 260,
    KEY_DELETE          = 261,
    KEY_RIGHT           = 262,
    KEY_LEFT            = 263,
    KEY_DOWN            = 264,
    KEY_UP              = 265,
    KEY_PAGE_UP         = 266,
    KEY_PAGE_DOWN       = 267,
    KEY_HOME            = 268,
    KEY_END             = 269,
    KEY_CAPS_LOCK       = 280,
    KEY_SCROLL_LOCK     = 281,
    KEY_NUM_LOCK        = 282,
    KEY_PRINT_SCREEN    = 283,
    KEY_PAUSE           = 284,
    KEY_F1              = 290,
    KEY_F2              = 291,
    KEY_F3              = 292,
    KEY_F4              = 293,
    KEY_F5              = 294,
    KEY_F6              = 295,
    KEY_F7              = 296,
    KEY_F8              = 297,
    KEY_F9              = 298,
    KEY_F10             = 299,
    KEY_F11             = 300,
    KEY_F12             = 301,
    KEY_LEFT_SHIFT      = 340,
    KEY_LEFT_CONTROL    = 341,
    KEY_LEFT_ALT        = 342,
    KEY_LEFT_SUPER      = 343,
    KEY_RIGHT_SHIFT     = 344,
    KEY_RIGHT_CONTROL   = 345,
    KEY_RIGHT_ALT       = 346,
    KEY_RIGHT_SUPER     = 347,
    KEY_KB_MENU         = 348,
    KEY_LEFT_BRACKET    = 91,
    KEY_BACKSLASH       = 92,
    KEY_RIGHT_BRACKET   = 93,
    KEY_GRAVE           = 96,
};

// ------- Defines and macros -
#define WHITE           (Color){ 255, 255, 255, 255 }
#define BLACK           (Color){ 0, 0, 0, 255       }

#define RED             (Color){ 255, 50, 100, 255  }
#define ORANGE          (Color){ 255, 153, 51, 255  }
#define YELLOW          (Color){ 255, 201, 90, 255  }
#define GREEN           (Color){ 102, 255, 102, 255 }
#define BLUE            (Color){ 128, 255, 0, 255   }
#define PURPLE          (Color){ 178, 102, 255, 255 }
#define PINK            (Color){ 255, 204, 255, 255 }
#define MAGENTA         (Color){ 255, 102, 255, 255 }

#define PI 3.14159265358979323846
#define DEG2RAD (PI / 180.0)
#define RAD2DEG (180.0 / PI)

// ------- Variables ---------
GLFWwindow *window;

int keyExit = KEY_ESCAPE;
int windowWidth, windowHeight;

int currentKeyState[512] = { 0 };
int previousKeyState[512] = { 0 };

// -------- Functions -----------
static void KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (key == keyExit && action == GLFW_PRESS) {   // close
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

static void ErrorCallback(int error, const char *description)
{
    printf("Error: %s\n", description);
}

// Draw a polygon of N sides
// https://github.com/raysan5/raylib/blob/1.0.4/src/shapes.c
static void DrawPoly(vec2d pos, int sides, float radius, float rotation, Color color)
{
    if (sides <= 3) sides = 3;

    glPushMatrix();
        glTranslatef(pos.x, pos.y, 0);
        glRotatef(rotation, 0, 0, 1);

        glBegin(GL_TRIANGLE_FAN);
            glColor4ub(color.r, color.g, color.b, color.a);
            glVertex2f(pos.x, pos.y);

            for (int i = 0; i < sides; i++) {
                glVertex2f(
                    radius*cos(i * 2 * PI / sides),
                    radius*sin(i * 2 * PI / sides)
                );
            }
        glEnd();
    glPopMatrix();
}

// ------ Core -------
// Window functions
void MiniGFX_CreateWindow(int w, int h, const char *title);
void MiniGFX_CloseWindow();
int MiniGFX_WindowCloses();
int MiniGFX_GetWindowWidth();
int MiniGFX_GetWindowHeight();

// Drawing functions
void MiniGFX_StartDrawing();
void MiniGFX_EndDrawing();
void MiniGFX_ClearTo(Color color);

// Keyboard functions
int MiniGFX_IsKeyUp(int key);
int MiniGFX_IsKeyHeld(int key);
int MiniGFX_IsKeyPressed(int key);
int MiniGFX_IsKeyReleased(int key);

// ------ Shapes -------
void MiniGFX_DrawPixel(int x, int y, Color color);
void MiniGFX_DrawPixelV(vec2d pos, Color color);

void MiniGFX_DrawRectangle(int x, int y, int w, int h, Color color);
void MiniGFX_DrawRectangleV(vec2d pos, vec2d size, Color color);
void MiniGFX_DrawRectangleRec(Rectangle rec, Color color);

void MiniGFX_DrawCircle(int x, int y, float radius, Color color);
void MiniGFX_DrawCircleV(vec2d pos, float radius, Color color);
void MiniGFX_DrawCircleC(Circle circle, Color color);

// ------ Sprites -------
Sprite MiniGFX_LoadSprite(const char *path);
void MiniGFX_UnloadSprite(Sprite sprite);
void MiniGFX_DrawSprite(Sprite sprite, int x, int y, float scale, Color tint);

// ---------------------
// Window functions

// Initialize OpenGL context
void MiniGFX_CreateWindow(int w, int h, const char *title)
{
    // check if glfw inits properly
    if (!glfwInit()) {
        exit(1);
    }

    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    // initialize the window
    window = glfwCreateWindow(w, h, title, NULL, NULL);
    if (!window) {
        glfwTerminate();
        exit(1);
    }

    // set hints and callbacks
    glfwSetKeyCallback(window, KeyCallback);
    glfwSetErrorCallback(ErrorCallback);

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);    // V-Sync on automatically
    glfwSetWindowPos(window, 230, 230);

    // Initialize graphics device
    int fbWidth, fbHeight;
    glfwGetFramebufferSize(window, &fbWidth, &fbHeight);
    glViewport(0, 0, fbWidth, fbHeight);

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);   // black by default

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();   // reset the projection matrix
    glOrtho(0, fbWidth, fbHeight, 0, 0, 1);     // top left corner is 0,0

    glMatrixMode(GL_MODELVIEW);     // THIS guy took me more time than necessary.
    glLoadIdentity();   // reset the modelview matrix
}

// Close the OpenGL context
void MiniGFX_CloseWindow()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

// Check if the ESC key or close button is pressed
int MiniGFX_WindowCloses()
{
    return glfwWindowShouldClose(window);
}

// Returns the window's width
int MiniGFX_GetWindowWidth()
{
    glfwGetWindowSize(window, &windowWidth, &windowHeight);

    return windowWidth;
}

// Returns the window's height
int MiniGFX_GetWindowHeight()
{
    glfwGetWindowSize(window, &windowWidth, &windowHeight);

    return windowHeight;
}

// Drawing functions

// Clear buffers
void MiniGFX_StartDrawing()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
}

// Swap buffers and poll events
void MiniGFX_EndDrawing()
{
    glfwSwapBuffers(window);
    glfwPollEvents();

    glFlush();
}

// Clear the background color to a certain color
void MiniGFX_ClearTo(Color color)
{
    // do some clamping calculations
    // OpenGL does its coloring things with values from 0.0 to 1.0
    float r = (float)color.r / 255;
    float g = (float)color.g / 255;
    float b = (float)color.b / 255;
    float a = (float)color.a / 255;

    glClearColor(r, g, b, a);
}

// Keyboard functions

// Check if a key is up
int MiniGFX_IsKeyUp(int key)
{
    if (glfwGetKey(window, key) == GLFW_RELEASE)
        return 1;
    else
        return 0;
}

// Check if a key is held down
int MiniGFX_IsKeyHeld(int key)
{
    if (glfwGetKey(window, key) == GLFW_PRESS)
        return 1;
    else
        return 0;
}

// Check if a key is pressed once
int MiniGFX_IsKeyPressed(int key)
{
    int pressed = 0;

    currentKeyState[key] = MiniGFX_IsKeyHeld(key);

    if (currentKeyState[key] != previousKeyState[key]) {
        if (currentKeyState[key])
            pressed = 1;
        previousKeyState[key] = currentKeyState[key];
    } else {
        pressed = 0;
    }

    return pressed;
}

// Check if a key is released
int MiniGFX_IsKeyReleased(int key)
{
    int released = 0;

    currentKeyState[key] = MiniGFX_IsKeyUp(key);

    if (currentKeyState[key] != previousKeyState[key]) {
        if (currentKeyState[key])
            released = 1;
        previousKeyState[key] = currentKeyState[key];
    } else {
        released = 0;
    }

    return released;
}

// ------ Shapes -------

// Draw a single pixel
void MiniGFX_DrawPixel(int x, int y, Color color)
{
    glBegin(GL_POINTS);
        glColor4ub(color.r, color.g, color.b, color.a);
        glVertex2i(x, y);
    glEnd();
}

// Draw a single pixel with vec2d type
void MiniGFX_DrawPixelV(vec2d pos, Color color)
{
    glBegin(GL_POINTS);
        glColor4ub(color.r, color.g, color.b, color.a);
        glVertex2f(pos.x, pos.y);
    glEnd();
}

// Draw a rectangle
void MiniGFX_DrawRectangle(int x, int y, int w, int h, Color color)
{
    glBegin(GL_QUADS);
        glColor4ub(color.r, color.g, color.b, color.a);
        glVertex2i(x, y);
        glVertex2i(x + w, y);
        glVertex2i(x + w, y + h);
        glVertex2i(x, y + h);
    glEnd();
}

// Draw a rectangle with vec2d type
void MiniGFX_DrawRectangleV(vec2d pos, vec2d size, Color color)
{
    glBegin(GL_QUADS);
        glColor4ub(color.r, color.g, color.b, color.a);
        glVertex2i(pos.x, pos.y);
        glVertex2i(pos.x + size.x, pos.y);
        glVertex2i(pos.x + size.x, pos.y + size.y);
        glVertex2i(pos.x, pos.y + size.y);
    glEnd();
}

// Draw a rectangle with Rectangle type
void MiniGFX_DrawRectangleRec(Rectangle rec, Color color)
{
    glBegin(GL_QUADS);
        glColor4ub(color.r, color.g, color.b, color.a);
        glVertex2i(rec.x, rec.y);
        glVertex2i(rec.x + rec.w, rec.y);
        glVertex2i(rec.x + rec.w, rec.y + rec.h);
        glVertex2i(rec.x, rec.y + rec.h);
    glEnd();
}

// Draw a circle
void MiniGFX_DrawCircle(int x, int y, float radius, Color color)
{
    // Avoid division by 0
    if (radius <= 0) radius = 0.1f;

    glEnable(GL_POLYGON_SMOOTH);
    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
    
    glBegin(GL_TRIANGLE_FAN);
        glColor4ub(color.r, color.g, color.b, color.a);
        glVertex2f(x, y);

        for (int i = 0; i <= 360; i++) {
            glVertex2f(x + sin(DEG2RAD*i) * radius, y + cos(DEG2RAD*i) * radius);
        }
    glEnd();
    
    glDisable(GL_POLYGON_SMOOTH);
}

// Draw a circle with vec2d type
void MiniGFX_DrawCircleV(vec2d pos, float radius, Color color)
{
    MiniGFX_DrawCircle((float)pos.x, (float)pos.y, radius, color);
}

// Draw a circle with Circle type
void MiniGFX_DrawCircleC(Circle circle, Color color)
{
    MiniGFX_DrawCircle(circle.x, circle.y, circle.radius, color);
}

// ------ Sprites -------

// Load sprite into GPU
Sprite MiniGFX_LoadSprite(const char *path)
{
    Sprite sprite;
    int imgWidth, imgHeight, imgBpp;

    // Loading image in question
    byte *data = stbi_load(path, &imgWidth, &imgHeight, &imgBpp, 4);

    // Convert data into an OpenGL texture
    GLuint id;
    glGenTextures(1, &id);  // Generate texture
    glBindTexture(GL_TEXTURE_2D, id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);       // Set texture to repeat on the x-axis
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);       // Set texture to repeat on the y-axis
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);  // Filter for pixel-perfect drawing
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);  // Filter for pixel-perfect drawing

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, imgWidth, imgHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

    // At this point we uploaded to GPU

    // Free the loaded data from RAM
    stbi_image_free(data);

    sprite.ID = id;
    sprite.width = imgWidth;
    sprite.height = imgHeight;

    return sprite;
}

// Unload sprite from GPU
void MiniGFX_UnloadSprite(Sprite sprite)
{
    glDeleteTextures(1, &sprite);
}

// Draw a sprite
void MiniGFX_DrawSprite(Sprite sprite, int x, int y, float scale, Color tint)
{
    glEnable(GL_TEXTURE_2D);    // enable texture usage

    glBindTexture(GL_TEXTURE_2D, sprite.ID);

    glPushMatrix();
        glTranslatef(x, y, 0);
        glScalef(scale, scale, 1.0f);

        glBegin(GL_QUADS);
            glColor4ub(tint.r, tint.g, tint.b, tint.a);
            glNormal3f(0.0f, 0.0f, 1.0f);                                       // Pointing towards viewer
            glTexCoord2f(0.0f, 0.0f); glVertex2f(0.0f, 0.0f);                   // Bottom-left corner of texture and quad
            glTexCoord2f(1.0f, 0.0f); glVertex2f(sprite.width, 0.0f);           // Bottom-right corner of texture and quad
            glTexCoord2f(1.0f, 1.0f); glVertex2f(sprite.width, sprite.height);  // Top-right corner of texture and quad
            glTexCoord2f(0.0f, 1.0f); glVertex2f(0.0f, sprite.height);          // Top-left corner of texture and quad
        glEnd();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);   // disable textures usage
}

#endif  // MINIGFX_H