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
	Instruction* instructionMemory;
    HelperFunctions helperfunctions;
public:
	Memory();
	Memory(int size, string filename);
	~Memory();
	Instruction getMemory(int PC);
	bool HasInstruction(int PC);

	//program memory
};