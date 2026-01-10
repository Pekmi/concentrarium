#pragma once
#include <vector>
#include <cstdint>

// Constantes par défaut pour le terrain 2D
const int GRID_2D_WIDTH_DEFAULT  = 16;
const int GRID_2D_HEIGHT_DEFAULT = 16;

// Structure de la grille 2D dans la ram
struct RamGrid2d {
    int width;
    int height;
    int cellSize;
    std::vector<uint8_t> RAM;
};

// Initialise une grille 2D avec les dimensions et la taille de cellule spécifiées
void initGrid(RamGrid2d& grid, int width = GRID_2D_WIDTH_DEFAULT, int height = GRID_2D_HEIGHT_DEFAULT, int cellSize = 1);

// Vérifie si les coordonnées (x, y) sont valides dans la grille
bool isPositionValid(const RamGrid2d& grid, int x, int y);

// Récupère la valeur de la cellule aux coordonnées (x, y)
uint32_t getCell(const RamGrid2d& grid, int x, int y);

// Définit la valeur de la cellule aux coordonnées (x, y)
void setCell(RamGrid2d& grid, int x, int y, uint32_t val);