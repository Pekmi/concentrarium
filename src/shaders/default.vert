#version 330 core
layout (location = 0) in vec3 aPos;

// Global variables that we set from C++
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
   // Multiply in REVERSE order: Proj * View * Model * Position
   gl_Position = projection * view * model * vec4(aPos, 1.0);
}