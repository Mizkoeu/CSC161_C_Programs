/****************************************************************************
***************************** Problem 5 Revision ****************************
****************************************************************************/
//5a. Write a program to sort an array of strings into descending order.

#include <stdio.h>
#include <string.h>
#include "ctype.h"
#define arrayLen 10

int main()
{
  //declare variables for loop
  int i, j;

  //declare a temporary pointer to string to be used in loop
  char * temp;

  //declare an array of strings to be sorted
  char * array[arrayLen] = {
    "apple", "strawberry",
    "peach", "pineapple",
    "watermelon", "mango",
    "zebra", "tiger",
    "citrus", "x-men"
  };

  //first, print out the original order of the array
  printf("Original array of strings\n");
  for (i = 0; i < arrayLen; i++)
    printf("%s\n", array[i]);

  //sorting strings with insertion sort
  for (i = 1; i < arrayLen; ++i)
    {
      //make temp point to the current string
      temp = array[i];
      j = i - 1;

      //loop to move the current string forward to the correct position
      while ((j >= 0) && (strcmp (temp, array[j]) > 0)) {
        array[j+1] = array[j];
        --j;
      }
      
      //set the pointer at correct position as current string
      array[j+1] = temp;
    }

  //print out the list of strings after sorting
  printf("Sorted array of strings in decending order\n");
  for (i = 0; i < arrayLen; i++)
    printf("%s\n", array[i]);
    
  return 0;
}


/****************************************************************************
 ******************************** Testing ***********************************

The main program already has ten strings stored in an array. The program
print out the original order of the strings and then after sorting, it 
prints out the strings in a descending order.

Original array of strings
apple
strawberry
peach
pineapple
watermelon
mango
zebra
tiger
citrus
x-men
Sorted array of strings in decending order
zebra
x-men
watermelon
tiger
strawberry
pineapple
peach
mango
citrus
apple

The program produces the output as expected.

***************************** Explanantion *********************************
Why does the code perform the required task?

This program simply uses the framework of insertion sort provided and 
performs the sorting in reverse. In particular, I reversed the strcmp 
Boolean in the while loop because we want the program to sort the strings
in descending rather than ascending order. Therefore, the ">" sign
indicates that temp is alphabetically behind array[i], and the program
moves temp in front (repeatedly). Another important feature to note is 
that this program does not use strcpy to move the actual strings around,
which would be extremely inefficient. Instead, the program sorts the 
pointers in the array based on the strings that the pointers point to. 
In this case, the strings in memory are not moved, but the pointers are
changed in position. Thus, the program works as intended. 

****************************************************************************/


/* 5b. Write a code segment that reads two integer variables and a line of
text that appears on a line by itself.
*/

int main()
{
  //declare variables to store integer inputs
  int m, n;
  
  //declare a character to be used later for scanning white-space
  char ch;

  //declare a string of appropriate size to store user input
  char text[50];

  //prompt for user input
  printf("Please enter 2 integers");
  printf("and a line of text on a line by itself:\n");

  //read the numbers entered
  scanf(" %d %d ", &m, &n);

  //use while to skip over all the white spcaes and newline
  while (isspace(ch = getchar()));

  //read string from user input after a non-space char encountered
  fgets(text, 50, stdin);

  //print out the integers and string read
  printf ("The numbers input are %d and %d.\n", m, n);
  printf ("The text entered is %c%s\n", ch, text);

  return 0;
}

/****************************************************************************
 ******************************** Testing ***********************************
234 5466   


     this is a string after a lot of spaces!
Program Outcome:
The numbers input are 234 and 5466.
The text entered is this is a string after a lot of spaces!


***************************** Explanantion *********************************
This program works as it skips all the white spaces after the number entered
before reading up to 50 characters of text. To make sure all white spaces
and newlines are ignored, I used a while loop with an "isspace" Boolean 
operator to make the program do nothing until it first encounters a 
character. In the end, the program prints out the first non-space character 
encountered (namely "ch") and the string read by fgets (namely, "text").The
fgets parameter of 50 limits the number of characters being read.

On a side note, my tests have shown that using scanf(" %d %d ", &m, &n) does
also effectively skip over all the white spaces and newline. Because there's
a space between the second %d and the " back quotation mark, scanf will read
all the spaces and newline until a character appears in the standard input
buffer. This, in fact, achieves the same final outcome as the program using
a while loop of isspace Boolean expressions.

****************************************************************************/
