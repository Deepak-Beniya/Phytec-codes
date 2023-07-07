#include <fcntl.h>
#include <sys/stat.h>        /* For mode constants */
       #include <semaphore.h>
#include<unistd.h>
#include<stdio.h>

int main()
{
	int ret,sval;
	sem_t *sem;


	sem = sem_open("deepak",O_RDWR);

	if(sem== SEM_FAILED)
	{
		perror("sem_open fail");
		return -1;
	}
	else printf("\n sem_open Successfully \n");

	sem_getvalue(sem,&sval);
	printf("\n semaphore value = (%d \n)",sval);


	ret =sem_wait(sem);
	printf("\n Process 2 executes critical section \n");
	sleep(10);
	printf("\n ret is (%d) \n ",ret);
	printf("\n process 2: \n");
	sem_post(sem);

	printf("\n Process 2 executed critical section \n");

	sem_getvalue(sem,&sval);
	printf("\n semaphore value = (%d)\n",sval);
}
