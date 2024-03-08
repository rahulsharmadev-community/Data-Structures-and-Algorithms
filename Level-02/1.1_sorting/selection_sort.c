#include <stdio.h>

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
    int i, j, min_index;
    for (i = 0; i < size - 1; i++)
    {
        min_index = i;
        for (j = i + 1; j < size; j++)
            if (arr[min_index] > arr[j]) // Hint: if a>b means b is minimum
                min_index = j;
        if (min_index != i)
            swap(&arr[i], &arr[min_index]);
    }
}
void descending(int *arr, int size)
{
    int i, j, min_index;
    for (i = 0; i < size - 1; i++)
    {
        min_index = i;
        for (j = i + 1; j < size; j++)
            if (arr[min_index] < arr[j]) // Hint: if a<b means b is maximum
                min_index = j;
        if (min_index != i)
            swap(&arr[i], &arr[min_index]);
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
