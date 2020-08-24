#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>

int got(int n,int m)
{
	int premul=1;
	int sum[n];
	for(int i=0;i<n;i++)
	{
		sum[i]=1;
	}
	for(int i=0;i<n;i++)
	{
		printf("%d\n",sum[i]);
	}
	for(int i=0;i<n;i++)
	{
		premul*=m;
		int index=(premul-1)%n;
		sum[index]=0;
	}
	int last =0;
	for(int i=0;i<n;i++)
	{
		if(sum[i]==1)
		{
			last=i;
		}
	}
	return last+1;
}
int main()
{
	int n=5;
	int m=2;
	scanf("%d",&n);
	scanf("%d",&m);
	printf("%d\n",got(n,m));
	return 0;
}
