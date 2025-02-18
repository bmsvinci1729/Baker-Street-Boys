#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "cpu.h"
#include "memory.h"
#include "parser.h"

class Simulator {
public:
    CPU cores[4];  // 4 CPU cores
    Memory memory; // Shared memory
    std::vector<Instruction> instructions;  // List of parsed instructions

    Simulator();
    void loadInstructions(std::vector<Instruction> instr);
    void execute();
    void printState();
};

#endif
