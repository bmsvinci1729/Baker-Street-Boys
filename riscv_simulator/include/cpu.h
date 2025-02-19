#ifndef CPU_H
#define CPU_H

#include <vector>
#include <unordered_map>
#include <string>
using namespace std; 

const int NUM_REGS = 32;

struct CPU {
    int core_id;
    int registers[NUM_REGS] = {0};  // registers value set to zero
    unordered_map<string, int> reg_map; // what is this for?
    int pc;  // Program Counter (PC)

    CPU(int id);
    void executeInstruction(const std::string& opcode, const std::vector<std::string>& operands, const std::unordered_map<std::string, int>& label_map);
    void printRegisters();
};

#endif
