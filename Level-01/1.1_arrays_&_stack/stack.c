
#include <stdio.h>
#include <stdbool.h>

#define MAX 100

void push(int *stack, int *topIndex, int element);
void pop(int *topIndex);
bool isEmpty(int topIndex);
void display(int *stack, int topIndex);
void stackStatus(int *stack, int topIndex);
int getInput(const char before[]);

int main()
{
    int stack[MAX];
    int topIndex = -1; // initially stack is empty

    int input;
    do
    {
        printf("\n\n1. Push operation\n2. Pop operation\n");
        printf("3. Check the stack status\n0. Exit.\n");
        input = getInput("Choose an option: ");
        if (input == 1)
            push(stack, &topIndex, getInput("Enter an element: "));
        else if (input == 2)
            pop(&topIndex);
        else if (input == 3)
            stackStatus(stack, topIndex);
        display(stack, topIndex);
    } while (input != 0);

    printf("Exit.");
    return 0;
}

void stackStatus(int *stack, int topIndex)
{
    if (isEmpty(*stack))
        printf("\nStatus: Stack is empty");
    else if (topIndex >= MAX - 1)
        printf("\nStack is full");
    else
        printf("\nStatus: Space available in stack");
    printf("\nNo. of Elements: %d", topIndex + 1);
    printf("\nAvailable space: %d", MAX - topIndex - 1);
}

int getInput(const char before[])
{
    int e;
    printf("%s", before);
    scanf("%d", &e);
    return e;
}

void push(int *stack, int *topIndex, int element)
{
    if (*topIndex >= MAX - 1)
        printf("\nStack overflow");
    else
        stack[++*topIndex] = element;
}

void pop(int *topIndex)
{
    if (isEmpty(*topIndex))
        printf("\nStack underflow");
    else
        --*topIndex;
}

bool isEmpty(int topIndex)
{
    return topIndex < 0;
}

void display(int *stack, int topIndex)
{
    if (isEmpty(topIndex))
        printf("\nStack is empty");
    else
    {
        printf("\nElements: ");
        for (int i = 0; i <= topIndex; i++)
            printf("%d, ", stack[i]);
    }
}
