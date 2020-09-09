#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	size_t i ;
  for (i = 0; i < 5; ++i) {
    fork();
  }
  unsigned int sec = 5;
  sleep(sec);
  return 0;
}

/**
	  * The number in "i" determines the depth of the fork tree
	  * Each process gets forked into 2, each of which get forked into 2 more
	  * The total number of processes will reach 2^i
	  */
