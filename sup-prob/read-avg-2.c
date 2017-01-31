/* program to 
      read numbers from the keyboard until negative entered
      average the numbers
      print them out in reverse order
*/

/* approach 2:  allocate space for numbers as needed */

#include <stdio.h>
#include <stdlib.h>

int main ()

{
  int arraySize = 10;
  int itemsRead = 0;
  int i;
  double sum = 0;

  double * values = malloc (arraySize * sizeof (double));

  /* read values */
  printf ("program to read, average, and display numbers\n");
  printf ("enter numbers, ending with a negative\n");
  scanf ("%lf", &values[itemsRead]);
  while (values[itemsRead] >= 0.0)
    {
      sum += values[itemsRead];
      itemsRead++;
      if (itemsRead == arraySize)
        {
          double * temp = malloc (2 * arraySize * sizeof (double));
          for (i = 0; i < itemsRead; i++)
            temp[i] = values[i];
          free (values);
          arraySize = 2 * arraySize;
          values = temp;
        }
      scanf ("%lf", &values[itemsRead]);
    }

  printf ("the average of the %d numbers is %lf\n",
          itemsRead, sum / itemsRead);

  printf ("the numbers in reverse order are:\n");
  for (i = itemsRead-1 ; i >= 0; i--)
    printf ("%10.2lf", values[i]);

  return 0;
}
