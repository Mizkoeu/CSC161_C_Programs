
/***********************************************************************
 * Name(s): Mike Zou                                                   *
 * Box(s): 4642                                                        *
 * Assignment: Supplemental Problem 7: Alphabetizing Numbers           *
 * Assignment for 12/02/16                                             *
 ***********************************************************************/

/* *********************************************************************
 * Academic honesty certification:                                     *
 *   Written/online sources used:                                      *
 *     CSC161 Reading: Strings in c                                    *
 *       http://www.cs.grinnell.edu/~walker/courses/161.fa16/show-resou*
 *       rce.php?resourceID=522                                        *
 *     By Henry M. Walker. Accessed on 11/29/16.                       *
 *   Help obtained                                                     *
 *     NONE                                                            *
 *   My/our signature(s) below confirms that the above list of sources *
 *   is complete AND that I/we have not talked to anyone else          *
 *   (e.g., CSC 161 students) about the solution to this problem       *
 *                                                                     *
 *   Signature: Mike Zou                                               *
 ***********************************************************************/

/* This program generates the names of the numbers from zero to two hundred 
   and prints them in alphabetical order. */

#include <stdio.h>
#include <string.h>

void numGenerate (int i, char **stringArray, char * number);

void insertionSort (char stringArray [201][30]);

int main ()
{
  //declare a string of special names to be used later to form number names.
  char *special[29] = {"zero", "one ", "two ", "three", "four ", "five ",
                       "six ", "seven ", "eight ", "nine ", "ten", "eleven",
                       "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
                       "seventeen", "eighteen", "nineteen", "twenty ",
                       "thirty ", "forty ", "fifty ", "sixty ", "seventy ",
                       "eighty ", "ninety ", "hundred "};

  //declare a 2D array to store names of numbers.
  char numberArray[201][30];

  //declare a string for temporarily holding number name generated.
  char numberHolder[30];

  //loop to generate all names of 1 to 200 and copy to 2D array.
  for (int i = 0; i <= 200; i++) {
    numGenerate (i, special, numberHolder);
    strcpy (numberArray[i],  numberHolder);
  }

  //use insertion sort algorithm to sort strings in 2D array.
  insertionSort (numberArray);

  //print the strings in the 2D array.
  for (int i = 0; i <= 200; i++)
    printf ("%s\n", numberArray[i]);
  
  return 0;
}

//function to generate the name of a number and store it in numberHolder.
void numGenerate (int i, char **stringArray, char * number)
{
  //determine the value of each digit of the given number.
  int singleDigit = (i % 100) % 10;
  int tensDigit = ((i % 100) - singleDigit) / 10;
  int hundredDigit = (i - (i % 100)) / 100;

  //generate name based on cases.
  if (i < 20)
    strcpy (number, stringArray[i]);
  else if (i < 100) {
    char singleName[5];
    char tensName[7];
    strcpy (singleName, stringArray[singleDigit]);
    strcpy (tensName, stringArray[tensDigit + 18]);
    strcat (tensName, singleName);
    strcpy (number, tensName);
  }
  else if (i < 120) {
    strcpy (number, "one hundred ");
    strcat (number, stringArray[i-100]);
  }
  else if (i < 200) {
    char singleName[5];
    char tensName[7];
    char hundredName[5];
    strcpy (singleName, stringArray[singleDigit]);
    strcpy (tensName, stringArray[tensDigit + 18]);
    strcpy (hundredName, stringArray[hundredDigit]);
    strcat (hundredName, stringArray[28]);
    strcat (hundredName, tensName);
    strcat (hundredName, singleName);
    strcpy (number, hundredName);
  }
  else strcpy (number, "two hundred");
}

//function to sort a 2D array.
void insertionSort (char stringArray [201][30])
{
  for (int k = 1; k < 201; k++) {
    char item[30];
    strcpy (item, stringArray[k]);
    int i = k-1;
    while ((i >= 0) && (strcmp (stringArray[i], item) > 0)) {
      strcpy (stringArray[i+1], stringArray[i]);
      i--;
    }
    strcpy (stringArray[i+1], item);
  }
}



/**********************************************************************
*********************  Statement of Correctness ***********************
***********************************************************************

This program can be easily checked to be correct because it outputs
the correct result: the names of 0 to 200 are indeed printed out in 
alphabetical order. This output, due to iits sheer length, shall not
be presented here in the statement of correctness.

To briefly explain the thought process behind this program, I wrote
down every word that can possibly come up in the name of these 201 
numbers, realizing in total there are only around 28 of them. Thus,
to simplify the procedure of making the 2D array of number names, I 
wrote a helper function to concatenate the 28 special strings according
to the number given. In this way, the program is much more efficient 
in terms of generating the initial array of number names. 

Then I implemented an insertion sort algorithm to sort the 2D array
in alphabetical order, which is a reasonably efficient sorting method
to use in this case. Finally, the program uses a simple loop to print
the 2D array one string in a line. 

After running the program, the output is indeed what we would expect.
I have checked that every string printed is alphabetically ordered and
all 201 numbers are in fact printed.

**********************************************************************
****************************** THE END  ******************************
*********************************************************************/
