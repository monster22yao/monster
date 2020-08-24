
#include"hello.h"
#ifdef Hello
#define HI 20
#endif
int main(int argc,char *argv[])
{
    printf("it's me, mario%d\n",HI);
    return 0;
}
int myadd(int a,int b)
{
	int aa=a+a;
	int bb=b+b;
	return aa+bb;
}
