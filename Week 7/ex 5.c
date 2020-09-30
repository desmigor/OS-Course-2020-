#include <stdio.h>
#include <stdlib.h>

int main()
{
	char **s = (char**)malloc(sizeof(char*));	// allocating memory for the pointer
	char foo[] = "Hello World";
	*s = foo; // The segmentation fault was happening on this line
	printf("s is %p\n", s);	 //  I used %p to print the address of pointer. The output is displayed in hexadecimal value.
	s[0] = foo;
	printf("s[0] is %s\n", s[0]);
	free(s);
	return 0;
}
