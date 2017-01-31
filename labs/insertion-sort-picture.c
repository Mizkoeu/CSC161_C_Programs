/* 
 * Program written by Erik Opavsky & David Cowden:  July 2011
 * Revised February 2014, October 2016 by Henry M. Walker
 */

#include "MyroC.h"
#include <unistd.h>  // needed for sleep function

/* Convert a Picture to a 1-dimensional array of Pixels

   Precondition: Pixel * pixArray is a two dimensional array of size
   [(*pic).height][(*pic).width] */
void picToPix1DArray (Picture * pic, Pixel pixArray []);

/* Convert a 1-dimensional array of Pixels to a Picture

   Precondition: Pixel * pixArray is a two dimensional array of size
   [(*pic).height][(*pic).width] */
void pix1DArrayToPic (Picture * pic, Pixel pixArray []);

// use insertion sort to sort the pixels in the picture array
void pixelInsertionSort (Picture * pic) ;

int
main ()
{
  rConnect ("/dev/rfcomm0");

  Picture  pic = rTakePicture();

  rDisplayPicture (&pic, -5, "unsorted"); // before any changes to pic

  pixelInsertionSort (&pic);

  rDisplayPicture (&pic, -5, "sorted"); // after sorting, before corner expansion

  sleep (5);

  rDisconnect();
  return 0;
} // main


/* Convert a Picture to a 1-dimensional array of Pixels

   Precondition: Pixel * pixArray is a two dimensional array of size
   [(*pic).height][(*pic).width] */

void picToPix1DArray (Picture * pic, Pixel pixArray [])
{
  int i, j, k;
  k = 0;
  for (i = 0; i < (*pic).height; i++)
    for (j = 0; j < (*pic).width; j++)
      {
         pixArray[k] = (*pic).pix_array[j][i];
         k++;
      }
}

/* Convert a 1-dimensional array of Pixels to a Picture

   Precondition: Pixel * pixArray is a two dimensional array of size
   [(*pic).height][(*pic).width] */

void pix1DArrayToPic (Picture * pic, Pixel pixArray [])
{
  int i, j, k;
      
  k = 0;
  for (i = 0; i < (*pic).height; i++)
    for (j = 0; j < (*pic).width; j++)
      {
	 (*pic).pix_array[j][i] = pixArray[k];
         k++;
      }
}

// use insertion sort to sort the pixels in the picture array
void pixelInsertionSort (Picture * pic) 
{
  // place pixels into a 1-dimensional array
  int width = (*pic).width;
  int height = (*pic).height;
  Pixel picArr[width * height];
  picToPix1DArray (pic, picArr); // put Pixels from pic into array picArr

  // apply insertion sort to pixels
  // CODE FOR AN INSERTION SORT GOES HERE
  int i, n;
  n = width*height;

  for (i = 1; i < n; i++)
    {
      Pixel temp = picArr[i];
      int j = i -1;
      while ((j >= 0) && ((temp.R + temp.G + temp.B) < (picArr[j].R +picArr[j].G+ picArr[j].B)))
        {
          picArr[i] = picArr[j];
          j--;
        }
      picArr[j+1] = temp;
    }

  // copy the sorted pixels back into the Picture
  pix1DArrayToPic (pic, picArr);
}

