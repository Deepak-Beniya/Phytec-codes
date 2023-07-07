#include<stdio.h>
       #include <sys/types.h>
       #include <unistd.h>

int main()

{
  int pid;

  printf("My process ID is : %d  and PPID : %d \n",getpid(),getppid());


  pid=fork();
  printf("My process ID is after fork : %d  and PPID : %d \n",getpid(),getppid());

  if(pid== -1){
	  printf("Error in creating child process \n");
  }
  else if(pid>0){
	  printf("Child process created:%d \n",getpid());
  }
 //getchar();
}

