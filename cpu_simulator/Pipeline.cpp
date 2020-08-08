#include "Pipeline.h"
#include "Execute.h"
#include "RegisterFile.h"

Pipeline::Pipeline(){
    helperfunctions.PrintDebug("Creating Pipeline");
};

Pipeline::Pipeline(string program){
    helperfunctions.PrintDebug("Creating Pipeline");
	PC = 0;
	stall_fetch = 0;
	ROB_ID = 0;
    cout << "seting rf execute\n";
	execute.setRegisterfile(&registerfile);
    cout << "setting rf iqueue\n";
	iqueue.setRegisterFile(&registerfile);
	fetchunit.initMem(100, program);
	finish = false;
    helperfunctions.PrintDebug("Finished Creating Pipeline");
}

void Pipeline::Pipe_Commit(){
    helperfunctions.PrintDebug("Init Commit");
	unsigned char instructions_commited = 0;
	
	for (int i = 0; i<COMMIT_WIDTH; i++){
		if (ROB.OldestExecuted()){			//Check if oldest instruction was executed
			instructions_commited++;
		}else{
			break;
		}	
	}	
	
	statistics.commit_instructions(instructions_commited);		//Update statistics
    helperfunctions.PrintDebug("Finish commit");
}

void Pipeline::Pipe_Execute(){
    helperfunctions.PrintDebug("Init Execute");
	unsigned char instructions_executed = 0;
	unsigned char execute_result = 0;
	
	for (int i = 0; i<ISSUE_WIDTH; i++){
		if (!ROB.isEmpty()){
			finish = false;
			if (iqueue.checkNextValidity()){
				Instruction instruction = iqueue.popInstruction();
				PC =  execute.getResult(instruction, PC);
                helperfunctions.PrintDebug("Instruction executed, new PC is " + to_string(PC));
				ROB.setCompleteInstruction(instruction.RobId);
				instructions_executed++;
			}else{
				break;
			}
		} else{
			finish = true;
		}
	}

	statistics.execute_instructions(instructions_executed);
	helperfunctions.PrintDebug("Finish Execute");
}

void Pipeline::Pipe_Fetch(){
    helperfunctions.PrintDebug("Init fetch");
	unsigned char instructions_fetched = 0;
	Instruction instruction;
	for (int i = 0; i<FETCH_WIDTH; i++){
		if (!stall_fetch){
			if (ROB.HasEntries() && iqueue.HasEntries()){
				if (fetchunit.HasInstruction(PC)){
					instruction = fetchunit.FetchInstruction(PC);				//Get instruction from memory
					ROB.InstructionInsertion(instruction, ROB_ID);	//Insert instruction in ROB
					iqueue.insertInstruction(instruction, ROB_ID);	//Insert instruction in instruction queue
					ROB_ID++;										//Increment ROB id
					instructions_fetched++;							//Increment counter of instructions fetched
					if (instruction.getType() == 'j'){				//Jump instructions
						PC = instruction.getImmediate();
					}	
					else if((instruction.getType() == 'i') && ((instruction.getOpcode()==5)||(instruction.getOpcode()==6))){			//Branch instruction
						stall_fetch = 1;
					}else{
						PC++;										//Other instructions
					}
				}else{
					break;
				}
			}
			else{
				break;;
			}
		}else{
			break;
		};
	}
	statistics.fetch_instructions(instructions_fetched);		//Update statistics
    helperfunctions.PrintDebug("Finish fetch");
}

bool Pipeline::getFinish(){
	return finish;
}


void Pipeline::getStats(){
	statistics.get_statistics();
}

