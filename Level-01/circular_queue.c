
#include <stdio.h>
#define MAX 3

// Function for enqueues an element from the circular queue.
void enQueue(int *queue, int *f, int *r, int element);

// Function for dequeues an element from the circular queue.
void deQueue(int *f, int *r);

// Function for display elements and status(f,r) of the circular queue.
void display(int *queue, int f, int r);

// Designed for retrieve an `int` input from the user with a specified prompt.
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
    // Check if the circular queue is full
    if ((*f == 0 && *r == MAX - 1) || (*r + 1) % MAX == *f)
        return;

    if (*f == -1 && *r == -1)
        // Only when queue is empty
        *f = *r = 0;
    else
        // when queue is not empty
        *r = (*r + 1) % MAX;

    // Insert the element at the rear index
    queue[*r] = element;
}

void deQueue(int *f, int *r)
{
    // Check if the circular queue is initially empty
    if (*f == -1 && *r == -1)
        return;

    // Increment front index in a circular manner
    *f = (*f + 1) % MAX;

    // Reset front and rear indices if the queue becomes empty
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

            // Increment index in a circular manner
            i = (i + 1) % MAX;
        }
    }
    if ((f == 0 && r == MAX - 1) || (r + 1) % MAX == f)
        printf("<----Queue is full");
    printf("\n");
}
