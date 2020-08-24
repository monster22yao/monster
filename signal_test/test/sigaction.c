#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<signal.h>
#include<signal.h>
#include<sys/wait.h>

void sys_err(const char *str)
{
	perror(str);
	exit(1);
}

void sig_catch(int signo){
	printf("catch you!! %d\n",signo);
	sleep(10);
	return;
}

int main(int argc, char *argv[])
{
	struct sigaction act,oldact;

	act.sa_handler=sig_catch;		// set callback function name
	sigemptyset(&(act.sa_mask));	// set mask when sig_catch working
	sigaddset(&act.sa_mask,SIGQUIT);
	act.sa_flags=0;					// usually use

	int ret;
	ret=sigaction(SIGINT,&act,&oldact);	
	if(ret==-1){
		sys_err("sigaction error");
	}
	//ret=sigaction(SIGQUIT,&act,&oldact);	
	if(ret==-1){
		sys_err("sigaction error");
	}

	while(1);
	
	return 0;
}
