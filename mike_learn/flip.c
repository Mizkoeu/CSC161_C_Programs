#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
  int pairs = 0;       
  int i;                // the counter variable
  int previousFlip = 0; // remember what the previous coin flip had
  

  srand (time (NULL));  /* seed the random number generator with
                           the current system time so it is different
                           every time the program is run */
  for (i = 0; i < 50000000; i++)
    {
      if (rand() % 2)
        {
          if (!previousFlip)
            pairs++;
          previousFlip = 1;
        }
      else previousFlip = 0;
    }
  printf ("The number is %d.\n", pairs);
  return 0;
}
