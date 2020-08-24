#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<pthread.h>

void sys_err(const char *str)
{
	perror(str);
	exit(1);
}

int main(int argc, char *argv[])
{
	int dp[10] = {
		1,2,3,4,5,6,7,8,9,10
	};
	for(int i = 0; i < 10; ++i){
		printf("now dp %d is %d!\n", i + 1, dp[i]);
	}
	char *p = "hellod";
	p[3] = 'M';
	printf("now %d\n",dp[100]);
	
	return 0;
}
