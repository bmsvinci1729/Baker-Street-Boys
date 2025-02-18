#include "simulator.h"
#include <iostream>

Simulator::Simulator() : cores{CPU(0), CPU(1), CPU(2), CPU(3)}, memory(4096) {}

void Simulator::loadInstructions(std::vector<Instruction> instr) {
    instructions = instr;
}

void Simulator::execute() {
    for (int i = 0; i < instructions.size(); i++) {
        cores[0].executeInstruction(instructions[i].opcode, instructions[i].operands);
    }
}

void Simulator::printState() {
    for (auto& core : cores) {
        core.printRegisters();
    }
    memory.printMemory();
}
