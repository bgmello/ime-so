/* Exercicio de criar threads */
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *runner(){
  while(1==1);
}

int main(int argc, char **argv){
  pthread_t tid;

  pthread_create(&tid, NULL, runner, argv[1]);

  pthread_join(tid, NULL);

  printf("Programa terminou");
  return 0;
}
