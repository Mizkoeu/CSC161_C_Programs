#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
  int i;
  srand (time ((time_t *) 0) );
  printf ("the first 12 numbers returned by the rand function are:\n");
  for (i  = 0; i < 4; i++)
    printf ("%15d %15d %15d\n", rand(), rand(), rand());

  return 0;
}
