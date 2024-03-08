#include <stdio.h>
#define MAX 8

void display(int *arr, int arrSize);
void swap(int *arr, int i, int j);
int partitioning(int *arr, int arrSize, int pivot);

int main()
{
    int arr[MAX] = {4,3,2,8,9,6,7,1};
    int pivot = 7; // assume

    partitioning(arr, MAX, pivot);
    display(arr, MAX);
    return 0;
}

int partitioning(int *arr, int arrSize, int pivot)
{
    int i = 0, j = 0;
    while (i < arrSize)
    {
        if (arr[i] > pivot)
            i++;
        else
        {
            swap(arr, i, j);
            i++;
            j++;
        }
    }

    return 0;
}

void swap(int *arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void display(int *arr, int arrSize)
{
    for (int i = 0; i < arrSize; i++)
        printf("%d, ", arr[i]);
}
