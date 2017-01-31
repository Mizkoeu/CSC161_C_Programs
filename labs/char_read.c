/* program to illustrate the use of the char data type
 */

#include <stdio.h>
#include <ctype.h>  /* draw upon several useful char functions */

int main()
{
  char c, d;
  printf("Please input a character:\n");
  scanf("%c", &c);
  printf ("   %c \t\t %d\n", c, c);
  if (isalpha (c))
    printf("%c is an alphabetica char\n", c);
  else
    printf("%c is not an alphabet\n", c);
  if (isalnum (c))
    printf("%c is either a letter char or a digit\n", c);
  else
    printf("%c is neither a letter nor a digit\n", c);
  d = toupper(c);
  printf ("%c capitalized is %c\n", c, d);
  return 0;
}
