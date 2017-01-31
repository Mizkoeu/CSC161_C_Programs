#include <stdio.h>
/* program illustrating arrays, strings, and pointers */

int main()
{
  /* first as an array of characters */
  char first [4] = {'C', 'o', 'l', 'd'};

  /* second as a string:  character array ending with a null */  
  char second[6] = "World";

  /* third as an array of characters */
  char third [16] = {'C', 'o', 'm', 'p', 'u', 't', 'e', 'r',
                     ' ', 'S', 'c', 'i', 'e', 'n', 'c', 'e'};

  /* fourth as a pointer to an array of characters */
  char * fourth = second;

  /* fifth as a pointer to a string literal */
  char * fifth = "Hello";

  //fifth[3] = 0;
  first[3] = second[3] = third[3] = 0;
  /* print first 3 characters in array */
  printf ("first 3 characters in each array\n");
  printf ("   first: %c%c%c\n",  first[0],  first[1],  first[2]);
  printf ("  second: %c%c%c\n", second[0], second[1], second[2]);
  printf ("   third: %c%c%c\n",  third[0],  third[1],  third[2]);
  printf ("  fourth: %c%c%c\n", fourth[0], fourth[1], fourth[2]);
  printf ("   fifth: %c%c%c\n",  fifth[0],  fifth[1],  fifth[2]);

  /* print base addresses */
  printf ("Variable addresses and array base addresses\n");
  printf ("   first address: %u,   array base address: %u\n", &first,  first);
  printf ("  second address: %u,   array base address: %u\n", &second, second);
  printf ("   third address: %u,   array base address: %u\n", &third,  third);
  printf ("  fourth address: %u,   array base address: %u\n", &fourth, fourth);
  printf ("   fifth address: %u,   array base address: %u\n", &fifth,  fifth);

  /* print arrays as strings */
  printf ("variables printed as strings\n");
  printf ("   first: %s\n", first);
  printf ("  second: %s\n", second);
  printf ("   third: %s\n", third);
  printf ("  fourth: %s\n", fourth);
  printf ("   fifth: %s\n", fifth);

  return 0;
}
