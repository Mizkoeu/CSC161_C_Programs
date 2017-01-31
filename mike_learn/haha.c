#include <stdio.h>

int main()
{ int hey;
  printf ("Gimme a number!:");
  scanf ("%d", &hey);
  printf ("%d\n", (int) (hey /10000));
  switch ((int) (hey / 10000))
    { case 0:
        printf("it's bloody 0!\n");
        break;
    case 1:
      printf ("It's one really?\n");
      break;
    case 2:
      printf ("LOL, Okay, it;s 2 I get it\n");
      break;
    default:
      printf ("it must be larger than 20000\n");
      break;
    }
  return 0;
}
