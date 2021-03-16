#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<sys/shm.h>
#include<sys/stat.h>
#include<unistd.h>
#define SIZE 4096

int main(){

  const char* name = "prod_cons";
  int shm_fd = shm_open(name, O_RDWR, 0666); 
  void *ptr;

  ptr = mmap(0, SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

  ptr += 512; 
  sprintf(ptr, "%d", 1);

  return 0;
}
