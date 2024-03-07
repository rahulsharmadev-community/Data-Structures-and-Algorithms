#include <stdio.h>
#define MAX 15

int maxInArray(int *arr, int arrSize);
void display(int *arr, int arrSize);
void countSort(int *arr, int arrSize, int exp);
int lenOfGreaterElement(int *arr, int arrSize);
int main()
{
    int arr[MAX] = {912, 236, 33, 435, 35, 4, 453, 9, 56, 54, 656, 5, 68, 9, 79};
    int exp = 1;
    int max = maxInArray(arr, MAX);
    while (exp < max)
    {
        countSort(arr, MAX, exp);
        exp *= 10;
    }

    display(arr, MAX);

    return 0;
}

void display(int *arr, int arrSize)
{
    for (int i = 0; i < arrSize; i++)
        printf("%d, ", arr[i]);
}
int maxInArray(int *arr, int arrSize)
{
    int max = arr[0];
    for (int i = 0; i < arrSize; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}
int lenOfGreaterElement(int *arr, int arrSize)
{
    int max = maxInArray(arr, arrSize);

    int count = 0;
    while (max > 0)
    {
        count++;
        max /= 10;
    }
    return count;
}
void countSort(int *arr, int arrSize, int exp)
{
    int range = 10;
    int freq[range], ans[arrSize];
    for (int i = 0; i < range; i++)
        freq[i] = 0;

    for (int i = 0; i < arrSize; i++)
    {
        int index = arr[i] / exp % 10;
        freq[index]++;
    }

    for (int i = 1; i < range; i++)
        freq[i] += freq[i - 1];

    for (int i = arrSize - 1; i >= 0; i--)
    {
        int idx = arr[i] / exp % 10;
        ans[freq[idx]-- - 1] = arr[i];
    }

    for (int i = 0; i < arrSize; i++)
        arr[i] = ans[i];
}