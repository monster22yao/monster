#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/wait.h>

int main(int argc, char *argv[])
{
	pid_t pid,wpid;
	pid=fork();

	int status;

	if(pid==0){
		printf("---child, my pid = %d, going to sleep 10s\n",getpid());
		sleep(10);
		printf("---------------child die---------------\n");
		return 73;
	}else if(pid>0){
		//wpid=wait(NULL);
		wpid=wait(&status);
		if(wpid==-1){
			perror("wait error");
			exit(1);
		}
		if(WIFEXITED(status)){
			printf("child exit with %d\n",WEXITSTATUS(status));
		}
		if(WIFSIGNALED(status)){
			printf("child kill with sigal %d\n",WTERMSIG(status));
		}
		printf("---------------parent wait finish: %d\n",wpid);
	}else{
		perror("fork");
		return 1;
	}

	return 0;
}
