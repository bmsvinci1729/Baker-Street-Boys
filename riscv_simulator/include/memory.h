#ifndef MEMORY_H
#define MEMORY_H

#include <vector>
using namespace std;

class Memory {
public:
    vector<int> memory;  // Simulated memory (4KB total)
    
    Memory(int size);
    
    int load(int address);
    void store(int address, int value);
    void printMemory();
};

#endif
