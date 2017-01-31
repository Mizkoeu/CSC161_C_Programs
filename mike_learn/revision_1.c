/**************** The revised code for Exam 1 Question 1 ************
********************************************************************/

#include <stdio.h>
#include "MyroC.h"

int main()
{ rConnect ("/dev/rfcomm0"); //Connect to robot via Bluetooth.
  int i; //declare variable for counting repetition of beep/rest.
  for (i = 0; i < 10; i++)
    { int n = 0;
      //while loop to beep a number of times depending on i.
      while (n <= i)
        { rBeep (1.0, 880); //plays a C5 note for 1 sec.
          n++;}
      rBeep (1.0, 0);
    }
  rDisconnect (); //disconnect from robot.
  return 0; //returns 0 if the program terminates properly.
}

/* Proper testing run on Scribbler 2 robots and it did exactly what
   it should according to the requirements. */
