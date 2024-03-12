
#include <stdio.h>
#include "_fun_.c"

void ascending(int *arr, int size);
void descending(int *arr, int size);

int main()
{
    int choice, input;
    int arrSize = getInput("Enter a size of array: ");
    int arr[arrSize];
    for (int i = 0; i < arrSize; i++)
        arr[i] = getInput("-> ");
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
            ascending(arr, arrSize);
            break;
        case 2:
            descending(arr, arrSize);
            break;
        case 0:
            printf("Exiting the program. Goodbye!\n\n");
            break;

        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
        if (choice != 0)
            display(arr, arrSize);
    } while (choice != 0);

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
