#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/**
* File: linked_list.c
 * Author: Jaafar Gharib
 * Date: 12/25/2023
 *
 * Description:
 * This file contains the implementation of a basic singly linked list in C. 
 * A singly linked list is a data structure consisting of a sequence of nodes 
 * where each node contains a value and a pointer to the next node in the list.
 * This implementation provides functions for creating a new list, adding nodes 
 * to the tail, adding nodes to the head removing the head node, and traversing
 * the list to print its contents. The singly linked list is a fundamental data
 * structure useful in various scenarios where dynamic and efficient element 
 * insertion and deletion are needed.
 *
 * The list is defined with the following structure:
 * - `node_t`: A structure representing a single node in the list.
 * - `linked_list_t`: A structure representing the entire list, 
 *                    including pointers to the head and tail nodes, 
 *                    and the size of the list.
 *
 * Functions:
 * - `newList`: Creates and initializes a new empty list.
 * - `isEmpty`: Checks if the list is empty.
 * - `getSize`: Returns the size of the list.
 * - `addNodeTail`: Adds a new node with a specified value to the end of the list.
 * - `addNodeHead`: Adds a new node with a specified value to the beginning of the list.
 * - `removeNodeHead`: Removes the node at the head of the list.
 * - `removeNodeTail`: Removes the node at the tail of the list.
 * - `printList`: Prints all elements in the list.
 *
 * Notes:
 * - This implementation does not include advanced features such as 
 *   iterator support or bidirectional traversal. 
 * - It is intended for educational purposes and may require modifications 
 *   for use in production code.
 */

// Defines node structure
typedef struct node_t 
{
  struct node_t *next; 
  int value;
}node_t;


// Defines a list structure
typedef struct 
{
  node_t *head;
  node_t *tail;
  int size;
}linked_list_t;


// Function that creates a new List
// Preconditions:
//  - 
// Postconditions:
//  - returns a new list structure 
//  - list size of 0 
//  - Head of list is null
//  - tail of list is null
linked_list_t* newList()
{
  linked_list_t *List = (linked_list_t*)malloc(sizeof(linked_list_t));
  List->size = 0;
  List->head = NULL;
  List->tail = NULL;

  return List;
}


// Function to check if list is empty
// Preconditions:
//  - takes in linked_list_t as param
//  - 
// Postconditions:
//  - returns true if nodes are null
//  - 
bool isEmpty(linked_list_t* List)
{
  if(List->head == NULL)
  {
    return true;
  }
  return false;
}


// Function that returns the size of a List
// Preconditions:
//  - takes in a list as a param
// Postconditions:
//  - returns number of nodes in list as int
int getSize(linked_list_t* List)
{
  return List->size;
}


// Function to add a Node to Head/Beginning of List
// Preconditions:
//  - Node value must be an integer
//  - 
// Postconditions:
//  - Node will be added to the Beginning of the list
//  - 
void addNodeHead(linked_list_t* List, int value)
{
  node_t *NewNode = (node_t*)malloc(sizeof(node_t));
  if (NewNode == NULL) {
    fprintf(stderr, "Failed to allocate memory for new node.\n");
    exit(1);
  }

  NewNode->value = value;

  if(isEmpty(List))
  {
    List->head = NewNode;
  }
  
  // Access size instead of checking if the 
  // List->head == NULL so no pointer dereference 
  if(List->size == 0)
  {
    List->tail = NewNode;
  }

  NewNode->next = List->head;
  List->head = NewNode;
  List->size++;
}


// Function to add a Node to Tail/End of List
// Preconditions:
//  - Node value must be an integer
// Postconditions:
//  - Node will be added to the End of the list
void addNodeTail(linked_list_t* List, int value)
{
  node_t *NewNode = (node_t*)malloc(sizeof(node_t));
  if(NewNode == NULL)
  {
    fprintf(stderr, "Failed to allocate memory for new node.\n");
    exit(1);
  }
  
  // Assign value taken as parameter to new node
  NewNode->value = value;
  NewNode->next = NULL;

  // Check if this is the first node to be added
  if(isEmpty(List))
  {
    List->head = NewNode;
    List->tail = NewNode;
  }

  else 
  {  
    List->tail->next = NewNode;
    List->tail = NewNode;
  }

  List->size++;
}


// Function to remove a Node to Head/Beginning of List
// Preconditions:
//  - Node value must be an integer
//  - 
//  -
// Postconditions:
//  - Node will be removed from the beginning of the list
//  - 
//  - 
void removeNodeHead(linked_list_t* List)
{
  if(isEmpty(List))
  {
    printf("Couldnt remove head, list is empty!\n");
  }

  node_t *temp = (node_t*)malloc(sizeof(node_t));

  temp = List->head;
  List->head = List->head->next;

  temp = NULL;
  free(temp);
  List->size--;
}



// Function that prints Node values of List
// Preconditions:
//  - Must take in a struct of List (Linked List)
// Postconditions:
//  - Prints out elements of list starting from 
//  - the head/beginning of list
void printList(linked_list_t* List)
{
  if(isEmpty(List))
  {
    printf("Error List is empty...\n");
  }

  node_t *temp = List->head;

  // Iterate through nodes printing their value
  printf("Elements: ");
  while (temp != NULL) 
  {
     printf("%d, ", temp->value);
     temp = temp->next;
  }
  printf("- End of list..\n");
}


// Main function to test other Functions of list
int main()
{
  linked_list_t* List = newList();

  printf("Empty(true): %d\n", isEmpty(List));
  printf("Adding nodes to list...\n");

  addNodeTail(List, 7);
  addNodeHead(List, 3);
  addNodeHead(List, 3);
  addNodeHead(List, 1);
  addNodeHead(List, 99);

  printList(List);

  removeNodeHead(List);
  
  // Print results
  printf("List size: %d, Head: %d, Tail: %d\n", getSize(List), List->head->value, List->tail->value);
  printList(List);
  printf("Empty(false): %d\n", isEmpty(List));

  free(List);
  
  return 0;
}
