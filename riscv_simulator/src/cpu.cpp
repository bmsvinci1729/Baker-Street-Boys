#include "cpu.h"
#include <iostream>

CPU::CPU(int id) : core_id(id), pc(0) {
    for (int i = 0; i < NUM_REGS; i++) {
        reg_map["x" + std::to_string(i)] = i;
    }
}

void CPU::executeInstruction(const std::string& opcode, const std::vector<std::string>& operands, const std::unordered_map<std::string, int>& label_map) {
    if (operands.empty()) {
        std::cerr << "Error: Missing operands for instruction: " << opcode << std::endl;
        return;
    }

    int rd = reg_map[operands[0]];
    int rs1 = operands.size() > 1 ? reg_map[operands[1]] : -1;
    int rs2 = operands.size() > 2 && reg_map.count(operands[2]) && opcode!="jalr" ? reg_map[operands[2]] : -1;


    if (opcode == "add") {
        registers[rd] = registers[rs1] + registers[rs2];
        pc += 4;
    } else if (opcode == "sub") {
        registers[rd] = registers[rs1] - registers[rs2];
        pc += 4;
    } else if (opcode == "bne") {
        if (operands.size() < 3) {
            std::cerr << "Error: Invalid operands for bne" << std::endl;
            return;
        }
        if (registers[rs1] != registers[rs2]) {
            std::string label = operands[2];  // The branch target label
            if (label_map.find(label) != label_map.end()) {
                pc = label_map.at(label) * 4;  // Jump to the correct instruction index
            } else {
                std::cerr << "Error: Undefined label '" << label << "'" << std::endl;
            }
        } else {
            pc += 4;  // Normal execution
        }
    } else if (opcode == "jal") {
        if (operands.size() < 2) {
            std::cerr << "Error: Invalid operands for jal" << std::endl;
            return;
        }
        registers[rd] = pc + 4;  // Save return address
        std::string label = operands[1];
        if (label_map.find(label) != label_map.end()) {
            pc = label_map.at(label) * 4;  // Jump
        } else {
            std::cerr << "Error: Undefined label '" << label << "'" << std::endl;
        }
    }

    else if(opcode == "jalr"){
        int rd = reg_map[operands[0]];
        int rs1 = reg_map[operands[1]];
        int offset = stoi(operands[2]);

        int new_pc = (registers[rs1]+offset);
        pc = new_pc;

    }
    else if (opcode == "lw") {
        if (operands.size() < 2) {
            std::cerr << "Error: Invalid operands for lw" << std::endl;
            return;
        }
        registers[rd] = 100;  // Placeholder for memory load
        pc += 4;
    } else if (opcode == "sw") {
        if (operands.size() < 2) {
            std::cerr << "Error: Invalid operands for sw" << std::endl;
            return;
        }
        std::cout << "Storing " << registers[rd] << " at memory[" << operands[1] << "]\n";
        pc += 4;
    } else if (opcode == "addi") {
        if (operands.size() < 3) {
            std::cerr << "Error: Invalid operands for addi" << std::endl;
            return;
        }
        registers[rd] = registers[rs1] + std::stoi(operands[2]);
        pc += 4;
    } else if (opcode == "and") {
        if (operands.size() < 3) {
            std::cerr << "Error: Invalid operands for and" << std::endl;
            return;
        }
        registers[rd] = registers[rs1] & registers[rs2];
        pc += 4;
    } else if (opcode == "or") {
        if (operands.size() < 3) {
            std::cerr << "Error: Invalid operands for or" << std::endl;
            return;
        }
        registers[rd] = registers[rs1] | registers[rs2];
        pc += 4;
    } else if (opcode == "xor") {
        if (operands.size() < 3) {
            std::cerr << "Error: Invalid operands for xor" << std::endl;
            return;
        }
        registers[rd] = registers[rs1] ^ registers[rs2];
        pc += 4;
    } else if (opcode == "sll") {
        if (operands.size() < 3) {
            std::cerr << "Error: Invalid operands for sll" << std::endl;
            return;
        }
        registers[rd] = registers[rs1] << std::stoi(operands[2]);
        pc += 4;
    } else if (opcode == "srl") {
        if (operands.size() < 3) {
            std::cerr << "Error: Invalid operands for srl" << std::endl;
            return;
        }
        registers[rd] = registers[rs1] >> std::stoi(operands[2]);
        pc += 4;
    } else if (opcode == "sra") {
        if (operands.size() < 3) {
            std::cerr << "Error: Invalid operands for sra" << std::endl;
            return;
        }
        registers[rd] = registers[rs1] >> std::stoi(operands[2]);  // Arithmetic shift
        pc += 4;
    } else {
        std::cerr << "Error: Unknown instruction: " << opcode << std::endl;
    }
}

void CPU::printRegisters() {
    std::cout << "Core " << core_id << " Registers:\n";
    for (int i = 0; i < NUM_REGS; i++) {
        std::cout << "x" << i << ": " << registers[i] << "\n";
    }
    std::cout << "PC: " << pc << "\n";  // Print Program Counter
}
