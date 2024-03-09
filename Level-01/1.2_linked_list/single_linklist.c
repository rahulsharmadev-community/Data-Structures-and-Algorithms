#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct LinkList
{
  int value;
  struct LinkList *next;
} *Node;

void display(Node head)
{
  if (head == NULL)
    printf("----No Element Found----");
  else
    printf("LinkList: ");
  while (head != NULL)
  {
    printf("%d, ", head->value);
    head = head->next;
  }
  printf("\n");
}

//  Creates and returns a new node with the specified initial value and next node.
//  `Note: This function only creates nodes and doesn't handle linked list operations.`
Node createNode(int initial, Node next)
{
  Node temp = (Node)malloc(sizeof(struct LinkList));
  temp->value = initial;
  temp->next = next;
  return temp;
}

//  Adds a new node with the given element at the end of the linked list.
void addNodeAtLast(Node *head, Node *tail, int *size, int element)
{
  Node newNode = createNode(element, NULL);
  if (*size == 0)
    *head = *tail = newNode;
  else
  {
    (*tail)->next = newNode;
    (*tail) = (*tail)->next; // Update the tail to the newly added node
  }
  (*size)++;
}

// Adds a new node with the given element at the beginning of the linked list.
void addNodeAtBeginning(Node *head, Node *tail, int *size, int element)
{
  Node newNode = createNode(element, *head);
  if (*size == 0)
    *head = *tail = newNode;
  else
    (*head) = newNode; // Update the head to the newly added node
  (*size)++;
}

// Adds a new node with the given element at the specified index in the linked list.
void addNodeAtIndex(Node *head, Node *tail, int *size, int idx, int element)
{
  if (idx < 0 || idx > *size)
    printf("----Invalid Index----");
  else
  {
    if (idx == 0)
      addNodeAtBeginning(head, tail, size, element);
    else if (idx == *size)
      addNodeAtLast(head, tail, size, element);
    else
    {
      Node before = *head;
      for (int i = 0; i < idx - 1; i++)
        before = before->next;
      before->next = createNode(element, before->next);
    }
    (*size)++;
  }
}

// Removes the last node from the linked list.
void removeNodeFromLast(Node *head, Node *tail, int *size)
{
  if (*size == 0)
    return;
  else if (*size == 1)
    *tail = *head = NULL;
  else
  {
    (*tail) = *head;
    for (int i = 0; i < *size - 2; i++)
      (*tail) = (*tail)->next;
    (*tail)->next = NULL;
  }
  (*size)--;
}

// Removes the first node from the linked list.
void removeNodeFromBeginning(Node *head, Node *tail, int *size)
{
  if (*size == 0)
    return;
  else if (*size == 1)
    *head = *tail = NULL;
  else
    *head = (*head)->next;
  (*size)--;
}

// Removes the node at the specified index from the linked list.
void removeNodeAtIndex(Node *head, Node *tail, int *size, int idx)
{
  if (idx < 0 || idx > *size)
    printf("----Invalid Index----");
  else
  {
    if (idx == 0)
      removeNodeFromBeginning(head, tail, size);
    else if (idx == *size)
      removeNodeFromLast(head, tail, size);
    else
    {
      Node before = *head;
      for (int i = 0; i < idx - 1; i++)
        before = before->next;
      before->next = before->next->next;
    }
    (*size)--;
  }
}

// This function displays a menu of operations related to a linked list and prompts the user to choose an option.
void displayUserMenu(Node *head, Node *tail, int *size);

int main()
{

  Node head;    //  - Node head: Pointer to the head of the linked list.
  Node tail;    //  - Node tail: Pointer to the tail of the linked list.
  int size = 0; //  - int size: Pointer to the size of the linked list.

  displayUserMenu(&head, &tail, &size);

  return 0;
}

int getInput(const char str[])
{
  int n;
  printf("%s", str);
  scanf("%d", &n);
  return n;
}

void displayUserMenu(Node *head, Node *tail, int *size)
{
  int choice, element, index;
  do
  {
    printf("\nMenu:\n");
    printf("1. Add Node at Last\n");
    printf("2. Add Node at Beginning\n");
    printf("3. Add Node at Index\n");
    printf("4. Remove Node from Last\n");
    printf("5. Remove Node from Beginning\n");
    printf("6. Remove Node from Index\n");
    printf("0. Exit\n");
    choice = getInput("Enter your choice: ");

    switch (choice)
    {
    case 1:
      element = getInput("Enter the element to add at last: ");
      addNodeAtLast(head, tail, size, element);
      break;

    case 2:
      element = getInput("Enter the element to add at the beginning: ");
      addNodeAtBeginning(head, tail, size, element);
      break;

    case 3:
      element = getInput("Enter the element to add: ");
      index = getInput("Enter the index to add at: ");
      addNodeAtIndex(head, tail, size, element, index);
      break;

    case 4:
      removeNodeFromLast(head, tail, size);
      break;

    case 5:
      removeNodeFromBeginning(head, tail, size);
      break;

    case 6:
      index = getInput("Enter the index to remove: ");
      removeNodeAtIndex(head, tail, size, index);
      break;

    case 0:
      printf("Exiting the program. Goodbye!\n\n");
      break;

    default:
      printf("Invalid choice. Please enter a valid option.\n");
    }
    if (choice != 0)
      display(*head);
  } while (choice != 0);
}