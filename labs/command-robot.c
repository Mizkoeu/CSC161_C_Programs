#include "MyroC.h"
#include <stdlib.h>

/*
 * Controlling the Scribbler 2 through command line input
 * 
 * This program takes in commands for the myro robot and sequentially
 * executes the commands.  Supported commands in this example are
 * (character)(double), e.g. l3 b0.5 s.2 r1, b.7, where the character indicates
 * the command.
 *
 * The following commands should be supported:
 * 'l' = turn left
 * 'r' = turn right 
 * 'f' = move forward
 * 'b' = move backward 
 * 's' = change speed
 *
 * The value after the command represents either 
 * the time it will be moving (for commands 'l', 'r', 'f', and 'b') or
 * the speed it will be changing to (for command 's').
 * Speed should be between -1 and 1.
 *
 * Authors: Erik Opavsky & April O'Neill
 *
 * Date: 7/7/11
 * Revised: 8/10/11
 * Revised: 5/2/12 by Henry M. Walker
 */

int
main (int argc, char *argv[])
{
  rConnect("/dev/rfcomm0");

  double speed = 1; // default speed
  int i;
  char command;   // string to identify the command
  double value;     // value to hold the command's parameter

  for ( ??? )
    {
      command = ???;
      value = ???;

      switch (???)
        {
        case 's': // change speed
          speed = *(argv[1] + 1);
          break;
        case 'l': // turn left
          ???;
          break;
        case 'r': // turn right
          ???;
          break;
        case 'f': // move forward
          ???;
          break;
        case 'b': // move backward
          ???;
          break;
        default:
          break;
        } // switch
    } // for

  rBeep (1, 500); // beep to indicate robot has completed all commands

  rDisconnect();

  return 0;
} // main
