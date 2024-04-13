#include <stdio.h>
#include "_fun_.c"

typedef struct Queue
{
    Node data;
    struct Queue *next;
} *Queue;

Queue front = NULL;
Queue rear = NULL;

// Function to check if the queue is empty
int isEmpty()
{
    return front == NULL;
}

// Function to enqueue (add) an element
void enqueue(Node element)
{
    Queue newNode = (Queue)malloc(sizeof(struct Queue));
    newNode->data = element;
    newNode->next = NULL;
    if (isEmpty())
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

// Function to dequeue (remove) an element
Node dequeue()
{
    Queue temp = front;
    Node element = temp->data;
    if (front == rear)
    {
        front = rear = NULL; // Reset if last element is dequeued
    }
    else
    {
        front = front->next;
    }
    free(temp);
    return element;
}

int count()
{
    int count = 0;
    Queue temp = front;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    return count;
}

void levelOrderPrint(Node node)
{
    enqueue(node);
    while (isEmpty() != 1)
    {
        for (int i = 0; i < count(); i++)
        {
            Node temp = dequeue();
            printf("%d, ", temp->data);

            if (node->left != NULL)
                enqueue(node->left);

            if (node->right != NULL)
                enqueue(node->right);
        }
        printf("\n");
    }
}

void main()
{
    int arr[] = {50, 25, 12, -1, -1, 37, 30, -1, -1, -1, 75, 62, -1, 70, -1, -1, 87, -1, -1};
    int sizeOfArray = sizeof(arr) / sizeof(arr[0]);
    Node root = createNode(arr[0], NULL, NULL);
    Pair rtp = createPair(1, root);
    Pair stack[sizeOfArray];
    int topIndex = -1;
    stack[++topIndex] = rtp;

    int idx = 0;
    while (topIndex >= 0)
    {
        Pair top = stack[topIndex];

        if (top->state == 1)
        {
            idx++;
            if (arr[idx] != -1)
            {
                top->node->left = createNode(arr[idx], NULL, NULL);
                stack[++topIndex] = createPair(1, top->node->left);
            }
            else
            {
                top->node->left = NULL;
            }
            top->state++;
        }
        else if (top->state == 2)
        {
            idx++;
            if (arr[idx] != -1)
            {
                top->node->right = createNode(arr[idx], NULL, NULL);
                stack[++topIndex] = createPair(1, top->node->right);
            }
            else
            {
                top->node->right = NULL;
            }
            top->state++;
        }
        else
        {

            topIndex--;
        }
    }

    levelOrderPrint(root);
}
