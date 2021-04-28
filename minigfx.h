#ifndef MINIGFX_H
#define MINIGFX_H

#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>

// ------- Types --------
typedef struct Color {
    unsigned int r;
    unsigned int g;
    unsigned int b;
    unsigned int a;
} Color;

// ------- Defines and macros -
#define WHITE       (Color){ 255, 255, 255, 255 }

// ------- Variables ---------
GLFWwindow *window;

int keyExit = GLFW_KEY_ESCAPE;

// -------- Functions -----------
static void KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (key == keyExit && action == GLFW_PRESS) {   // close
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

// ------ Core -------
// Window functions
void Mini_InitWindow(int w, int h, const char *title);
void Mini_CloseWindow();
int Mini_WindowCloses();

// Drawing functions
void Mini_StartDrawing();
void Mini_EndDrawing();
void Mini_ClearTo(Color color);

// ---------------------
// Window functions

// Initialize OpenGL context
void Mini_InitWindow(int w, int h, const char *title)
{
    // check if glfw inits properly
    if (!glfwInit()) {
        exit(1);
    }

    // initialize the window
    window = glfwCreateWindow(w, h, title, NULL, NULL);
    if (!window) {
        glfwTerminate();
        exit(1);
    }

    // set hints and callbacks
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    glfwSetKeyCallback(window, KeyCallback);

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);    // V-Sync on automatically
}

// Close the OpenGL context
void Mini_CloseWindow()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

// Check if the ESC key or close button is pressed
int Mini_WindowCloses()
{
    return glfwWindowShouldClose(window);
}

// Drawing functions

// Clear buffers
void Mini_StartDrawing()
{
    int width, height;

    glfwGetFramebufferSize(window, &width, &height);

    glViewport(0, 0, width, height);
    glClear(GL_COLOR_BUFFER_BIT);
}

// Swap buffers and poll events
void Mini_EndDrawing()
{
    glfwSwapBuffers(window);
    glfwPollEvents();
}

// Clear the background color to a certain color
void Mini_ClearTo(Color color)
{
    // do some clamping calculations
    // OpenGL does its coloring things with values from 0.0 to 1.0
    float r = (float)color.r / 255;
    float g = (float)color.g / 255;
    float b = (float)color.b / 255;
    float a = (float)color.a / 255;

    glClearColor(r, g, b, a);
}

#endif  // MINIGFX_H