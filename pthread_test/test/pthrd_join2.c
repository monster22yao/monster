#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<pthread.h>

struct thrd{
	int var;
	char str[256];
};

void sys_err(const char *str)
{
	perror(str);
	exit(1);
}

void *tfn(void *arg){
	struct thrd *tval;
	tval=malloc(sizeof(tval));
	tval->var=100;
	strcpy(tval->str,"hello thread");

	return (void *)tval;
}

int main(int argc, char *argv[])
{
	pthread_t tid;
	struct thrd *retval;

	int ret=pthread_create(&tid,NULL,tfn,NULL);
	if(ret!=0){
		sys_err("pthread_create error");
	}

	ret=pthread_join(tid,(void **)&retval);
	if(ret!=0){
		sys_err("pthread_join error");
	}

	printf("child thread exit with var = %d,str = %s\n",retval->var,retval->str);

	pthread_exit(NULL);
	
	return 0;
}
