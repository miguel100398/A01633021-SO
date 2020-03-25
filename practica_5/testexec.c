#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main( int argc, const char* argv[] )
{
	int pid = fork();
    if (pid==0){
         execlp("ls", "ls", "-a", "/", (char *) NULL);
    }else{
        printf( "soy el padre pid:%d \n", pid );
    }
   
}
