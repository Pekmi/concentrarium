#include <iostream>
#include <iomanip>
#include "ramGrid2d.h"

int main() {
    std::cout << "=== Exemple Terrain 2D ===" << std::endl;
    
    // Création d'une grille 2D de 8x8 avec cellules de 2 octets
    RamGrid2d grid;
    initGrid(grid, 16, 16, 2);
    
    std::cout << "Grille faite: " << grid.width << "x" << grid.height 
              << ", taille cellule: " << grid.cellSize << " octets" << std::endl;
    std::cout << "Memoire totale: " << grid.RAM.size() << " octets" << std::endl << std::endl;
    
    // Écriture de quelques valeurs
    setCell(grid, 0, 0, 0x1234);
    setCell(grid, 1, 0, 0x5678);
    setCell(grid, 0, 1, 0xABCD);
    setCell(grid, 7, 7, 0xFFFF);
    
    // Lecture et affichage
    std::cout << "Valeurs ecrites:" << std::endl;
    std::cout << "  (0,0) = 0x" << std::hex << std::setfill('0') << std::setw(4) 
              << getCell(grid, 0, 0) << std::endl;
    std::cout << "  (1,0) = 0x" << std::setw(4) << getCell(grid, 1, 0) << std::endl;
    std::cout << "  (0,1) = 0x" << std::setw(4) << getCell(grid, 0, 1) << std::endl;
    std::cout << "  (7,7) = 0x" << std::setw(4) << getCell(grid, 7, 7) << std::endl;
    
    // Test de validation de coordonnées
    std::cout << std::endl << "Test de validation:" << std::endl;
    std::cout << "  (5,5) valide? " << (isPositionValid(grid, 5, 5) ? "Oui" : "Non") << std::endl;
    std::cout << "  (10,5) valide? " << (isPositionValid(grid, 10, 5) ? "Oui" : "Non") << std::endl;
    
    // Test d'accès hors limites (affichera un message d'erreur)
    std::cout << std::endl << "Tentative d'acces hors limites:" << std::endl;
    uint32_t val = getCell(grid, 20, 20);
    
    return 0;
}
