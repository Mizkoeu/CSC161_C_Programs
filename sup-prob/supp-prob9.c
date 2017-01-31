
/***********************************************************************
 * Name(s): Mike Zou                                                   *
 * Box(s): 4642                                                        *
 * Assignment: Supplemental Problem 9: Printing Cross Words            *
 * Assignment for 12/02/16                                             *
 ***********************************************************************/

/* *********************************************************************
 * Academic honesty certification:                                     *
 *   Written/online sources used: NONE                                 *
 *   Help obtained                                                     *
 *     NONE                                                            *
 *   My/our signature(s) below confirms that the above list of sources *
 *   is complete AND that I/we have not talked to anyone else          *
 *   (e.g., CSC 161 students) about the solution to this problem       *
 *                                                                     *
 *   Signature: Mike Zou                                               *
 ***********************************************************************/

/* This program reads two words from a terminal window and prints them 
in the cross word pattern (assuming they have a letter in common). The 
program is case sensitive and different cases of letters are considered
different. */

#include <stdio.h>
#include <string.h>

int main()
{
  //declare strings to store user inputs.
  char word1[50];
  char word2[50];

  //prompt for and scan user input.
  printf ("Please enter 2 words with at least one common letter: ");
  scanf ("%s %s", word1, word2);

  //define string lengths for use in loops.
  int len1 = strlen(word1);
  int len2 = strlen(word2);

  //define variable to keep track of position of the common letter.
  int i, n;
  
  //define exitVal for breaking out of nested-loop.
  int exitVal = 1;

  //nested-loop to compare words letter by letter.
  for (i = 0; (i < len1) && (exitVal != 0); i++) {
    for (n = 0; n < len2; n++) {    
      if (word1[i] == word2[n]) {
        exitVal = 0;
        break;
      }
    }
  }

  //when input words have no common letter, error message is printed.
  if (exitVal != 0) {
    printf ("Sorry, I don't see any common letter in your words...\n");
    return 0;
  }

  //print the cross words line by line
  for (int k = 0; k < len1; k++) {
    /*at the line where common letter first appears, entire word is 
      printed horizontally */
    if (k == i - 1)
      printf ("%s\n", word2);

    //otherwise, one char is printed per line
    else {
      //lopp of white space to put the char in right position
      for (int j = 0; j < n; j++) 
        printf (" ");
      printf ("%c\n", word1[k]);}
  }
  
  return 0;
}

/***********************************************************************
******************************   Testing  ******************************
************************************************************************
Case 1: both words have common letter as the first letter
Please enter 2 words with at least one common letter: functional food
Expected outcome: 
food
u
n
c
t
i
o
n
a
l

Actual outcome:
food
u
n
c
t
i
o
n
a
l

Case 2: common letters are in the middle
Please enter 2 words with at least one common letter: haywire kiwi
Expected outcome:
  h
  a
  y
kiwi
  i
  r
  e

Actual outcome:
  h
  a
  y
kiwi
  i
  r
  e

Case 3: common letters are both at the end of words
Please enter 2 words with at least one common letter: problems wings
Expected outcome:
    p
    r
    o
    b
    l
    e
    m
wings

Actual outcome:
    p
    r
    o
    b
    l
    e
    m
wings

Case 4: more than one common letters
Please enter 2 words with at least one common letter: Google tooth
Expected outcome:
 G
tooth
 o
 g
 l
 e

Actual outcome:
 G
tooth
 o
 g
 l
 e

Case 5: no common letter at all
Please enter 2 words with at least one common letter: writer blog 
Expected outcome: error message should be printed.
Actual outcome:
Sorry, I don't see any common letter in your words...

Case 6: common letter is in different cases (upper/lower)
Please enter 2 words with at least one common letter: functional SCHEME
Expected outcome: Error message since no cmmon letter is found.
Actual outcome:
Sorry, I don't see any common letter in your words...


***********************************************************************
*********************  Statement of Correctness ***********************
***********************************************************************
I ran this program many times to check every conceivable scenario of user
inputs and see if the program works as expected. It turns out that the 
program handles all the cases nicely and print out the cross words pattern
as described in the problem. 

The idea behind the program is that it compares the two words entered in
a nested-loop (comparison on every possible combinations of letters) and 
breaks out of the loop once a pair of identical letters is encountered.
Then the variables i and n record the positions of the found letter in 
their respective words, while an exitVal records if the loop is completed 
without finding any common letter. Lastly, the program either prints an
error message if no common letter is found, or prints out the cross word
pattern line by line using a simple conditional nested in a loop (see 
code above).

The program meets every condition set forth in the problem. Firstly, 
the cross word pattern is achieved. Secondly, if the words have more 
than one letter in common, then they are printed with the crossing at
the first common letter found by the searching algorithm. If the words 
have no letters in common, then the program does print an error message.

Overall, the program is short and concise. It conveys the simple idea
of reading, processing and printing characters in strings. My testings
have shown that the program is correct and runs efficiently.

***********************************************************************
***********************************************************************/

