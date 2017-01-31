/* program to test skipping of white space by scanf */

#define MaxLen 10
#include <stdio.h>

int main ()
{
  char str [MaxLen];
  
  printf ("enter string\n");

  scanf ("%10s", str);
  
  printf ("'%10s'\n", str);


  return 0;
}
