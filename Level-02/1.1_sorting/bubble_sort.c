#include <stdio.h>
#include <stdbool.h>

void swap(int *a, int *b);
void display(int *arr, int size);
void ascending(int *arr, int size);
void descending(int *arr, int size);

int main()
{
    int arr[] = {23, 43, 45, 65, 12, 5};
    int size = 6;
    ascending(arr, size);
    display(arr, size);
    descending(arr, size);
    display(arr, size);

    return 0;
}

void ascending(int *arr, int size)
{
    int i, j;
    for (i = 0; i < size - 1; i++)
    {
        bool isSorted = true;
        for (j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                isSorted = false;
            }
        if (isSorted)
            break;
    }
}
void descending(int *arr, int size)
{
    int i, j;
    for (i = 0; i < size - 1; i++)
    {
        bool isSorted = true;
        for (j = 0; j < size - i - 1; j++)
            if (arr[j] < arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                isSorted = false;
            }
        if (isSorted)
            break;
    }
}

void display(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d, ", arr[i]);
    printf("\n");
}
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
