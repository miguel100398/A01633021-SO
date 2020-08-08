#pragma once
#include "HelperFunctions.h"
#include "Instruction.h"
#include <fstream>
#include "HelperFunctions.h"
#include <vector>
using namespace std;

//Instruction Memory
class Memory
{
private:
	ifstream inputStream;
    HelperFunctions helperfunctions;
    int number_instructions;
public:
	Memory();
    Instruction* instructionMemory;
	Memory(int size, string filename);
	~Memory();
	Instruction getMemory(int PC);
	bool HasInstruction(int PC);
    void initMem(int size, string program);

	//program memory
};