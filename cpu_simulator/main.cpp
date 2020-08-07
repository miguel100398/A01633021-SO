#include "Pipeline.h"
using namespace std;

int main (){
	string program;
	
	for(;;){
		cout << "Introduce program to be executed: ";
		//cin >> program;
		//if (program == "exit"){
		//	break;
		//}
        cout << "antes de pipeline";
		//Pipeline main_pipeline(program);
		//Fetch first instruction to avoid ROB is empty
        /*
		main_pipeline.Pipe_Fetch();
		do {
			main_pipeline.Pipe_Commit();
			main_pipeline.Pipe_Execute();
			main_pipeline.Pipe_Fetch();
		} while(!main_pipeline.getFinish());
		
		main_pipeline.getStats();
        */
	}
	
}
