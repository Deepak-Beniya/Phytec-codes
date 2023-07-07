#include<stdio.h>
#include <unistd.h>

/* sleep(30) ,sleep(50 )In this Program Parent die first child becomes orphan .so, that PID of the child will be 1 or adjecent process PID will be initilize to the child process ID
 * sleep(50),sleep(20),IN this program child dies first then the child will show <defunc> beside the child process. contunesily run ps -ef on 2nd terminal

int var;

int main(){
       pid_t fork_val;
       var =5;
  printf("My process ID is : %d  and PPID : %d \n",getpid(),getppid());

  fork_val=fork();

  if(fork_val<0){
          printf("Failed to create child \n");
  }
  else if(fork_val==0){
          printf("I am in child Process %d \n",getpid());
          var = 10;
          printf("var value is :%d \n",var);
          char *args[] = {"./pm4",NULL}; 
//          execv(args[0],args);
sleep(30);

  }
 
  else{
          printf("I am from parent ID is : %d \n",getpid());
          printf("var value is :%d \n",var);
sleep(10);

  }

}

