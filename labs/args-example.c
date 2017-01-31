#include <stdio.h>

int main (int argc, char *argv[])
{
  printf ("argc\n");
  for (int i = 0; i < argc; i++)
    printf ("Argument %1d: %s\n", i + 1, argv[i]);

  return 0;
}
