#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>

int main(void) {

	int file = open("ex1.txt", O_RDWR);
	if (file == -1)
	{
		printf("Error in opening the file 'ex1.txt'\n");
	}

	struct stat file_buff;
	if (fstat(file, &file_buff) != 0)
	{
		perror("Unable to get stats of the file\n");
    	return 1;
	}
	size_t filesize = file_buff.st_size;

	char string[] = "This is a nice day";

	char * region = mmap(
    	NULL,
    	filesize,
    	PROT_READ|PROT_WRITE,
    	MAP_SHARED,
    	file,
    	0
  	);

	if (region == MAP_FAILED)
	{
		close(file);
    	perror("Could not mmap");
    	return 1;
  	}

  	memcpy(region, string, sizeof(string)-1);

  	// printf("%ld\n", sizeof(string));
  	// printf("New string: %s\n", region);

  	int unmap_result = munmap(region, sizeof(string)-1);
  	if (unmap_result != 0)
  	{
  		close(file);
    	perror("Could not munmap the file\n");
    	return 1;
  	}

  	close(file);

  	return 0;
}
