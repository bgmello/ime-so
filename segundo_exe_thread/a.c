#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

int x;

int main(){

  if(fork()==0){
    x = 2;
    printf("filho = %d\n", x);
    exit(0);
  }
  else{
    wait(NULL);
    printf("pai = %d\n", x);
  }

  return 0;
}
