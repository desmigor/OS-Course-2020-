#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int j=0;
void *thread(void * arg)
{
		sleep(1);
		printf("Thread message #%d\n",j);
		j++;
	return NULL;
}

int main()
{
	pthread_t t;
	int i;
	for (i=0;i<3;i++){
	printf("Thread #%d created\n",i);
	pthread_create (&t,NULL,&thread,NULL);
	pthread_join(t,NULL); //It waits for the thread to finish
}

pthread_exit(NULL);
return 0;
}

