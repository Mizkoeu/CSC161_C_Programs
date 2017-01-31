/* Definition of data structure and operations
   for working with Scheme-like lists
*/

/* librarys for standard I/O, strings, and memory allocation */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* maximum size of an array within a list node */
#define strMax 50   

typedef struct Node * listType;

typedef struct Node {
   char data [strMax];
   listType next;
} listNode;


/* ---------------------------------------------------------------- */
/* function prototypes, listed in alphabetical order */

char * car (listType list);
/* pre-condition:  list is an initialized list (actually list node)
   post-condition: head of the list is returned
*/

listType cdr (listType list);
/* pre-condition:  list is an initialized list (actually list node)
   post-condition: tail of the list is returned
*/

listType cons (char * newData, listType rest);
/* pre-condition:  newData is an initialized string
                   rest is an intialized list
   post-condition: returns new node with newData copied to data field
                   and next field pointing to rest
*/

/* function prototypes, listed in alphabetical order */

void listDelete (listType * list);
/* pre-condition:  list is an initialized list
   post-condition: list is changed to a NULL list
                   with any previously-defined nodes deallocated
*/

void listInit (listType * list);
/* pre-condition:  none
   post-condition: list is initialized to a null list
*/

void listPrint (listType list);
/* pre-condition:  list is an initialized list
   post-condition: data in each node is printed, Scheme-style, within ()
*/

/* ---------------------------------------------------------------- */
/* function definitions */

char * car (listType list) {
/* pre-condition:  list is an initialized list (actually list node)
   post-condition: head of the list is returned
*/
  return list->data;
}

listType cdr (listType list) {
/* pre-condition:  list is an initialized list (actually list node)
   post-condition: tail of the list is returned
*/
  return list->next;
}

listType cons (char * newData, listType rest) {
/* pre-condition:  newData is an initialized string
                   rest is an intialized list
   post-condition: returns new node with newData copied to data field
                   and next field pointing to rest
*/

  /* allocate space for new node */
  listType newNode = (listType)malloc(sizeof(listNode));

  /* copy newData field into data field,
       being careful not to overflow array
  */
  strncpy (newNode->data, newData, strMax);

  /* define next field of node as the rest of the list */
  newNode->next = rest;

  /* return newly initialized node */
  return newNode;
}

void listDelete (listType * list) {
/* pre-condition:  list is an initialized list
   post-condition: list is changed to a NULL list
                   with any previously-defined nodes deallocated
*/
  if (*list != NULL) {
    /* recursively remove the rest of the list nodes */
    listDelete (&((*list)->next));
    /* deallocate the space for the node itself */
    free (*list);
    /* set list pointer to null list */
    *list = NULL;
  }
}

void listInit (listType * list) {
  /* pre-condition:  none
     post-condition: list is initialized to a null list
  */
  *list = NULL;
}

void listPrint (listType list){
/* pre-condition:  list is an initialized list
   post-condition: data in each node is printed, Scheme-style, within ()
*/
  listType listPtr = list;
  char * separator = "";

  printf ("(");
  while (listPtr != NULL) {
    printf ("%s\"%s\"", separator, listPtr->data);
    separator = " ";
    listPtr = listPtr->next;
  }
  printf (")\n");
}


// 2. Write second function
// a) Using Scheme like functions like car and cdr:





// b) using C syntax:

char * second (listType list) {
  if (list == NULL) {
    return NULL;
  }
  else if (list->next == NULL) {
    return NULL;
  }
  else          
  return (list->next)->data;
}



// 3. Write count function
// a) Using Scheme like functions like car and cdr:
int count1 (listType list, char * item) {
  int counter = 0;
  while (list != NULL)
    {
      if (strcmp (car (list), item) == 0)
        { counter++;
          list = cdr (list);
        }
      else
        list = cdr (list);
    }
  return counter;
}

// b) using C syntax:
int count2 (listType list, char * item) {
  int count = 0;
  while (list != NULL)
    {
      if (strcmp (list->data, item) == 0)
        { count++;
          list = list->next;
        }
      else
        list = list->next;      
    }
  return count;
}


/* ---------------------------------------------------------------- */
/* main program */

int main () {
  /* testing for lists-like-Scheme operations */
  printf ("testing of lists-like-scheme operations\n");
  
  /* declarations */
  listType a;
  listType b;
  listType c;
  listType d;
  listType e;
  char * str;
  char * str2;

  /* create lists */
  listInit (&a);
  b = cons ("node B", a);
  c = cons ("node C", b);
  d = cons ("node D", c);
  d = cons ("node C", d);
  e = cdr (d);
  
  /* check list creation */
  printf ("list a:  ");
  listPrint (a);
  
  printf ("list b:  ");
  listPrint (b);
  
  printf ("list c:  ");
  listPrint (c);
  
  printf ("list d:  ");
  listPrint (d);
  
  printf ("list e:  ");
  listPrint (e);
  
  /* test car operation (cdr tested earlier) */
  str = car (d);
  printf ("car of list d:  %s\n", str);

  str2 = second (b);
  printf ("second of list b:  %s\n", str2);

  printf ("there are %d of iems in d. \n", count1 (d, "node C"));
  /* clean up */
  listDelete (&d);
  listPrint (c);
  a = NULL;
  b = NULL;
  c = NULL;  
  e = NULL;
  printf ("list d:  ");
  listPrint (d);

  printf ("end of testing\n");
}
