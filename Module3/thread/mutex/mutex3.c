#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>


int global=0;
pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
static void * threadFunc(void *arg)
{
        int local =0;


        printf("\nThread function 1 is executed \n");

        pthread_mutex_lock(&mut);
        for(int i =0;i<10000;i++)
        {
                local=global;
                local++;
                global=local;
        }

      printf("thread 1 local value :%d \n",local);

      pthread_mutex_unlock(&mut);
}

int main(int arg,char *argv[])
{
        int t1,t2;
        pthread_t *t1_id,*t2_id;
        void *res;

        t1 = pthread_create(&t1_id,NULL,threadFunc,NULL);
        t2 = pthread_create(&t2_id,NULL,threadFunc,NULL);

        if (t1 !=0)
        {
                perror("pthread_create error \n");
        }
        else printf("Thread 1 created 1st time success \n");

        if (t2 !=0)
        {
                perror("pthread_create error \n");
        }
        else printf("Thread 1 created 2nd time success \n");

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

