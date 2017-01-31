#include "MyroC.h"


int main()
{
  rConnect("/dev/rfcomm0");
  int i;
  double speed[] = {.1, -.2, .3, -.4, .5, -.6, .7, -.8, .9, 1.0};
  double time[] = {1.0, .9, .8, .7, .6, .5, .4, .3 ,.2 ,.1};
  double turnspeed[] = {.1, .2, .3, -.4, .5, -.6, .7, -.8, .9, -1.0};
  double turntime[] = {.4, .2, .8, .5, .3, .9, 1.2, 2.2, 1.5, .7};
  for (i = 0; i < 10; i++)
    {rForward(speed[i], time[i]);
      rTurnRight(turnspeed[i], turntime[i]);
    }
  rDisconnect();
  return 0;
}
