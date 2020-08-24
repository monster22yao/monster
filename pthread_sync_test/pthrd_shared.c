#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<pthread.h>

pthread_mutex_t mutex;

void *tfn(void *arg){
	srand(time(NULL));

	while(1){
		pthread_mutex_lock(&mutex);
		printf("hello ");
		sleep(1);
		printf("world\n");
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
	return NULL;
}

int main(int argc, char *argv[])
{
	pthread_t tid;
	srand(time(NULL));
	int ret=pthread_mutex_init(&mutex,NULL);
	if(ret!=0){
		fprintf(stderr,"mutex init error:%s\n",strerror(ret));
		exit(1);
	}

	pthread_create(&tid,NULL,tfn,NULL);
	while(1){
		pthread_mutex_lock(&mutex);
		printf("HELLO ");
		sleep(1);
		printf("WORLD\n");
		pthread_mutex_unlock(&mutex);
		sleep(1);
	}
	pthread_join(tid,NULL);

	pthread_mutex_destroy(&mutex);
	
	return 0;
}
