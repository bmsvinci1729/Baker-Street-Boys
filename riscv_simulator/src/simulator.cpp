#include "simulator.h"
#include "cpu.h"
#include "memory.h"
#include "parser.h"
#include <iostream>

Simulator::Simulator() : cores{CPU(0), CPU(1), CPU(2), CPU(3)}, memory(4096) {}

void Simulator::loadInstructions(ParsedProgram parsedProgram) {
    instructions = parsedProgram.instructions;
    label_map = parsedProgram.label_map;  // Store label mapping
}

void Simulator::execute() {
    int totalInstructions = instructions.size();
    while (cores[0].pc / 4 < totalInstructions) {
        int index = cores[0].pc / 4;
        cores[0].executeInstruction(instructions[index].opcode, instructions[index].operands, label_map);
        cores[1].executeInstruction(instructions[index].opcode, instructions[index].operands, label_map);
        cores[2].executeInstruction(instructions[index].opcode, instructions[index].operands, label_map);
        cores[3].executeInstruction(instructions[index].opcode, instructions[index].operands, label_map);
    }
}

void Simulator::printState() {
    for (auto& core : cores) {
        core.printRegisters();
    }
    memory.printMemory();
}
