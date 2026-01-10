#include <iostream>
#include "ramGrid3d.h"

// transforme les coordonnées en un index linéaire dans la RAM
static size_t coordinatesToRamIndex(const RamGrid3d& grid, int x, int y, int z) {
    return static_cast<size_t>(((z * grid.height + y) * grid.width + x) * grid.cellSize);
}

// vérifie si les coordonnées sont valides dans la grille
bool isPositionValid(const RamGrid3d& grid, int x, int y, int z) {
    return x >= 0 && x < grid.width &&
           y >= 0 && y < grid.height &&
           z >= 0 && z < grid.depth;
}

// initialise la grille avec les dimensions et la taille de cellule spécifiées
void initGrid(RamGrid3d& grid, int width, int height, int depth, int cellSize) {
    grid.width = width;
    grid.height = height;
    grid.depth = depth;
    grid.cellSize = cellSize;
    size_t totalBytes = static_cast<size_t>(width) * height * depth * cellSize;
    grid.RAM.assign(totalBytes, 0);
}

// définit la valeur de la cellule aux coordonnées
void setCell(RamGrid3d& grid, int x, int y, int z, uint32_t val) {
    if (!isPositionValid(grid, x, y, z)) {
        std::cout << "Erreur: coordonnées hors limites (setCell 3D)\n";
        return;
    }
    size_t idx = coordinatesToRamIndex(grid, x, y, z);
    // Écriture little-endian octet par octet
    for (int i = 0; i < grid.cellSize; ++i) {
        grid.RAM[idx + i] = static_cast<uint8_t>((val >> (8 * i)) & 0xFF);
    }
}

// récupère la valeur de la cellule aux coordonnées
uint32_t getCell(const RamGrid3d& grid, int x, int y, int z) {
    if (!isPositionValid(grid, x, y, z)) {
        std::cout << "Erreur: coordonnées hors limites (getCell 3D)\n";
        return 0;
    }
    size_t idx = coordinatesToRamIndex(grid, x, y, z);
    uint32_t val = 0;
    // Lecture little-endian octet par octet
    for (int i = 0; i < grid.cellSize; ++i) {
        val |= static_cast<uint32_t>(grid.RAM[idx + i]) << (8 * i);
    }
    return val;
}