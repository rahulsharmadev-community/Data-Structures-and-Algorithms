
#include <stdio.h>
#define size 10

int lastIndex = 3;
void insertAt(int *arr, int pos, int element);
void insertAtBegin(int *arr, int element);
void insertAtEnd(int *arr, int element);
void display(int *arr);

int main()
{
    int arr[size] = {12, 15, 23, 45};
    int action;
    while (1)
    {
        printf("\n1: Insert at position\n2: Insert at begin\n3: Insert at end\n0: Exit the program\nWaiting for input: ");
        scanf("%d", &action);
        if (action == 0)
            break;
        else if (action > 0 && action < 3)
        {
            int pos, n;
            printf("Entered element: ");
            scanf("%d", &n);
            switch (action)
            {
            case 1:
                printf("Entered position: ");
                scanf("%d", &pos);
                insertAt(arr, pos, n);
            case 2:
                insertAtBegin(arr, n);
            case 3:
                insertAtEnd(arr, n);
            default:
                display(arr);
            }
        }
        else
            printf("\nWrong input try agian!\n");
    }

    return 0;
}

void insertAtBegin(int *arr, int element)
{
    if (lastIndex + 1 >= size)
    {
        printf("\nArray overflow.\n");
    }
    else
    {
        int i = lastIndex;
        while (i >= 0)
        {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[0] = element;
    }
}
void insertAtEnd(int *arr, int element)
{
    if (lastIndex + 1 >= size)
    {
        printf("\nArray overflow.\n");
    }
    else
    {
        arr[lastIndex + 1] = element;
    }
}
void insertAt(int *arr, int pos, int element)
{
    if (pos >= size)
    {
        printf("\nArray overflow.\n");
    }
    else if (pos > lastIndex)
    {
        printf("\nOutof bounday.\n");
    }
    else
    {
        int i = lastIndex;
        while (pos <= i)
        {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[pos] = element;
    }
}

void display(int *arr)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d, ", arr[i]);
    }
}
