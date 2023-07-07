#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void handler1(int sig2)
{
//      printf("signal received %d\n",sig);
//      printf("My process ID is %d",getpid());
//      (void) signal(SIGTERM,SI

        printf("Wake up time\n");
//      alarm(2);

}

void handler2(int sig2)
{
        printf("hi i am from sig kill\n");

}
int main()
{
	int cpid;
	cpid = fork();

	if(cpid==0)
	{
		printf("I am in child Process ID is : %d|\n",getpid());
	}
	else
	{
		signal(SIG_CHILD,handler1);
	}
	
        while(1)
	{
                printf("I am in Parent Process \n");
                sleep(1);
        }
        return 0;
}
