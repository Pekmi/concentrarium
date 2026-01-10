#include <iostream>
#include "ramGrid2d.h"

// transforme les coordonnées en un index linéaire dans la RAM
static size_t coordinatesToRamIndex(const RamGrid2d& grid, int x, int y) {
    return static_cast<size_t>((y * grid.width + x) * grid.cellSize);
}

// vérifie si les coordonnées sont valides dans la grille
bool isPositionValid(const RamGrid2d& grid, int x, int y) {
    return x >= 0 && x < grid.width &&
           y >= 0 && y < grid.height;
}

// initialise la grille avec les dimensions et la taille de cellule spécifiées
void initGrid(RamGrid2d& grid, int width, int height, int cellSize) {
    grid.width = width;
    grid.height = height;
    grid.cellSize = cellSize;
    size_t totalBytes = static_cast<size_t>(width) * height * cellSize;
    grid.RAM.assign(totalBytes, 0);
}

// définit la valeur de la cellule aux coordonnées
void setCell(RamGrid2d& grid, int x, int y, uint32_t val) {
    if (!isPositionValid(grid, x, y)) {
        std::cout << "Erreur: coordonnees hors limites (setCell 2D)\n";
        return;
    }
    size_t idx = coordinatesToRamIndex(grid, x, y);
    // Écriture little-endian octet par octet
    for (int i = 0; i < grid.cellSize; ++i) {
        grid.RAM[idx + i] = static_cast<uint8_t>((val >> (8 * i)) & 0xFF);
    }
}

// récupère la valeur de la cellule aux coordonnées
uint32_t getCell(const RamGrid2d& grid, int x, int y) {
    if (!isPositionValid(grid, x, y)) {
        std::cout << "Erreur: coordonnees hors limites (getCell 2D)\n";
        return 0;
    }
    size_t idx = coordinatesToRamIndex(grid, x, y);
    uint32_t val = 0;
    // Lecture little-endian octet par octet
    for (int i = 0; i < grid.cellSize; ++i) {
        val |= static_cast<uint32_t>(grid.RAM[idx + i]) << (8 * i);
    }
    return val;
}