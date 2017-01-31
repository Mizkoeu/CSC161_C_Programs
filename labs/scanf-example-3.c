/* C code for Example 3 for Reading Data with scanf 
   use input
12:34:56
or
12 : 34 : 56
*/

#include <stdio.h>

int main ()
{
  int hr, min, sec;
  /* uncomment for variation 3a */
  //scanf ("%d:%d:%d", &hr, &min, &sec);
  /* uncomment for variation 3b */
  scanf ("%d :%d :%d", &hr, &min, &sec);
  printf ("hours-minutes-sections: %d-%d-%d\n",
          hr, min, sec);

  return 0;
}
