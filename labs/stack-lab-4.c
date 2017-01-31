/* Stacks with Arrays Lab
   Version 4:  Stack contains array of strings
               push copies string to stack
*/

#define MaxStack 50  /* MaxStack stands for the size of all stack arrays */
#define StringLength 5 /* maximum length of string on stack */
#include <stdlib.h>

typedef struct {
  int topPosition;
  char stackArray [MaxStack][StringLength];
} stringStack;      /* type for a stack of strings */

/* index of standard stack operations            changes from Version 1 */
void initializeStack (stringStack * stack);   /* only printf changed */
int size (stringStack stack);                 /* unchanged */
int empty (stringStack stack);                /* unchanged */
int full (stringStack stack);                 /* unchanged */
int push (stringStack *stack, char * item);   /* must copy string to stack */
/* post-condition:  item string is added to stack  
                    length of string is returned 
*/
char * pop (stringStack *stack);              /* must create copied string */
char * top (stringStack stack);               /* must create copied string */
void print (stringStack stack);               /* unchanged */
char * get_nth (stringStack stack, int nth);  /*  must create copied string */
/* assume nth indexing starts at 1 */

/* ---------------------------------------------------------------------- */
/* Implementation of stack operations */

void initializeStack (stringStack * stack) {
  printf ("initialization of stack --- implementation 4\n");
  printf ("    stack struct i array of strings, copying in, return address\n");
  stack->topPosition = -1;
}

int size (stringStack stack) {
  return stack.topPosition+1;
}

int empty (stringStack stack){
  /* determine if there are any items in a stackArray */
  return (stack.topPosition == -1);
}

int full (stringStack stack) {
  /* determine if there are more positions in a stackArray */
  return (stack.topPosition == (MaxStack-1));
}

int push (stringStack *stack, char * item) {
/* post-condition:  item string is added to stack
                    length of string is returned 
*/
  /* return -1 if stack full */
  if (full (*stack)) {
    printf ("attempt to push item onto an already full stack\n");
    return -1;
  }
  
  /* add item to stack */
  (stack->topPosition) ++;
  strncpy (stack->stackArray[stack->topPosition], item, StringLength);
  return strlen(item);
}

char * pop (stringStack *stack) {
  char * item;  /* string [base address] to return */
  /* return -1 if stack empty */
  if (empty (*stack)) {
    printf ("attempt to pop item from an empty stack\n");
    return (char *) -1;
  }
  /* remove item from stack */
  item = stack->stackArray[stack->topPosition];
  (stack->topPosition) --;
  return item;
}
  
char * top (stringStack stack){
  char * item;  /* string [base address] to return */
  /* return -1 if stack empty */
  if (full (stack)) {
    printf ("attempt to access item on an empty stack\n");
    return (char *) -1;
  }
  /* remove item from stack */  
  item = stack.stackArray[stack.topPosition];
  return item;
}

void print (stringStack stack) {
  int i;
  printf ("contents of stack from top to bottom:\n");
  for (i = stack.topPosition; i >= 0; i--)
    printf ("    %s\n", stack.stackArray[i]);
  printf ("end of stack\n");
}

char * get_nth (stringStack stack, int nth) {
  /* assume nth indexing starts at 1
     translate to 0-indexed arrays, counting from topPosition 
     return null if invalid index specified */
  char * item;  /* string [base address] to return */
  if ((nth < 1) || (nth > stack.topPosition+1)) {
    printf ("position %d is not a valid location in this stack\n", nth);
    return "error";
  }
  item = malloc (strlen (stack.stackArray[stack.topPosition - nth + 1])+1);
  strcpy (item, stack.stackArray[(stack.topPosition) - nth + 1]);
  return item;
}

