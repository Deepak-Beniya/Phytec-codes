#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void fun(int sig)
{
	printf("I got the signal :%d \n",sig);
//	(void) signal(SIGINT,SIG_DFL);

}

int main()
{

//	(void) signal(SIGINT,fun);
       while(1){
	printf("HI DEEPAK \n");
	printf("PID is:%d \n",getpid());
        sleep(1);
	signal(SIGTERM,fun);

       }
}

	

