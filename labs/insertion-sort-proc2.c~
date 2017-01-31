#include <stdio.h>

void printArray (unsigned * array, int length)
{
  int i;

  printf ("[ ");
  for (i = 0; i < length; i++)
    printf ("%u ", array[i]);
  printf ("]\n");
} //printArray


int main()
{
  int i, n;
  unsigned array [] = {4, 2, 2, 3, 1, 9, 7};
  n = 7;
  
  printArray (array, 7);

  for (i = 1; i < n; ++i) {
    int key = array[i];
    int j = i - 1;
    while ((j >= 0) && (key < array[j])) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }

  printArray (array, 7);

  return 0;
} /* main */
