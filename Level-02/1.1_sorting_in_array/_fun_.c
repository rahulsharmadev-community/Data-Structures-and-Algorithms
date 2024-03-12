#include <stdio.h>

int getInput(const char str[])
{
    int n;
    printf("%s", str);
    scanf("%d", &n);
    return n;
}

void getArrayInput(int *arr, int arrSize)
{
    for (int i = 0; i < arrSize; i++)
        arr[i] = getInput("-> ");
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
