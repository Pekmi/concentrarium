#version 330 core
out vec4 FragColor;

in vec2 TexCoord; // Input from Vertex Shader

uniform sampler2D ourTexture; // The actual image data

void main()
{
    // Texture lookup: "Get the color at coordinate TexCoord"
    FragColor = texture(ourTexture, TexCoord);
}