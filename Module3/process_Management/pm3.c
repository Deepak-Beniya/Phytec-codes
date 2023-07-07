#include<stdio.h>
#include <unistd.h>

int main()
{
  char *args[] = {"./pm4",NULL};
  char *file = "ls";
  char *arg1 = "-a";
  char *arg2 = "-s";	  

  printf("I am Deepak,My ID is %d \n",getpid());
  execvpe(args[0],args);
  //execl(file,arg1,arg2);
  printf("Hello Satyam \n");

}
