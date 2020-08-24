#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<errno.h>
#include<string.h>

int main(int argc,char *argv[])
{
	int fd;
	
	fd =open("open.c",O_WRONLY);

	printf("fd = %d, errno=%d:%s\n",fd,errno,strerror(errno));

	close(fd);

	return 0;
}
