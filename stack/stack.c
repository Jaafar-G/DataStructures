#include <stdio.h>
#include <stdlib.h>

// Preconditions:
// stack element must be of type int
// stack size determined by size variable
// size varibale must be in limits on MININT < size < MAXINT
// Postconditions:
// Stack must have a int top, int size, and int element attributes. 
struct stack 
{
  int top;
  int size;
  int *element;
};
int push(struct stack *Stack);// ,int element);
int pop(struct stack *Stack);
int get(struct stack *Stack);
int empty(struct stack *Stack);

// Function to create stack 
// Preconditions:
// caller must specify the size of stack
// Size must be in bounds MININT < size < MAXINT
// Postconditions:
// must return stack of size specified 
struct stack* createStack(int size)
{
  struct stack* Stack = (struct stack*)malloc(sizeof(struct stack)); 
  Stack->element = (int*)malloc(sizeof(int) * size);
  Stack->top = -1;
  Stack->size = size;
  return Stack;
};

// Function that allows user to operate stack
int main()
{
  // Menu
  printf("Enter a to push, b to pop, and c to get the top value from the stack\n");
  char c;
  struct stack* Stack = createStack(100);
  while((c = getchar()) != EOF)
  {
    if(c == 'a'){push(Stack);}
    if(c == 'b'){pop(Stack);}
    if(c == 'c'){get(Stack);}
  } 
  return 0;
}

 // Function that determines if stack is empty  
int empty(struct stack *Stack)
{
  if (Stack->top == -1)
  {
    printf("Stack is empty!");
    return 1;
  }
  return 0;
}

// function to insert element to stack
// Preconditions:
// element to be added must be of type int 
// stack must not be full
// Postconditions:
// top will be incremented
// element will be added to the top of the stack
int push(struct stack *Stack)
{
  if(Stack->top == 100)
  {
    printf("Stack is full");
    return 0;
  }

  int temp;
  printf("Enter a number to push onto the stack: \n");
  scanf("%d", &temp);

  //increase top by one
  Stack->top++; 
  // add element to the stack
  Stack->element[Stack->top] = temp;

  // Return element that was pushed unto the stack
  return Stack->element[Stack->top];

}

// function to remove element from top of stack
// Preconditions:
// stack must not be empty
// Postconditions:
// top of stack should point to top -1
int pop(struct stack *Stack)
{
  if(empty(Stack) == 1)
  {
    printf("Stack is empty!\n");
    return -1;
  }
  printf("Popping the element off of the stack\n");
  // Decrement top 
  Stack->top--;
  // Return element that was popped off
  return Stack->element[Stack->top+1];
}

// Function to return value at the top of the stack
// Preconditions:
// stack should not be empty
// Postconditions:
// should return value at the top of the stack
int get(struct stack *Stack)
{
  if ( empty(Stack) == 1)
  {
    return -1;
  }
  // Print the element at the top of the stack
  printf("The element at the top of the stack is: %d\n", Stack->element[Stack->top]);
  return Stack->element[Stack->top];
}
