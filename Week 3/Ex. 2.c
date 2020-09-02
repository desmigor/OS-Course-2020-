#include <stdio.h>

void bubble_sort(int array[], int n)
{
  int c, d, t;
 
  for (c = 0 ; c < ( n - 1 ); c++)
  {
    for (d = 0 ; d < n - c - 1; d++)
    {
      if (array[d] > array[d+1])
      {
        /* Swapping */

        t         = array[d];
        array[d]   = array[d+1];
        array[d+1] = t;
      }
    }
  }
}

int main(){

   int count, temp, i, j, number[30];

   printf("How many numbers are u going to enter?: ");
   scanf("%d",&count);

   printf("Enter %d numbers: ",count);

   for(i=0;i<count;i++)
   scanf("%d",&number[i]);
   
   bubble_sort(number, count);
 
  printf("Sorted list in ascending order:\n");
 
  for ( j = 0 ; j < count ; j++ ){
  	 printf("%ld", number[j]);
  	 printf (" ");
  }
    
  return 0;
   }
   
