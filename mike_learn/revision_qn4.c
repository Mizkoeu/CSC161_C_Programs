/**************** The revised code for Exam 1 Question 4 ************
********************************************************************/

#include <stdio.h>
#include "MyroC.h"

int main()
{ rConnect ("/dev/rfcomm0");
  
  /*(a): write a segment of code that determines the average value
    of Scribbler 2's right light sensor over 6 readings. */
  
  int avgLight = rGetIRTxt ("right", 6);
  
  /*(b): use if statements to compute and print categories. */
  if (avgLight <= 9999)
    print ("Very bright!\n");
  else if (avgLight <= 19999)
    print ("Moderately bright..\n");
  else if (avgLight <= 29999)
    print ("Somewhat bright\n");
  else if (avgLight <= 39999)
    print ("Somewhat dim\n");
  else if (avgLight <= 49999)
    print ("dim...\n");
  else
    print ("Very dim!\n");

  /*(c): use switch statement to compute and print categories. */
  switch ((int) (avgLight / 10000))
  //divide avgLight by 10000 and cast the quotient into an integer type.
    {
    case 0:
      print ("Very bright!\n");
      break;
    case 1:
      print ("Moderately bright..\n");
      break;
    case 2:
      print ("Somewhat bright\n");
      break;
    case 3:
      print ("Somewhat dim\n");
      break;
    case 4:
      print ("dim...\n");
      break;
    default:
      print ("Very dim!\n");
      break;
    }
  rDisconnect (); //disconnect from robot.
  return 0; //returns 0 if the program terminates properly.
}

/* Proper testing run on Scribbler 2 robots by exposing the right
   light sensor to varying light intensity and get readings. It did
   exactly what it should according to the requirements. */
