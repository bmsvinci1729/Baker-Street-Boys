#include "simulator.h"
#include "parser.h"
#include <iostream>

int main() {
    Simulator sim;
    ParsedProgram parsedProgram = parseAssemblyFile("tests/bubble_sort.asm");

    if (parsedProgram.instructions.empty()) {
        std::cerr << "Error: No instructions loaded!" << std::endl;
        return 1;
    }

    sim.loadInstructions(parsedProgram);
    sim.execute();
    sim.printState();

    return 0;
}
