/* Exercicio para somar vetor usando processo filho */
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main(){

  int pid = fork();
  int v[10];

  for(int i=1;i<=10;i++){
    v[i-1] = i;
  }

  if(pid<0){
    fprintf(stderr, "Falha no Fork");
    exit(-1);
  }

  else if(pid==0){
    int sum = 0;

    for(int i=0;i<5;i++) sum+=v[i];

    exit(sum);
  }
  else{
    int child_status;

    wait(&child_status);

    if(WIFEXITED(child_status)){
    
      int final_sum = WEXITSTATUS(child_status);

      for(int i=5;i<10;i++) final_sum += v[i];

      printf("A soma do vetor e: %d\n", final_sum);

    }

    else{
      printf("Filho terminou anormamente");
    }

    exit(0);

  }

  return 0;
}
