
    /***********************************************************************
     * Name(s): Abyaya Lamsal, Mike Zou                                    *
     * Box(s): 4017, 4642                                                  *
     * Assignment name: Project 100: Image Processing Project              *
     *      (25% off if name/number does not match assignment)             *
     * Assignment for 11/07/16                                             *
     ***********************************************************************/

    /* *********************************************************************
     * Academic honesty certification:                                     *
     *   Written/online sources used:                                      *
     *     CSC161 Reading: Laboratory Exercise on Transforming Pictures    *
     *        http://www.cs.grinnell.edu/~walker/courses/161.fa16/show-reso*
     *        urce.php?resourceID=988                                      *
     *     CSC161 Lab: Laboratory Exercise on Transforming Pictures        *
     *        We took the grayscale calculation from this lab.             *
     *   Help obtained                                                     *
     *     NONE                                                            *
     *   My/our signature(s) below confirms that the above list of sources *
     *   is complete AND that I/we have not talked to anyone else          *
     *   (e.g., CSC 161 students) about the solution to this problem       *
     *                                                                     *
     *   Signature:                                                        *
     ***********************************************************************/

#include "MyroC.h"
#include <stdio.h>


//Function prototypes
void pixelStrip (Picture * pic, char color);
void pictureRedder (Picture * pic);
void pictureGreener (Picture * pic);
void pictureBluer (Picture * pic);
void circleSelect (Picture * pic, int xCenter, int yCenter, int radius);
void switchPixel (Picture * pic);

/* Preconditions: The character that is inputted for pixelStrip should limit to 
                  'R', 'G', or 'B'.*/

int main ()
{
  rConnect("/dev/rfcomm0");

  // declare pic for storing picture taken by robot.
  Picture pic;
  pic.height= 192;
  pic.width= 256;

  // prompting for color character.
  char ch;
  printf("Enter color char: ");
  scanf("%c", &ch);
          


  // testing functions by displaying and saving altered pics.
   pic = rTakePicture();
  rDisplayPicture(&pic, 5, "hello");
  rSavePicture (&pic, "Hello.jpeg");
  
  pixelStrip(&pic, ch);
  rDisplayPicture(&pic, 5, "hello pixStrip");
  rSavePicture (&pic, "pixStrip.jpeg");
  
  pictureRedder (&pic);
  rDisplayPicture(&pic, 5, "hello Reddit");
  rSavePicture (&pic, "Reddit.jpeg");

  pictureGreener (&pic);
  rDisplayPicture(&pic, 5, "hello Greener");
  rSavePicture (&pic, "GreenerHello.jpeg");
    
  pictureBluer (&pic);
  rDisplayPicture(&pic, 5, "hello Bluer");
  rSavePicture (&pic, "Bluer.jpeg");
  
  circleSelect (&pic, 100, 100, 70);
  rDisplayPicture(&pic, 5, "hello Circle");
  rSavePicture (&pic, "Circle.jpeg");
  
  switchPixel(&pic);
  rDisplayPicture(&pic, 5, "hello againCreativity!!!");
  rSavePicture (&pic, "Creativity.jpeg");

  rDisconnect();
  
  return 0;
}

void pixelStrip (Picture * pic, char color)
{
  int row, col;


  for (row=0; row<(*pic).height; row++)
    {
      for (col=0; col< (*pic).width; col++)
        {  
          int red_component= (*pic).pix_array [row] [col].R;
          int green_component= (*pic).pix_array [row] [col].G;
          int blue_component= (* pic).pix_array [row] [col].B;
          Pixel nored = {0, green_component, blue_component};
          Pixel nogreen = {red_component, 0, blue_component};
          Pixel noblue = {red_component, green_component, 0};
          if (color == 'R')
           (*pic).pix_array [row] [col]= nored;
          else if (color == 'G')
           (*pic).pix_array [row] [col]= nogreen;
          else
           (*pic).pix_array [row] [col]= noblue;
        }
    }
}


void pictureRedder (Picture * pic)
{
  int row, col;

  for (row=0; row<(*pic).height; row++)
    {
      for (col=0; col< (*pic).width; col++)
        {
          int green= (*pic).pix_array [row] [col].G;
          int blue= (* pic).pix_array [row] [col].B;
          int red= (* pic).pix_array [row] [col].R;
          Pixel redder= {red + ((255 - red)/2), green, blue};
          (*pic).pix_array [row] [col]= redder;
 
          
        }
    }
}

void pictureGreener (Picture * pic)
{
  int row, col;

  for (row=0; row<(*pic).height; row++)
    {
      for (col=0; col< (*pic).width; col++)
        {
          int red_component= (*pic).pix_array [row] [col].R;
          int blue_component= (* pic).pix_array [row] [col].B;
          int green= (* pic).pix_array [row] [col].G;
          Pixel greener = {red_component, green + ((255 - green)/2) , blue_component};
          (*pic).pix_array [row] [col]= greener;
        }
    }
}

void pictureBluer (Picture * pic)
{
  int row, col;

  for (row=0; row<(*pic).height; row++)
    {
      for (col=0; col< (*pic).width; col++)
        {
          int green_component= (*pic).pix_array [row] [col].G;
          int red_component= (* pic).pix_array [row] [col].R;
          int blue= (* pic).pix_array [row] [col].B;
          Pixel bluer = {red_component, green_component, blue + ((255 - blue)/2)};
          (*pic).pix_array [row] [col]= bluer;
        }
    }
}

void circleSelect (Picture * pic, int xCenter, int yCenter, int radius)
{
  int row, col;

  for (row=0; row<(*pic).height; row++)
    {
      for (col=0; col< (*pic).width; col++)
        {
          int x = col - xCenter;
          int y = row - yCenter;
          if ( x * x + y * y <= radius * radius)
            // Changes the pixel to grayscale in the selected circle
            { int gray = 0.3 * (*pic).pix_array[row][col].R
                + 0.59 * (*pic).pix_array[row][col].G
                + 0.11 * (*pic).pix_array[row][col].B ;
              Pixel grayPix={gray, gray, gray};
              (*pic).pix_array [row][col] = grayPix;
            }
        }
    }
}

/* The function switches the RGB components of all pixels. The red component's value is
   changed to the value of the green component. The green component's value is
   changed to the value of the blue component.  The blue component's value is
   changed to the value of the red component. */

void switchPixel (Picture * pic)
{
  int row, col;

  for (row=0; row<(*pic).height; row++)
    {
      for (col=0; col< (*pic).width; col++)
        {
          int red= (* pic).pix_array [row] [col].R;
          int green= (*pic).pix_array [row] [col].G;
          int blue= (* pic).pix_array [row] [col].B;
          Pixel newPix = {green, blue, red};
          (*pic).pix_array [row][col] = newPix;
        }
    }     
}
