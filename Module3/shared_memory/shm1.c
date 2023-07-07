#include <sys/types.h>
#include <sys/shm.h>
#include<stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define KEY 1234

int main(){

   int shmid;
   shmid=shmget(KEY,8000, IPC_CREAT);
   printf("Address of the shared memory is : %d \n",shmid);

   return 0;

}
