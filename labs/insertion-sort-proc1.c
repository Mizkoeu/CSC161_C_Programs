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
  int i, min, n, pos, temp;
  unsigned array [] = {4, 2, 2, 3, 1, 9, 7};
  n = 7;
  
  printArray (array, 7);

  for (i = 0; i < n; i++)
    {
      min = i; 
      for (pos = i + 1; pos < n; pos++) 
        {
          if (array[pos] < array[min])
            min = pos;
        }
      if (min != i)
        {
          temp = array[i];
          array[i] = array[min];
          array[min] = temp;
        }
    }

  printArray (array, 7);

  return 0;
} /* main */

