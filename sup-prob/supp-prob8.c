
/***********************************************************************
 * Name(s): Mike Zou                                                   *
 * Box(s): 4642                                                        *
 * Assignment: Supplemental Problem 8: Common Letters                  *
 * Assignment for 12/02/16                                             *
 ***********************************************************************/

/* *********************************************************************
 * Academic honesty certification:                                     *
 *   Written/online sources used:                                      *
 *      Stackexchange: C program to find frequency of characters in a  *
 *                     string. Found at http://stackoverflow.com/questi*
 *                     ons/6712587/counting-frequency-of-characters-in-*
 *                     a-string                                        *
 *      Although code is written in java, the main idea of counting fre*
 *      quency is learned from reading this post on Stackoverflow      *
 *   Help obtained                                                     *
 *     NONE                                                            *
 *   My/our signature(s) below confirms that the above list of sources *
 *   is complete AND that I/we have not talked to anyone else          *
 *   (e.g., CSC 161 students) about the solution to this problem       *
 *                                                                     *
 *   Signature: Mike Zou                                               *
 ***********************************************************************/

/* This is a program that reads two strings and counts how many letters 
   the strings have in common. */


#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
  /*declare strings for storing user input.
    size of string is set at 50 since words in most languages don't 
    surpass this limit */
  
  char word1[50];
  char word2[50];

  /*declare and initialize  string of int to store frequency of 
    each alphabetical letter in a word */
  
  int count1[26] = {0};
  int count2[26] = {0};

  //declare and initialize sum to count the number of common letters.
  int sum = 0;

  //declare and initialize variables for loops.
  int j = 0;
  int k = 0;

  //prompt for and scan user input.
  printf ("Please enter 2 words to compare: ");
  scanf ("%s %s", word1, word2);

  //loop through first input string to count letter frequency
  while (word1[j] != '\0') {
    char letter = tolower (word1[j]); //words are case-insensitive
    count1[letter - 'a']++;
    j++;
  }
  
  //loop through second input string to count letter frequency
  while (word2[k] != '\0') {
    char letter = tolower (word2[k]);
    count2[letter - 'a']++;
    k++;
  }

  /* compare the letter counts of two words and find max number 
     of common letters. */
  for (int i = 0; i < 26; i++) {
    if (count1[i] < count2[i])
      sum += count1[i];
    else sum += count2[i];
  }

  //print the result.
  printf ("Number of common letters is  %d!\n", sum);
  
  return 0;
}




/***********************************************************************
******************************   Testing  ******************************
************************************************************************
Preliminary testing: we can test the examples from the problem and see
if the results are correct.

Please enter 2 words to compare: room tool
Number of common letters is 2!

Please enter 2 words to compare: fewer red
Number of common letters is 2!

Please enter 2 words to compare: Mississippi Iowa
Number of common letters is 1!

It seems that our program is working!

To provide more rigorous testing, we can consider separate cases:
Case 1: no common letter at all between words
Please enter 2 words to compare: hard soft
Expected outcome: 0
Actual outcome:
Number of common letters is  0!

Case 2: more than one DIFFERENT common letters
Please enter 2 words to compare: Fate flight
Expected outcome: 2
Actual outcome:
Number of common letters is  2!


Case 3: more than one SAME common letters
Please enter 2 words to compare: Gooogle Omnitooooth
Expected outcome: 3
Actual outcome:
Number of common letters is 3!

Case 4: common letters are in upper and lower cases 
       (To make sure that the program is case-insensitive)
Please enter 2 words to compare: KlarK kobe 
Expected outcome: 1
Actual outcome:   
Number of common letters is  1!

Case 5: when punctuation marks and numbers are present in string
Please enter 2 words to compare: nike2016 apple2016
Expected outcome: 1
Actual outcome: 
Number of common letters is  1!


Please enter 2 words to compare: hey! hello!
Expected outcome: 2
Actual outcome: 
Number of common letters is  2!



***********************************************************************
*********************  Statement of Correctness ***********************
***********************************************************************

I ran this program multiple times with a wide variety of representative
cases considered. For each case, I only showed one testing scenario, but
there are more examples I tried, all of which produce results as expected.
The program does what it is supposed to do according to the supplemental 
problem description. 

The idea behind the program is simply to count the frequency of all 26 
letters appearing in both strings entered. Then the 2 int arrays of letter 
frequencies can be compared on a one to one basis. For example, the 
frequencies of letter 'a' in both strings are compared, then those of
'b', and 'c', and so forth. The program takes the lesser of the two
frequencies and add it to a sum value to keep track of number of common
letters. Taking the lesser of the two counts is because we want to find
the number of common letters, which means to take the intersection of 
the two sets. At the end of the loop through all 26 letter frequencies,
we exhaust the list and come to a final result of how many common letters
exist between the two strings. 

Since I used tolower function to convert all letters to lower case,
the program also deals with special cases such as when the strings have 
the same spelling but different cases. I experimented input strings with 
numbers and punctuation marks, all of which worked as expected (didn't 
count towards the number of common letter).

With these results, we can arrive at the conclusion that the proogram 
is correct all intents and purposes. 


**********************************************************************
****************************** THE END  ******************************
*********************************************************************/
