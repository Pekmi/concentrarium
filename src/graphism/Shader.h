#pragma once

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader {
public:
    // The Program ID (the "handle" to the shader on the GPU)
    unsigned int ID;

    // Constructor: Reads the files and builds the shader
    Shader(const char* vertexPath, const char* fragmentPath);

    // Activates the shader
    void use();

    // Utility to delete the program when we are done
    void deleteProgram();
    
private:
    // Helper function to check for compile errors
    void checkCompileErrors(unsigned int shader, std::string type);
};