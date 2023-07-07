#include<pthread.h>
#include<stdio.h>

static void * threadFunc(void *arg)
{
	char *str =(char *) arg;

	printf("\nThread function is executed \n");
	printf("\n ThreadFunc : arrgument passed to thread are : %s \n Thread Process PID is : %d \n",str,getpid());

	(void) sleep(10);
	printf("\n ThreadFunc is exiting \n");

	pthread_exit(0);

}

int main()
{   
	int ret;
	pthread_t threadID;

       ret = pthread_create(&threadID ,NULL ,threadFunc ,"Hello Deepak");

       if(ret!=0)
       {
	       printf("thread not created \n");
       }
       printf("\n Main Process PID is : %d \n",getpid());
       sleep(2);
       
       ret = pthread_join(threadID,)
        if(res !=0)
	{
		perror("rthread_join error");
	}

       printf("\n Main Process Exiting \n");

       
   //    exit(0);
       return 0;
}

