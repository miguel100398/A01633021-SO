#include "Memory.h"
#include <iostream>
using namespace std;

Memory::Memory() {
    helperfunctions.PrintDebug("Creating Memory size 16");
	instructionMemory = new Instruction[16];
    helperfunctions.PrintDebug("Finished Creating Memory");
};

Memory::Memory(int size, string filename) {
    helperfunctions.PrintDebug("Creating Memory size " + to_string(size) + " program " + filename);
	instructionMemory = new Instruction[size];
	unsigned int* unsignedValues = new unsigned int[size];
	inputStream.open(filename, ios::in);
	int i = 0;
    string word;
    while (getline(inputStream,word,',')){
        unsignedValues[i] = stoul(word);
        instructionMemory[i] = Instruction(unsignedValues[i]);
        i++;
    }

    helperfunctions.PrintDebug("Finished Creating Memory");
};

bool Memory::HasInstruction(int PC){
	if (instructionMemory[PC].exists){
		return true;
	}else{
		return false;
	}
}

Instruction Memory::getMemory(int PC){
	return instructionMemory[PC];
}

Memory::~Memory() {
	delete[] instructionMemory;
};