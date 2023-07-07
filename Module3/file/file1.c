#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<stdio.h>

int main()
{
	int fd;
	fd=open("hello.txt",O_RDONLY);
	if(fd==-1)
	{
		printf("failed to create file \n");
	}
	else printf("file created successfully \n");
}
