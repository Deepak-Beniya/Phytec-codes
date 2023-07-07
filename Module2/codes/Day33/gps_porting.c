#include <stdio.h>
#include <string.h>
#include <fcntl.h> 
#include <errno.h> 
#include <termios.h> 
#include <unistd.h> 
#include<limits.h>

int main() {
       	
  char data[255];
  int fd;
  fd = open("gps_data.txt",O_RDWR);
	if(fd == -1)
	{
		printf("unable to open file\n");
	}
	else
	{
		printf("file opened successfully\n");
	}
  
  
    read(fd,data,sizeof(data));
    
	        printf("\nLattitude is :");
                for(int i=19;i<29;i++)
                 {
                 printf("%c",data[i]);
	       	}

                printf("\nLongitude is :");
	        for(int i=32;i<43;i++)
                 {
                 printf("%c",data[i]);
                }
		printf("\n");

  close(fd);
  return 0; 
}
