
    /***********************************************************************
     * Name: Mike Zou                                                      *
     * Box(s): 4642                                                        *
     * Assignment: Supplemental Problem 1: Computer a Babysitter's fee     *
     *      (25% off if name/number does not match assignment)             *
     * Assignment for <09/16/16>                                           *
     ***********************************************************************/

    /* *********************************************************************
     * Academic honesty certification:                                     *
     *   Written/online sources used:                                      *
     *     [CSC161 Reading: Boolean values and expressions                 *
     *      http://www.cs.grinnell.edu/~walker/courses/161.fa16/show-      *
     *      resource.php?resourceID=237                                    *
     *      By H. M. Walker. Accessed on 09/14/16.                         *
     *      CSC161 Reading: An introduction to Conditional statements in C *
     *      http://www.cs.grinnell.edu/~walker/courses/161.fa16/show-      *
     *      resource.php?resourceID=236                                    *
     *      By H. M. Walker. Accessed on 09/14/16.                         *
     *   Help obtained                                                     *
     *     [Verified with Prof. Walker the case of input hours 12 and 0,   *
     *      both of which indicate midnight.]                              *
     *     ["none" required for Supplemental Problems                      *
     *   My/our signature(s) below confirms that the above list of sources *
     *   is complete AND that I/we have not talked to anyone else          *
     *   (e.g., CSC 161 students) about the solution to this problem       *
     *                                                                     *
     *   Signature:                                                        *
     *                                                                     *
     ***********************************************************************/

#include<stdio.h>

int main()
{
//Initializing the variables that we will be using.
    int begin_hour;
    int begin_min;
    int end_hour;
    int end_min;
    double fee;

//Some introductory comments to inform user of the intent of the program.
    printf("This is a program that calculates the fee for babysitting in the time range of 6 pm to 6 am. \n");
    printf("Please provide relevant information below!:) \n");
 
/*First, we take 4 integer inputs from user, and prompt error message when invalid input is entered.
 Note: This part contains loop statements, but loop concept is not used in the main execution of
 the program.*/
    do {
    printf("Please enter the beginning hour (between 0 and 12 inclusive): ");
    scanf("%d", &begin_hour);
    if ((begin_hour < 0) || (begin_hour > 12))
    {
        printf("The beginning hour must be between 0 and 12 inclusive, as mentioned above!\n");
    }
    } while ((begin_hour < 0) || (begin_hour > 12));
    
    do {
    printf("Please enter the beginning minutes (between 0 and 59 inclusive): ");
    scanf("%d", &begin_min);
    if ((begin_min < 0) || (begin_min > 59))
    {
        printf("The beginning minutes must be between 0 and 59 inclusive, as mentioned above!\n");
    }
    } while ((begin_min < 0) || (begin_min > 59));
    
    
    do {
    printf("Please enter the ending hour (between 0 and 12 inclusive): ");
    scanf("%d", &end_hour);
    if ((end_hour < 0) || (end_hour > 12))
    {
        printf("The ending hour must be between 0 and 12 inclusive, as mentioned above!\n");
    }
    } while ((end_hour < 0) || (end_hour > 12));
    
    do {
    printf("Please enter the ending minutes (between 0 and 59 inclusive): ");
    scanf("%d", &end_min);
    if ((end_min < 0) || (end_min > 59))
    {
        printf("The ending minutes must be between 0 and 59 inclusive, as mentioned above!\n");
    }
    } while ((end_min < 0) || (end_min > 59));
    
//Then, we start the program proper by setting up layered conditional statements:
    if ((begin_hour < 6) || (begin_hour == 12)){
         fee = 2.25 * ((end_hour % 12) - (begin_hour % 12) + (end_min - begin_min)/60.0);
        }
    else if (begin_hour < 9) { 
        if ((end_hour < 6) || (end_hour == 12) || ((end_hour == 6) && (end_min == 0)))
         {
         fee = 2.75 * (9 - begin_hour - begin_min/60.0) + 1.75 * 3 + 2.25 * (end_hour % 12 + end_min/60.0);
            }
        else if (end_hour < 9) {
         fee = 2.75 * (end_hour - begin_hour + (end_min - begin_min)/60.0);
            }
        else {
         fee = 2.75 * (9 - begin_hour - begin_min/60.0) + 1.75 * (end_min/60.0 + end_hour - 9);
        }}
    else {
        if ((end_hour <= 6) || (end_hour == 12)) {
         fee = 1.75 * (12 - begin_hour - begin_min/60.0) + 2.25 * (end_hour % 12 + end_min/60.0);
        }
        else if (end_hour >= 9) {
         fee = 1.75 * (end_hour - begin_hour + (end_min - begin_min)/60.0);
        }}
        
//Lastly, we output/print the sitter's fee.
    printf("In this case, the sitter get paid $%.2lf. Hooray!\n", fee);
//if all is well, the program returns 0.
    return 0;
}

/*************************************************************************************
 * Statement of Correctness
 * a) Provide a numbered listing of the circumstances that can reasonably 
   arise in this problem:
     
   1. Begin and end in early evening;
   2. Begin and end in late evening;
   3. Begin and end in early morning;
   4. Begin in early evening and end in late evening (covering 2 periods);
   5. Begin in late evening and end in early morning (covering 2 periods);
   6. Begin in early evening and end in early morning (covering all 3 periods);
   7. Case 3,5,6 should be experimented with begin_hour/end_hour = 12 or 0 to 
      make sure interpretation of these 2 values is exactly the same!


 * b) Listing of test cases to be considered, with the expected outcome 
   CASES      INPUTS       EXPECTED OUTCOME
   Case 1: (6, 30, 8, 45)  $6.19
   Case 2: (9, 30, 12, 0)  $4.38
   Case 3: (0, 30, 3, 0)   $5.62
   sub-case:(12, 30 3, 0)  $5.62
   Case 4: (7, 30, 11, 30) $8.50 
   Case 5: (10, 0, 0, 30)  $4.62
   sub-case:(10, 0, 12, 30) $4.62
   Case 6: (6, 0, 12, 30)  $14.62
   sub-case:(6, 0, 0, 30)  $14.62
   (sub-cases serve the purpose to test if 12 and 0 both mean midnight 
    in the program.)

 * c) Listing of actual test runs 
   CASES      INPUTS       ACTUAL TEST VALUES
   Case 1: (6, 30, 8, 45)  $6.19
   Case 2: (9, 30, 12, 0)  $4.38
   Case 3: (0, 30, 3, 0)   $5.62
   sub-case:(12, 30 3, 0)  $5.62
   Case 4: (7, 30, 11, 30) $8.50 
   Case 5: (10, 0, 0, 30)  $4.62
   sub-case:(10, 0, 12, 30) $4.62
   Case 6: (6, 0, 12, 30)  $14.62
   sub-case:(6, 0, 0, 30)  $14.62

 * d) Statement of why the program is correct

      This program calculates the sitter's fee by dividing the beginning time
   and ending time into specific cases and was implemented by using layered
   conditional statements.The arithmetics behind the program is simple and I 
   have double checked its correctness by running large number of tests,some
   of which are listed above as test examples.

      After considering all posible scenarios in this problem, I have tested the 
   program output against the expected outcomes in the various cases and found 
   the program to work as expected. Important cases such as time-periods with 1,2 
   or 3 different rates are considered in the test-suite. More importantly, I have
   also tested the early morning cases by assigning either 12 or 0 to indicate
   midnight and got the same results. It turns out that the interpretation of both
   12 and 0 as midnight was successfully implemented. Furthermore, I have tested 
   inputting invalid integers, which indeed resulted in error messages and a prompt
   for re-entering data. 

      Overall, I conclude that my program works well since it gives the correct 
   results and solves the particular problem of calculating sitter's fee based 
   on time periods worked.


****************************** The End *******************************************/
