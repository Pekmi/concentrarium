cmake_minimum_required(VERSION 4.1)
project(concentrarium)

set(CMAKE_CXX_STANDARD 20)

# Exemples pour les grilles 2D et 3D
add_executable(example2d "src/memory/example2d.cpp" "src/memory/ramGrid2d.cpp")
add_executable(example3d "src/memory/example3d.cpp" "src/memory/ramGrid3d.cpp")

# Ancien exécutable (si besoin de le garder pour compatibilité)
# add_executable(2dRamGrid "src/memory/2dRamGrid.cpp")
add_executable(3dRamGrid "src/memory/ramGrid3d.cpp")
