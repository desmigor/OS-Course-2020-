#include <stdio.h>
#include <stdlib.h>
void triangle (int n){
   int i,k,j;
   for (i = 0; i <= n; i++){
   	for (k=n; k>i; k--)
   		printf(" ");
   	for (j = 1;j <=(2*i-1); j++)
   	    printf("*");
   	printf("\n");
   }
}

int main(int argc, char** argv) {
    int arg1 = atoi(argv[1]);
  triangle (arg1);
    return 0; 
}


