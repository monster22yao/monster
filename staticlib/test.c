#include<stdio.h>
#include"mymath.h"
int mul(int a,int b)
{
	return a*b;
}
int main(int argc,char *argv[])
{
	int a=4,b=6;
	printf("%d+%d=%d\n",a,b,add(a,b));
	printf("%d-%d=%d\n",a,b,sub(a,b));
	printf("%d/%d=%d\n",a,b,div(a,b));
	printf("--%d*%d=%d\n",a,b,mul(a,b));
	return 0;
}
