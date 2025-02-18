#ifndef MEMORY_H
#define MEMORY_H

#include <vector>

class Memory {
public:
    std::vector<int> memory;  // Simulated memory (4KB total)
    
    Memory(int size);
    
    int load(int address);
    void store(int address, int value);
    void printMemory();
};

#endif
