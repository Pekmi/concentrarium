#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include "../memory/ramGrid2d.h"
#include "../classes/Agent.h"
#include "../classes/logic/MineralBehavior.h"

// Une petite fonction pour afficher proprement
char getIcon(CellType type) {
    switch (type) {
        case CellType::EMPTY: return '.';
        case CellType::STONE: return '#';
        case CellType::DIRT:  return 'o';
        case CellType::SAND:  return 'S';
        case CellType::WATER: return '~';
        default: return '?';
    }
}

int main() {
    // init
    RamGrid2d world;
    int width = 54;
    int height = 26;

    // scène de test
    std::cout << "Génération du monde...\n";
    initGrid(world, width, height, 4);

    // sol en pierre
    for(int x = 0; x < width; x++) {
        Agent stone = { CellType::STONE, 0, 0 };
        setCell(world, x, height-1, AgentCodec::encode(stone)); // Sol
    }

    Agent empty = { CellType::EMPTY, 0, 0 };
    Agent sand = { CellType::SAND, 0, 0 };
    Agent stone = { CellType::STONE, 0, 0 };

    setCell(world, 0, 0, AgentCodec::encode(stone));

    for (int i = 0; i < width*2; ++i) {
        int stoneX = rand() % width;
        int stoneY = 3*height/4 + rand() % (height / 4);
        setCell(world, stoneX, stoneY, AgentCodec::encode(stone));
    }

    for (int i = 0; i < 25; ++i) {
        int sandX = rand() % width;
        int sandY = rand() % (height / 3);
        setCell(world, sandX, sandY, AgentCodec::encode(sand));
    }

    // // génération d'un entonnoir en pierre au milieu
    // Agent stone = { CellType::STONE, 0, 0 };
    // int funnelBaseX = rand() % (width - 10) + 5;
    // setCell(world, funnelBaseX, 10, AgentCodec::encode(stone));
    // setCell(world, funnelBaseX + 1, 11, AgentCodec::encode(stone));
    // setCell(world, funnelBaseX + 4, 11, AgentCodec::encode(stone));
    // setCell(world, funnelBaseX + 5, 10, AgentCodec::encode(stone));

    // // Random sand placements floating at the top
    // Agent sand = { CellType::SAND, 0, 0 };
    // for (int i = 0; i < 3; ++i) {
    //     int sandX = rand() % 10 + funnelBaseX;
    //     int sandY = rand() % 5 + 1;
    //     setCell(world, sandX, sandY, AgentCodec::encode(sand));
    // }

    // boucle principale
    while (true) {
        // rendu
        std::cout << "\033[2J\033[1;1H"; 
        std::cout << "--- SAND SIMULATION ---\n";

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                uint32_t raw = getCell(world, x, y);
                Agent a = AgentCodec::decode(raw);
                std::cout << getIcon(a.type) << " ";
            }
            std::cout << "\n";
        }

        // logique (update)
        for (int y = height - 1; y >= 0; y--) {
            
            for (int x = 0; x < width; x++) {
                
                uint32_t raw = getCell(world, x, y);
                Agent a = AgentCodec::decode(raw);

                // vide, on passe
                if (a.type == CellType::EMPTY) continue;

                // minéral, on traite avec MineralBehavior
                if (a.type == CellType::SAND || a.type == CellType::DIRT || a.type == CellType::STONE) {
                    MineralBehavior::update(world, x, y, raw);
                }
            }
        }

        // pause
        std::this_thread::sleep_for(std::chrono::milliseconds(350));
    }

    return 0;
}