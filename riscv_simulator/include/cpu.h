#ifndef CPU_H
#define CPU_H

#include <vector>
#include <unordered_map>
#include <string>

const int NUM_REGS = 32;

struct CPU {
    int core_id;
    int registers[NUM_REGS] = {0};  
    std::unordered_map<std::string, int> reg_map;
    int pc;  // Program Counter (PC)

    CPU(int id);
    void executeInstruction(const std::string& opcode, const std::vector<std::string>& operands);
    void printRegisters();
};

#endif
