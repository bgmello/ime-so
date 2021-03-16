#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<sys/shm.h>
#include<sys/stat.h>
#include<unistd.h>
#define SIZE 4096


int main(){

  const char* name = "prod_cons";
  int shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666); 
  void *ptr;
  char* data;
  char *message_0 = "Hello ";
  char *message_1 = "World!";

  ftruncate(shm_fd, SIZE);

  ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);

  void *ptr_1 = ptr+512;

  sprintf(ptr, "%s", message_0);
  ptr+=strlen(message_0);
  sprintf(ptr, "%s", message_1);

  sprintf(ptr_1, "%d", -1);

  int a;

  while(sscanf(ptr_1, "%d", &a) && a==-1);
  
  shm_unlink(name);
  return 0;
}
