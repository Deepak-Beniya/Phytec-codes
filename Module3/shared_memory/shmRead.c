#include <sys/types.h>
#include <sys/shm.h>
#include<stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#define KEY 1234

int main(){

   int shmid;
   void *memory;

   shmid=shmget(KEY,8000,IPC_CREAT);

   memory = shmat(shmid,(const void *) 0,0);

    printf("DATA is : %s",memory);


}

