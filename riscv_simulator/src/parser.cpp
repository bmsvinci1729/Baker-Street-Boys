#include "parser.h"
#include <fstream>
#include <sstream>
#include <iostream>

ParsedProgram parseAssemblyFile(const std::string& filename) {
    ParsedProgram parsedProgram;
    std::ifstream file(filename);
    std::string line;
    int instructionIndex = 0;

    if (!file) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return parsedProgram;
    }

    // First Pass: Identify Labels
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string firstWord;
        ss >> firstWord;

        if (firstWord.empty() || firstWord[0] == '#') {
            continue;  // Ignore empty lines and comments
        }

        if (firstWord.back() == ':') {
            std::string label = firstWord.substr(0, firstWord.size() - 1);  // Remove ':'
            parsedProgram.label_map[label] = instructionIndex;
        } else {
            instructionIndex++;  // Only increment for real instructions
        }
    }

    file.clear();
    file.seekg(0);  // Reset file pointer for second pass

    // Second Pass: Parse Instructions
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string firstWord;
        ss >> firstWord;

        if (firstWord.empty() || firstWord[0] == '#') {
            continue;  // Ignore empty lines and comments
        }

        if (firstWord.back() == ':') {
            continue;  // Ignore labels in second pass
        }

        Instruction inst;
        inst.opcode = firstWord;
        std::string operand;
        while (ss >> operand) {
            inst.operands.push_back(operand);
        }

        if (!inst.opcode.empty()) {
            parsedProgram.instructions.push_back(inst);
        }
    }

    return parsedProgram;
}
