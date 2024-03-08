

#include <stdio.h>
#define MAX 15

void display(int *arr, int arrSize);
void countSort(int *arr, int arrSize, int exp);
int maxInArray(int *arr, int arrSize);
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

// Function to display elements of an array
void display(int *arr, int arrSize)
{
    for (int i = 0; i < arrSize; i++)
        printf("%d, ", arr[i]);
}

// Function to find the maximum value in an array
int maxInArray(int *arr, int arrSize)
{

    int max = arr[0];
    for (int i = 0; i < arrSize; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// Function to find the length of the greater element in the array [optional]
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

/*
Function to perform Radix Sort using counting sort
 - `range`: Represents the range of possible digits (0 to 9) in the decimal number system.
 - `freq[range]`: An array to store the frequency of each digit at the current digit place.
 - `ans[arrSize]`: An auxiliary array to store the sorted elements temporaril
 - `exp`: The current digit place being processed (e.g., 1 for the units digit, 10 for the tens digit, and so on).
 */
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