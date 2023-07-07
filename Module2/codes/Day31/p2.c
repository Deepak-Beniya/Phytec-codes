#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<string.h>


int main()
{
        int fd;
        char buf[20];
        fd=open("hello.txt",O_RDWR | O_CREAT);
        if(fd == -1)
        {
                printf("unable to create file\n");
        }
        else
        {
                printf("file created successfully\n");
        }

        read(fd,buf,15);


        for(int i=0;i<20;i++){
                printf("%c",buf[i]);
        }


        close(fd);




}

