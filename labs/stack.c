#include <stdio.h>
#include <string.h>

/* MaxStack identifies the maximum size
   of all stack arrays */
#define MaxStack  50  

typedef struct {
  int topPosition;
  char * stackArray [MaxStack];
} stringStack;  /* type for a stack of strings */

int isFull (stringStack stack) {
  /* determine if an item can be added to the stack */
  return (stack.topPosition == (MaxStack-1));
}
int push (stringStack *stack, char * item) {
  /* return -1 if stack full */
  if (isFull (*stack)) {
    printf ("attempt to push item ");
    printf ("onto an already full stack\n");
    return -1;
  }
  /* add item to stack */
  else
  (stack->topPosition) ++;
  stack->stackArray[stack->topPosition] = item;
  return strlen(item);
}


void initializeStack (stringStack * stack)
{
  stack->topPosition = -1;
}

int isEmpty (stringStack stack)
{
  if (stack.topPosition == -1)
    return 0;
  else
    return -1;
}

char * pop (stringStack *stack)
{
  if (isEmpty (*stack))
    return (char *) 0;
  else {
    (stack->topPosition)--;
    return stack->stackArray[stack->topPosition + 1];
  }
}

  

char * top (stringStack stack)
{
  if (isEmpty (stack))
    return 0;
  else
    return stack.stackArray [stack.topPosition];
}

int main()
{
  //char *hi = "!!!";
  char *hey[MaxStack] = {"this is an array",
                         "HAHAHAHA",
                         "This is so fun!",
  };
  stringStack hello = {2, hey[MaxStack]};
  push (&hello, "!!");
  for (int i = 0; i < 50; i++)
    printf ("%s\n", hello.stackArray[i]);
  return 0;
}

