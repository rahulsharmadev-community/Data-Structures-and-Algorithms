#include <stdio.h>
#define MAX 15

void countSort(int *arr, int *ans, int arrSize, int min, int max);
void minMax(int *arr, int arrSize, int *min, int *max);
int main()
{
    int min, max;
    int arr[MAX] = {9, 6, 3, 5, 3, 4, 3, 9, 6, 4, 6, 5, 8, 9, 9};
    minMax(arr, MAX, &min, &max);
    int ans[MAX];
    countSort(arr, ans, MAX, min, max);
    for (int i = 0; i < MAX; i++)
        printf("%d, ", ans[i]);

    return 0;
}

void minMax(int *arr, int arrSize, int *min, int *max)
{
    int _min = arr[0], _max = arr[0];
    for (int i = 1; i < arrSize; i++)
    {
        if (arr[i] > _max)
            _max = arr[i];
        if (arr[i] < _min)
            _min = arr[i];
    }
    *min = _min;
    *max = _max;
}

void countSort(int *arr, int *ans, int arrSize, int min, int max)
{
    int range = max - min + 1;
    int freq[range];
    for (int i = 0; i < range; i++)
        freq[i] = 0;

    for (int i = 0; i < arrSize; i++)
    {
        int index = arr[i] - min;
        freq[index] += 1;
    }

    for (int i = 1; i < range; i++)
        freq[i] += freq[i - 1];

    for (int i = arrSize - 1; i >= 0; i--)
    {
        int idx = arr[i] - min;
        ans[freq[idx]-- - 1] = arr[i];
    }
}