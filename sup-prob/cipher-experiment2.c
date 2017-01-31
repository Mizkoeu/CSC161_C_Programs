#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
  int m, n;
  int row = 3;
  int col = 4;
  char cipher[row][col];
  //int arraySize = row * col;
  //char * text = malloc (arraySize * sizeof (char));

  int i = 0;
  int counter;
  int strset;

  int rect = row * col;

  
  char text[rect];
  printf("input something: ");
  int len;

  while (1)
    {
      i = 0;
      char letter = 'a';
    fgets (text, rect, stdin);
    int len = strlen (text);

    if (len < rect)
      {for (strset = len - 1; strset < rect; strset++)
        {
          text[strset] = letter;
          letter++;
        }}
  
      //int END = 0;

      for (m = 0; m < row; m++)
        {
          for (n = 0; n < col; n++)
            {
              //text[i] = getchar();
              //if ((text[i] != '\n') && END == 0)
              cipher[m][n] = text[i];
              /* else
                 {
                 cipher[m][n] = 'a';
                 END = 1;
                 }*/
              i++;
            }
        }

      for (n = 0; n < col; n++)
        {
          for (m = 0; m < row; m++)
            {
              printf ("%c", cipher[m][n]);
            }
        }
    }
  //x++;
        
  /*if (i == arraySize)
    {
    char * temp = malloc (2 * arraySize * sizeof (char));
    for (x = 0; x < arraySize; x++)
    temp[x] = text[x];
    free (text);
    arraySize = 2 * arraySize;
    text = temp;
    i++;
    printf("%lu\n", strlen(text));
    }*/
  //scanf ("%c", &text[i]);
  //printf("\n");

  printf("\n");
  return 0;

}
