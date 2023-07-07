#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int global=0;
pthread_mutex_t my_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t myCondVar = PTHREAD_COND_INITIALIZER;
int doneFlag =0;
char buf[100];

/* Produce Thread */
void * threadA(void * p) {
	printf("\n ThreadA Scheduled First \n");
	sleep(1);
	pthread_mutex_lock(&my_mutex);
	printf("\n ThreadA critical section executed always first \n");

        /* Produce will */
	sprintf(buf,"This is data buffer ");
	doneFlag =1;
	pthread_cond_signal(&myCondVar);
	pthread_mutex_unlock(&my_mutex);
}

/* Consumer thread */
void * threadB(void *p) {
	printf("\n ThreadB Scheduled Second \n");
	pthread_mutex_lock(&my_mutex);
	if (doneFlag == 0)
		pthread_cond_wait(&myCondVar,&my_mutex);

        /* consumer will consume data here */  
	printf("\n ThreadB :signal received from threadA,this is always executed after threadA critical section %d \n",doneFlag);
	printf("\n The buffer received from the producer thread is (%s) \n",buf);
	pthread_mutex_unlock(&my_mutex);

}
	


  int main() {

	  pthread_t pthreadA;
	  pthread_create(&pthreadA,NULL,threadA,NULL);
	  pthread_t pthreadB;
	  pthread_create(&pthreadB,NULL,threadB,NULL);
	 // sleep(2);
	  pthread_join(&pthreadA,NULL);
	  pthread_join(&pthreadB,NULL);
	  printf("\n Main thread is exiting now \n ");
	  return(EXIT_SUCCESS);


  }
