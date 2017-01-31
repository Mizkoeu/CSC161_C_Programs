#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Maximum length of names */
#define strMax 20

typedef struct node
{ char data [strMax];
  struct node * next;
} queueNode;

typedef struct {
  queueNode * head;
  queueNode * tail;
} stringQueue;

/* initialize queue referenced by the parameter
 */
void initializeQueue (stringQueue * queue);
   
/* return whether the queue is empty
   pre:  queue is an initialized queue
   post: returns 1 (true) if queue is empty;
   0 otherwise
*/
int isEmpty (stringQueue queue);
  
/* return whether the queue is full
   pre:  queue is an initialized queue
   post: returns 1 (true) if an additional item
   cannot be added to the queue;
   0 otherwise
*/
int isFull (stringQueue queue);

/* insert given item into back of the queue
   pre:  the specified queue is initialized
   returns:  -1 if queue is full
   otherwise, length of item, if item added
*/
int enqueue (stringQueue * queue, char* item);

/* removes front item from queue referenced by parameter
   pre:  the specified queue is initialized
   returns:  0 if queue is full
   otherwise, pointer to the item removed
*/
char * dequeue (stringQueue * queue);

int main()
{
  stringQueue queue;
  

  return 0;

}

void intitalizeQueue (stringQueue * queue)
{
  queue->head = NULL;
  queue->tail = NULL;
}

int isEmpty (stringQueue queue)
{
  if (queue.head == NULL)
    return 1;
  else return 0;
}

int enqueue (stringQueue *queue, char * item)
{
  queueNode *newNode = (queueNode *)malloc(sizeof(queueNode));
  strcpy (newNode->data, item);
  if (isEmpty (*queue)) {
    queue->head = newNode;
    return strlen(item);}
  else {
    (queue->tail)->next = newNode;
    return strlen(item);}
}

char * dequeue (stringQueue * queue)
{
  if (isEmpty (*queue))
    return 0;
  else {
    char temp[20];
    strcpy (temp, (queue->head)->data);
    queueNode *firstQueue = queue->head; 
    queue->head = (queue->head)->next;
    free (firstQueue);
    return temp;}
}
