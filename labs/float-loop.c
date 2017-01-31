/* Program to study a loop with floats */
#include <stdio.h>

int main ()
{
  float inc = 1.0/10.0;
  float val = 0.0;
  float end = 1.0;
  float sum = 0.0;

  printf ("program to loop with floats from %22.15f to %22.15f increment %22.15f\n",
          val, end, inc);

  while (val != end)
    {
      /* add to sum and print */
      sum += val;
      printf ("val = %22.15f;  sum = %22.15f\n", val, sum);

      /* increment val for loop test and next iteration */
      val += inc;
    }

  printf ("loop terminated with val = %22.15f;  sum = %22.15f\n", val, sum);

}
