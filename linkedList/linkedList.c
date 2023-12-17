#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <strings.h>
#include <unistd.h>

 // Define Type Node
 // Node included in first line because it is self-referential
// meaning it is self-referencing inside the structure
typedef struct node_t
{
  int nValue;
  struct node_t *next;
}node_t;

 // Linked list is not self self-referencing so no
 // linked_list_t in the typedef struc statement
typedef struct 
{
  // Head is a pointer because it points to the 
  // first node at the beginning of the list 
  node_t *head;
  node_t *tail;
  node_t *current;
  int size;

}linked_list_t;


 // Functions that created a new linked list
linked_list_t* newList()
{
  // Allocates enough memory for a Linked list
  // casts void* return type to linkedlist*
  linked_list_t* List = (linked_list_t*)malloc(sizeof(linked_list_t));

  List->head = NULL;
  List->size = 0;
  List->tail = NULL;

  return List;
}


bool isEmpty(linked_list_t* List)
{ 
  if (List->head == NULL)
  {
    return true;
  }

  return false;
}


int getSize(linked_list_t* List)
{
  return List->size;
}


// Add nValue funtion 
void addNodeTail(linked_list_t* List, int value)
{
  // Initialize and declare new node
  // Allocates memory for new node
  node_t* newNode = (node_t*)malloc(sizeof(node_t));
  newNode->nValue = value;
  newNode->next = NULL;

  // Error Handling for Failed memory allocation
  if(newNode == NULL)
  {
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
  }


  // If list is empty add assign new nValue to Head
  if (isEmpty(List))
  {
    List->head = newNode;
    List->tail= newNode;
  }

  else 
  {
    // Set Current node to point to new node 
    List->tail->next = newNode;
    // Set current node to new node 
    List->tail = newNode;
  }

  List->size++;
}


void removeNodeHead(linked_list_t* List)
{
  printf("Removing Head...\n");
  // Sets Head to node after head
  // to be removed to null 
  List->head = List->head->next;

  // Frees memory that was allocated to Node that is being removed
}


void printlist(linked_list_t* List)
{
  node_t* temp = List->head;

  printf("Elements: ");
  while(temp != NULL) 
  {
    printf("%d, ", temp->nValue);
    temp = temp->next;
  }

  printf("\n");

}

int main()
{
  // Initializes New List 
  linked_list_t* List = newList();  

  // Adds Node to list with value of 7
  addNodeTail(List, 7);
  addNodeTail(List, 1);
  addNodeTail(List, 1);

  // tests to See if 
  printf("isEmpty: %d, Head: %d\n", isEmpty(List), List->head->nValue);

  // Print the list
  printlist(List);

  removeNodeHead(List);

  // tests to See if 
  printf("isEmpty: %d, Head: %d\n", isEmpty(List), List->head->nValue);

  // Print the list
  printlist(List);
  //no error return
  return 0;
}
