#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>

void sys_err(const char *str)
{
	perror(str);
	exit(1);
}

int main(int argc, char *argv[])
{
	pid_t pid;

	if((pid=fork())<0){
		perror("fork");
		exit(1);
	}else if(pid==0){
		printf("child process PID is %d\n",getpid());
		printf("Group ID of child is %d\n",getpgid(0));
		printf("Session ID of child is %d\n",getsid(0));

		sleep(10);
		setsid();

		printf("Changed:\n");

		printf("child process PID is %d\n",getpid());
		printf("Group ID of child is %d\n",getpgid(0));
		printf("Session ID of child is %d\n",getsid(0));

		sleep(20);

		exit(0);
	}
	
	return 0;
}
