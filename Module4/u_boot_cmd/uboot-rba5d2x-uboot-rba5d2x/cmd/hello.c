#include<common.h>
#include<command.h>
#include<console.h>
#include<linux/delay.h>

static int do_hello(struct cmd_tbl *cmdtp, int flag,int argc,char *const argv[])
{
	printf("I am From Hello CMD\n");
	return 0;
}

U_BOOT_CMD(hello,1,0,do_hello,"Hello CMD Introduction","start - Rset the hello.\n""Printf The hello cmd '.");
