#pragma once
#include <cstdint>
struct RamGrid2d;
struct Agent;

class MineralBehavior {
public:

    // public function to update mineral behavior
    static void update(RamGrid2d& grid, int x, int y, uint32_t rawSelf);

private:

    // règle gravité
    static bool applyGravity(RamGrid2d& grid, int x, int y, const Agent& self, uint32_t rawSelf);
    
};