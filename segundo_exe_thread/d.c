/* Exercicio de criar threads */
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int v[] = {1,2,3,4,5,6,7,8,9,10,11,12};
int soma;

void *soma_primeira_parte(){
  for(int i=0;i<3;i++)soma+=v[i];
}

void *soma_segunda_parte(){
  for(int i=3;i<6;i++)soma+=v[i];
}

void *soma_terceira_parte(){
  for(int i=6;i<9;i++)soma+=v[i];
}

void *soma_quarta_parte(){
  for(int i=9;i<12;i++)soma+=v[i];
}

int main(int argc, char **argv){
  pthread_t tid1, tid2, tid3, tid4;

  pthread_create(&tid1, NULL, soma_primeira_parte, argv[1]);
  pthread_create(&tid2, NULL, soma_segunda_parte, argv[1]);
  pthread_create(&tid3, NULL, soma_terceira_parte, argv[1]);
  pthread_create(&tid4, NULL, soma_quarta_parte, argv[1]);

  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
  pthread_join(tid3, NULL);
  pthread_join(tid4, NULL);

  printf("Valor soma = %d\n", soma);
  return 0;
}
