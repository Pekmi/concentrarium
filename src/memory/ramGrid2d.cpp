#include <iostream>
#include <vector>
#include "2dRamGrid.h"

// setup
const int width  = 16;
const int height = 16;


// core functions
int coordinatesToRamIndex(int x, int y){
    return( x + ( y*width ) );
}

bool isPlacementValid(int x, int y){
    return( x >= 0  &&  x < width &&
            y >= 0  &&  y < height);
}

void setCell(std::vector<uint8_t>& RAM, int x, int y, uint8_t value){
    if(isPlacementValid(x, y)){
        RAM[coordinatesToRamIndex(x,y)] = value;
    }else{ std::cout << "Le placement est en dehors des limites (2dRamGrid setCell)"; }
}

uint8_t getCell(const std::vector<uint8_t>& RAM, int x, int y) {
    if(isPlacementValid(x, y)){
        return( RAM[coordinatesToRamIndex(x, y)] );
    }else{ std::cout << "Le placement est en dehors des limites (2dRamGrid getCell)"; return 0;}
}