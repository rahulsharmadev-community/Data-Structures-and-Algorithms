
#include <stdio.h>
#define MAX 3

void enQueue(int *queue, int *f, int *r, int element);
void deQueue(int *f, int *r);
void display(int *queue, int f, int r);
int getInput(const char str[]);

int main()
{
    int queue[MAX];
    int f = -1, r = -1; // front(f), rear(r)

    int input;
    do
    {
        printf("\n\n(1. EnQueue, 2. DeQueue, 0. Exit.)\n");
        input = getInput("Choose an option: ");
        if (input == 1)
            enQueue(queue, &f, &r, getInput("Enter an element: "));
        else if (input == 2)
            deQueue(&f, &r);
        display(queue, f, r);
    } while (input != 0);
    printf("Exit.");
    return 0;
}

int getInput(const char str[])
{
    int n;
    printf("%s", str);
    scanf("%d", &n);
    return n;
}

void enQueue(int *queue, int *f, int *r, int element)
{
    if ((*f == 0 && *r == MAX - 1) || (*r + 1) % MAX == *f)
        return;

    if (*f == -1 && *r == -1)
        *f = *r = 0;
    else
        *r = (*r + 1) % MAX;
    queue[*r] = element;
}

void deQueue(int *f, int *r)
{
    if (*f == -1 && *r == -1)
        return;

    *f = (*f + 1) % MAX;
    if ((*r + 1) % MAX == *f)
        *f = *r = -1;
}

void display(int *queue, int f, int r)
{
    if (f == -1 && r == -1)
        printf("\n----Queue is empty----");
    else
    {
        int i = f;
        printf("\nFront = %d, Rear = %d", f, r);
        printf("\nElements: ");
        while (1)
        {
            printf("%d, ", queue[i]);
            if (i == r)
                break;
            i = (i + 1) % MAX;
        }
    }
    if ((f == 0 && r == MAX - 1) || (r + 1) % MAX == f)
        printf("<----Queue is full");
    printf("\n");
}
