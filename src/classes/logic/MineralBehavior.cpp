#include "MineralBehavior.h"
#include "../Agent.h"
#include "../../memory/ramGrid2d.h"


void MineralBehavior::update(RamGrid2d& grid, int x, int y, uint32_t rawSelf) {
    
    // décode une seule fois pour tout le monde
    Agent self = AgentCodec::decode(rawSelf);

    // applique la gravité
    if (applyGravity(grid, x, y, self, rawSelf)) return;

}


bool MineralBehavior::applyGravity(RamGrid2d& grid, int x, int y, const Agent& self, uint32_t rawSelf) {
    int yBas = y + 1;
    // si déjà en bas
    if (!isPositionValid(grid, x, yBas)) return false;

    uint32_t rawBelow = getCell(grid, x, yBas);
    Agent below = AgentCodec::decode(rawBelow);

    if (below.type == CellType::EMPTY) {
        setCell(grid, x, yBas, rawSelf);
        setCell(grid, x, y, 0);
        return true;
    }
    
    // sable coule dans l'eau
    if (self.type == CellType::SAND && below.type == CellType::WATER) {
        setCell(grid, x, yBas, rawSelf);
        setCell(grid, x, y, rawBelow);
        return true;
    }

    return false; // peut pas tomber
}