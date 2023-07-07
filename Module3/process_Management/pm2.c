#include<stdio.h>
       #include <sys/types.h>
       #include <unistd.h>

int main()

{
  int pid;

  printf("My process ID is : %d  and PPID : %d \n",getpid(),getppid());
  

  pid=fork();
  printf("My process ID is after fork : %d  and PPID : %d \n",getpid(),getppid());

  printf("pid : %d \n",pid);
/*  if ((pid =fork())==0)
  {
	  printf("hello from the child \n");
  }
  else 
  {
	  printf("Hello from the parent\n");
  }*/

  if(pid>0){
	  printf("hello from parent \n");
  }
  else 
	  printf("hello from child \n");
 getchar();
}

