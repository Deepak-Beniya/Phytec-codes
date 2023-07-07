#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void handler1(int sig2)
{
//      printf("signal received %d\n",sig);
//      printf("My process ID is %d",getpid());
//      (void) signal(SIGTERM,SIG_DFL);

        printf("Wake up time\n");
//      alarm(2);

}

void handler2(int sig2)
{
        printf("hi i am from sig kill\n");

}
int main()
{
        printf("My process ID is %d\n",getpid());

        signal(SIGKILL,handler1);
        signal(SIGKILL,handler2);

        while(1)
        {
                printf("Hello World\n");
                sleep(1);
        }
        return 0;
}

                
