#include "simulator.h"
// #include "parser.h"
#include <iostream>

using namespace std; 


vector<Instruction> parseFile(const string& filename) {
    vector<Instruction> instructions;
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        Instruction inst;
        ss >> inst.opcode;
        string operand;

        while (ss >> operand) {
            inst.operands.push_back(operand);
        }

        if (!inst.opcode.empty()) {
            instructions.push_back(inst);
        }
    }

    return instructions;
}

int main() {
    Simulator sim;
    vector<Instruction> instructions = parseFile("tests/bubble_sort.asm");
    

    sim.loadInstructions(instructions);
    sim.execute();
    sim.printState();

    return 0;
}
