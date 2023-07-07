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


   shmid=shmget(KEY,8000, IPC_CREAT);
  if(shmid >= 0)
  {
	  printf("Shared Memory Segment Created Successfully : %d \n",shmid);
  }

   memory = shmat(shmid,(const void *) 0,0);
   strcpy((char *) memory,"Deepak");

   printf("Number of attachment: %ls",(int *)memory);

   return 0;

}

