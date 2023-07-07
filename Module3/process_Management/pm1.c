#include<stdio.h>
       #include <sys/types.h>
       #include <unistd.h>

int main()

{  
  int pid;	
  
  printf("My process ID is : %d  and PPID : %d \n",getpid(),getppid());
  printf("My process ID is : %d  and PPID : %d \n",getpid(),getppid());

  pid=fork();
  printf("My process ID is after fork : %d  and PPID : %d \n",getpid(),getppid());

  printf("hi fork \n");
  printf("pid : %d \n",pid);
 getchar(); 
}
