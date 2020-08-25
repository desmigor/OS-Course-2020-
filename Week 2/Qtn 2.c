#include <stdio.h>
#include <string.h>
int main()
{
   char s[1000];

   printf("Enter a string to reverse\n");
   scanf("%[^\n]", &s);
   strrev(s);
   printf("Reverse of the string: %s\n", s);
   return 0;
}
