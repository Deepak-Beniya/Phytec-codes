#include <stdio.h>
#include <string.h>
#include <fcntl.h> 
#include <errno.h> 
#include <termios.h> 
#include <unistd.h> 

int main() {
       	
  char data[20];
  int fd;
  fd = open("dev/ttyACM0", O_RDWR );
	if(fd == -1)
	{
		printf("unable to create file");
	}
	else
	{
		printf("file created successfully");
	}



  struct termios deepak;

  tcgetattr(fd,&deepak);

  deepak.c_iflag &= ~(IXON | IXOFF | IXANY);
  deepak.c_oflag &= ~OPOST;
  deepak.c_lflag &= ~(ICANON |ECHO | ECHOE | ECHONL  | ISIG ); 
  deepak.c_cflag &= ~(CSIZE | PARENB);
  deepak.c_cflag &= ~CRTSCTS;
  deepak.c_cflag |= CS8;
  deepak.c_cflag |= (CREAD | CLOCAL);
  deepak.c_cflag |= B9600;
  deepak.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL); 
  deepak.c_cc[VMIN] = 0;
  deepak.c_cc[VTIME] = 0;
  deepak.c_cflag &= ~CSTOPB;
  tcsetattr(fd,TCSANOW, &deepak);
  
  while(1){

    printf("\n Waiting for message...\n");
    sleep(3);
    read(fd,data,sizeof(data));
    if(data > 0)
    {

            for(int i=0;i<20;i++)
	        {
                 printf("%c",data[i]);
            }
     
    }
    else
    {
      printf("Data not read");
    }

    memset(data,0,sizeof(data));
    
    sleep(1);
 
   
  }
  
  close(fd);
  return 0; 
}
