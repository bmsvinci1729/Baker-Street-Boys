#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include <string>
#include <unordered_map>

struct Instruction {
    std::string opcode;
    std::vector<std::string> operands;
};

struct ParsedProgram {
    std::vector<Instruction> instructions;
    std::unordered_map<std::string, int> label_map;  // Maps labels to instruction indices
};

ParsedProgram parseAssemblyFile(const std::string& filename);

#endif
