#include <stdio.h>
#define MAX 5

void swap(int *arr, int i, int j);
void display(int *arr, int arrSize);
void quickSort(int *arr, int firstIdx, int lastIdx);
int partition(int *arr, int pivot, int firstIdx, int lastIdx);

int main()
{
    int arr[MAX] = {2, 4, 1, 6, 3};
    quickSort(arr, 0, MAX - 1);
    display(arr, MAX);
    return 0;
}

void quickSort(int *arr, int firstIdx, int lastIdx)
{
    if (firstIdx >= lastIdx)
        return;
    int m = partition(arr, arr[lastIdx], firstIdx, lastIdx);
    quickSort(arr, firstIdx, m - 1); // for left side
    //  for `m` is index is already sorted
    quickSort(arr, m + 1, lastIdx); // for right side
}

int partition(int *arr, int pivot, int firstIdx, int lastIdx)
{
    int i = firstIdx, j = firstIdx;
    while (i <= lastIdx)
    {
        if (arr[i] > pivot)
            i++; // set element at right side
        else
        { // set element at left side
            swap(arr, i, j);
            i++;
            j++;
        }
    }
    return j - 1;
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
