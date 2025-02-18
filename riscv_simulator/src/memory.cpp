// #include "memory.h"
#include <vector>
#include <iostream>
using namespace std;

class Memory {
public:
    Memory(int size);
    int load(int address);
    void store(int address, int value);
    void printMemory();

private:
    vector<int> memory;
};

Memory::Memory(int size) : memory(size, 0) {}

int Memory::load(int address) {
    return memory[address];
}

void Memory::store(int address, int value) {
    memory[address] = value;
}

void Memory::printMemory() {
    std::cout << "Memory Dump:\n";
    for (size_t i = 0; i < memory.size(); i++) {
        if (memory[i] != 0)
            std::cout << "Memory[" << i << "]: " << memory[i] << "\n";
    }
}
