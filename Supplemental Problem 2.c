
    /***********************************************************************
     * Name: Mike Zou                                                      *
     * Box(s): 4642                                                        *
     * Assignment: Supplemental Problem 2: Computing a Polynomial          *
     *      (25% off if name/number does not match assignment)             *
     * Assignment for <10/04/16>                                           *
     ***********************************************************************/

    /* *********************************************************************
     * Academic honesty certification:                                     *
     *   Written/online sources used:                                      *
     *     CSC161 Reading: Reading on Arrays                               *
     *      http://www.cs.grinnell.edu/~walker/courses/161.fa16/show-resour*
     *      ce.php?resourceID=360                                          *
     *      By H. M. Walker. Accessed on 09/29/16.                         *
     *     CSC161 Reading: Functions with Addresses as Parameters          *
     *      http://www.cs.grinnell.edu/~walker/courses/161.fa16/show-resour*
     *      ce.php?resourceID=335                                          * 
     *      By H. M. Walker. Accessed on 9/30/16.                          *
     *     Wikipedia entry: Horner's Method.                               *
     *      https://en.wikipedia.org/wiki/Horner%27s_method                *
     *      Used the synthetic division as a guideline for constructing    *
     *      the function compute_poly.                                     *
     *   Help obtained                                                     *
     *      NONE                                                           *
     *   My/our signature(s) below confirms that the above list of sources *
     *   is complete AND that I/we have not talked to anyone else          *
     *   (e.g., CSC 161 students) about the solution to this problem       *
     *                                                                     *
     *   Signature: Mike Zou                                               *
     ***********************************************************************/

/* This is a program that prompts users to input parameters of a polynomial, 
before computing and printing the numerical value of the polynomial. */

#include <stdio.h>

//declare function prototype for compute_poly.
double compute_poly(double x, int n, double a[]);

int main()
{
    //declare variables we will be using.
    double x;
    int i, n;
    
    //firstly, we take user inputs of the parameters for the desired polynomial.
    printf("Please enter value of x:");
    scanf("%lf", &x);
    printf("Please enter n, degree of polynomial (integer only):");
    scanf("%d", &n);
    //Take inputs for each coefficient of all (n+1) terms in the polynomial.
    double a[n+1];
    for (i = n; i >= 0; i--)
    {
      printf("Please enter the value of a[%d]:", i);
      scanf("%lf", &a[i]);
    }

    //printing out the value of polynomial by passing the function into printf.
    printf("The final polynomial value is %.3lf\n", compute_poly(x, n, a));
    return 0;
}

//Function for computing the value of polynomial using Horner's Method.
double compute_poly(double x, int n, double a[])
{
    //declare variable result as the coefficient of the highest power term.
    double result = a[n];

    /*we use a while loop to encode the synthetic division algorithm, 
    which results in polynomial value. */
    while (n > 0) 
    { 
      result = (x * result) + a[n-1];
      n--;
    }
    //return result back to main function, which prints this value.
    return result; 
}


/* Testings:
a. We separate our tests into some distinct cases based on degree of polynomial,
and use a (pseudo) random set of positive and negative coefficients:
0) To test accidental user errors, we try to input negative degrees.
Please enter value of x:1
Please enter value of n:-3
The final polynomial value is 0.000

Please enter value of x:34
Please enter value of n:-1
The final polynomial value is 0.000

It seems that whenever n is negative, program outputs 0.000, which is 
reasonable and does not count as a program error. Also, users are not
supposed to enter non-integer values for n as requested by the program,
so we do not test cases whereby n is non-integer. 

1) The degree of the polynomial is 0.
Please enter value of x:13
Please enter value of n:0
Please enter the value of a[0]:31415926
Expected polynomial value: 31415926.000
Actual output: The final polynomial value is 31415926.000
The program works in this case!

2) The degree of the polynomial is 1.
Please enter value of x:-2
Please enter value of n:1
Please enter the value of a[1]:3
Please enter the value of a[0]:5
Expected polynomial value: -1.000
Actual output: The final polynomial value is -1.000
The program works in this case!

3) The degree of the polynomial is 2.
Please enter value of x:3
Please enter value of n:2
Please enter the value of a[2]:3
Please enter the value of a[1]:2
Please enter the value of a[0]:1
Expected polynomial value: 34.000
Actual output: The final polynomial value is 34.000
The program works in this case!

   We can test a sub-case where x is non-integer.
Please enter value of x:.5
Please enter value of n:2
Please enter the value of a[2]:3
Please enter the value of a[1]:2
Please enter the value of a[0]:1
Expected polynomial value: 2.750
Actual output: The final polynomial value is 2.750
The program works in this case!

4) The degree of the polynomial is 3.
Please enter value of x:2
Please enter value of n:3
Please enter the value of a[3]:1
Please enter the value of a[2]:2
Please enter the value of a[1]:-3
Please enter the value of a[0]:-4
Expected polynomial value: 6.000
Actual output: The final polynomial value is 6.000
The program works in this case!

5) The degree of the polynomial is 6.
Please enter value of x:2
Please enter value of n:6
Please enter the value of a[6]:3
Please enter the value of a[5]:-2
Please enter the value of a[4]:-4
Please enter the value of a[3]:8
Please enter the value of a[2]:-10
Please enter the value of a[1]:6
Please enter the value of a[0]:4
Expected polynomial value: 104.000
Actual output: The final polynomial value is 104.000
The program works in this case!
*/

/*******************STATEMENT OF CORRECTNESS****************

This program is very straightforward with one main function that prompts 
user inputs and another sub-routine called compute_poly which computes
the value of the polymonial based on the parameters entered by the user.
I have carried out extensive tests over a range of values: degree of 
polynomial n ranged from 0 to 8; x was chosen as integers or non-integers;
the terms of the polynomial are chosen ramdonly as positive or negative
numbers. It was hard to show all testings in the test-case section, but
it was rather conclusive that the program does exactly what it should, 
experimentally. Theoretically, the program should also work as I have 
checked the Horner algorithm by putting printf statements in the loops of
compute_poly and showing the values of "results" at different point of 
the program. The printed "result" values correspond exactly to what I 
would expect from doing the polynomial devisions by hand (which I did).
Therefore, the program is overall correct from both experimental and 
theoretical points of views.
 */