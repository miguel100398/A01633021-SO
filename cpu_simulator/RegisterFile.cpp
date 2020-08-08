#include "RegisterFile.h"
#include "HelperFunctions.h"

RegisterFile::RegisterFile()
{
    helperfunctions.PrintDebug("Creating Register File size 16");
	r = new unsigned int[16];
	valid = new bool[16];
	for (int i = 0; i < 16; i++) {
		valid[i] = false;
	}
	valid[0] = true;
	r[0] = 0;
    helperfunctions.PrintDebug("Finished Creating Register File");
}

RegisterFile::RegisterFile(int size)
{
    helperfunctions.PrintDebug("Creating Register File size " + to_string(size));
	r = new unsigned int[size];
	valid = new bool[size];
	for (int i = 0; i < size; i++) {
		valid[i] = false;
	}
	valid[0] = true;
	r[0] = 0;
    helperfunctions.PrintDebug("Finished Creating register file");
}

RegisterFile::~RegisterFile()
{
	delete[] r;
	delete[] valid;
}
