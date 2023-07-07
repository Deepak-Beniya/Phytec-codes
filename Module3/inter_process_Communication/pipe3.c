#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<string.h>
int main()
{
        char ch[20];
        char ch1[20];
        mkfifo("f1",0666);
        mkfifo("f2",0666);
        int fd=open("f1",O_RDONLY);
        int fd1=open("f2",O_WRONLY);

        while(1)
        {
		read(fd,ch,sizeof(ch));
                printf("Received Message : %s \n",ch);
	        printf("Enter the message to send... \n");
                scanf("%s",ch1);
                write(fd1,ch1,strlen(ch1)+1);
		sleep(1);
        }
}

