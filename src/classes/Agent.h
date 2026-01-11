#pragma once
#include <cstdint>


// Types of cells in the simulation
enum class CellType : uint8_t {
    EMPTY = 0,

    // MINERALS (MineralBehaviour)
    STONE = 1,
    DIRT = 2,
    SAND = 3,

    // FLUIDS (FluidBehaviour)
    WATER = 90,
    LAVA = 91,

    // ORGANIC (OrganicBehaviour)
    LIFE = 100
};


// Logic structure 
struct Agent
{
    CellType type; 
    uint8_t variant;
    uint16_t data;
};


// Codecs (readable to RAM representation)
class AgentCodec {
public:
    
    // Transforms the readable structure into a compact uint32_t representation
    static uint32_t encode(const Agent& agent) {
        uint32_t raw = 0;
        raw |= (static_cast<uint8_t>(agent.type));              // bits 0-7
        raw |= (static_cast<uint32_t>(agent.variant) << 8);     // bits 8-15
        raw |= (static_cast<uint32_t>(agent.data) << 16);       // bits 16-31
        return raw;
    }

    // Transforms the compact uint8_t representation back into the readable structure
    static Agent decode(uint32_t raw) {
        Agent agent;
        agent.type = static_cast<CellType>(raw & 0xFF);                 // bits 0-7
        agent.variant = static_cast<uint8_t>((raw >> 8) & 0xFF);        // bits 8-15
        agent.data = static_cast<uint16_t>((raw >> 16) & 0xFFFF);       // bits 16-31
        return agent;
    }

};