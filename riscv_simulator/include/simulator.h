#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "cpu.h"
#include "memory.h"
#include "parser.h"
#include <unordered_map>

class Simulator {
public:
    CPU cores[4];  // 4 CPU cores
    Memory memory; // Shared memory
    std::vector<Instruction> instructions;  // List of parsed instructions
    std::unordered_map<std::string, int> label_map;  // Map for label positions

    Simulator();
    void loadInstructions(ParsedProgram parsedProgram);
    void execute();
    void printState();
};

#endif
