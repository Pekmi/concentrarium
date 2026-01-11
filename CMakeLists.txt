cmake_minimum_required(VERSION 4.1)
project(concentrarium)

set(CMAKE_CXX_STANDARD 20)

# Exemples pour les grilles 2D et 3D
# add_executable(example2d "src/memory/example2d.cpp" "src/memory/ramGrid2d.cpp")
# add_executable(example3d "src/memory/example3d.cpp" "src/memory/ramGrid3d.cpp")

# Test avec simulation de gravité
add_executable(test 
    "src/classes/test.cpp" 
    "src/memory/ramGrid2d.cpp"
    "src/classes/logic/MineralBehavior.cpp"
)
target_include_directories(test PRIVATE "${CMAKE_SOURCE_DIR}/src")

