#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct LinkList
{
  int value;
  struct LinkList *next;
} *Node;

Node createNode(int initial)
{
  Node temp = (Node)malloc(sizeof(struct LinkList));
  temp->value = initial;
  temp->next = NULL;
  return temp;
}

void display(Node data)
{
  if (data == NULL)
    return;
  printf("%d, ", data->value);
  display(data->next);
}

void addNode(Node *node, int element)
{
  if ((*node)->next == NULL)
  {
    Node temp = createNode(element);
    (*node)->next = temp;
    return;
  }
  addNode(&((*node)->next), element);
}

#define count(a, ...) _count(a, (0, ##__VA_ARGS__))
int _count(Node data, int i)
{
  if (data == NULL)
    return i;
  count(data->next, ++i);
}

#define insertAt(a, b, c, ...) _insertAt(a, b, c, (0, ##__VA_ARGS__))
void _insertAt(Node *node, int index, int element, int i)
{
  if (index < 0)
  {
    printf("Invalid index\n");
    return;
  }
  else if ((*node) == NULL)
  {
    printf("Outof index\n");
    return;
  }
  if (index == 0 && i == 0)
  {
    Node temp = createNode(element);
    temp->next = (*node);
    (*node) = temp;
    return;
  }
  else if (index - 1 == i)
  {
    Node temp = createNode(element);
    temp->next = (*node)->next;
    (*node)->next = temp;
    return;
  }
  i++;
  insertAt(&((*node)->next), index, element);
}

int main()
{
  Node node = createNode(12);
  addNode(&node, 13);
  addNode(&node, 33);
  addNode(&node, 34);
  insertAt(&node, 2, 88);
  insertAt(&node, 3, 101);
  insertAt(&node, 19, 101);
  display(node);
  printf("\nCount: %d", count(node));
  return 0;
}
