#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main ()
{

  int row, col;
  printf ("Enter the dimensions (format: row column): ");
  scanf ("%d %d\n", &row, &col);

  int m, n, strset;
  char cipher[row][col];
  int len;

  //char ch;
  //int rect = row*col;
  char text[row*col+1];
  char * result;
  
  
  printf ("Input text to be encrypted: ");
  getchar();

  while ((result = fgets(text, row*col, stdin)) != NULL)
    {
      int i = 0;
      len = strlen(text);
      char letter = 'a';
      //if (len == 0)
      //break;
      if (len < row*col) {
        for (strset = len; strset < row*col -1; strset++)
          {
            text[strset] = letter;
            letter++;
          }
      }

      for (m = 0; m < row; m++)
        {
          for (n = 0; n < col; n++)
            {
              cipher[m][n] = text[i];
              i++;
            }
        }

      for (n = 0; n < col; n++)
        {
          for (m = 0; m < row; m++)
              printf ("%c", cipher[m][n]);
        }
    }
  
  printf("\n");
  
  return 0;
}
