/*
 * minigfx: a small, simple and intuitive graphics library made in C
 * Made by Laurentino Luna (laurenloco) in 2021
 *
 * Version: 1.0.7
 *
 * minigfx is licensed under zlib. Check LICENSE for more
*/

#ifndef MINIGFX_H
#define MINIGFX_H

#if defined(_WIN32)
    #include "include/GLFW/glfw3.h"
#else
    #include <GLFW/glfw3.h>
#endif
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>	// boolean type

#ifdef MINIGFX_IMPLEMENTATION

#define STB_IMAGE_IMPLEMENTATION
#define FONTSTASH_IMPLEMENTATION
#define GLFONTSTASH_IMPLEMENTATION
#define RAYMATH_IMPLEMENTATION

#endif

#define MAX_BUFFERS         4
#define BUFFER_LEN       1024
#define PI  3.14159
#define DEG2RAD     (PI / 180)
#define RAD2DEG     (180 / PI)

#include "external/stb_image.h"
#include "external/fontstash.h"
#include "external/glfontstash.h"

// ------- Types --------
typedef struct mgfx_color {
    unsigned int r;
    unsigned int g;
    unsigned int b;
    unsigned int a;
} mgfx_color;

typedef struct mgfx_vec2d {
    float x, y;
} mgfx_vec2d;

typedef struct mgfx_rec {
    float x, y;
    int w, h;
} mgfx_rec;

typedef struct mgfx_circle {
    int x, y;
    float radius;
} mgfx_circle;

typedef struct mgfx_sprite {
    unsigned int ID;
    int width, height;
} mgfx_sprite;

typedef struct mgfx_camera2d {
    mgfx_vec2d offset;      // Displacement from the target
    mgfx_vec2d target;      // Zoom origin
    float rotation;
    float zoom;             // Camera's zoom (scaling). Default should be 1.0f
} mgfx_camera2d;

typedef unsigned char byte;
typedef int mgfx_font;

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

enum {
    MOUSE_LEFT = 0,
    MOUSE_RIGHT,
    MOUSE_MIDDLE
};

// ------- Defines and macros -
#define MGFX_WHITE           (mgfx_color){ 255, 255, 255, 255 }
#define MGFX_BLACK           (mgfx_color){ 0, 0, 0, 255       }
#define MGFX_DARKGRAY        (mgfx_color){ 68, 68, 68, 255 }
#define MGFX_GRAY            (mgfx_color){ 128, 128, 128, 255 }
#define MGFX_LIGHTGRAY       (mgfx_color){ 192, 192, 192, 255 }

#define MGFX_RED             (mgfx_color){ 255, 50, 100, 255  }
#define MGFX_ORANGE          (mgfx_color){ 255, 153, 51, 255  }
#define MGFX_YELLOW          (mgfx_color){ 255, 201, 90, 255  }
#define MGFX_GREEN           (mgfx_color){ 102, 255, 102, 255 }
#define MGFX_BLUE            (mgfx_color){ 0, 128, 255, 255   }
#define MGFX_PURPLE          (mgfx_color){ 178, 102, 255, 255 }
#define MGFX_PINK            (mgfx_color){ 255, 204, 255, 255 }
#define MGFX_MAGENTA         (mgfx_color){ 255, 102, 255, 255 }

#ifdef MINIGFX_IMPLEMENTATION

// ------- Variables ---------
GLFWwindow *window;
FONScontext *fs;

int keyExit = KEY_ESCAPE;
int windowWidth, windowHeight;

int currentKeyState[512] = { 0 };
int previousKeyState[512] = { 0 };

int currentMouseState[3] = { 0 };
int previousMouseState[3] = { 0 };

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

#endif

// ------ Core -------
// Window functions
int mgfx_CreateWindow(int w, int h, const char *title);                                             // Initialize OpenGL context
void mgfx_CloseWindow();                                                                            // Close the OpenGL context
int mgfx_WindowCloses();                                                                            // Check if the ESC key or close button is pressed
int mgfx_GetWindowWidth();                                                                          // Returns the window's width
int mgfx_GetWindowHeight();                                                                         // Returns the window's height

// Drawing functions
void mgfx_StartDrawing();                                                                           // Clear buffers
void mgfx_StopDrawing();                                                                            // Swap buffers and poll events
void mgfx_ClearTo(mgfx_color color);                                                                // Clear the background color to a certain color

// Keyboard functions
int mgfx_IsKeyUp(int key);                                                                          // Check if a key is up (not held)
int mgfx_IsKeyHeld(int key);                                                                        // Check if a key is held
int mgfx_IsKeyPressed(int key);                                                                     // Check if a key is pressed once
int mgfx_IsKeyReleased(int key);                                                                    // Check if a key is released

// Mouse functions
int mgfx_IsMouseButtonUp(int button);                                                               // Check if a mouse button is not being held
int mgfx_IsMouseButtonHeld(int button);                                                             // Check if a mouse button is being held
int mgfx_IsMouseButtonPressed(int button);                                                          // Check if a mouse button is pressed once
int mgfx_IsMouseButtonReleased(int button);                                                         // Check if a mouse button is released
int mgfx_GetMouseX();                                                                               // Returns mouse x position
int mgfx_GetMouseY();                                                                               // Returns mouse y position
mgfx_vec2d mgfx_GetMousePosition();                                                                 // Returns mouse position

// Misc. functions
int mgfx_RandomInt(int min, int max);                                                               // Returns a random integer

// ------ Shapes -------
void mgfx_DrawPixel(int x, int y, mgfx_color color);                                                // Draw a single pixel
void mgfx_DrawPixelV(mgfx_vec2d pos, mgfx_color color);                                             // Draw a single pixel with vec2d type

void mgfx_DrawRectangle(int x, int y, int w, int h, mgfx_color color);                              // Draw a rectangle
void mgfx_DrawRectangleV(mgfx_vec2d pos, mgfx_vec2d size, mgfx_color color);                        // Draw a rectangle with vec2d type
void mgfx_DrawRectangleRec(mgfx_rec rec, mgfx_color color);                                         // Draw a rectangle with Rectangle type

void mgfx_DrawCircle(int x, int y, float radius, mgfx_color color);                                 // Draw a circle
void mgfx_DrawCircleV(mgfx_vec2d pos, float radius, mgfx_color color);                              // Draw a circle with vec2d type
void mgfx_DrawCircleC(mgfx_circle circle, mgfx_color color);                                        // Draw a circle with Circle type

// ------ Sprites -------
mgfx_sprite mgfx_LoadSprite(mgfx_sprite *sprite, const char *path);                                 // Load sprite into GPU
void mgfx_UnloadSprite(mgfx_sprite *sprite);                                                        // Unload sprite from GPU
void mgfx_DrawSprite(mgfx_sprite *sprite, int x, int y, mgfx_color tint);                           // Draw a sprite
void mgfx_DrawSpriteEx(mgfx_sprite *sprite, int x, int y, float scale, float rotation, mgfx_color tint);  // Draw a sprite with extended options
void mgfx_DrawPartialSprite(mgfx_sprite *sprite, mgfx_rec rec, mgfx_vec2d pos, float scale, mgfx_color tint);// Draw part of a sprite

// ------ Text -------
int mgfx_LoadFont(const char *path);                                                                // Load font from path
void mgfx_DrawText(int font, const char *text, float x, float y, float fontSize, mgfx_color color); // Draw a piece of text
void mgfx_DrawTextBlurred(mgfx_font font, const char *text, float x, float y, float intensity, float fontSize, mgfx_color color);   // Draw a piece of blurred text
void mgfx_DrawTextShadow(mgfx_font font, const char *text, float x, float y, mgfx_color shadowColor,
                         float intensity, float fontSize, mgfx_color textColor);                              // Draw a piece of shadowed text
const char *mgfx_FormatText(const char *text, ...);                                                 // Formatting of text with variables to embed

#ifdef MINIGFX_IMPLEMENTATION

// ---------------------
// Window functions

// Initialize OpenGL context
int mgfx_CreateWindow(int w, int h, const char *title)
{
    // check if glfw inits properly
    if (!glfwInit()) {
        printf("MINIGFX ERROR: Could not initialize GLFW\n");
        return -1;
    }

    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    // initialize the window
    window = glfwCreateWindow(w, h, title, NULL, NULL);
    if (!window) {
        printf("MINIGFX ERROR: Could not initialize window properly\n");
        glfwTerminate();
        return -1;
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

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);   // black by default

    glEnable(GL_BLEND);     // enable color blending; required to work with transparencies
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // check for fs initialization
    fs = glfonsCreate(512, 512, FONS_ZERO_TOPLEFT);
    if (fs == NULL) {
        printf("FONTSTASH ERROR: Could not create stash\n");
        return -1;
    }

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();   // reset the projection matrix
    glOrtho(0, fbWidth, fbHeight, 0, 0, 1);     // top left corner is 0,0

    glMatrixMode(GL_MODELVIEW);     // THIS guy took me more time than necessary.
    glLoadIdentity();   // reset the modelview matrix

    srand(time(NULL));  // seed the random number generator
}

// Close the OpenGL context
void mgfx_CloseWindow()
{
    glfonsDelete(fs);

    glfwDestroyWindow(window);
    glfwTerminate();
}

// Check if the ESC key or close button is pressed
int mgfx_WindowCloses()
{
    return glfwWindowShouldClose(window);
}

// Returns the window's width
int mgfx_GetWindowWidth()
{
    glfwGetWindowSize(window, &windowWidth, &windowHeight);

    return windowWidth;
}

// Returns the window's height
int mgfx_GetWindowHeight()
{
    glfwGetWindowSize(window, &windowWidth, &windowHeight);

    return windowHeight;
}

// Drawing functions

// Clear buffers
void mgfx_StartDrawing()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
}

// Swap buffers and poll events
void mgfx_StopDrawing()
{
    glfwSwapBuffers(window);
    glfwPollEvents();

    glFlush();
}

// Clear the background color to a certain color
void mgfx_ClearTo(mgfx_color color)
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

// Check if a key is up (not held)
int mgfx_IsKeyUp(int key)
{
    if (glfwGetKey(window, key) == GLFW_RELEASE)
        return 1;
    else
        return 0;
}

// Check if a key is held down
int mgfx_IsKeyHeld(int key)
{
    if (glfwGetKey(window, key) == GLFW_PRESS)
        return 1;
    else
        return 0;
}

// Check if a key is pressed once
int mgfx_IsKeyPressed(int key)
{
    int pressed = 0;

    currentKeyState[key] = mgfx_IsKeyHeld(key);

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
int mgfx_IsKeyReleased(int key)
{
    int released = 0;

    currentKeyState[key] = mgfx_IsKeyUp(key);

    if (currentKeyState[key] != previousKeyState[key]) {
        if (currentKeyState[key])
            released = 1;
        previousKeyState[key] = currentKeyState[key];
    } else {
        released = 0;
    }

    return released;
}

// Mouse functions

// Check if a mouse button is not being held
int mgfx_IsMouseButtonUp(int button)
{
    if (glfwGetKey(window, button) == GLFW_RELEASE)
        return 1;
    else
        return 0;
}

// Check if a mouse button is being held
int mgfx_IsMouseButtonHeld(int button)
{
    if (glfwGetMouseButton(window, button) == GLFW_PRESS)
        return 1;
    else
        return 0;
}

// Check if a mouse button is pressed once
int mgfx_IsMouseButtonPressed(int button)
{
    int pressed = 0;

    currentMouseState[button] = mgfx_IsMouseButtonHeld(button);

    if (currentMouseState[button] != previousMouseState[button]) {
        if (currentMouseState[button])
            pressed = 1;
        previousMouseState[button] = currentMouseState[button];
    } else {
        pressed = 0;
    }

    return pressed;
}

// Check if a mouse button is released
int mgfx_IsMouseButtonReleased(int button)
{
    int released = 0;

    currentMouseState[button] = mgfx_IsMouseButtonUp(button);

    if (currentMouseState[button] != previousMouseState[button]) {
        if (currentMouseState[button])
            released = 1;
        previousMouseState[button] = currentMouseState[button];
    } else {
        released = 0;
    }

    return released;
}

// Returns mouse x position
int mgfx_GetMouseX()
{
    double mouseX, mouseY;
    glfwGetCursorPos(window, &mouseX, &mouseY);

    return (int)mouseX;
}

// Returns mouse y position
int mgfx_GetMouseY()
{
    double mouseX, mouseY;
    glfwGetCursorPos(window, &mouseX, &mouseY);

    return (int)mouseY;
}

// Returns mouse position
mgfx_vec2d mgfx_GetMousePos()
{
    double mouseX, mouseY;
    glfwGetCursorPos(window, &mouseX, &mouseY);

    mgfx_vec2d position = (mgfx_vec2d){ mouseX, mouseY };

    return position;
}

// Misc. functions

// Returns a random integer
int mgfx_RandomInt(int min, int max)
{
    if (min > max) {
        int tmp = max;
        max = min;
        min = tmp;
    }
    
    return (rand()%(abs(max-min)+1) + min);
}

// ------ Shapes -------

// Draw a single pixel
void mgfx_DrawPixel(int x, int y, mgfx_color color)
{
    glBegin(GL_POINTS);
        glColor4ub(color.r, color.g, color.b, color.a);
        glVertex2i(x, y);
    glEnd();
}

// Draw a single pixel with vec2d type
void mgfx_DrawPixelV(mgfx_vec2d pos, mgfx_color color)
{
    glBegin(GL_POINTS);
        glColor4ub(color.r, color.g, color.b, color.a);
        glVertex2f(pos.x, pos.y);
    glEnd();
}

// Draw a rectangle
void mgfx_DrawRectangle(int x, int y, int w, int h, mgfx_color color)
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
void mgfx_DrawRectangleV(mgfx_vec2d pos, mgfx_vec2d size, mgfx_color color)
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
void mgfx_DrawRectangleRec(mgfx_rec rec, mgfx_color color)
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
void mgfx_DrawCircle(int x, int y, float radius, mgfx_color color)
{
    // Avoid division by 0
    if (radius <= 0) radius = 0.1f;

    glBegin(GL_TRIANGLE_FAN);
        glColor4ub(color.r, color.g, color.b, color.a);
        glVertex2f(x, y);

        for (int i = 0; i <= 360; i++) {
            glVertex2f(x + sin(DEG2RAD*i) * radius, y + cos(DEG2RAD*i) * radius);
        }
    glEnd();    
}

// Draw a circle with vec2d type
void mgfx_DrawCircleV(mgfx_vec2d pos, float radius, mgfx_color color)
{
    mgfx_DrawCircle((float)pos.x, (float)pos.y, radius, color);
}

// Draw a circle with Circle type
void mgfx_DrawCircleC(mgfx_circle circle, mgfx_color color)
{
    mgfx_DrawCircle(circle.x, circle.y, circle.radius, color);
}

// ------ Sprites -------

// Load sprite into GPU
mgfx_sprite mgfx_LoadSprite(mgfx_sprite *sprite, const char *path)
{
    int imgWidth, imgHeight, imgBpp;

    // Loading image in question
    byte *data = stbi_load(path, &imgWidth, &imgHeight, &imgBpp, 4);

    if (data == NULL) {
        printf("MINIGFX ERROR: Could not load sprite properly\n");
    }

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

    sprite->ID = id;
    sprite->width = imgWidth;
    sprite->height = imgHeight;
}

// Unload sprite from GPU
void mgfx_UnloadSprite(mgfx_sprite *sprite)
{
    glDeleteTextures(1, &sprite->ID);
}

// Draw a sprite
void mgfx_DrawSprite(mgfx_sprite *sprite, int x, int y, mgfx_color tint)
{
    mgfx_DrawSpriteEx(sprite, x, y, 1.0f, 0.0f, tint);
}

// Draw a sprite with extended options
void mgfx_DrawSpriteEx(mgfx_sprite *sprite, int x, int y, float scale, float rotation, mgfx_color tint)
{
    glEnable(GL_TEXTURE_2D);    // enable texture usage

    glBindTexture(GL_TEXTURE_2D, sprite->ID);

    glPushMatrix();
        glTranslatef(x, y, 0);
        glScalef(scale, scale, 1.0f);
        glRotatef(rotation, 0, 0, 1.0f);

        glBegin(GL_QUADS);
            glColor4ub(tint.r, tint.g, tint.b, tint.a);
            glNormal3f(0.0f, 0.0f, 1.0f);                                       // Pointing towards viewer
            glTexCoord2f(0.0f, 0.0f); glVertex2f(0.0f, 0.0f);                   // Bottom-left corner of texture and quad
            glTexCoord2f(1.0f, 0.0f); glVertex2f(sprite->width, 0.0f);           // Bottom-right corner of texture and quad
            glTexCoord2f(1.0f, 1.0f); glVertex2f(sprite->width, sprite->height);  // Top-right corner of texture and quad
            glTexCoord2f(0.0f, 1.0f); glVertex2f(0.0f, sprite->height);          // Top-left corner of texture and quad
        glEnd();
    glPopMatrix();

    glDisable(GL_TEXTURE_2D);   // disable textures usage
}

// Draw part of a sprite
void mgfx_DrawPartialSprite(mgfx_sprite *sprite, mgfx_rec rec, mgfx_vec2d pos, float scale, mgfx_color tint)
{
    glEnable(GL_TEXTURE_2D);    // enable texture usage
    
    glBindTexture(GL_TEXTURE_2D, sprite->ID);
    
    glPushMatrix();
        glTranslatef(pos.x, pos.y, 0);
        glScalef(scale, scale, 1.0f);

        glBegin(GL_QUADS);
            glColor4ub(tint.r, tint.g, tint.b, tint.a);
            glNormal3f(0.0, 0.0, 1.0);

            // Bottom-left corner for sprite and quad
            glTexCoord2f((float)rec.x / sprite->width, (float)rec.y / sprite->height); 
            glVertex2f(0.0f, 0.0f);
        
            // Bottom-right corner for sprite and quad
            glTexCoord2f((float)(rec.x + rec.w) / sprite->width, (float)rec.y / sprite->height);
            glVertex2f(rec.w, 0.0f);
                
            // Top-right corner for sprite and quad
            glTexCoord2f((float)(rec.x + rec.w) / sprite->width, (float)(rec.y + rec.h) / sprite->height); 
            glVertex2f(rec.w, rec.h);
                
            // Top-left corner for sprite and quad
            glTexCoord2f((float)rec.x / sprite->width, (float)(rec.y + rec.h) / sprite->height);
            glVertex2f(0.0f, rec.h);
        glEnd();
    glPopMatrix();
    
    glDisable(GL_TEXTURE_2D);    // disable texture usage
}

// ------ Text -------

// Load font from path
int mgfx_LoadFont(const char *path)
{
    int fn = fonsAddFont(fs, "font", path);

    // Check if font was properly loaded
    if (fn == FONS_INVALID) {
        printf("MINIGFX ERROR: Could not load font\n");
        exit(1);
    }

    return fn;
}

// Draw a piece of text
void mgfx_DrawText(mgfx_font font, const char *text, float x, float y, float fontSize, mgfx_color color)
{
    unsigned int c = glfonsRGBA(color.r, color.g, color.b, color.a);

    fonsClearState(fs);
    fonsSetFont(fs, font);

    fonsSetSize(fs, fontSize);
    fonsSetColor(fs, c);
    fonsDrawText(fs, x, y+fontSize-6, text, NULL);
}

// Draw a piece of blurred text
void mgfx_DrawTextBlurred(mgfx_font font, const char *text, float x, float y, float intensity, float fontSize, mgfx_color color)
{
    unsigned int c = glfonsRGBA(color.r, color.g, color.b, color.a);

    fonsClearState(fs);
    fonsSetFont(fs, font);

    fonsSetSize(fs, fontSize);
    fonsSetColor(fs, c);
    fonsSetSpacing(fs, 5.0f);
    fonsSetBlur(fs, intensity);
    fonsDrawText(fs, x, y+fontSize-6, text, NULL);
}

// Draw a piece of shadowed text
void mgfx_DrawTextShadow(mgfx_font font, const char *text, float x, float y, mgfx_color shadowColor,
                         float intensity, float fontSize, mgfx_color textColor)
{
    unsigned int cs = glfonsRGBA(shadowColor.r, shadowColor.g, shadowColor.b, shadowColor.a);
    unsigned int ct = glfonsRGBA(textColor.r, textColor.g, textColor.b, textColor.a);

    fonsClearState(fs);
    fonsSetFont(fs, font);

    fonsSetSize(fs, fontSize);
    fonsSetColor(fs, cs);
    fonsSetSpacing(fs, 0.0f);
    fonsSetBlur(fs, intensity);
    fonsDrawText(fs, x, y+fontSize-6, text, NULL);

    fonsSetColor(fs, ct);
    fonsSetBlur(fs, 0);
    fonsDrawText(fs, x, y+fontSize-6, text, NULL);
}

// Formatting of text with variables to embed
const char *mgfx_FormatText(const char *text, ...)
{
    char buffers[MAX_BUFFERS][BUFFER_LEN] = { 0 };
    int index = 0;

    char *current_buffer = buffers[index];
    memset(current_buffer, 0, MAX_BUFFERS); // clear buffers before

    va_list args;
    va_start(args, text);
    vsnprintf(current_buffer, BUFFER_LEN, text, args);
    va_end(args);

    index++;
    if (index >= MAX_BUFFERS) {
        index = 0;
    }

    return current_buffer;
}

#endif

#endif  // MINIGFX_H
