#include "cpu.h"
#include <iostream>

CPU::CPU(int id) : core_id(id), pc(0) {
    for (int i = 0; i < NUM_REGS; i++) {
        reg_map["x" + std::to_string(i)] = i; // why not all zero
    }
}

void CPU::executeInstruction(const std::string& opcode, const std::vector<std::string>& operands) {
    int rd = reg_map[operands[0]];
    int rs1 = reg_map[operands[1]];
    int rs2 = (operands.size() > 2) ? reg_map[operands[2]] : -1;

    if (opcode == "add") {
        registers[rd] = registers[rs1] + registers[rs2];
    } else if (opcode == "sub") {
        registers[rd] = registers[rs1] - registers[rs2];
    } else if (opcode == "bne") {
        if (registers[rs1] != registers[rs2]) {
            pc += std::stoi(operands[2]);  // Jump to label offset
        }
    } else if (opcode == "jal") {
        registers[rd] = pc + 4;  // Save return address
        pc += std::stoi(operands[1]);  // Jump
    } else if (opcode == "lw") {
        registers[rd] = 100; // Placeholder
    } else if (opcode == "sw") {
        std::cout << "Storing " << registers[rd] << " at memory[" << operands[1] << "]\n";
    } else if (opcode == "addi") {
        registers[rd] = registers[rs1] + std::stoi(operands[2]);
    }

    pc += 4;  // Move to next instruction
}

void CPU::printRegisters() {
    std::cout << "Core " << core_id << " Registers:\n";
    for (int i = 0; i < NUM_REGS; i++) {
        std::cout << "x" << i << ": " << registers[i] << "\n";
    }
}