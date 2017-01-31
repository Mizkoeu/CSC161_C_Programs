/************************
 * scanf-example.c
 *
 * Program to show a simple use of scanf.
 *
 * Author: April O'Neill
 * Created: 25 July 2011
 *
 * Revised:  16 October 2012 by Henry M. Walker
 ************************/

#include <stdio.h>

int
main()
{
  double number;
  char input[30];     /* 30 is an arbitrary number, limiting input's length */

  printf ("Enter a number of the double type: ");
  scanf ("%lf", &number);  // supply address of double variable
  printf ("\tYou entered the number \"%lf\".\n", number);

  printf ("Enter a word: ");
  scanf ("%s", input);     // as an array, input represents a base address
  printf ("\tYou entered the word \"%s\".\n", input);

  printf ("\n\tSummary\n");
  printf ("\tnumber:  %lf\n", number);
  printf ("\tstring:  %s\n", input);

  return 0;
}
