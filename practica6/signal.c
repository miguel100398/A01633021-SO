#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void processSignal(int s){
    printf("Recibi segnal %d\n", s);
}

void signalCantKillMe(int s){
    printf("No me puedes matar\n");
}

int main(){
    signal(10, processSignal);
    signal(15, signalCantKillMe);
    while(1){
        sleep(3);
        printf("trabajando\n");
    }
    return 1;
}