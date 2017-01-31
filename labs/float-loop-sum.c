/* program to compute the average of 10 real nubers,
   after discarding the smallest and largest.
*/

#include <stdio.h>

int main ()
{
  printf ("program to compute average of 10 real numbers,\n");
  printf ("  after discarding the smallest and largest\n");

  printf ("enter 10 numbers:  ");

  float smallest = 0;
  float largest = 0;
  float next;
  float sum = 0;

  int i;
  for (i = 0; i < 10; i++)
    {  
      scanf ("%f", &next);
      if (smallest > next)
        smallest = next;
      if (largest < next)
        largest = next;
      sum += next;
    }
  
  float result = (sum - smallest - largest) / 8.0;

  printf ("The computed truncated average is %lf\n", result);

  return 0;
}
