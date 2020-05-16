#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFSIZE 512

int main(int argc, char **argv){
    char *originFilename = argv[1];
    char *dstFilename = argv[2];

    int from, to, nr, nw, n;
    char buf[BUFSIZE];

    if ((from=open(originFilename, O_RDONLY)) < 0) {
        printf("Error opening source file");
        return(1);
    }

    if ((to=creat(dstFilename, 0666)) < 0) {
        printf("Error creating destination file");
        return(2);
      } 

    while((nr=read(from, buf, sizeof( buf))) != 0) {
        if (nr < 0) {
        printf("Error reading source file");
        return(3);
        }

        nw=0;
        do {
          if ((n=write(to, &buf[nw], nr-nw)) < 0) {
            printf("Error writing destination file");
            return(4);
          }
          nw += n;
        } while (nw < nr);
      }
      close(from); close(to);
}