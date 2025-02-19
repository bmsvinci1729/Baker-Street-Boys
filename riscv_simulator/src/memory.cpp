// #include "memory.h"
#include <vector>
#include <iostream>
using namespace std;

class Memory {
public:
    vector<int> memory;  // Simulated memory (4KB total)
    
    Memory(int size);
    
    int load(int address);
    void store(int address, int value);
    void printMemory();
};

Memory::Memory(int size) : memory(size, 0) {}

int Memory::load(int address) {
    return memory[address]; // so loads the value present at "address" in the memory vector
}

void Memory::store(int address, int value) {
    memory[address] = value; // value stored at address
}


// need to do the beautification part

void Memory::printMemory() {
    std::cout << "Memory Dump:\n";
    for (int i = 0; i < memory.size(); i++) {
        if (memory[i] != 0)
            std::cout << "Memory[" << i << "]: " << memory[i] << "\n";
    }
}
 
