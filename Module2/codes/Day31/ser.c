#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
        int fd;
        fd=open("/dev/ttyUSB0",O_CREAT);
        if(fd == -1)
        {
                printf("Unable to open the file");

        }
        else
        {
                printf("located successfully");
        }


}
