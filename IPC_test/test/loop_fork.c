#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<sys/wait.h>

int main(int argc, char *argv[])
{
	int i;
	pid_t pid,wpid;
	
	for(i=0;i<5;i++){
		if(fork()==0){
			if(i==2){
				pid=getpid();
				printf("------pid = %d\n",pid);
			}
			break;
		}
	}
	if(5==i){
		sleep(5);
		//wait(NULL);
		//wpid=waitpid(-1,NULL,WNOHANG);
		wpid=waitpid(pid,NULL,0);
		if(wpid==-1){
			perror("waitpid error");
			exit(1);
		}
		printf("I am parent, wait a child finish : %d\n",wpid);
	}
	else{
		sleep(i);	
		printf("I am %dth child, pid = %d\n",i+1,getpid());
	}

	return 0;
}
