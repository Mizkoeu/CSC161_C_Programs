
/***********************************************************************
 * Name(s): Mike Zou                                                   *
 * Box(s): 4642                                                        *
 * Assignment: Supplemental Problem 5: Singly-linked-list Processing   *
 * Assignment for 12/02/16                                             *
 ***********************************************************************/

/* *********************************************************************
 * Academic honesty certification:                                     *
 *   Written/online sources used:                                      *
 *     CSC161 Reading: Linked Lists in C                               *
 *       http://www.cs.grinnell.edu/~walker/courses/161.fa16/show-resou*
 *       rce.php?resourceID=743                                        *
 *     By Henry M. Walker. Accessed on 11/29/16.                       *
 *   Help obtained                                                     *
 *     NONE                                                            *
 *   My/our signature(s) below confirms that the above list of sources *
 *   is complete AND that I/we have not talked to anyone else          *
 *   (e.g., CSC 161 students) about the solution to this problem       *
 *                                                                     *
 *   Signature:                                                        *
 ***********************************************************************/
/* This program is provided online in Problem 5 (found at http://www.cs.
grinnell.edu/~walker/courses/161.fa16/show-path-file.php?pathFile=suppl-
prob-main-body.php#5). */

/*Functions removeDuplicates and duplicate are added
to provide a additional operations on a linked list. Specifically, the
removeDuplicates function keeps diferring nodes while removes all other
identical nodes; the duplicate function adds a duplicate of each node 
after the node on the currrent list. */


/* A program shell  to maintain a linked list of names */

/* library for standard I/O */
#include <stdio.h>

/* library for memory allocation */
#include <stdlib.h>

#include <string.h>

/* Maximum length of names */
#define strMax 20

struct node
{ char data [strMax];
  struct node * next;
};

/* function prototypes, listed in alphabetical order */

void addName(struct node ** firstPtr);
/* pre-condition:  firstPtr points to the pointer
                   designating the head of a list
  post-condition:  a name is read and
                   inserted into the list at a designated place
*/

void print(struct node * first);
/* pre-condition:  first designates the first node of a list 
  post-condition:  The items on the list are printed from first to last
                   the list itself is unchanged
*/

void removeDuplicates (struct node * first);
/* pre-condition:  first designates the first node of a list 
  post-condition:  each name on the list appears only once (no duplicate names)
                   when duplicates occur on the original list,
                      only the first occurence remains after processing
*/

void duplicate (struct node * firstPtr);
/* pre-condition:  first designates the first node of a list 
  post-condition:  each node is duplicated, with the new node inserted
                   after the original node
*/

int main (void) {
  /* program to coordinate the menu options and calls the requested function */

  struct node * first = NULL;   /* pointer to the first list item */
  char option[strMax];          /* user response to menu selection */

  printf ("Program to Maintain a List of Names\n");

  while (1) {
    /* print menu options */
    printf ("Options available\n");
    printf ("I - Insert a name (from the keyboard) into the list\n");
    printf ("P - Print the names on the list\n");
    printf ("R - Remove duplicate names (leaving only the first occurence)\n");
    printf ("D - Duplicate each node\n");
    printf ("Q - Quit\n");

    /* determine user selection */
    printf ("Enter desired option: ");
    scanf ("%s", option);
    
    switch (option[0])
      { case 'I':
        case 'i': 
          addName(&first);
          break;
        case 'P':
        case 'p': 
          print(first);
          break;
        case 'R':
        case 'r': 
          removeDuplicates(first);
          break;
        case 'D': 
        case 'd': 
          duplicate(first);
          break;
        case 'Q':
        case 'q':
          printf ("Program terminated\n");
          return 0;
          break;
        default: printf ("Invalid Option - Try Again!\n");
          continue;
      }
  }
}
        
void addName(struct node ** firstPtr) {
  char oldName [strMax];
  struct node * newNode = (struct node *)malloc(sizeof(struct node));
  struct node * listPtr;
  struct node * prevPtr;

  printf ("Enter name to be inserted into list: ");
  scanf ("%s", newNode->data);

  if (*firstPtr == NULL) {
    /* insert name's node at start of list */
    newNode->next = *firstPtr;
    *firstPtr = newNode;
  }
  
  else {
    printf ("Enter old name which new name should preceed, \n");
    printf ("or enter ? if new name should be placed last\n");
    scanf ("%s", oldName);

    if (strcmp (oldName, (*firstPtr)->data) == 0) {
      /* insert name's node at start of list */
      newNode->next = *firstPtr;
      *firstPtr = newNode;
    }
    else {
      /* insert name's node after start of the list */
       
      /* start at beginning of list */
      listPtr = (*firstPtr)->next;  /* the current node to search */
      prevPtr = *firstPtr;          /* the node behind listPtr */
       
      while (listPtr && (strcmp (oldName, listPtr->data) != 0)) {
        prevPtr = listPtr;
        listPtr = prevPtr->next;
      }

      newNode->next = prevPtr->next;
      prevPtr->next = newNode;
    }
  }
  printf ("%s inserted into the list\n\n", newNode->data);
}

void print(struct node * first) {
  struct node * listElt = first;
  printf ("The names on the list are:\n\n");

  while (listElt) {
    printf ("%s\n", listElt->data);
    listElt = listElt->next;
  }

  printf ("\nEnd of List\n\n");
}


/* Define added function removeDuplicates */

void removeDuplicates (struct node * first) {
  
  //declare node pointer for iterating the element being compared to.
  struct node * point = first;

  //declare node pointer for following elements to compare with "point".
  struct node * comparer = first;

  //loop through all elements to be compared to.
  while (point) {

    //loop through all following elements to compare with "point".
    while (comparer->next) {

      //if 2 elements are identical, skip the node and deallocate it.
      if (strcmp (point->data, (comparer->next)->data) == 0) {
        struct node * temp = comparer->next;
        comparer->next = (comparer->next)->next;
        free (temp);
      }

      //if not the same, simply move on to next node,
      else
        comparer = comparer->next;
    } 

    //after "comparer" reaches the end of list, "point" move on to next node.
    point = point->next;
    //reset comparer pointer.
    comparer = point;
  }
}


/* Define added function duplicate*/

void duplicate (struct node * firstPtr) {
  
  //loop through the entire linked list.
  while (firstPtr) {

    //allocate a new node.
    struct node * newCopy = malloc (sizeof (struct node));

    //copy string from firstPtr to new node.
    strcpy (newCopy->data, firstPtr->data);

    //insert the new node after current node.
    newCopy->next = firstPtr->next;
    firstPtr->next = newCopy;

    //firstPtr points to the node after the newly created node. 
    firstPtr = newCopy->next;
  }
}


/*********************************************************************
******************************   Testing  ****************************
**********************************************************************
To test the correctness of this program, we need to firstly create a 
reasonably varied linked list using addName function. Then we may test
difference cases and see if the duplicates in the list are removed,
and if the right number of duplicates are created. 

Specifically, there are a few cases to consider. 
Case 1: There is not element in the list.
*Expected outcome: nothing is removed or added by the procedures. The 
said list should still remain a null list.

*Actual outcome: Indeed the list remains a null list regardless of how
many times the function removeDuplicates and duplicate are called.

Case 2: There is only one element in the list.
The names on the list are:

Gaudi

End of List

*Expected outcome:
removeDuplicates finds no duplicate and thus the list remains as is;
duplicate would create a copy of Gaudi and append it after the curent node:
Gaudi
Gaudi

*Acutal outcome:
Enter desired option: r
Enter desired option: p
The names on the list are:

Gaudi

End of List
(Result as expected)

Enter desired option: d
Enter desired option: p
The names on the list are:

Gaudi
Gaudi

End of List
(Result as expected)

Case 3: When all elements are the same.
The names on the list are:

hello
hello
hello
hello

End of List

*Expected outcome: removeDuplicate should trim the list down to just
one element, while duplicate should create a list of 8 same elements
(effectively doubling the number of same elements currently present).

*Actual outcome: 
Enter desired option: r
Enter desired option: p
The names on the list are:

hello

End of List
(Outcome as expected)

Enter desired option: d
Enter desired option: p
The names on the list are:

hello
hello
hello
hello
hello
hello
hello
hello

End of List
(Outcome as expected)


Case 4: The first copy of a name is not at beginning of the list. 
The names on the list are:

hello
myfriend
world
myfriend
this
myfriend

End of List

*Expected outcome: 
the first copy of a name on list is retained, while
all other copies after the first are deleted. Thus it should look like:
hello
myfriend
world
this

Then if we call the fucntion duplicate, every element should have a 
duplicate immediately afterward, as follows:
hello
hello
myfriend
myfriend
world
world
this
this

*Actual outcome:
Enter desired option: r
Enter desired option: p
The names on the list are:

hello
myfriend
world
this

End of List
(As expected)

Enter desired option: d
Enter desired option: p
The names on the list are:

hello
hello
myfriend
myfriend
world
world
this
this

End of List
(As expected)

Case 5: When there are more than 1 item with duplicates.
The names on the list are:

Einstein
Newton
Bohr
Planck
Newton
Einstein
Newton
Bohr

End of List

*Expected outcome: 
removeDuplicates keeps only the first copy of each distinct element:
Einstein
Newton
Bohr
Planck

duplicate would produce a list of double size, one duplicate following
an original element on the list:
Einstein
Einstein
Newton
Newton
Bohr
Bohr
Planck
Planck

*Actual outcome: 
Enter desired option: r
Enter desired option: p
The names on the list are:

Einstein
Newton
Bohr
Planck

End of List
(As expected)

Enter desired option: d
Enter desired option: p
The names on the list are:

Einstein
Einstein
Newton
Newton
Bohr
Bohr
Planck
Planck

End of List
(As expected)

Special Cases on different type of strings:

Case 6: When there are strings with same letters but different cases
schrodinger
Schrodinger
schroDinger

*Expected outcome:
Since our algorithm uses strcmp function, the comparison of nodes should
be case-sensitive. So strings with same spelling but different cases 
would be considered non-duplicates.
 
Duplicate procedure runs as per normal.

*Actual outcome:
Enter desired option: r
Enter desired option: p
The names on the list are:

schrodinger
Schrodinger
schroDinger

End of List
(As expected)

Enter desired option: d
Enter desired option: p
The names on the list are:

schrodinger
schrodinger
Schrodinger
Schrodinger
schroDinger
schroDinger

End of List
(As expected)

Case 7: When strings input contain numbers and punctuation marks.
The names on the list are:

@#$
31415926
Hawking
31415926
@#$

End of List

*Expected outcome: removeDuplicate should find the first and last
elements identical and remove the last @#$. Also the second 31415926
should be removed as well:
@#$
31415926
Hawking

Duplicate still does its
usual work of duplicating every element in the list.
@#$
@#$
31415926
31415926
Hawking
Hawking

*Actual outcome:
Enter desired option: r
Enter desired option: p
The names on the list are:

@#$
31415926
Hawking

End of List
(As expected!)

Enter desired option: d
Enter desired option: p
The names on the list are:

@#$
@#$
31415926
31415926
Hawking
Hawking

End of List
(As expected!)

**********************************************************************
*********************  Statement of Correctness ***********************
**********************************************************************

I ran this program multiple times with a wide variety of representative
cases considered. The program does what it is supposed to do according 
to the supplemental problem description. 

Firstly, the program strict follows the procedures of removing
duplicates and adding duplicates as prescribed by the given question.
Every step is implemented in code with maximum readability, efficiency
and conciseness in mind. Therefore, the program has a strong theoreti-
cal foundation as it should conceptually work according to the box-
and-poitner diagrams I drew.

Secondly, the program indeed gives us the expected results when I 
tested various conditions of the initial linked list. When there is 
no element in the list, the two functions keep the list as null. When 
there's one element, the removeDuplicate function removes no element
since there cannot be any duplicate in a one-element-list; duplicate
function successfully adds an identical element behind the current 
node. When there's more nodes and different elements with duplicates,
this program also trim the list of duplicate elements and retain the
original positions of the first copies of the elements in the list. 

Even with special cases such as when the strings inputted have the 
same spelling but different cases, the case-sensitive program 
treats them as differing elements. I also experimented inputs with 
numbers and punctuation marks, all of which worked as expected.

With these results, we can arrive at the conclusion that the proogram 
is correct all intents and purposes. 


**********************************************************************
****************************** THE END  ******************************
*********************************************************************/
