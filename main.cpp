#include "simulator.h"
#include "parser.h"

int main() {
    Simulator sim;
    std::vector<Instruction> instructions = parseAssemblyFile("tests/bubble_sort.asm");
    sim.loadInstructions(instructions);
    sim.execute();
    sim.printState();
    return 0;
}
