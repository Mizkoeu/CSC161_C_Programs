/* This program illustrates how to 
      connect to the Scribbler robot, 
      beep, and 
      disconnect. 
 */

#include "MyroC.h" // include the library for Scribbler commands

int
main()
{
  rConnect("/dev/rfcomm0"); // connect to Scribbler

  rBeep(1,700); //beep for 1 second at a frequency of 550 Hz.

  rBeep(4, 600);

  rBeep(1, 440);

  rBeep(1, 800);

  rBeep(1, 500);
  
  
  rDisconnect(); // disconnect from Scribbler

  return 0; // return, indicating no errors have occurred
} // main
