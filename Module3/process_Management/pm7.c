#include<stdio.h>
#include <unistd.h>


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
sleep(16);

  }
 
  else{
//	  wait();
          printf("I am from parent ID is : %d \n",getpid());
          printf("var value is :%d \n",var);
	  
sleep(10);

  }
 

}

