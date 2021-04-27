/* Exercicio de criar threads */
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int x;

void *modifica(){
  x = 2;
}

int main(int argc, char **argv){
  pthread_t tid;

  pthread_create(&tid, NULL, modifica, argv[1]);

  pthread_join(tid, NULL);

  printf("Valor = %d\n", x);
  return 0;
}
