
#include <stdio.h>
#include <stdbool.h>
#include "_fun_.c"

void merge(int *arr, bool isAss, int start, int mid, int end);
void sort(int *arr, bool isAss, int start, int end);

int main()
{
    int choice, input;
    int arrSize = getInput("Enter a size of array: ");
    int arr[arrSize];
    getArrayInput(arr, arrSize);
    printf("\nMenu:\n");
    printf("1. Sort in ascending\n");
    printf("2. Sort in descending\n");
    printf("0. Exit\n");
    do
    {
        choice = getInput("Choose an options: ");
        switch (choice)
        {
        case 1:
            sort(arr, true, 0, arrSize - 1);
            printf("Sorted in ascending order: ");
            display(arr, arrSize);
            break;
        case 2:
            sort(arr, false, 0, arrSize - 1);
            printf("Sorted in descending order: ");
            display(arr, arrSize);
            break;
        case 0:
            printf("Exiting the program. Goodbye!\n\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}

void sort(int *arr, bool isAss, int start, int end)
{
    if (start >= end)
        return;
    int mid = (start + end) / 2;
    sort(arr, isAss, start, mid);
    sort(arr, isAss, mid + 1, end);
    merge(arr, isAss, start, mid, end);
}

void merge(int *arr, bool isAss, int start, int mid, int end)
{
    int i = start, k = 0;
    int j = mid + 1;
    int temp[end - start + 1];
    while (i <= mid && j <= end)
    {
        if (isAss && arr[i] < arr[j] || !isAss && arr[i] > arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }
    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= end)
        temp[k++] = arr[j++];

    for (i = 0; i < k; i++)
        arr[start + i] = temp[i];
}
