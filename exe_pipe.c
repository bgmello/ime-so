/* Exercicio para executar comando ls -l | wc -l usandi pipe */
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
  int fd[2], pid1, pid2;

  char *prog1[3] = {"/bin/ls", "-l", NULL};
  char *prog2[2] = {"/usr/bin/wc", NULL};

  pipe(fd);
  if((pid1=fork())==0){
    dup2(fd[1], STDOUT_FILENO);
    close(fd[0]); close(fd[1]);
    execv(prog1[0], prog1);
  }
  if((pid2=fork())==0){
    dup2(fd[0], STDIN_FILENO);
    close(fd[0]); close(fd[1]);
    execv(prog2[0], prog2);
  }

  close(fd[0]); close(fd[1]);
  waitpid(pid1, NULL, 0);
  waitpid(pid2, NULL, 0);
  return 0;
}
