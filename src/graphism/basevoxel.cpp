#include "Window.h"
#include <iostream> // Add this to use cin

int main() {
    Window myWindow(800, 600, "Concentrarium Voxel Engine");

    while (!myWindow.shouldClose()) {
        glClearColor(0.2f, 0.3f, 0.8f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        myWindow.update();
    }
    
    // --- ADD THIS BLOCK ---
    std::cout << "Program finished. Press Enter to exit..." << std::endl;
    std::cin.get(); 
    // ----------------------

    return 0;
}