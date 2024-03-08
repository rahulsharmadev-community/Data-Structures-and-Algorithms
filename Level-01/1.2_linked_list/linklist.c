#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct LinkList
{
  int value;
  struct LinkList *next;
} *Node;

Node createNode(int initial, Node *next)
{
  Node temp = (Node)malloc(sizeof(struct LinkList));
  temp->value = initial;
  temp->next = next;
  return temp;
}

void display(Node head)
{
  Node tmp = head;
  while (tmp != NULL)
  {
    printf("%d, ", tmp->value);
    tmp = tmp->next;
  }
}

void addNodeAtLast(Node *head, Node *tail, int element)
{
  Node temp = createNode(element);

  if (*head)
    if ((*node)->next == NULL)
    {
      Node temp = createNode(element);
      (*node)->next = temp;
      return;
    }
}

int count(Node head)
{
  int count = 0;
  Node tmp = head;
  while (tmp != NULL)
  {
    count++;
    tmp = tmp->next;
  }
  return count;
}

int main()
{
  Node head = createNode(12);
  addNodeAtLast(&node, 13);
  addNodeAtLast(&node, 33);
  addNodeAtLast(&node, 34);
  insertAt(&node, 2, 88);
  insertAt(&node, 3, 101);
  insertAt(&node, 19, 101);
  display(node);
  printf("\nCount: %d", count(node));
  return 0;
}
