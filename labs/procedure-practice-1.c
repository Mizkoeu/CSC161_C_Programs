#include "MyroC.h"
#include "eSpeakPackage.h"
#include "scale-notes.h"
#include <stdio.h>
/*  A sequence of beeps, involving at least 6 notes, each of which has a specific frequency and duration. That is, tune_forward will be a sequence of at least rBeep commands. */
void tune_forward ()
{
}

/* The same sequence of rBeep commands used for tune_forward, except in the reverse order.*/

void tune_backward ()
{
}
/*A sequence of Scribbler 2 movements, using a combination of at least 3 rForward and at least 3 rTurnRight commands. */
void move_clockwise ()
{
}
/*
  The same sequence of movement commands used for move_clockwise, except that each rTurnRight command is replaced by the corresponding rTurnLeft command. */
void move_counter_clockwise ()
{
}


/* Print message then play the tune forwards before moving the robot clockwise*/
void tune_forw_move_clock ()
{ printf ("tune forward and move clockwise\n");
  tune_forward ();
  move_clockwise ();
    
}
// Print message then play tune forwards then move counter clockwise
void tune_forw_move_counter ()
{ printf ("tune forwards and move counter-clockwise\n");
  tune_forward ();
  move_counter_clockwise ();
}
/* Print message then play the tune backwards before moving the robot clockwise*/
void tune_back_move_clock ()
{ printf ("tune backwards and move clockwise\n");
  tune_backward ();
  move_clockwise ();
}
// Print message then play tune backwards then move counter clockwise
void tune_back_move_counter ()
{ printf ("tune backwards and move counter-clockwise\n");
  tune_backward ();
  move_counter_clockwise ();
}

int main ()
{
  rConnect ("/dev/rfcomm0");
  eSpeakConnect ();
  tune_forward (); //Plays tune beginning to end
  move_clockwise (); // move robot clockwise
  tune_backward (); // Play tune end to beginning
  move_counter_clockwise (); //move robot counter clockwise
  tune_backward ();
  tune_forward ();
  rDisconnect ();
  eSpeakDisconnect ();

  return 0;
}
