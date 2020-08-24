#include"head.h"
int sub(int a,int b)
{
return a-b;
}
int main()
{
	int a=10,b=5;
	printf("%d-%d=%d\n",a,b,sub(a,b));
	return 0;
}
