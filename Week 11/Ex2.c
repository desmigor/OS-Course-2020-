#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

int main()
{
	char string[] = "Hello\n";

	setvbuf(stdout, NULL, _IOLBF, sizeof(string));

	for (int i = 0; i < sizeof(string)-1; ++i)
	{
		printf("%c\n", string[i]);
		sleep(1);
	}
	return 0;
}
