
#include <stdio.h>
#include <string.h>
#include <fcntl.h> 
#include <errno.h> 
#include <termios.h> 
#include <unistd.h> 

int main() {
  
  char rfid[20];

  int fd;
	char buf[20];
  fd = open("/dev/ttyUSB0", O_RDWR );
	if(fd == -1)
	{
		printf("unable to create file");
	}
	else
	{
		printf("file created successfully");
	}



  struct termios new_termios;

  tcgetattr(fd,&new_termios);

  new_termios.c_iflag &= ~(IXON | IXOFF | IXANY);
  new_termios.c_oflag &= ~OPOST;
  new_termios.c_lflag &= ~(ICANON |ECHO | ECHOE | ECHONL  | ISIG ); 
  new_termios.c_cflag &= ~(CSIZE | PARENB);
  new_termios.c_cflag &= ~CRTSCTS;
  new_termios.c_cflag |= CS8;
  new_termios.c_cflag |= (CREAD | CLOCAL);
  new_termios.c_cflag |= B9600;
  //new_termios.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL); 

  new_termios.c_cc[VMIN] = 0;
  new_termios.c_cc[VTIME] = 0;


  int a;
  //new_termios.c_cflag &= ~CSTOPB;

  a=tcsetattr(fd,TCSANOW, &new_termios);
  
  while(1){

    printf("\n Waiting for message...\n");

    int data = read(fd,rfid,sizeof(rfid));

    while(1){
    if(data > 0)
    {

            for(int i=0;i<data;i++)
	    {
                 printf("%c",rfid[i]);
            }
     
    }
    else
    {
      printf("Data not read");
   
     
   
    }
     
     
    }

    
  }
  
  close(fd);
  return 0; // success
};
