#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

static void * threadFunc(void *arg)
{

printf("Thread : threadFunc started\n");
while(1)
{
sleep(1);
printf("\nthreadFunc : Thread is inside a loop\n");
}

printf("\n ThreadFunc: exiting now \n");
}




int main(int argc, char *argv[])
{
int s,count;
pthread_t tid;
s= pthread_create(&tid, NULL, threadFunc, NULL);
if(s!=0)
        perror("Thread create error");
for(count = 0; count < 10; count++){
sleep(2);
        printf("main thread: Countvalue =(%d)\n", count);
}
//pthread_cancel(tid);
//sleep(3);
printf("\n main thread: exiting now \n");
pthread_exit(NULL);
}

