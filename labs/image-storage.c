
    /***********************************************************************
     * Name(s) Siyu Zhang, Yoon Choi                                       *
     * Box(s):   4753, 3343                                                *
     * Assignment name:   module 100: Grouping Data and Image Processing   *
     * with the Scribbler 2:: Image Storage and Processing                 *
     * Assignment for 11/07/16                                             *
     ***********************************************************************/

    /* *********************************************************************
     * Academic honesty certification:                                     *
     *   Written/online sources used:                                      *
     *            readings:        Structures in C — structs               *
     *                             Image Storage and Processing            *
     *   Help obtained                                                     *
     *     [none]                                                          *
     *   My/our signature(s) below confirms that the above list of sources *
     *   is complete AND that I/we have not talked to anyone else          *
     *   (e.g., CSC 161 students) about the solution to this problem       *
     *                                                                     *
     *   Signature:                                                        *
     ***********************************************************************/

1
a. understood.
b.The program will present a warning when it is compiled,since we difine the some procedure in the header file. But it still works.
c.The expression {0, 0, 0} gives the struct three variables. Therefore the red, green and blue components are all 0, which is the color black. Whitepixel struck is {255, 255, 255}.
d.  
  myArt.pix_array [myArt.height/2]  [myArt.width/2]    = blackPix;
  myArt.pix_array [myArt.height/2]  [myArt.width/2+1]  = blackPix;
  myArt.pix_array [myArt.height/2+1][myArt.width/2]    = blackPix;
  myArt.pix_array [myArt.height/2+1][myArt.width/2+1]  = blackPix;
  myArt.pix_array [myArt.height-2]  [myArt.width/2]    = bluePix;
  myArt.pix_array [myArt.height-2]  [myArt.width/2+1]  = bluePix;
  myArt.pix_array [myArt.height-1]  [myArt.width/2]    = bluePix;
  myArt.pix_array [myArt.height-1]  [myArt.width/2+1]  = bluePix;
  myArt.pix_array [myArt.height/2]  [0]                = greenPix;
  myArt.pix_array [myArt.height/2]  [1]                = greenPix;
  myArt.pix_array [myArt.height/2+1]  [0]              = greenPix;
  myArt.pix_array [myArt.height/2+1]  [1]              = greenPix;
  myArt.pix_array [0]  [myArt.width/2]                 = redPix;
  myArt.pix_array [0]  [myArt.width/2+1]               = redPix;
  myArt.pix_array [1]  [myArt.width/2]                 = redPix;
  myArt.pix_array [1]  [myArt.width/2+1]               = redPix;
we wrote the code above in the program
e.
"display of myArt" is displayed in the windows title
20 : it will be opened for 20 seconds
-3 : it will be opened for 3 seconds but since it is a negative integer, other pictures could be shown simultaneously (non-blocking).
0  : nothing will happen


2
a.
#include <stdio.h>    
#include "MyroC.h"

Picture create_white_image (int height, int width);

void add_green (Picture * pic);

int main ()
{
  printf ("program to create, display, and save an image\n");

  printf ("creating and displayng a green image\n");
  Picture pic = create_white_image (200, 300);
  
  printf ("adding stripes to image and displaying the result\n");
  add_green (&pic);
  rDisplayPicture (&pic, 5.0, "green box");


  return 0;
}

Picture create_white_image (int height, int width)
{
  int i, j;
  Picture newPic;
  Pixel whitePix = {255, 255, 255};

  newPic.width = width;
  newPic.height = height;

  for (i = 0; i < height; i++)
    for (j = 0; j < width; j++)
      newPic.pix_array[i][j] = whitePix;

  return newPic;
}

void add_green (Picture * pic)
{
  int i, j;
  Pixel greenPix = {0, 255, 0};



  for (i = 25; i < ((*pic).height - 25); i++)
    for (j = 75; j < ((*pic).width - 75); j++)
      (*pic).pix_array[i][j] = greenPix;
}

3
void colorToGray (Picture * pic)
{
  int i, j;
  int component;
  for (i = 0; i < ((*pic).height); i++)
    {for (j = 0; j < ((*pic).width); j++)
      { component = (((*pic).pix_array[i][j]).R * 0.3 + ((*pic).pix_array[i][j]).G * 0.59 + ((*pic).pix_array[i][j]).B * 0.11);
        (*pic).pix_array[i][j].R = component;
        (*pic).pix_array[i][j].G = component;
        (*pic).pix_array[i][j].B = component;
      }}}
4
void setPictureMax (Picture * pic)
{
  int i, j;
  int max;
  int blue;
  int green;
  int red;
  for (i = 0; i < (*pic).height; i++)
    { for (j = 0; j < (*pic).width ; j++)
        { red = ((*pic).pix_array[i][j]).R;
          green =  ((*pic).pix_array[i][j]).G;
          blue  = ((*pic).pix_array[i][j]).B;
          if ((red <= blue) && (green <= blue))
              max = blue;
          else if ((red >= blue)&& (red >= green))
              max = red;
          else 
            max = green;

          if (red < max)
            red = 0;
          if (green < max)
            green = 0;
          if (blue < max)
            blue = 0;
          (*pic).pix_array[i][j].R = red;
          (*pic).pix_array[i][j].G = green;
          (*pic).pix_array[i][j].B = blue;
        }}}
5.

#include <stdio.h>    
#include "MyroC.h"



int main ()
{
  Picture pic;
  rConnect ("/dev/rfcomm0");
  int col, row;
  Picture temp;
  int height;
  pic = rTakePicture();
  height = pic.height;
  temp.height = height;
  temp.width = pic.width;
   for (row = 0; row < pic.height; row++)
    { for (col = 0; col < pic.width ; col++)
        temp.pix_array[height - row - 1][col] =  pic.pix_array[row][col];
    }
   pic = temp;
   rDisplayPicture (&pic, 5, "upsidedown");
   rDisconnect();
   return 0;
}

6.
#include <stdio.h>    
#include "MyroC.h"



int main ()
{
  Picture pic;
  rConnect ("/dev/rfcomm0");
  int col, row;
  Picture temp;
  int height;
  pic = rTakePicture();
  height = pic.height;
  temp.height = height;
  temp.width = pic.width;
  for (row = 0; row < pic.height; row++)
    { for (col = 0; col < pic.width ; col++)
        { (temp.pix_array[row][col]).R =  (255 - (pic.pix_array[row][col]).R);
          (temp.pix_array[row][col]).G =  (255 - (pic.pix_array[row][col]).G);
          (temp.pix_array[row][col]).B =  (255 - (pic.pix_array[row][col]).B);
        }}
  pic = temp;
  rDisplayPicture (&pic, 5, "upsidedown");
  rDisconnect();
  return 0;
}

7.
#include <stdio.h>    
#include "MyroC.h"



int main ()
{
  Picture pic;
  rConnect ("/dev/rfcomm0");
  int col, row;
  Picture temp;
  int height;
  int width;
  pic = rTakePicture();
  rDisplayPicture (&pic, 5, "original");
  height = pic.height;
  width = pic.width;
  temp.height = height;
  temp.width = width;
   for (row = 0; row < pic.height; row++)
    { for (col = 0; col < pic.width ; col++)
        temp.pix_array[row][width - 1 - col] =  pic.pix_array[row][col];
    }
   pic = temp;
   rDisplayPicture (&pic, 5, "left-to-right");
   rDisconnect();
   return 0;
}

8.
#include <stdio.h>    
#include "MyroC.h"



int main ()
{
  Picture pic;
  rConnect ("/dev/rfcomm0");
  int col, row;
  int brightest;
  int brightcol;
  int brightrow;

  pic = rTakePicture();
  brightest = ((pic.pix_array[0][0]).R + (pic.pix_array[0][0]).G + (pic.pix_array[0][0]).B);
  for (row = 0; row < pic.height; row++)
    { for (col = 0; col < pic.width ; col++)
        { if (brightest < (pic.pix_array[row][col]).R + (pic.pix_array[row][col]).G + (pic.pix_array[row][col]).B)
        { brightest = ((pic.pix_array[row][col]).R + (pic.pix_array[row][col]).G + (pic.pix_array[row][col]).B);
                brightcol = col;
                brightrow = row;
            }}}

  printf ("The coordinates for row is %d and for column is %d\n", brightrow, brightcol);
  rDisconnect();
  return 0;
}

9.

#include <stdio.h>    
#include "MyroC.h"



int main ()
{
  Picture pic;
  rConnect ("/dev/rfcomm0");
  int col, row;
  int brightest;
  int brightcol;
  int brightrow;
  Pixel red = {255, 0, 0};
  pic = rTakePicture();
  brightest = ((pic.pix_array[0][0]).R + (pic.pix_array[0][0]).G + (pic.pix_array[0][0]).B);
  for (row = 0; row < pic.height; row++)
    { for (col = 0; col < pic.width ; col++)
        { if (brightest < (pic.pix_array[row][col]).R + (pic.pix_array[row][col]).G + (pic.pix_array[row][col]).B)
        { brightest = ((pic.pix_array[row][col]).R + (pic.pix_array[row][col]).G + (pic.pix_array[row][col]).B);
                brightcol = col;
                brightrow = row;
            }}}
    for (row = 0; row < pic.height; row++)
    { for (col = 0; col < pic.width ; col++)
        { if ((((col - brightcol)*(col - brightcol)) + ((row - brightrow)*(row - brightrow))) == 25)
            pic.pix_array[row][col] = red;}}
    rDisplayPicture (&pic, 5, "picture");
  printf ("The coordinates for row is %d and for column is %d\n", brightrow, brightcol);
  rDisconnect();
  return 0;
}

10.

#include <stdio.h>    
#include "MyroC.h"
int sum (int col, int row, Picture pic)
{
  int i;
  int j;
  int sum = 0;
  for (i = row; i <(row + 3); i++)
    for (j = col; j < (col + 3) ; j++)
   sum =+ ((pic.pix_array[i][j]).R + (pic.pix_array[i][j]).G + (pic.pix_array[i][j]).B);
  return sum;
}


int main ()
{
  Picture pic;
  rConnect ("/dev/rfcomm0");
  int col, row;
  int brightest;
  int brightcol;
  int brightrow;
  Pixel red = {255, 0, 0};
  pic = rTakePicture();
  brightest = sum (0, 0, pic);

  for (row = 0; row < pic.height; row+=3)
    { for (col = 0; col < pic.width ; col+=3)
        { if (brightest < sum (col, row, pic))
            { brightest = sum (col, row, pic);
                brightcol = col;
                brightrow = row;
            }}}


  for (row = 0; row < pic.height; row++)
    { for (col = 0; col < pic.width ; col++)
        { if ((((col - brightcol-1)*(col - brightcol-1)) + ((row - brightrow-1)*(row - brightrow-1))) == 25)
            pic.pix_array[row][col] = red;}}
    rDisplayPicture (&pic, 5, "picture");
  printf ("The coordinates for row is %d and for column is %d\n", brightrow, brightcol);
  rDisconnect();
  return 0;
}



