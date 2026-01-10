cmake_minimum_required(VERSION 4.1)
project(concentrarium)

set(CMAKE_CXX_STANDARD 20)

# SETUP LIBRARIES (The "Glue")

# --- GLFW ---
option(GLFW_BUILD_DOCS "Build the GLFW documentation" OFF)
option(GLFW_INSTALL "Generate installation target" OFF)
add_subdirectory(vendor/glfw)

# --- GLAD ---
add_library(glad vendor/glad/src/glad.c)
target_include_directories(glad PUBLIC vendor/glad/include)

# --- GLM ---
add_library(glm INTERFACE)
target_include_directories(glm INTERFACE vendor/glm)

add_executable(graphism 
    src/graphism/basevoxel.cpp 
    src/graphism/Window.cpp
    src/graphism/Shader.cpp
)

target_link_libraries(graphism 
    PRIVATE 
    glfw 
    glad 
    glm
)

# Automatically copy the 'shaders' folder to the build directory
file(COPY ${CMAKE_SOURCE_DIR}/src/shaders DESTINATION ${CMAKE_BINARY_DIR})