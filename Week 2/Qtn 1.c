#include <stdio.h>
#include <limits.h>
#include <float.h>
int main() {
  int a;
  float b;
  double c;
  a=INT_MAX;
  b=FLT_MAX;
  c=DBL_MAX;
   printf("Integer Size:%ld \t",sizeof(a)); printf(" Integer Max:%d \n",a);
   printf("Float Size:%ld \t",sizeof(b)); printf(" Float Max:%.10e\n",b);
   printf("Double Size:%ld \t",sizeof(c)); printf(" Double Max:%.10e\n",c);
   return 0;
}
