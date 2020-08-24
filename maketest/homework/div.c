#include"head.h"
int div1(int a,int b)
{
return a/b+1;
}
int main()
{
	int a=10,b=5;
	printf("%d/%d=%d\n",a,b,div1(a,b));
	return 0;
}
