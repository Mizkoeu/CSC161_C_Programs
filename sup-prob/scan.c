#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
  char haha[30];
  fgets(haha, 10, stdin);
  printf ("%s", haha);
  fgets(&haha[10], 10, stdin);
  printf ("%s", haha);
  return 0;
}
