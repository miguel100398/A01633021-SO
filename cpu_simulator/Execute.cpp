#include "Execute.h"
#include "HelperFunctions.h"

Execute::Execute(){
    helperfunctions.PrintDebug("Creating Execute");
    helperfunctions.PrintDebug("Finished Creating Execute");
}

void Execute::setRegisterfile(RegisterFile *newregisterfile){
	registerfile = newregisterfile;
}

unsigned int Execute::getResult(Instruction instruction, int PC)
{
	type = instruction.getType();
	if (type == 'R'){
		operand1 = registerfile->r[instruction.getSrc1()];
		operand2 = registerfile->r[instruction.getSrc2()];
		opcode = static_cast<op_t>(instruction.getOpcode());
		dest = instruction.getDest();
	}else if (type == 'I'){
		operand1 = registerfile->r[instruction.getSrc1()];
		operand2 = instruction.getImmediate();
		opcode = static_cast<op_t>(instruction.getOpcode());
		dest = instruction.getDest();
	}else if (type == 'J'){
		operand1 = instruction.getImmediate();
		opcode = JUMP;
	}else{
		operand1 = instruction.getImmediate();
		opcode = static_cast<op_t>(instruction.getOpcode());
		dest = instruction.getDest();
	}
	result = 0;
    if (type == 'P'){
        cout << "Enter parameter: ";
        cin >> registerfile->r[2];
    }else{
        switch (opcode)
        {
        case ADD:
            registerfile->r[dest] = operand1 + operand2;
            break;
        case SUB:
            registerfile->r[dest] =  operand1 - operand2;
            break;
        case MULTIPLY:
            registerfile->r[dest] = operand1 * operand2;
            break;
        case DIVIDE:
            registerfile->r[dest] = operand1 / operand2;
            break;
        case MODULO:
            registerfile->r[dest] = operand1 % operand2;
            break;
        case BEQ:
            //registerfile->r[dest] = registerfile->r[dest] - operand1;
            if (registerfile->r[dest] == operand1){
                return operand2;
            }else{
                return PC;//PC+1;
            }
            break;
        case BNE:
            //registerfile->r[dest] = registerfile->r[dest] - operand1;
            //if (registerfile->r[dest] != 0){
            if (registerfile->r[dest] != operand1){
                return operand2;
            }else{
                return PC;//PC+1;
            }
            break;
        case MOV:
            registerfile->r[dest] = operand1;
            break;
        case MOV_PRINT:
            //idk if this goes here we'll figure it out eventually
            registerfile->r[dest] = operand1;
            cout << "result = " + to_string(operand1) + "\n";
            break;
        case JUMP:
            return operand1;
            break;
        }
    }    
    helperfunctions.PrintDebug("Executed dest["+to_string(dest)+"]= " +to_string(registerfile->r[dest])+" operand1 "+to_string(operand1)+" operand2 "+to_string(operand2));
    //string held;
    //cin >> held;
	registerfile->valid[dest] = true;
	return PC;
}