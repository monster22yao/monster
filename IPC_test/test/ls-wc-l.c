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
	int fd[2];
	int ret;
	pid_t pid;

	ret=pipe(fd);
	if(ret==-1){
		sys_err("pipe error");
	}

	pid=fork();
	if(pid==-1){
		sys_err("fork error");
	}else if(pid>0){
		close(fd[1]);
		dup2(fd[0],STDIN_FILENO);
		execlp("wc","wc","-l",NULL);
		sys_err("exclp wc error");
	}else if(pid==0){
		close(fd[0]);
		dup2(fd[1],STDOUT_FILENO);
		execlp("ls","ls",NULL);
		sys_err("exclp ls error");
	}

	return 0;
}
