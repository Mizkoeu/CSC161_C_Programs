/* C code for Examples 1 and 2 for Reading Data with scanf 
     use input 
K2.71828  H 3.141592
*/

#include <stdio.h>

int main ()
{
  double a, b;
  int i, result;
  char ch1, ch2;

  /* uncomment for example 1 */
  //result = scanf("%c %lf %c %d %lf", &ch1, &a, &ch2, &i, &b);
  /* uncomment for example 2 */
  result = scanf("%c%lf%c%d%lf", &ch1, &a, &ch2, &i, &b);
  printf ("Results:  ch1:  '%c'\n", ch1);
  printf ("            a:  %lf\n", a);
  printf ("          ch2:  '%c'\n", ch2);
  printf ("            i:  %d\n", i);
  printf ("            b:  %lf\n", b);
  printf ("       result:  %d\n", result);

  return 0;
}
