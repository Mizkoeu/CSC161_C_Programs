/* program to allow experimentation of several stack implementations */

#include <stdio.h>
#include <string.h>

/* include successive stack implementations with the following line */
#include "stack-lab-1.c"

int main ()
{
  /* set up stack variable */
  stringStack myStack;
  initializeStack (&myStack);
 
  printf ("program to follow status of string variables during processing\n");
  printf ("progress commentary      a     b     c     d     e     f     g     h\n");

  char a [6] = "apple";
  char b [6] = "beans";
  char c [6] = "corn";
  printf ("initialize a, b, c  ");
  printf (" %5s %5s %5s\n", a, b, c); 

  /* push a, b, c on stack */
  push (&myStack, a);
  push (&myStack, b);
  push (&myStack, c);

  /* pop stack 3 times */
  char * d = pop (&myStack);
  char * e = pop (&myStack);
  char * f = pop (&myStack);
  printf ("pop to get d, e, f  ");
  printf (" %5s %5s %5s %5s %5s %5s\n", a, b, c, d, e, f); 

  /* change a, e */
  strcpy (a, "fruit");
  strcpy (e, "peas");
  printf ("change a, e         ");
  printf (" %5s %5s %5s %5s %5s %5s\n", a, b, c, d, e, f);

  /* create new strings g, h and push on stack */ 
  char g [6] = "beet";
  char h [6] = "olive";
  push (&myStack, g);
  push (&myStack, h);

  printf ("push new g, h       ");
  printf (" %5s %5s %5s %5s %5s %5s %5s %5s\n", a, b, c, d, e, f, g, h);

  /* change g */
  strcpy (g, "dill");
  printf ("change g            ");
  printf (" %5s %5s %5s %5s %5s %5s %5s %5s\n", a, b, c, d, e, f, g, h);

  return 0;
}
