#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int n=0;
		printf("Please enter a number (size of array): ");
		scanf("%d", &n);

	
	int *arr = (int*)malloc(n * sizeof(int));
	
	int i;
	for(i=0; i<n; i++)
		arr[i] = i;
	
	printf("The Array is :\n");
	printf("{ ");
	for(i=0; i<n-1; i++)
		printf("%d, ", arr[i]);
	printf("%d }\n", arr[n-1]);
	
	free(arr);
	
	return 0;
}
