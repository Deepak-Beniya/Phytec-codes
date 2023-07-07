#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

#define KEY 1234
typedef struct{
        long msgtype;
        char buffer[100];
}msg;

int main()
{
        int qid;
        int i;
        msg m1,m2,m3;
        qid = msgget(KEY, IPC_CREAT);
        printf("%d",qid);
	i=msgrcv(qid,&m1,sizeof(msg),1,0);
	for(i=0;i<100;i++)
	{
		printf("%c",m1.buffer[i]);
	}

		printf("\n");

        i=msgrcv(qid,&m2,sizeof(msg),2,0);
        for(i=0;i<100;i++)
        {
                printf("%c",m2.buffer[i]);
        }

                printf("\n");

	i=msgrcv(qid,&m3,sizeof(msg),3,0);
        for(i=0;i<100;i++)
        {
                printf("%c",m3.buffer[i]);
        }
                printf("\n");





}
