#include "HelperFunctions.h"

HelperFunctions::HelperFunctions(){

}

void HelperFunctions::PrintDebug(string message){
    if (DEBUG){
        cout << "-D- " << message << "\n";
    }
}