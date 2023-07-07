       #include <sys/types.h>
       #include <sys/ipc.h>
       #include <sys/msg.h>
#include <stdio.h>
#include <unistd.h>

#define KEY 1234

int main()
{

    int qid;
    int i;
    struct msqid_ds buf;

            qid = msgget(KEY, IPC_CREAT);

	    msgctl(qid,IPC_STAT, &buf);
	    printf("Number of messages in queue: %d \n",buf.msg_qnum);
	    printf(" Maximum  of bytes in queue%d \n",buf.msg_qbytes);
	    printf("Number of bytes in queue :%d \n",buf.msg_cbytes);

return 0;
}
