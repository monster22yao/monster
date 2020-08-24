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
	int i;
	alarm(1);

	for(i=0;;i++){
		printf("%d\n",i);
	}
	
	return 0;
}
