#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<fcntl.h>
#include<sys/mman.h>

struct student{
	int id;
	char name[256];
	int age;
};

void sys_err(const char *str)
{
	perror(str);
	exit(1);
}

int main(int argc, char *argv[])
{
	struct student stu;
	struct student *p;

	int fd=open("/dev/zero",O_RDWR);
	
	p=mmap(NULL,490,PROT_READ,MAP_SHARED,fd,0);
	if(p==MAP_FAILED){
		sys_err("mmap error");
	}
	
	close(fd);

	while(1){
		printf("id = %d, name = %s, age = %d\n",p->id,p->name,p->age);
		sleep(1);
	}

	munmap(p,sizeof(stu));

	return 0;
}
