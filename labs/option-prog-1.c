/* program to read integers and real numbers 
   and to compute sums in each category.  
   if a user types 'i', an integer should follow
      on the same line
   if a user types 'r', a real number should follow
      on the same line
   if the user types 'q', the program should report
      the integer and real sums and quit

   version a:  processing the user option with getchar
*/

#include <stdio.h>
#include <ctype.h>

int main ()
{
  /* variable declaration and initialization */
  int int_sum = 0;
  double real_sum = 0.0;
  char ch;
  int i;
  double d;

  printf ("program to compute integer and real sums\n");
  printf ("user options:\n");
  printf ("  enter i and an integer on the same line\n");
  printf ("  enter r and a real number on the line\n");
  printf ("  enter q to quit\n");

  /* strip initial white space */
  while (isspace (ch = getchar ()));

  /* allow both uppercase and lowercase options */
  ch = tolower (ch);

  /* process line */
  while (ch != 'q')
    {      
      if (ch == 'i')
        {
          scanf ("%i", &i);
          int_sum += i;
        }
      else if (ch == 'r')
        {
          scanf ("%lf", &d);
          real_sum += d;
        }
      else
        {
          printf ("invalid option:  %c\n", ch);
        }
      
      /* strip newline and any other white space */
      while (isspace (ch = getchar ()));
      
      /* allow both uppercase and lowercase options */
      ch = tolower (ch);
    }

  printf ("totals:\n");
  printf ("   integer sum: %d\n", int_sum);
  printf ("   real sum:    %lf\n", real_sum);

  return 0;
}
