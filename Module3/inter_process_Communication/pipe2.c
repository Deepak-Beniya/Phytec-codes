#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
int main()
{
	char ch[20];
	char ch1[20];
	mkfifo("f1",0666);
	mkfifo("f2",0666);
	int fd=open("f1",O_WRONLY);
	int fd1=open("f2",O_RDONLY);

	while(1)
	{
		printf("Enter the message to send... \n");
		scanf("%s",ch);
		write(fd,ch,strlen(ch)+1);
		sleep(1);
		read(fd1,ch1,sizeof(ch1));
		printf("Received Message : %s \n",ch1);
	}
}





