#include "Window.h"
#include "Shader.h"
#include <iostream> // Add this to use cin

int main() {
    Window myWindow(800, 600, "Concentrarium Voxel Engine");

    // --- SHADER COMPILATION START ---

    Shader myShader("src/shaders/default.vert", "src/shaders/default.frag");

    // --- SHADER COMPILATION END ---
    
    float vertices[] = {
    -0.5f,  0.5f, 0.0f, // Top Left
     0.5f,  0.5f, 0.0f, // Top Right
    -0.5f, -0.5f, 0.0f,  // Bottom Left
     0.5f, -0.5f, 0.0f   // Bottom Right
    };
    
    unsigned int indices[] = {
        0, 1, 3, // Top Triangle
        0, 2, 3  // Bottom Triangle
    };

    unsigned int VAO, VBO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    while (!myWindow.shouldClose()) {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // 1. Activate the Orange Color Shader
        myShader.use();

        // 2. Activate the Triangle Data
        glBindVertexArray(VAO);

        // DRAW ELEMENTS instead of Arrays
        // Mode: Triangles
        // Count: 6 (We have 6 indices in our array)
        // Type: Unsigned Int (The type of our indices array)
        // Offset: 0
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        myWindow.update();
    }

    myShader.deleteProgram();
    return 0;
}