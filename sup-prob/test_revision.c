/****************************************************************************
***************************** Problem 3 Revision ****************************
****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxStringLength 50

typedef struct node * stringStack;
typedef struct node {
    char * str;
    struct node * next;
} stackNode;

//3a. Write code for initializeStack

/* initialize stack referenced by the parameter */
void initializeStack (stringStack * stack)
{
  //initialize by letting the pointer (*stack) point to NULL.
  (*stack) = NULL;
}

//3b. Writ the code for pop

/* removes top item from stack referenced by parameter
    pre: the specified stack is initialized
    return: 0 if stack is empty
    otherwise, pointer to the item removed 
*/
char * pop (stringStack *stack)
{
  //first, check if the stack is empty
  if (*stack == NULL)
    return (char *) 0;
  
  else {
    //if not, then create a temp pointer to point at first node
    stringStack temp = *stack;

    //Then move the pointer pointing the first node to the next node
    *stack = (*stack)->next;

    //return the string in the node removed by using temp
    return temp->str;
  }
}

//3 Additional function: push implementation
/* insert given item onto top of the stack
   pre:  the specified stack is initialized
    returns: length of item, if item added
*/
int push (stringStack *stack, char * item) 
{
  //declare variable len to denote length of item
  int len = strlen (item);

  //create a new node 
  stackNode *new = malloc (sizeof (stackNode));

  //initialize the node
  new->str = item; //new node has str that points to item
  new->next = NULL; //new node has a next that points to NULL initially

  //when stack is empty, point the stack to new node
  if (*stack == NULL)
    *stack = new;

  //if not, add new node in front of current first node
  else {
    new->next = *stack;
    *stack = new;
  }

  //return length of the string added
  return len;
}

int main()
{
  stringStack myStack;
  initializeStack (&myStack);
    
  char a [6] = "apple";
  char b [6] = "beans";
  char c [6] = "melons";
  push (&myStack, a);
  push (&myStack, b);
  push (&myStack, c);
  pop (&myStack);
  push (&myStack, a);

  while (myStack != NULL) {
    printf ("%s\n", myStack->str);
    myStack = myStack->next;}

  printf ("\n");
    
  return 0;
}


/****************************************************************************
 ******************************** Testing ***********************************

zoutianh@banach:mike_learn$ test_revision
apple
beans
apple

The program works as expected, as the third node "melons" is successfully 
popped and "apple" is then pushed.

***************************** Explanantion *********************************

This is a simple program that implements a stack using linked list.
The initializeStack function is simply setting the stringStack to NULL, 
which effectively makes the *stack pointer point to NULL.

The pop function first checks if the stack is empty. If not, then it creates
a new temp pointer to keep track of the first node in order to  access the 
str later to return its value. And lastly, the first node pointer is moved
to point to the next node, effectively popping the first node out of the 
stack structure.

The push function creates and initialize a node with the str pointing to 
the item given as a parameter. Then if current stack is empty, the first 
node pointer points to the new node. If the stack is not empty, then the 
new node is linked to the first node, before the first node pointer is 
moved to point to the new node instead. Effectively, the new node now 
becomes the first node. At last, the program outputs the length of the item
given. 

The tests have shown that the program runs and gives correct results. Thus,
the program is indeed correct and meets the requirements set forth in the 
question.

****************************************************************************/
