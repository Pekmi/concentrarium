#include "Window.h"
#include "Shader.h"
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

int main() {
    Window myWindow(800, 600, "Concentrarium Voxel Engine");

    // --- SHADER COMPILATION START ---

    Shader myShader("src/shaders/default.vert", "src/shaders/default.frag");

    // --- SHADER COMPILATION END ---
    
    // 36 Vertices (6 faces, 2 triangles per face)
    // Format: X, Y, Z
    float vertices[] = {
        -0.5f, -0.5f, -0.5f, 
         0.5f, -0.5f, -0.5f,  
         0.5f,  0.5f, -0.5f,  
         0.5f,  0.5f, -0.5f,  
        -0.5f,  0.5f, -0.5f, 
        -0.5f, -0.5f, -0.5f, 

        -0.5f, -0.5f,  0.5f, 
         0.5f, -0.5f,  0.5f,  
         0.5f,  0.5f,  0.5f,  
         0.5f,  0.5f,  0.5f,  
        -0.5f,  0.5f,  0.5f, 
        -0.5f, -0.5f,  0.5f, 

        -0.5f,  0.5f,  0.5f, 
        -0.5f,  0.5f, -0.5f, 
        -0.5f, -0.5f, -0.5f, 
        -0.5f, -0.5f, -0.5f, 
        -0.5f, -0.5f,  0.5f, 
        -0.5f,  0.5f,  0.5f, 

         0.5f,  0.5f,  0.5f, 
         0.5f,  0.5f, -0.5f, 
         0.5f, -0.5f, -0.5f, 
         0.5f, -0.5f, -0.5f, 
         0.5f, -0.5f,  0.5f, 
         0.5f,  0.5f,  0.5f, 

        -0.5f, -0.5f, -0.5f, 
         0.5f, -0.5f, -0.5f, 
         0.5f, -0.5f,  0.5f, 
         0.5f, -0.5f,  0.5f, 
        -0.5f, -0.5f,  0.5f, 
        -0.5f, -0.5f, -0.5f, 

        -0.5f,  0.5f, -0.5f, 
         0.5f,  0.5f, -0.5f, 
         0.5f,  0.5f,  0.5f, 
         0.5f,  0.5f,  0.5f, 
        -0.5f,  0.5f,  0.5f, 
        -0.5f,  0.5f, -0.5f
    };

    unsigned int VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glEnable(GL_DEPTH_TEST);

    while (!myWindow.shouldClose()) {
        
        // Get the current size of the window (this changes when you resize!)
        int width = myWindow.getWidth();
        int height = myWindow.getHeight();

        // Tell OpenGL to paint on the WHOLE window
        // (If you skip this, the image might stay stuck in the corner or stretch weirdly)
        glViewport(0, 0, width, height);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        // Clear both Color AND Depth info
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        myShader.use();

        // MODEL: Where is the object? 
        // We leave it at (0,0,0) for now (Identity Matrix)
        glm::mat4 model = glm::mat4(1.0f); 
        // Optional: Spin it! Uncomment the next line to see it rotate
        model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));

        // VIEW: Where is the camera?
        // We move the "Camera" BACKWARDS (positive Z) so we can see the object
        glm::mat4 view = glm::mat4(1.0f);
        view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f)); 
       
        // PROJECTION: with the NEW Aspect Ratio
        // IMPORTANT: Use (float) to prevent integer division (e.g. 800/600 = 1 instead of 1.33)
        float aspectRatio = (float)width / (float)height;
        glm::mat4 projection = glm::perspective(glm::radians(45.0f), aspectRatio, 0.1f, 100.0f);

        // Send matrices to the Shader
        int modelLoc = glGetUniformLocation(myShader.ID, "model");
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

        int viewLoc = glGetUniformLocation(myShader.ID, "view");
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
        
        int projLoc = glGetUniformLocation(myShader.ID, "projection");
        glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

        // ------------------------------------

        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 36);

        myWindow.update();
    }

    myShader.deleteProgram();
    return 0;
}