#include "Window.h"

// 1. The Constructor Implementation
Window::Window(int width, int height, const char* title) {
    // Start GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW!" << std::endl;
        return;
    }

    // configure options (optional, but good practice for Modern OpenGL)
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create the actual window
    window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window!" << std::endl;
        glfwTerminate();
        return;
    }

    // Make this window the current focus
    glfwMakeContextCurrent(window);

    // Load OpenGL functions using GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD!" << std::endl;
        return;
    }

    // Tell OpenGL the size of the window
    glViewport(0, 0, width, height);
}

// 2. The Destructor Implementation
Window::~Window() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

// 3. Helper functions
bool Window::shouldClose() {
    return glfwWindowShouldClose(window);
}

void Window::update() {
    glfwSwapBuffers(window); // Show the new frame
    glfwPollEvents();        // Check for mouse/keyboard input
}