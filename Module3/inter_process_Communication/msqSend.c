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
        m1.msgtype = 1;
        for(i=0; i<100;i++)
                m1.buffer[i]='a';
        m2.msgtype = 2;
        for(i=0; i<100; i++)
                m2.buffer[i]='b';
        m3.msgtype = 3;
        for(i=0; i<100; i++)
                m3.buffer[i]= 'c';
        i = msgsnd(qid,&m1,sizeof(msg),IPC_NOWAIT);
        printf("%d\n",qid);
        printf("return value of msgsnd of As= %d\n",i);

        i = msgsnd(qid,&m2,sizeof(msg),IPC_NOWAIT);
        printf("%d\n",qid);
        printf("return value of msgsnd of As= %d\n",i);

	i = msgsnd(qid,&m3,sizeof(msg),IPC_NOWAIT);
        printf("%d\n",qid);
        printf("return value of msgsnd of As= %d\n",i); 


}
