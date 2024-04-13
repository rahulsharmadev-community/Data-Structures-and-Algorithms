#include <stdio.h>
#include <malloc.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} *Node;

typedef struct Pair
{
    int state;
    struct Node *node;
} *Pair;

Pair createPair(int state, Node node)
{
    Pair pair = (Pair)malloc(sizeof(struct Pair));
    pair->state = state;
    pair->node = node;
    return pair;
}

Node createNode(int data, Node left, Node right)
{
    Node node = (Node)malloc(sizeof(struct Node));
    node->data = data;
    node->left = left;
    node->right = right;
    return node;
}

void display(Node node)
{
    if (node == NULL)
        return;
    printf("%d\n", node->data);
    display(node->left);
    display(node->right);
}
