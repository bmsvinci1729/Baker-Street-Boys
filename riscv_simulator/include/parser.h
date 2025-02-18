#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream> 
using namespace std;

struct Instruction{
    string opcode;
    vector<string> operands;
};

