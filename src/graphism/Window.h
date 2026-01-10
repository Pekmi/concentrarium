#pragma once // Prevents this file from being included twice

#include <glad/glad.h>  // MUST be included before GLFW
#include <GLFW/glfw3.h>
#include <iostream>

class Window {
public:
    // Constructor: Runs when you create the window
    Window(int width, int height, const char* title);
    
    // Destructor: Runs when the window is deleted
    ~Window();

    // Checks if the user wants to close the window
    bool shouldClose();

    // Swaps buffers (updates the screen) and checks for clicks
    void update();

private:
    GLFWwindow* window; // A pointer to the raw window structure
};