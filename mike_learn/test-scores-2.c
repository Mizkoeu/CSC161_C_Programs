#include <stdio.h>
#include <string.h>

/* Program to record, print, and process three test scores and final exam scores
   for several students
*/

/* a student struct identifies relevant data for one student
 */
struct student 
{
   char name [20];
   double test1;
   double test2;
   double test3;
   double exam;
};

double computeAverage (struct student stu)
{
  return (stu.test1 +stu.test2+stu.test3 + 2 * stu.exam)/5.0;

}

void addTen (struct student * stu)
{
  (*stu).test2 = (*stu).test2 * 1.1;

}


/* procedure to print a student's name and record */
void printStudent (struct student stu)
{
  printf ("%-20s: %7.1lf  %7.1lf  %7.1lf   %7.1lf   %7.1lf\n",
	  stu.name, stu.test1, stu.test2, stu.test3, stu.exam, computeAverage(stu));
}

void printMinMax (struct student stu [], int numStudents)
{
  double MAX = computeAverage(stu[0]);
  double  MIN = computeAverage(stu[0]);
  int i;
  char nameMax[20];
  char nameMin[20];
  for (i = 0; i < numStudents; i++)
    {
      if (computeAverage(stu[i]) >= MAX){
        MAX = computeAverage(stu[i]);
        strcpy (nameMax, stu[i].name);}
      if (computeAverage(stu[i]) <= MIN) {
        MIN = computeAverage(stu[i]);
        strcpy (nameMin, stu[i].name);}
    }
  printf ("Max is %lf with name of %s\n", MAX, nameMax);
  printf ("Min is %lf with name of %s\n", MIN, nameMin);
}

int main ()
{
  /* declaration and initialization of students */
  struct student stu [4] = {
                             {"Michael Mouse",      93.2, 98.7, 89.6, 95.6},
                             {"Sebastian the Fish", 75.3, 78.8, 72.6, 92.6},
                             {"Shamrock the Cat",   85.3, 87.2, 78.5, 82.8},
			     {"Inky the Dog",       98.6, 86.9, 69.8, 93.1}
                            };

  /* print initital student records  */
  printf ("Initial student records\n");
  printf ("name                    test 1   test 2   test 3  final exam    Average\n");
  int i;
  for (i = 0; i < 4; i++)
    {
      printStudent (stu[i]);
    }

  printMinMax ( stu, 4);
  return 0;
}
