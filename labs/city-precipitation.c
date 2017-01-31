/* Program to print and process precipitation in six cities,
   based on totals recorded during the eight days December 18-25, 2014.
*/

#include <stdio.h>

/* function returns total rainfall for the city with the given number */
double computeCityPrecip (double rain [8][6], int cityNum);

int main ()
{

  char * cities [6] = {"Chicago", "Denver", "Des Moines", 
                       "Phoenix", "San Jose", "Seattle"};
  char * states [6] = {"Illinois", "Colorado", "Iowa",
                       "Arizona", "California", "Washington"};
  double precip [][6] = { 
            /* Dec. 18 */  { 0.00 , 0.00 , 0.00 , 0.00 , 0.00 , 0.51 }, 
            /* Dec. 19 */  { 0.00 , 0.00 , 0.00 , 0.00 , 0.19 , 0.12 }, 
            /* Dec. 20 */  { 0.00 , 0.00 , 0.00 , 0.00 , 0.06 , 0.77 },
            /* Dec. 21 */  { 0.00 , 0.00 , 0.00 , 0.00 , 0.00 , 0.00 },  
            /* Dec. 22 */  { 0.28 , 0.14 , 0.34 , 0.00 , 0.00 , 0.00 },  
            /* Dec. 23 */  { 0.13 , 0.00 , 0.34 , 0.00 , 0.02 , 0.81 },  
            /* Dec. 24 */  { 0.12 , 0.00 , 0.09 , 0.00 , 0.04 , 0.21 },   
            /* Dec. 25 */  { 0.00 , 0.21 , 0.00 , 0.00 , 0.00 , 0.00 }   
                         };
/* source: 
    http://www.accuweather.com/en/us/chicago-il/60608/weather-forecast/348308 
    and similar pages from accuweather, accessed December 27, 2014.
*/

  int row, col;
  /* print titles */
  printf ("Precipitation at six cities over eight days in December 2014\n");
  printf ("         ");
  for (col = 0; col < 6; col++)
    printf ("%-11s", cities[col]);
  printf ("\n");
  printf ("  Date   ");
  for (col = 0; col < 6; col++)
    printf ("%-11s", states[col]);
  printf ("\n\n");

  /* print precipitation table */
  for (row = 0; row < 8; row++)
    {
      printf ("Dec. %2d", row+18);
      for (col = 0; col < 6; col++)
        {
          printf ("   %5.2lf   ", precip[row][col]);
        }
      printf ("\n");
    }
  printf ("\n");

  /* print total precipitation for each city */
  printf ("Totals ");
  for (col = 0; col < 6; col++)
    {
      printf ("   %5.2lf   ", computeCityPrecip (precip, col));
    }
      printf ("\n\n");
 
  return 0;
}


/* function returns the total rainfall for the city with the given number */
double computeCityPrecip (double rain [8][6], int cityNum)
{
  int k;
  double sum = 0.0;
  for (k = 0; k < 8; k++)
    sum += rain [k][cityNum];
  return sum;
}

