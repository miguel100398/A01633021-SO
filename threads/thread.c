#include <pthread.h>
#include <stdio.h>


#define NUMTHREADS 5

int val = 5;
pthread_mutex_t mutex;

void * hello(void *id){
    long int_id = (long)id;              //En realidad no es direccion, es un entero disfrazado de direccion
    pthread_mutex_lock(&mutex);
    printf("Hello world %ld, %d\n",int_id, val);
    val += val;
    pthread_mutex_unlock(&mutex);
}

int main(){
    pthread_t hilos[NUMTHREADS]; //Arreglo para guardar informacion de hilos
    for (long i = 0; i< NUMTHREADS; i++){
        pthread_create(&hilos[i], NULL, hello,(void *)i);  //Lo disfrazo como si fuera direccion
    }
    pthread_exit(NULL);  //Espera a que todos los hilos terminen
    return 0;
}