#pragma once
#include "Instruction.h"
#include <queue> 
#include "HelperFunctions.h"
using namespace std;

#define MAX_ENTRIES 10

typedef struct rob_data_s{
    bool valid_bit;
    Instruction instruction;
    long rob_id;
} rob_data_t;

class ReorderBuffer
{
    private:
        int num_entries;
        deque<rob_data_t> rob_list;
        HelperFunctions helperfunctions;
    public:
        ReorderBuffer();
        bool isEmpty();
        bool OldestExecuted();
        void setCompleteInstruction(long robid);
        bool HasEntries();
        void InstructionInsertion(Instruction instruction, long robid);

};