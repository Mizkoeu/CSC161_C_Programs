
    /***********************************************************************
     * Name(s): Mujtaba Aslam, Mike Zou                                    *
     * Box(s): 3093, 4642                                                  *
     * Assignment name: Module 011: Robot Command Project                  *
     *      (25% off if name/number does not match assignment)             *
     * Assignment for 10/28/16                                             *
     ***********************************************************************/

    /* *********************************************************************
     * Academic honesty certification:                                     *
     *   Written/online sources used:                                      *
     *     CSC161 Reading: Character-by-Character Input                    *
     *       http://www.cs.grinnell.edu/~walker/courses/161.fa16/show-resou*
     *       rce.php?resourceID=545                                        *
     *     CSC161 Reading: Strings in c                                    *
     *       http://www.cs.grinnell.edu/~walker/courses/161.fa16/show-resou*
     *       rce.php?resourceID=522                                        *
     *       We used this reading for the use of strcmp function           *
     *     By Henry M. Walker. Accessed on 10/26/16.                       *
     *   Help obtained                                                     *
     *     NONE                                                            *
     *   My/our signature(s) below confirms that the above list of sources *
     *   is complete AND that I/we have not talked to anyone else          *
     *   (e.g., CSC 161 students) about the solution to this problem       *
     *                                                                     *
     *   Signature: Mujtaba Aslam, Mike Zou                                *
     ***********************************************************************/
/* This program allows users to input commands and make the robot perform corresponding
actions. The users can enter parameters to control the actions. The program also prints 
out the total number of actions taken in one run ("quit" is not counted as an action). */

#include <stdio.h>
#include "MyroC.h" //include headerfile for robot connection.
#include <string.h> //include headerfile for string operations.

/* Declare function prototypes for robot routines*/
void dance (int x);
void backnforth (double x);
void wiggle (double x);
void playsong (int x, int y);
void forwardLeftBeep ();
void jumpback();

int main()
{
  char option[30]; //declare a string for storing user input
  
  /* Declare variables passed into robot action functions as parameters */
  double speed, duration;
  int freq, freq2, repeat;
  
  int counter = 0; //variable to count total number of robot actions.
  
  rConnect ("/dev/rfcomm0");

  /* set up a while loop that repeats until "quit" is scanned */
  while (1)
    { /* Printing all available robot actions*/
      printf ("Menu Options\n");
      printf ("  forward - Moves the robot forward\n");
      printf ("  backward - Moves the robot backward\n");
      printf ("  left - Turns left\n");
      printf ("  right - Turns right\n");
      printf ("  beep - Makes the robot beep\n");
      printf ("  dance - Makes the robot dance for specified number of times\n");
      printf ("  backnforth - Moves backward & forward 6 times for a specified speed\n");
      printf ("  wiggle - Turns the robot left and right 7 times for a given duration \n");
      printf ("  playsong - Plays a tune incrementing from a given starting to an ending pitch\n");
      printf ("  forwardLeftBeep - Moves the robot forward and then turn left while beeping\n");
      printf ("  jumpback - Makes the robot move backwards 6 times in a breaking motion\n");
      printf ("  quit - Quit\n");
      printf ("Enter option:  ");
      /* Scan user input and store in option string*/
      scanf("%s", option);

      /* Compare strings and carry out corresponding actions*/
      if (strcmp (option, "forward") == 0)
        { printf ("Enter speed and duration:");
          scanf ("%lf %lf", &speed, &duration);
          rForward (speed, duration); 
        }
      else if (strcmp (option, "backward") == 0)
        { printf ("Enter speed and duration:");
          scanf ("%lf %lf", &speed, &duration);
          rBackward (speed, duration); 
        }
      else if (strcmp (option, "left") == 0)
        { printf ("Enter speed and duration:");
          scanf ("%lf %lf", &speed, &duration);
          rTurnLeft (speed, duration); 
        }
      else if (strcmp (option, "right") == 0)
        { printf ("Enter speed and duration:");
          scanf ("%lf %lf", &speed, &duration);
          rTurnRight (speed, duration); 
        }
      else if (strcmp (option, "beep") == 0)
        { printf ("Enter duration and frequency:");
          scanf ("%lf %d", &duration, &freq);
          rBeep (duration, freq); 
        }
      else if (strcmp (option, "dance") == 0)
        { printf ("Enter number of repetitions:");
          scanf ("%d", &repeat);
          dance (repeat); 
        }
      else if (strcmp (option, "backnforth") == 0)
        { printf ("Enter the speed of forward/backward movement:");
          scanf ("%lf", &speed);
          backnforth (speed); 
        }
      else if (strcmp (option, "wiggle") == 0)
        { printf ("Enter the duration of each turn:");
          scanf ("%lf", &duration);
          wiggle (duration); 
        }
      else if (strcmp (option, "playsong") == 0)
        { printf ("Enter the starting and ending pitches:");
          scanf ("%d %d", &freq, &freq2);
          playsong (freq, freq2); 
        }
      else if (strcmp (option, "forwardLeftBeep") == 0)
        {  forwardLeftBeep (); 
        }
      else if (strcmp (option, "jumpback") == 0)
        {  jumpback (); 
        }
      else if (strcmp (option, "quit") == 0)
        { printf ("The number of actions taken by the robot: %d\n", counter);
          printf ("Program terminated\n");
          rDisconnect ();
          return 0;
        }
      else continue; // Skip to beginning of the loop if other inputs are scanned.

      counter++; // Counter increments by one to keep track of number of actions so far.
    }
}


/* Dance routine repeated x times*/
void dance (int x)
{ int i;
  for (i = 0; i < x; i++)
    { rForward (1.0, 0.5);
      rTurnLeft (0.5, 0.8);
      rTurnRight (0.6, 0.7);
      rBackward (0.8, -1.5); //Non-blocking action.
      rBeep (1.5, 740);
    }
}

/* Robot moves back and forth with specified speed*/
void backnforth (double x)
{ int i;
  for (i = 0; i < 6; i++)
    { rForward (x, 0.2);
      rBackward (x, 0.2);
    }
}

/* Robot wiggles 7 times with spcified duration of each turn*/
void wiggle (double x)
{ int i = 0;
  while (i <= 6)
    { rTurnLeft (0.8, x);
      rTurnRight (0.8, x);
      i++;
    }
}

/* Robot plays tune from a starting pitch to an ending pitch*/
void playsong (int x, int y)
{ int i = x;
  while (i <= y)
    { rBeep (1.0, i);
      i += (y - x) / 10;
    }
}

/* Robot moves forward and then turns left while beeping*/
void forwardLeftBeep ()
{
  rForward (2, 1.5);
  rTurnLeft (0.8, -1.5); // Non-blocking action.
  rBeep (0.5, 660);
  rBeep (0.5, 770);
  rBeep (0.5, 900);
}

/* Robot steps back in a breaking motion*/
void jumpback()
{ 
  int i;
  for (i = 0; i < 6; i++)
    { rForward (1.0, -0.2);
      rBackward (1.0, 0.2);
    }
}
