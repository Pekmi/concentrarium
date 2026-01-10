#pragma once
#include <vector>
#include <cstdint>

// Constantes par défaut pour le terrain 3D
const int GRID_3D_WIDTH_DEFAULT  = 16;
const int GRID_3D_HEIGHT_DEFAULT = 16;
const int GRID_3D_DEPTH_DEFAULT  = 16;

// Structure de la grille 3D dans la ram
struct RamGrid3d {
    int width;
    int height;
    int depth;
    int cellSize;
    std::vector<uint8_t> RAM;
};

// Initialise une grille 3D avec les dimensions et taille de cellule spécifiées
void initGrid(RamGrid3d& grid, int width = GRID_3D_WIDTH_DEFAULT, int height = GRID_3D_HEIGHT_DEFAULT, int depth = GRID_3D_DEPTH_DEFAULT, int cellSize = 1);

// Vérifie si les coordonnées (x, y, z) sont valides dans la grille
bool isPositionValid(const RamGrid3d& grid, int x, int y, int z);

// Récupère la valeur de la cellule aux coordonnées (x, y, z)
uint32_t getCell(const RamGrid3d& grid, int x, int y, int z);

// Définit la valeur de la cellule aux coordonnées (x, y, z)
void setCell(RamGrid3d& grid, int x, int y, int z, uint32_t val);
