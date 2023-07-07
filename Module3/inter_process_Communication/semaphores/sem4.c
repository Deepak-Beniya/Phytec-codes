#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<stdlib.h>
#include<stdio.h>
#define KEY 1234

union semun{
	int val;
	struct semid_ds *buf;
	unsigned short int *array;
	struct seminfo *_buf;
};


int main()
{
	int semid,retval;
	struct sembuf *sbuf;
	union semun su,su1;
	sbuf =(struct sembuf*) malloc(sizeof(struct sembuf));
	semid = semget(KEY,1,IPC_CREAT);
	printf("semid = %d \n ",semid);
	sbuf->sem_num = 0;
	sbuf->sem_op =0;
	sbuf->sem_flg = IPC_NOWAIT ;
	semop(semid,sbuf,1);
	printf("semval set to 1 \n");
	getchar();
	getchar();
	su.val =0;
	retval = semctl(semid,0,SETVAL,su);
	sbuf->sem_num =0;
	sbuf->sem_op =-1;
	sbuf->sem_flg = IPC_NOWAIT;
        printf("before setting semval to 0 \n");
	retval= semop(semid,sbuf,1);
	printf("After setting semval to 0 retval = %d  \n",retval);
	perror("semval :");
	getchar();
        getchar();

}



