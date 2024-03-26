#include <stdio.h>
#include <stdbool.h>
#include "_fun_.c"

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
    int i, j, key;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void descending(int *arr, int size)
{
    int i, j, key;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] < key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
