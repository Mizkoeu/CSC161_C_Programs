#include<stdio.h>
#include "MyroC.h"


/* Extra credit Lab: Exercise on Loops
Lab Partners: Mike, Eliza.

Question 1: The purpose of the printf("\n") is to print a new line after the 
loop  above is completed. This statement is not in the loop because it is not
included in the curly braces immediately after the for statement.

Question 2: There's no output printed for the for and while loop, but 11 was
printed in the do ... while loop. This is because both the for and while loop
execute following commands only if start <= end (but 11 > 10, so nothing is 
carried out), whereas for do .. while statement, the program runs the first 
segment of the code (block of code after "do") before doing such Boolean 
evaluations. Therefore the do ... while outputs the start integer 11.

Question 3: See the code below. */

int main()
{
  /*
//Declaring variables
  int quarts = 1;
  double liters;
  printf ("Table of quart and liter equivalent\n");
  printf("Quarts        Liters\n");

Question 3:
// (a) First version: implement the loop using for construct.

  for (quarts = 1; quarts <= 12; quarts++)
    {
      liters = quarts * .9463;
      printf("%4d%16.4lf\n", quarts, liters);
    }
  printf("\n"); 

//(b) Second version: implement the loop using while construct.
  
  while (quarts <= 12)  
    {liters = quarts * .9463;
      printf("%4d%16.4lf\n", quarts, liters);
      quarts++;
    } */


//Question 4:


  int i = 1;
  rConnect ("/dev/rfcomm0");
/* (a) for loop that moves Scribbler forward 5 times. 
  for (i = 1; i <= 5; i++)
    {
      rForward (.5, 1);
      rForward (0, 0.5); //short pause to see effect more clearly.
    }
*/
/* (b) while loop that moves Scribbler in some direction for increasing 
   amount of time 
  while (i <= 5)
    {
      rForward (.5, i/2.0);
      rForward (0, 0.5); //short pause to see effect more clearly.
      i++;
      } */
/* (c) for loop that moves Scribbler at changing times.
  for (i = 1; i <= 5; i++)
    {
      rForward (i/6.0, 1);
      rForward (0, 0.5); //short pause to see effect more clearly.
      } */
/* (d) while loop that change both speed than time in the same loop.*/
  for (i = 1; i <= 5; i++)
    {
      rForward (i/6.0, 3.0/i);
      rForward (0, 0.5); //short pause to see effect more clearly.
      }

  rDisconnect ();

} 
