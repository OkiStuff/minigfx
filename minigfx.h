#ifndef MINIGFX_H
#define MINIGFX_H

#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <stdio.h>
#include <stdlib.h>

// ------- Types --------
typedef struct Color {
    unsigned int r;
    unsigned int g;
    unsigned int b;
    unsigned int a;
} Color;

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

// ------- Variables ---------
GLFWwindow *window;

int keyExit = KEY_ESCAPE;

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

// ------ Core -------
// Window functions
void MiniGFX_InitWindow(int w, int h, const char *title);
void MiniGFX_CloseWindow();
int MiniGFX_WindowCloses();

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

// ---------------------
// Window functions

// Initialize OpenGL context
void MiniGFX_InitWindow(int w, int h, const char *title)
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

void MiniGFX_DrawPixel(int x, int y, Color color)
{
    glBegin(GL_POINTS);
        glColor4ub(color.r, color.g, color.b, color.a);
        glVertex2i(x, y);
    glEnd();
}

#endif  // MINIGFX_H