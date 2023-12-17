#include <stdio.h>
#include <stdlib.h>

struct queue
{
  int size;
  int* head;
  int* tail;
  
};

struct queue* createQueue(int size)
{
  struct queue* Queue = createQueue(100); 
  Queue->size = size;
  int* head;
  int* tail;

  return Queue;
};

int enqueue(struct queue* Queueu, int c);
int dequeue();


// Function that allows user to operate stack
int main()
{
  // Menu
  printf("Enter a to push, b to pop, and c to get the top value from the stack\n");
  char c;
  struct stack* Queue = createQueue(100);
  while((c = getchar()) != EOF)
  {
    if(c == 'a'){enqueue(Queue);}
    if(c == 'b'){dequeue(Queue);}
    if(c == 'c'){get(Queue);}
  } 
  return 0;
}


