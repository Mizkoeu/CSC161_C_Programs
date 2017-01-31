/* Program to illustrate the creation and development of a Picture
   with MyroC.

   For this example, a Picture is developed, displayed, and saved with
   these properties:

   * the Picture will be 200 pixels high by 300 pixels wide
   * the outside border of the picture is black
   * the inside picture (a square of 150 pixels by 150 pixels)
        has diagonal rows of colored stripes

*/

#include <stdio.h>     // for printf
#include "MyroC.h"

/* procedure to create and return an image that is all black */
Picture create_black_image (int height, int width);

/* procedure to add stripes to a picture */
void add_stripes (Picture * pic);

int main ()
{
  printf ("program to create, display, and save an image\n");

  printf ("creating and displayng a black image\n");
  Picture pic = create_black_image (200, 300);
  /* Display image for 5 seconds in window called "original pic" */
  rDisplayPicture (&pic, -5.0, "original pic");
  
  printf ("adding stripes to image and displaying the result\n");
  add_stripes (&pic);
  rDisplayPicture (&pic, 5.0, "stripped pic");

  printf ("saving picture to file called 'stripped-picture.jpg'\n");
  rSavePicture (&pic, "stripped-picture.jpg");
  
  return 0;
}

/* procedure to create and return an image that is all black */
Picture create_black_image (int height, int width)
{
  int i, j;
  Picture newPic;
  Pixel blackPix = {0, 0, 0};

  /* set dimensions of new picture */
  newPic.width = width;
  newPic.height = height;

  /* iterate through all pixels in the picture, setting each to black */
  for (i = 0; i < height; i++)
    for (j = 0; j < width; j++)
      newPic.pix_array[i][j] = blackPix;

  return newPic;
}

/* procedure to add stripes to a picture */
void add_stripes (Picture * pic)
{
  /* Define an array of pixel colors */
  Pixel colorPalette [ 6] = {
                               {255, 0, 0},    /* red */
                               {0, 0, 255},    /* blue  */
                               {255, 255, 0},  /* redGreen */
                               {0, 255, 0},    /* green */
                               {255, 0, 255},  /* redBlue*/
                               {0, 255, 255}  /* blueGreen*/
                             } ;


  /* in adding stripes to the image, 
        leave 25-pixel border unchanged at top and bottom
	leave 75-pixel border unchanged at left and right
  */
  int row, col;

  for (row = 25; row < (*pic).height - 25; row++)
    for (col = 75; col < (*pic).width - 75; col++)
      {
        /* stripes will be 10 pixels wide,
	   and will repeat every 6 colors */
	int colorIndex = ((row + col) / 10) % 6;

	(*pic).pix_array[row][col] = colorPalette [colorIndex];

      }
}


