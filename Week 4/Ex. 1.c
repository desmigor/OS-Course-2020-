#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t n;
    n=fork();
    int i;
    for (i=0;i<10;i++){
    	if (n>0)
    	printf("Hello from parent [%d- %d]\n", n, i);
    	else 
    	printf("Hello from child [%d- %d]\n", n, i);
    }
}
	/*
	 * Calling fork() returns the PID of the child process to the parent, and 0 to the child
	 * getpid() function will return the PID of the process in its call
	 * The PID increases by 1 for each new process
	 */
