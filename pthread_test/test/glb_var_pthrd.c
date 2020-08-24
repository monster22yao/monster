#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<pthread.h>

int var=100;

void *tfn(void *arg){
	var=200;
	printf("thread, var = %d\n",var);

	return NULL;
}

void sys_err(const char *str)
{
	perror(str);
	exit(1);
}

int main(int argc, char *argv[])
{
	printf("At first var = %d\n",var);

	pthread_t tid;
	pthread_create(&tid,NULL,tfn,NULL);
	sleep(1);

	printf("after pthread_create, var = %d\n",var);
	
	return 0;
}
