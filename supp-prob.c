
    /***********************************************************************
     * Name: Mike Zou                                                      *
     * Box(s): 4642                                                        *
     * Assignment: Supplemental Problem 1: Computer a Babysitter's fee     *
     ***********************************************************************/
     /* Problem: Computing a Babysitter's Fee

A baby sitter charges $2.75 per hour until 9:00 pm (while the kids are still up), 
$1.75 per hour between 9:00 pm and midnight, and $2.25 per hour after midnight 
(since late night baby sitting interferes with morning classes).

Write a program that reads four integer values (the sitter's starting time in hours 
and minutes and the ending time in hours and minutes) and computes the sitter's fee. 
Assume all times are between 6:00 pm and 6:00 am, and hours should be specified as 
being between 0 and 12 (inclusive). Hours outside the range of 0 to 12 should be 
considered invalid.

The hour 6 should be considered as 6:00 pm, when it is entered as a starting time.
The hour 6 should be considered as 6:00 am, when it is entered as an ending time.
The following table may clarify allowed time values for this problem.

Starting	Starting	Ending	Ending	Starting	Ending
Hour	    Minutes	    Hour	Minutes	Time	    time
8	        0	        3	    30	    8:00pm	    3:30am
6	        0       	0   	45  	6:00pm  	12:45am
12      	0	        6   	0	    12:00am    	6:00am

Programming Note: You may NOT use loops or recursion in this program. */

    /* *********************************************************************
     * Academic honesty certification:                                     *
     *   Written/online sources used:                                      *
     *     [CSC161 Reading: Boolean values and expressions                 *
     *      http://www.cs.grinnell.edu/~walker/courses/161.fa16/show-      *
     *      resource.php?resourceID=237
     *      By H. M. Walker. Accessed on 09/14/16.
     *      CSC161 Reading: An introduction to Conditional statements in C *
     *      http://www.cs.grinnell.edu/~walker/courses/161.fa16/show-      *
     *      resource.php?resourceID=236
     *      By H. M. Walker. Accessed on 09/14/16.
     *   Help obtained                                                     *
     *     [Verified with Prof. Walker the case of input hours 12 and 0,   *
     *      both of which indicate midnight.]                              *
     *     ["none" required for Supplemental Problems                      *
     *   My/our signature(s) below confirms that the above list of sources *
     *   is complete AND that I/we have not talked to anyone else          *
     *   (e.g., CSC 161 students) about the solution to this problem       *
     *                                                                     *
     *   Signature:                                                        *
     ***********************************************************************/ss

#include<stdio.h>

int main()
{
//Initializing the variables we will be using.
    int begin_hour;
    int begin_min;
    int end_hour;
    int end_min;
    double fee;

//Some introductory comments to let user know the intent of the program.
    printf("This is a program that calculates the fee for babysitting in the time range of 6 pm to 6 am. \n");
    printf("Please provide relevant information below!:) \n");
 
 //First, we take the 4 integer inputs from user, and prompt error when the user enters invalid inputs.   
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
    
//Then, we start the program proper:
    if (begin_hour >= 9 && begin_hour != 12) {
        if (end_hour >= 9) {
            fee = 1.75 * (end_hour - begin_hour + (end_min - begin_min)/60.0);
        }
        if (end_hour <= 6) {
            fee = 1.75 * 3 + 2.25 * (end_hour % 12 + end_min/60.0);
        }}
        
    else if (begin_hour >= 6) { 
        if ((end_hour < 6) || (end_hour == 12) || ((end_hour == 6) && (end_min == 0))) {
            fee = 2.75 * (9 - begin_hour - begin_min/60.0) + 1.75 * 3 + 2.25 * (end_hour % 12 + end_min/60.0);
            }
        else if (end_hour < 9) {
            fee = 2.75 * (end_hour - begin_hour + (end_min - begin_min)/60.0);
            }
        else {
            fee = 2.75 * (9 - begin_hour - begin_min/60.0) + 1.75 * (end_min/60.0 + end_hour - 9);
        }}
        
    else {
        fee = 2.25 * (end_hour % 12 + end_min/60.0);
        }
        
//Lastly, we output the sitter's fee.
    printf("In this case, the sitter get paid $%.2lf. Hooray!\n", fee);
    return 0;
}
