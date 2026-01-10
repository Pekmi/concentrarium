#include <iostream>
#include <iomanip>
#include "ramGrid3d.h"

int main() {
    std::cout << "=== Exemple Terrain 3D ===" << std::endl;
    
    // Création d'une grille 3D de 8x8x4 avec cellules de 4 octets
    RamGrid3d grid;
    initGrid(grid, 8, 8, 4, 4);
    
    std::cout << "Grille faite: " << grid.width << "x" << grid.height << "x" << grid.depth
              << ", taille cellule: " << grid.cellSize << " octets" << std::endl;
    std::cout << "Mémoire totale: " << grid.RAM.size() << " octets" << std::endl << std::endl;
    
    // Écriture de quelques valeurs
    setCell(grid, 0, 0, 0, 0x12345678);
    setCell(grid, 1, 0, 0, 0xABCDEF00);
    setCell(grid, 0, 1, 0, 0x11223344);
    setCell(grid, 7, 7, 3, 0xFFFFFFFF);
    setCell(grid, 3, 3, 2, 0xDEADBEEF);
    
    // Lecture et affichage
    std::cout << "Valeurs ecrites:" << std::endl;
    std::cout << "  (0,0,0) = 0x" << std::hex << std::setfill('0') << std::setw(8) 
              << getCell(grid, 0, 0, 0) << std::endl;
    std::cout << "  (1,0,0) = 0x" << std::setw(8) << getCell(grid, 1, 0, 0) << std::endl;
    std::cout << "  (0,1,0) = 0x" << std::setw(8) << getCell(grid, 0, 1, 0) << std::endl;
    std::cout << "  (7,7,3) = 0x" << std::setw(8) << getCell(grid, 7, 7, 3) << std::endl;
    std::cout << "  (3,3,2) = 0x" << std::setw(8) << getCell(grid, 3, 3, 2) << std::endl;
    
    // Test de validation de coordonnées
    std::cout << std::endl << "Test de validation:" << std::endl;
    std::cout << "  (5,5,2) valide? " << (isPositionValid(grid, 5, 5, 2) ? "Oui" : "Non") << std::endl;
    std::cout << "  (18,5,2) valide? " << (isPositionValid(grid, 10, 5, 2) ? "Oui" : "Non") << std::endl;
    std::cout << "  (5,5,10) valide? " << (isPositionValid(grid, 5, 5, 10) ? "Oui" : "Non") << std::endl;
    
    // Test d'accès hors limites (affichera un message d'erreur)
    std::cout << std::endl << "Tentative d'accès hors limites:" << std::endl;
    uint32_t val = getCell(grid, 20, 20, 20);
    
    return 0;
}
