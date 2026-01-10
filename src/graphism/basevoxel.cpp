#include "Window.h"
#include <iostream> // Add this to use cin

// 1. The Vertex Shader (Positions)
const char* vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n" // Read input from Attribute 0
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n" // Output the position
    "}\0";

// 2. The Fragment Shader (Colors)
const char* fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n" // Output Orange Color
    "}\n\0";

int main() {
    Window myWindow(800, 600, "Concentrarium Voxel Engine");

    // --- SHADER COMPILATION START ---

    // 1. Compile Vertex Shader
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    // (Ideally, we would check for errors here, but let's skip for speed)

    // 2. Compile Fragment Shader
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    // 3. Link them into a Program
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // 4. Cleanup (Delete the individual papers now that we have the book)
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    // --- SHADER COMPILATION END ---
    
    float vertices[] = {
    -0.5f, -0.5f, 0.0f, // Bottom Left
     0.5f, -0.5f, 0.0f, // Bottom Right
     0.0f, 0.5f, 0.0f  // Top Center
    };
    
    unsigned int VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    while (!myWindow.shouldClose()) {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // 1. Activate the Orange Color Shader
        glUseProgram(shaderProgram);

        // 2. Activate the Triangle Data
        glBindVertexArray(VAO);

        // 3. Draw!
        glDrawArrays(GL_TRIANGLES, 0, 3);

        myWindow.update();
    }
    
    // --- ADD THIS BLOCK ---
    std::cout << "Program finished. Press Enter to exit..." << std::endl;
    std::cin.get(); 
    // ----------------------

    return 0;




}