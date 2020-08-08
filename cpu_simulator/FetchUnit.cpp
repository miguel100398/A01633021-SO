#include "fetchunit.h"

FetchUnit::FetchUnit(){
    helperfunctions.PrintDebug("Creating Fetch Unit");
    helperfunctions.PrintDebug("Finished creating Fetch unit");
}

FetchUnit::FetchUnit(string program){
    helperfunctions.PrintDebug("Creating Fetch Unit");
    Memory memory(MEMORY_SIZE, program);
    helperfunctions.PrintDebug("Finished Creating Fetch Unit");
}

Instruction FetchUnit::FetchInstruction(int PC){
    return memory.getMemory(PC);
}

bool FetchUnit::HasInstruction(int PC){
	return memory.HasInstruction(PC);
}
