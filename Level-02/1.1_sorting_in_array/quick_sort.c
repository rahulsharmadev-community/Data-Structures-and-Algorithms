#include <stdio.h>
#include "_fun_.c"
#define MAX 5

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
