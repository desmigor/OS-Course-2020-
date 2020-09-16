#include <stdio.h>
#include <pthread.h>

int j=0;
char s[20];
int position;
int bcons, bprod;
long long int t;

void *consume(void *arg)
{
	while (1)
	{
		if(bcons)
		continue;
		if (position==0)
		{
			bcons=1;
			bprod=0;
			continue;
		}
		printf ("%c", s[position]);
		position--;
	}
	pthread_exit(NULL);
	return NULL;
}

void* produce(void *arg)
{
while(1)
{
	if(bprod)
	continue;
	
	if(position==20){
		bcons=0;
		bprod=1;
		printf ("Done production with time %lld\n",t++);
		continue;
	}
	s[position]='a'+position;
	position++;
}
pthread_exit(NULL);
return NULL;
}


int main()
{
	bcons=1;
	
	pthread_t tprod,tcons;

	pthread_create (&tprod,NULL,produce,NULL);
	pthread_create (&tcons,NULL,consume,NULL);
	while(1);
// stopped at 154767
return 0;
}

