/* Cria um processo filho que roda um programa de loop infinito */
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main(){

  int pid = fork();

  if(pid<0){
    fprintf(stderr, "Falha no Fork");
    exit(-1);
  }

  else if(pid==0){
    execl("./loop", "loop", NULL);
    exit(1);
  }
  else{
    wait(NULL);
    exit(0);
  }

  return 0;
}
