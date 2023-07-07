#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<string.h>


int main()
{
        int fd;
	char buf[30];
	loff_t offset;
        fd=open("lseek.txt",O_RDWR | O_CREAT | O_APPEND);
	if(fd == -1)
	{
		printf("unable to create file");
	}
	else
	{
		printf("file created successfully");
	}
        
	write(fd,"HELLO WORLD\n",15);
		
        offset=lseek(fd,0,SEEK_CUR);
	printf("%d",offset);
	write(fd,"I am",5);

	offset=lseek(fd,-2,SEEK_CUR);
	printf("%d",offset);
	write(fd,"Deepak",8);

	offset=lseek(fd,0,SEEK_CUR);
	printf("%d",offset);
	


	close(fd);

	


}

