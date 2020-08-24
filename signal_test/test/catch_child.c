#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<signal.h>
#include<sys/wait.h>

void sys_err(const char *str)
{
	perror(str);
	exit(1);
}

void catch_child(int signo){
	pid_t wpid;

	while((wpid=wait(NULL))!=-1){
		printf("-----catch child id %d\n",wpid);
	}

	return;
}

int main(int argc, char *argv[])
{
	pid_t pid;
	// block
	sigset_t set;
	sigemptyset(&set);
	sigaddset(&set,SIGCHLD);
	sigprocmask(SIG_BLOCK,&set,NULL);

	int i;
	for(i=0;i<5;i++){
		if((pid=fork())==0){
			break;
		}
	}
	if(i==5){
		struct sigaction act;

		act.sa_handler=catch_child;
		sigemptyset(&act.sa_mask);
		act.sa_flags=0;

		sigaction(SIGCHLD,&act,NULL);

		// unblock
		sigprocmask(SIG_UNBLOCK,&set,NULL);
		
		printf("I'm parent, pid = %d\n",getpid());

		while(1);
	}else{
		printf("I'm child, pid = %d\n",getpid());
	}
	
	return 0;
}
