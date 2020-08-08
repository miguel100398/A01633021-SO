#include "Memory.h"
#include <iostream>
#include <string>
using namespace std;

Memory::Memory() {
    helperfunctions.PrintDebug("Creating Memory size 16");
	instructionMemory = new Instruction[16];
    helperfunctions.PrintDebug("Finished Creating Memory");
    number_instructions = 0;
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
        instructionMemory[i].exists = true;
        cout << " " + to_string(instructionMemory[i].exists);
        i++;
        number_instructions++;
    }

    helperfunctions.PrintDebug("Finished Creating Memory");
};

void Memory::initMem(int size, string program){
    helperfunctions.PrintDebug("Init mem");
    instructionMemory = new Instruction[size];
	unsigned int* unsignedValues = new unsigned int[size];
	inputStream.open(program, ios::in);
	int i = 0;
    string word;
    while (getline(inputStream,word,',')){
        unsignedValues[i] = stoul(word);
        instructionMemory[i] = Instruction(unsignedValues[i]);
        instructionMemory[i].exists = true;
        cout << " " + to_string(instructionMemory[i].exists);
        i++;
        number_instructions++;
    }
    helperfunctions.PrintDebug("FInish Init mem");
}

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