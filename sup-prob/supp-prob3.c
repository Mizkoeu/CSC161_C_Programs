
    /***********************************************************************
     * Name: Mike Zou                                                      *
     * Box(s): 4642                                                        *
     * Assignment: Supplemental Problem 3: Grading Password                *
     *      (25% off if name/number does not match assignment)             *
     * Assignment for <11/01/16>                                           *
     ***********************************************************************/

    /* *********************************************************************
     * Academic honesty certification:                                     *
     *   Written/online sources used:                                      *
     *     CSC161 Reading: Strings in C                                    *
     *      http://www.cs.grinnell.edu/~walker/courses/161.fa16/show-resour*
     *      ce.php?resourceID=522                                          *
     *      By H. M. Walker. Accessed on 10/31/16.                         *
     *     CSC161 Reading: Characters in C                                 *
     *      http://www.cs.grinnell.edu/~walker/courses/161.fa16/show-resour*
     *      ce.php?resourceID=521                                          * 
     *      By H. M. Walker. Accessed on 10/30/16.                         *
     *   Help obtained                                                     *
     *      NONE                                                           *
     *   My/our signature(s) below confirms that the above list of sources *
     *   is complete AND that I/we have not talked to anyone else          *
     *   (e.g., CSC 161 students) about the solution to this problem       *
     *                                                                     *
     *   Signature: Mike Zou                                               *
     ***********************************************************************/

/* This is a program designed to assign letter grades to user-input passwords 
   based on specific criteria such as length and presence of certain character 
   types. */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

//declare function prototypes.
char gradePassword (char * password);

int main()
{
  int score = 0; //declare and initialize score.
  char password[60]; //declare a char array of size 60.
  char * pwd = password; //declare pointer that points to password array.
    
  /* Prompt user for character inputs and scan into string. */
  printf("Please enter your password: ");
  scanf("%s", pwd);
    
  /* Print final score. */
  printf("Your password received a letter grade of %c!\n", gradePassword (pwd));
 
  return 0; 
}

char gradePassword (char * password)
{
  //declare variables.
  int score = 0;
  int i; 
  char grade;
  int len = strlen (password);
    
  //check presence of vowel.
  for (i = 0; i < len; i++)
    {   
      if (!isalpha (password[i]))
        continue;
      char c = (tolower (password[i]));
      if ((c == 'a') || (c == 'e') || (c == 'i') || (c == 'o') || (c == 'u'))
        {score++;
          break;
        }
    }
    
  //check presence of consonant.
  for (i = 0; i < len; i++)
    {   
      if (!isalpha (password[i]))
        continue;
      char c = (tolower (password[i]));
      if ((c != 'a') && (c != 'e') && (c != 'i') && (c != 'o') && (c != 'u'))
        {score++;
          break;
        }
    }
    
  //check presence of lower-case letter.
  for (i = 0; i < len; i++)
    {   if (islower (password[i]))
        {score++;
          break;
        }
    }
    
  //check presence of upper-case letter.
  for (i = 0; i < len; i++)
    {   if (isupper (password[i]))
        {score++;
          break;
        }
    }
    
  //check presence of number.
  for (i = 0; i < len; i++)
    {   if (isdigit (password[i]))
        {score++;
          break;
        }
    }
    
  //check presence of punctuation.
  for (i = 0; i < len; i++)
    {   if (ispunct (password[i]))
        {score++;
          break;
        }
    }
    
  //print current score for testing purpose.
  printf ("currently score is %d\n", score);
    
        
  //alter score based on length of password;
  if (len < 6)
    score -= 2;
  else if ((6 <= len) && (len < 9));
  else if ((9 <= len) && (len <= 11))
    score += 1;
  else if ((12 <= len) && (len <= 15))
    score += 2;
  else 
    score += 4;
    
  //print score for testing purpose.    
  printf ("currently score is %d\n", score);
    
  //calculate grade based on score.
  if (score < 0)
    grade = 'U'; //grade is Undefined when score is negative.
  else if (score < 3)
    grade = 'F';
  else if (score < 5)
    grade = 'D';
  else if (score < 7)
    grade = 'C';  
  else if (score < 9)
    grade = 'B';
  else
    grade = 'A';
    
  return grade;
}

/************************* Testing **********************************
 ********************************************************************
Expected Circumstances:
    Firstly, the password can have varying lengths, which we can check
    against the grade rule. Secondly, we can have passwords with only
    numbers, letters or punctuation marks, or a combination of them.
    We can test these cases easily, as shown below.

Test Category: Checking Length
(We test the correctness with digit-only passwords of varying length)

    Case 1: Length is less than 6 characters:
    Expected return grade: U (score of 1 - 2 = -1) --> "undefined" grade
    Actual test run:
    Please enter your password: 12345
    currently score is 1
    currently score is -1
    Your password received a letter grade of U!
    
    Case 2: Length is between 6 and 8 (inclusive):
    Expected return grade: F (score of 1 + 0 = 1)
    Actual test run:
    Please enter your password: 12345678
    currently score is 1
    currently score is 1
    Your password received a letter grade of F!
    
    Case 3: Length is between 9 and 11 (inclusive):
    Expected return grade: F (score of 1 + 1 = 2)
    Actual test run:
    Please enter your password: 1234567890
    currently score is 1
    currently score is 2
    Your password received a letter grade of F!
    
    Case 4: Length is between 12 and 15 (inclusive):
    Expected return grade: D (score of 1 + 2 = 3)
    Actual test run:   
    Please enter your password: 123456789012
    currently score is 1
    currently score is 3
    Your password received a letter grade of D!
    
    Case 5: Length is greater than 15 characters:
    Expected return grade: C (score of 1 + 4 = 5)
    Actual test run:    
    Please enter your password: 12345678901234567
    currently score is 1
    currently score is 5
    Your password received a letter grade of C!

Test Category: Checking presence of char types
(Here we keep all test passwords at same length of 11 char)

    Case 1: Presence of at least one lower-case letter
    Please enter your password: ttttttttttt 
    Expected grade: D (score of (1+1)+1=3)
    Actual test run:
    currently score is 2
    currently score is 3
    Your password received a letter grade of D!
    
    Case 2: Presence of at least one upper-case letter
    Please enter your password: WRHTBGCZDQP
    Expected grade: D (score of (1+1)+1=3)
    Actual test run:
    currently score is 2
    currently score is 3
    Your password received a letter grade of D!
    
    Case 3: Presence of at least one vowel
    Please enter your password: aaaaaeeeiio
    Expected grade: D (score of (1+1)+1=3)
    Actual test run:
    currently score is 2
    currently score is 3
    Your password received a letter grade of D!

    Case 4: Presence of at least one consonant
    Please enter your password: trhywqcbnmk
    Expected grade: D (score of (1+1)+1=3)
    Actual test run:
    currently score is 2
    currently score is 3
    Your password received a letter grade of D!

    Case 5: Presence of at least one punctuation mark
    Please enter your password: 1357913!579
    Expected grade: D (score of (1+1)+1=3)
    Actual test run:
    currently score is 2
    currently score is 3
    Your password received a letter grade of D!
    
    Case 4: Combination of digit, letter, vowel, consonant:
    Please enter your password: 235711prime
    Expected grade: C (score of (1+1+1+1)+1=5)
    Actual test run:
    currently score is 4
    currently score is 5
    Your password received a letter grade of C!
    
Test Category: Special cases
(To be rigorous about the test, we try inputs with white spaces)
    
    Case 1: User inputs white-spaces before typing actual password
    Please enter your password:      12345hqwurt
    Expected grade: C (score of (1+1+1+1)+1=5)
    Actual test run    
    currently score is 4
    currently score is 5
    Your password received a letter grade of C!
    (The starting whitespaces are skipped over when reading)
    
    Case 2: User enters white-spaces after the password
    Please enter your password: 123456qwert (5 white-spaces)
    Expected grade: C (score of (1+1+1+1)+1=5)
    Actual test run  
    currently score is 4
    currently score is 5
    Your password received a letter grade of C!
    (A word of caution, the program does not count white-spaces
     as inputs under any circumstances!)
    
    
*************************** Statement of Correctness *******************
To test this program, I first made sure that all the warnings and errors 
are taken care of while compiling. Then I ran the program multiple times
with different combinations of character types, as shown above in the 
testing section. For each password combination, I checked the rules laid
out in the supplemental problem, and predicted what the final score and 
corresponding grade would be, before comparing with the actual test result.
Moreover, I put in test printf() statements to track the value of score
variable in the gradePassword() function every step of the way. The results
returned from the program agrees completely with the expected values.

In addition, I tested some special cases such as input of white-spaces,
tabs, before and after the actual password. It turned out that these inputs
were not read into the string (thereofore not evaluated in the program), 
as expected. 

On a side note, while this program achieves clarity in terms of the codes,
it's certainly not the most efficient as the algorithm simply goes through
the string multiple times, breaking out of the loop whenever it encounters
a particular char type. An alternative algorithm would be to count the 
number of each char type and increment score if the number is positive. 
This alternative algorithm might be faster to run. However, the password
input is limited to 60 characters (which is reasonably large), so the 
algorithm efficiency is not severely undermining the usefulness of the 
program. 

 ***********************************************************************/
