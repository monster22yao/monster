#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>

int var=100;

int main(int argc, char *argv[])
{
	pid_t pid;

	pid =fork();

	if(pid==-1){
		perror("fork error");
		exit(1);
	}else if(pid>0){
		var=288;
		printf("parent, var = %d\n",var);
		printf("I am parent pid = %d, getppid = %d\n",getpid(),getppid());
	}else if(pid==0){
		var=200;
		printf("I am child pid = %d, ppid = %d\n",getpid(),getppid());
		printf("child, var = %d\n",var);
	}

	printf("---------------finish---------------\n");

	return 0;
}
