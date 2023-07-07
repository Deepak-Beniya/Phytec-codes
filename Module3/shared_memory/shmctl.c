       #include <sys/types.h>
       #include <sys/ipc.h>
       #include <sys/msg.h>
#include <stdio.h>
#include <unistd.h>

#define KEY 1234

int main()
{

   int shmid;
   void *memory;
   int buf;
   shmid=shmget(KEY,8000, IPC_CREAT);

    struct shmid_ds buf;

            shmid=shmctl(shmid,8000, &buf);


         //   shmctl(qid,IPC_STAT, &buf);
            printf("Last attach Time : %d \n",buf.shm_atime);
            printf(" size of shared memory %d \n",buf.shm_segsz);
           

return 0;
}

