#include <stdio.h>

int main()

{
  int matrix[3][6] = {
    {2,6,4,1,8,5},
    {43,67,13,24,88,12},
    {-3,5,-9,12,3,18}
  };

  int i, n;
  /*
  for (n = 0; n < 3; n++)
    { for (i = 1; i < 6; i++) 
        {
          int temp = matrix[n][i];
          int j = i - 1;
          while ((j >= 0) && (temp < matrix[n][j])) {
            matrix[n][j+1] = matrix[n][j];
            j--;
          }

          matrix[n][j+1] = temp;
        }
    }
  */

  for (i = 0 ; i < 6; i ++)
    { for (n = 0; n < 3; n++)
        {
          int temp = matrix[n][i];
          int j = n - 1;
          while ((j >= 0) && (temp < matrix[j][i])) {
            matrix[j+1][i] = matrix[j][i];
            j--;
          }

          matrix[j+1][i] = temp;
        }
    }

  for (n = 0; n < 3; n++) {
    for (i = 0; i < 6; i++)
      printf (" %5d", matrix [n][i]);
    printf ("\n");            
  }

  return 0;
}
