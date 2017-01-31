#include <stdio.h>
#include "MyroC.h"

int
main()
{
  rConnect("/dev/rfcomm0");


  Picture pics[6];
  int i; 
  double duration = 10.0;
  for (i = 0; i < 6; i++)
    {
      pics[i] = rTakePicture();
      rTurnRight (.5, .5);
    }
  for (i = 5; i >= 0; i--)
    {
      rDisplayPicture (&pics[i], duration, "Picture!!!"); 
    }
  printf ("Relax, and enjoy the photos!\n");

  rDisconnect();
  return 0;
}
