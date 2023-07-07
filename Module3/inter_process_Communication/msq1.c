       #include <sys/types.h>
       #include <sys/ipc.h>
       #include <sys/msg.h>
       #include<stdio.h>
       #include<unistd.h>

#define KEY 1234

int main()
{
	int msgid;
	msgid = msgget(KEY,IPC_CREAT);
	if(msgid >= 0)
	{
		printf("MsgQ created Successfully %d :\n",msgid);
	}
}

