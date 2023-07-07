
#include <stdio.h>
#include <string.h>
#include <fcntl.h> 
#include <errno.h> 
#include <termios.h> 
#include <unistd.h> 

int main() {
   
       int data[20];	
  char rfid[20];
  int len;
  int fd;
	char buf[20];
  fd = open("/dev/ttyUSB1", O_RDWR );
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
  new_termios.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL); 

  new_termios.c_cc[VMIN] = 0;
  new_termios.c_cc[VTIME] = 0;
  

  
  new_termios.c_cflag &= ~CSTOPB;
  tcflush(fd,TCIOFLUSH);
  tcsetattr(fd,TCSANOW, &new_termios);
  /*
  strcpy(data,"Hi how are you \n");
  len = strlen(data);
  len = write(fd,data,len);
  printf("\n Wrote %d bytes over uart \n",len);
  memset(data,0,20);

  printf("\n Waiting for message...\n");

  sleep(5);



 len =read(fd,data,len);
 printf("Received %d bytes\n",len);
 //printf("Received string : %c \n",data);
 
 for(int i = 0; i <20; i++)
 {
   printf("%c", data[i]);
 }*/
  while(1){

    printf("\n Waiting for message...\n");
    sleep(5);
    int data ;
    data = read(fd,rfid,20);

    
    if(rfid > 0)
    {

            for(int i=0;i<20;i++)
	    {
                 printf("%c",rfid[i]);
            }
     
    }
    else
    {
      printf("Data not read");
    }
    sleep(1);
 
   
  }
  
  close(fd);
  return 0; // success
}
