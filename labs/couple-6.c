/* A couple decides to have children.
   They decide to continue to have children until 
      they have at least one boy and one girl.
   Then they decide to stop having children.

   This program simulates family size for 1000 couples.
   An asserion requires that the likelihood of boys
   is between 1/3 and 2/3.
*/

#include <stdio.h>

/* libraries for the pseudo-random number generator */
#include <stdlib.h>
#include <time.h>
/* Within the time.h library,
 *    time returns a value based upon the time of day
 * Within the stdlib.h library
 *    rand returns a pseudo-random integer between 0 and RAND_MAX
 */

/* library for the assert function to check assertions/pre-conditions */
#include <assert.h>

#define numberOfCouples 1000

/* procedure to simulate the number of children for one couple 
   parameter fraction_boys:  the percentage of boys born, 
                             expressed as a decimal fraction
   return:  the total number of children for the couple
   pre-condition:  0.33 <= franction_boys <= 0.66
*/
int simulate_couple (double fraction_boys)
{
  /* actively enforce the pre-condition */
  assert ((0.33 <= fraction_boys) && (fraction_boys <= 0.66));

  /* couple starts with no children */
  int boys = 0;
  int girls = 0;

  /* couple has children */
  while ((boys == 0) || (girls == 0))
    {  
      if ((((double) rand()) / ((double) RAND_MAX)) < fraction_boys) 
	boys++;
      else
	girls++;
    }

  /* report the family size */
  return boys + girls;
}

/* procedure to conduct simulation for several couples 
   parameter numCouples:     the number of couples to be simulated
   parameter fraction_boys:  the percentage of boys born, 
                             expressed as a decimal fraction
*/
void simulate_several_couples (int numCouples, double fraction_boys)
{
   int couple;
  int total_children = simulate_couple (fraction_boys);
  int max_children = total_children;
  for (couple = 1; couple < numCouples; couple++)
    {
      int couple_children = simulate_couple (fraction_boys); 

      /* accumulate total number of children */
      total_children += couple_children;

      /* check for new maximum */
      if (max_children < couple_children)
        max_children = couple_children;
    }

  double avg_children = ((double) total_children) / numCouples;
  printf (" fraction boys:  %6.3lf     average:  %6.2lf     maximum:  %3d\n",
          fraction_boys, avg_children, max_children);
  
}

int main ()
{
  /* initialize pseudo-random number generator */
  /* change the seed to the pseudo-random number generator, 
     based on the time of day */
  srand (time ((time_t *) 0) );

  /* print initial title for program */
  printf ("Simulation of family size with %d couples\n", numberOfCouples);

  /* run simulation for several couples */
  double boy_fraction;
  for (boy_fraction = 0.5; boy_fraction <= 0.52; boy_fraction += 0.002)
    {
      simulate_several_couples (numberOfCouples, boy_fraction);
    }

  return 0;
}
