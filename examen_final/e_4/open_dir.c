#include <dirent.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
  struct stat mystat, *sp = &mystat;
  int r;
  char *filename, path[1024], cwd[256];
  DIR* mydirectory;
  struct dirent* mydirent;
  filename = "./";
  if (argc > 1)
    filename = argv[1];
  if ((r = lstat(filename, sp)) < 0) {
    printf("no such file %s\n", filename);
    exit(1);
  }
  strcpy(path, filename);
  if (path[0] != '/') {
    getcwd(cwd, 256);
    strcpy(path, cwd);
    strcat(path, "/");
    strcat(path, filename);
  }
  if (S_ISDIR(sp->st_mode)) {
    if ((mydirectory = opendir(filename)) == NULL){   //Revisar apertura de archivo
        printf("Can't oppen directory \n");        // No se pudo abrir
        exit(1);
    }
    while ((mydirent = readdir(mydirectory)) != NULL){   //Leer mientras existan registros
        printf ("%s\n", mydirent->d_name);      //Imprimir contenido
    }
    if (closedir(mydirectory)){             //Cerrar directorio
        printf ("Can't close directory \n");   //No se pudo cerrar
        exit(1);
    }
    exit(0);
  }
}
