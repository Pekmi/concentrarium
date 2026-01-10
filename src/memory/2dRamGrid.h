#pragma once
#include <vector>
#include <cstdint>

// setup
const int GRID_WIDTH = 16;
const int GRID_HEIGHT = 16;

// 
struct RamGrid2d {
    std::vector<uint8_t> RAM;
};

// Prototypes des fonctions (Promesses)
void initGrid(RamGrid2d& grid);
bool isValid(int x, int y);
uint8_t getCell(const RamGrid2d& grid, int x, int y);
void setCell(RamGrid2d& grid, int x, int y, uint8_t val);