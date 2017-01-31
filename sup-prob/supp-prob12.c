
/***********************************************************************
 * Name(s): Mike Zou                                                   *
 * Box(s): 4642                                                        *
 * Assignment: Supplemental Problem 12: Elementary Text Analysis       *
 * Assignment for 12/09/16 (Extra-credit due last day of class)        *
 ***********************************************************************/

/* *********************************************************************
 * Academic honesty certification:                                     *
 *   Written/online sources used:                                      *
 *     CSC161 Reading: Character-by-Character Input                    *
 *       http://www.cs.grinnell.edu/~walker/courses/161.fa16/show-resou*
 *       rce.php?resourceID=545                                        *
 *     By Henry M. Walker. Accessed on 12/06/16.                       *
 *     TutorialsPoint: ungetc() function in C Library                  *
 *       https://www.tutorialspoint.com/c_standard_library/c_function_u*
 *       ngetc.htm                                                     *
 *       Accesed for help on writing the fpeek function.               *
 *   Help obtained                                                     *
 *     NONE                                                            *
 *   My/our signature(s) below confirms that the above list of sources *
 *   is complete AND that I/we have not talked to anyone else          *
 *   (e.g., CSC 161 students) about the solution to this problem       *
 *                                                                     *
 *   Signature: Mike Zou                                               *
 ***********************************************************************/

/* This program takes the name of a file as a command-line argument, opens 
the file, reads through it to determine the number of words in each sentence, 
displays the total number of words and sentences, and computes the average 
number of words per sentence. */

#include <stdio.h>
#include "ctype.h"

//function prototype of a peeking procedure
int fpeek(FILE *stream);

int main (int argc, char *argv[])
{
  //check if correct number of arguments are entered
  if (argc != 2) {
    printf ("Wrong number of arguments entered.\n");
    return 0;
  }

  //open the file as input on command line
  FILE * infile = fopen (argv[1], "r");
  
  //declare variables for storing char, counting words & sentences
  char ch;
  int word = 0;
  int wordSum = 0;
  int sentence = 0;

  printf ("This program counts words and sentences in file ");
  printf ("\"%s\"\n\n", argv[1]);

  //skip over all the initial white spaces before reading
  while (isspace (fpeek(infile)))
    ch = fgetc(infile);

  //loop through text stream till end of file
  while ((ch = fgetc(infile)) != EOF) {
    
    if (isspace(ch)) {
      //if current char is space and the next one is not, we add
      //one to our word count
      if (isalpha(fpeek(infile)))
        word++;

      //if the next char is not letter, then we move on in the loop
      //in other words, digits and punctuations are considered as
      //white space as well.
      else;
    }

    //if an uppercase LETTER or NUMBER precedes '.', then the program skips
    //over and it's not considered a word
    else if (((isupper(ch)) || (isdigit(ch))) && fpeek(infile) == '.')  
      ch = fgetc(infile);
      
    else if ((ch == '!') || (ch == '.') || (ch == '?')) {

      //make sure it's a white space after the punctuation
      //then we can safely call it a sentence. 
      if (isspace (ch = fpeek(infile))) {
        
        sentence++;

        //account for the first word of sentence
        word++;

        //increment the sumWord by word count
        wordSum += word;

        //prints out sentence and word counts
        printf ("Sentence: %3d    Words: %4d\n", sentence, word);

        //skip over the white spaces after end of the previous sentence
        while (isspace (fpeek(infile)))
          ch = fgetc(infile);

        //reset the word count
        word = 0;      
      }
      
      //in case there're multiple '!', '?' punctuations marks in a row
      //we move on to the next char (yes, people do that!!)
      else ;
    }

    //for every other case, we simply move on to the next char in the stream
    else;
  }

  double average = (double) wordSum / sentence;
  
  printf ("\nFile ");
  printf ("\"%s\" ", argv[1]);
  printf ("contains %d words in %d sentences for an average ", wordSum, sentence);
  printf ("of %.1lf words per sentence.\n", average);

  //after the program completes, we can safely close the file.
  fclose (infile);

  return 0;
}

//helper function to peek at next char before putting it back
int fpeek(FILE *stream)
{
  int c;
  c = fgetc(stream);
  ungetc(c, stream);
  return c;
}


/****************************************************************************
 ******************************** Testing ***********************************

Miscellaneous test: to test if various criteria are met.

File content as shown below:
Hello, I'm Mike Z. ou. How are you? Haha!!!! This is the file 123 ...

After running the program, we get this result:

zoutianh@halmos:sup-prob$ sup12 haha.txt
This program counts words and sentences in file "haha.txt"

Sentence:   1    Words:    5
Sentence:   2    Words:    3
Sentence:   3    Words:    1
Sentence:   4    Words:    4

File "haha.txt" contains 13 words in 4 sentences for an average of 3.2 words 
per sentence.

Which is as we expected. Notice that period after uppercase letter Z is 
ignored, and the single quote ' is ignored as well. Also, 123 as a number 
is not counted as a word at all. Lastly, the many exclamation marks ! are
not overcounted and considered the end of just one sentence.

More tests: When there's no sentence in the file at all.

Input file as shown below (Example taken from the problem):

After they walked, talked, and ate, the first person said, "I'd like
to swim: crawl, sidestroke, and butterfly."

Actual outcome:

This program counts words and sentences in file "haha.txt"


File "haha.txt" contains 0 words in 0 sentences for an average of -nan words 
per sentence.

Which is also expected as there's no standalone sentence terminating 
punctuation marks in this sentence. So there's 0 sentence ovreall, and
the program naturally does not count how many words there are since it
woudn't make sense to have words in 0 sentence.


More interesting test: Multiple white spaces and newlines!

File input as shown below:

    White space ( spaces, tabs, line feeds, and return characters) are 

considered          as equivalent. Multiple white space characters are 
 considered       the same as one space character. 

Thus, the     above passage would      equivalent to     the following!

Actual program outcome:

This program counts words and sentences in file "haha.txt"

Sentence:   1    Words:   13
Sentence:   2    Words:   12
Sentence:   3    Words:    9

File "haha.txt" contains 34 words in 3 sentences for an average of 11.3 words 
per sentence.

This is again as expected, despite the white spaces at the beginning of the
file and other multiples of white spaces appearing in the text. I even put 
in many extra newlines to test if the counting runs correctly.


*****************************************************************************
**************************** Statement of Correctness ***********************
*****************************************************************************

After laborious work, this program is finally developed such that all the 
requirements mentioned in the problem are met. I ran this program multiple
times by testing it on different files and it succeeded in counting the 
words, sentences and calculating the sum, average correctly.

Firstly, the program skips over all the white spaces at the beginning of 
the file, until it reaches the first non-space character. Then the program
enters a while loop to iterate till the end of the file. There are various
conditions to be met in the loop, which will be explained later on. 

The program counts the number of words by recognizing that word is defined 
as any contiguous sequence of letters. So once the program encounters a 
letter after either a white-space, a digit or a punctuation mark (except
for '.', '?', '!'), the word count increments by one. Though realize that
the first word of each sentence is always skipped because of the initial 
skipping through the white spaces. Therefore we increment the word count by
one as soon as a terminating punctuation mark is encounterd. 

The first caveat is that periods after capital letters or digits do not 
count as a sentence terminator. As such, I put an if condition in the 
loop to test if a period follows the capital letter or digit. If so, then
the '.' is skipped over. 

The second caveat is that digits and punctuations (except for apostrophy,
periods, exclamation point and question marks) are considered the same
as white spaces. This is achieved by the first condition in the loop:
if the char following the white space is not a letter, then the program
simply moves on to read the next char.

The third and last caveat is that multiple spaces, tabs, line feeds and 
newlines are considered the same as one space char. In order to do this,
I used a while loop to skip over all the consecutive white space chars.
Only the very last white space will be considered in the loop at all.

It's relatively easy to count the number of sentences. I wrote an if 
condition to check if '.', '!' or '?' is encountered. Moreover, to make
sure multiple such chars are in a row, I used a while loop to skip to 
the very last such char. Then the sentence counter would increment if 
the char after is a white space.

Overall, the program runs and gives the correct output during all tests
of a wide array of cases. Therefore, this program must be correct as it
fulfills all the requirements mentioned in the problem. 

*****************************************************************************
********************************** The End **********************************
****************************************************************************/
