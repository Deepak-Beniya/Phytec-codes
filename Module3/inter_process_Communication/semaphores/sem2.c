       #include <sys/types.h>
       #include <sys/ipc.h>
       #include <sys/sem.h>
#include<stdio.h>
       #include <fcntl.h>           /* For O_* constants */
       #include <sys/stat.h>        /* For mode constants */
       #include <semaphore.h>

#define KEY 1234

int main()
{
        int semid;
	sem_t *semaddr;
	int sval;
        semaddr = sem_open("deepak", O_CREAT | O_RDWR ,0660,1);

        if(semaddr==0)
        {
                printf("Semaphore not created \n");
        }

        else printf("file created successfully \n");

	sem_getvalue(semaddr, &sval );
	printf("\n before sem_wait semaphore value = (%d) \n",sval);

	sem_wait(semaddr);
	sem_getvalue(semaddr,&sval);
	printf("\n after sem_wait semaphore value = (%d) \n",sval);

	printf("\n process 1 : executing Critical section \n ");
	sleep(10);
	sem_post(semaddr);
	printf("\n critical section executed \n ");
        sem_getvalue(semaddr,&sval);
        printf("\n after sem_post semaphore value = (%d) \n",sval);

//	sem_unlink("deepak");

        return 0;
}

