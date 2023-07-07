#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int global=0;
static void * threadFunc1(void *arg)
{
        int local =0;

        printf("\nThread function 1 is executed \n");

        for(int i =0;i<10000;i++)
	{
		local=global;
		local++;
		global=local;
	}

      printf("thread 1 local value :%d \n",local);

}

static void * threadFunc2(void *arg)
{
        int local =0;

        printf("\nThread function 2 is executed \n");

        for(int i =0;i<10000;i++)
        {
                local=global;
                local++;
                global=local;
        }

	printf("thread 2 local value :%d \n",local);


}



int main(int arg,char *argv[])
{
        int t1,t2;
        pthread_t *t1_id,*t2_id;
        void *res;

        t1 = pthread_create(&t1_id,NULL,threadFunc1,NULL);
	t2 = pthread_create(&t2_id,NULL,threadFunc2,NULL);

        if (t1 !=0)
	{
	      	perror("pthread_create error \n");
	}
	else printf("Thread 1 created success \n");

	if (t2 !=0)
        {
                perror("pthread_create error \n");
        }
        else printf("Thread 2 created success \n");

	t1 = pthread_join(t1_id,NULL);
	if (t1 !=0)
		perror("pthread_join \n");

	t2 = pthread_join(t2_id,NULL);
        if (t2 !=0)
                perror("pthread_join \n");

        

	printf("Value of global is : %d \n",global);

        printf("main thread : Thread Returned  \n");

//        pthread_exit(0);

}


