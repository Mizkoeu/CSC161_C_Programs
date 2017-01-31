/* program to average two numbers */

#include <stdio.h>

int main ()
{
  int num1, num2;
  printf ("Enter two integers:  ");
  scanf ("%d%d", &num1, &num2);
  int avg = (num1/2) + (num2/2);
  printf ("The average of the numbers is %d\n", avg);
  
  return 0;
}
