#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<fcntl.h>
#include<sys/wait.h>

void sys_err(const char *str)
{
	perror(str);
	exit(1);
}

int main(int argc, char *argv[])
{
	int fd1,fd2;
	pid_t pid;
	char buf[1024];
	char *str="-----------test for shared fd in parent child process-----\n";

	pid =fork();
	if(pid<0){
		perror("open error");
		exit(1);
	}else if(pid==0){
		fd1=open("text.txt",O_RDWR);
		if(fd1<0){
			perror("open error");
			exit(1);
		}
		write(fd1,str,strlen(str));
		printf("child wrote over...\n");
	}else{
		fd2=open("text.txt",O_RDWR);
		if(fd2<0){
			perror("open error");
			exit(1);
		}
		sleep(1);

		int len=read(fd2,buf,sizeof(buf));
		write(STDOUT_FILENO,buf,len);

		wait(NULL);
	}
	
	return 0;
}
