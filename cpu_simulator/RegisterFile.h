#pragma once
#include "HelperFunctions.h"

//Variable Data
class RegisterFile
{
private:
    HelperFunctions helperfunctions;

public:
	RegisterFile();
	RegisterFile(int size);
	~RegisterFile();
	unsigned int* r;
	bool* valid;
};
