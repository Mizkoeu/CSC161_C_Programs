/***********************************************************************
 * Name: Mike Zou                                                      *
 * Box(s): 4642                                                        *
 * Assignment name: Supplemental Problem 4: A Simple Route Cipher      *
 *      (25% off if name/number does not match assignment)             *
 * Assignment for 11/15/16                                             *
 ***********************************************************************/

/* *********************************************************************
 * Academic honesty certification:                                     *
 *   Written/online sources used:                                      *
 *      CSC161 Reading: Character-by-Character Input                   *
 *        http://www.cs.grinnell.edu/~walker/courses/161.fa16/show-reso*
 *        urce.php?resourceID=545                                      *
 *   Help obtained                                                     *
 *     NONE.                                                           *
 *   My/our signature(s) below confirms that the above list of sources *
 *   is complete AND that I/we have not talked to anyone else          *
 *   (e.g., CSC 161 students) about the solution to this problem       *
 *                                                                     *
 *   Signature:                                                        *
 ***********************************************************************/
/* This program encrypts a message via router cipher method. It takes in
the row and colum numbers and arrange the message in  blocks of retangles,
before printing the encoded message. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
  int m, n; //variables for loop over 2D-array of blocks.
  int row, col; //variables for size of blocks to be determined by user.
  printf ("Enter the dimensions (format: row column): ");
  scanf ("%d %d\n", row, col);
  
  char cipher[row][col]; //declare a 2D char array.
  char text[200]; //declare a 1D string of length 200.
  int i = 0; //variable to keep track of current char in text.
  int counter; //variable for loop over the blocks.
  int strset; //variable to set extra chars to alphabetical letters.

  printf("We get: ");  //preparing for printing encrypted text

  //Read the message input and store in text string.
  fgets (text, 200, stdin);
  int len = strlen (text);
  int rect = row * col;
  //Calculate how many blocks there are in total by rounding up.
  int total = (len + (rect -2)) / rect; //rect-2 makes sure result is round up.
    
  char set = 'a'; 

  //we start filling up the extra spaces with alph letters.
  for (strset = len - 1; strset < total*rect; strset++)
    {
      text[strset] = set;
      set++;
    }

  //The loop for processing and printing each block.
  for (counter = 1; counter <= total; counter++)
    {
      for (m = 0; m < row; m++)
        {
          for (n = 0; n < col; n++)
            {
              //we extract chars from text and put them into cipher rectangle.
              cipher[m][n] = text[i];
              i++; //i increments to keep track of where we are in text[].
            }
        }

      //print out the block column by column.
      for (n = 0; n < col; n++)
        {
          for (m = 0; m < row; m++)
            {
              printf ("%c", cipher[m][n]);
            }
        }
    }
      
  printf("\n");
  return 0;

}
