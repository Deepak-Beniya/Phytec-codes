#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

static void * threadFunc(void *arg)
{
        int count =0;

        printf("\nThread function is executed \n");

	for(count =0 ;count < MAX; count++);
	sleep(5);
	printf("\n ThreadFunc is exiting \n");
        
	if(count < 500)
	{
		return (void *) "count < 500";
	}
	else 
	{
		return (void *) "count > 500";
        }
       /*  printf("\n ThreadFunc : arrgument passed to thread are : %s \n Thread Process PID is : %d \n",str,getpid());

        (void) sleep(10);
        printf("\n ThreadFunc is exiting \n");

        pthread_exit(0); */

}


int main(int arg,char *argv[])
{
	int s;
        pthread_t *t1_id;
        void *res;

	s = pthread_create(&t1_id,NULL,threadFunc,NULL);

	if (s !=0)
		perror("pthread_create error");

        s= pthread_join(t1_id,&res);

	if (s !=0)
		perror("pthread_join error");
	printf("main thread : Thread Returned  \n");

//	printf("Main Thread Exiting now \n");
//	pthread_exit(0);
}
