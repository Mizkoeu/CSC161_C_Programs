
/***********************************************************************
 * Name(s): Mike Zou                                                   *
 * Box(s): 4642                                                        *
 * Assignment: Extra-credit Supplemental Problem 6: Unusual Canceling  *
 * Assignment for 12/09/16 (Extra-credit problem)                      *
 ***********************************************************************/

/* *********************************************************************
 * Academic honesty certification:                                     *
 *   Written/online sources used:                                      *
 *     NONE                                                            *
 *   Help obtained                                                     *
 *     NONE                                                            *
 *   My/our signature(s) below confirms that the above list of sources *
 *   is complete AND that I/we have not talked to anyone else          *
 *   (e.g., CSC 161 students) about the solution to this problem       *
 *                                                                     *
 *   Signature: Mike Zou                                               *
 ***********************************************************************/

/*This program find all fractions whose numerators and denominators 
are two-digit numbers and whose values remain unchanged after "canceling." 
 */

#include <stdio.h>

int main()
{
  //declare variables for 4 digits which form the fraction format of "ab/cd".
  int a, b, c, d;

  /* We can then start a nested loop to try different combinations 
     of the 4 digits and determine if they satisfy the "cancelling"
     criterion.
  */

  //tens digit of numerator should start from 1 and reiterate till 9
  for (a = 1; a <= 9; a++)
    
    for (b = 0; b <= 9; b++)

      /* tens digit of denominator should start from 1 and reiterate till 9
      note: if we want to find fractions of values less than 1
            we can loop from c = a to c = 9, so that c is always
            greater than a. As such, the fractions is always less than 1
            But the problem does not ask of this. */
      for (c = 1; c <= 9; c++)
        
        for (d = 0; d <= 9; d++)
          
          {
            //omit the case when numerator and denominator are equal
            if ((a == c) && (b == d))
              break;

            /*when tens-digits are equal, we compare the fraction and the 
              value after "cancelling" */
            if ((a == c) && ((10*a + b)*d == (10*c + d)*b))
              printf ("%d%d/%d%d\n", a, b, c, d);       

            //when tens-digit of numerator and single-digit of denominator
            //are equal
            if ((a == d) && ((10*a + b)*c == (10*c + d)*b)) 
              printf ("%d%d/%d%d\n", a, b, c, d);

            //when tens-digit of denominator and single-digit of numerator
            //are equal
            if ((b == c) && ((10*a + b)*d == (10*c + d)*a))
              printf ("%d%d/%d%d\n", a, b, c, d);
            
            /*when single-digits are equal, we need to make sure numerator
              and denominator are not multiples of 10, then compare the 
              fraction and the value after "cancelling" */
            if ((b == d) && (b != 0) && ((10*a + b)*c == (10*c + d)*a))
              printf ("%d%d/%d%d\n", a, b, c, d);
            
          }

  return 0;
}

/****************************************************************************
 ******************************** Testing ***********************************

zoutianh@pythagoras:sup-prob$ sup6
16/64
19/95
26/65
49/98
64/16
65/26
95/19
98/49

The program works as expected and prints out all 8 luck fractions that
satisfy the criteria specified in the problem.

****************************************************************************
***************************** Explanantion *********************************
****************************************************************************

This program has a simple structure. It loops through all possible values of
a, b, c, d which give all possible fractions with 2 digit numerator and 2 
digit denominator. Then it executes the if conditions for all the cases, to
determine if each particular number is a lucky fraction.

Note that this program follows strictly from the description in the problem,
which means that the fraction does not necessarily need to be less than 1. 
In this case, the prorgam searches through all possible fractions and comes
up with 8 lucky fractions, instead of the mere 4 mentioned in the linked 
article. If the fractions need to be less than 1, we can simply loop digit
c from current value of a to 9 (so that c is always greater than a). However,
this program meets the problem requirement and hence does not need such 
modification.

Lastly, the if conditions in the nested-loop also checks and ignores all the 
trivial conditions such as when the denominator and numerator are the same, 
or when they are both multiples of 10. This is indeed verified from the 
print results we get from running the program. 


****************************************************************************
******************************* THE END ************************************
****************************************************************************/
