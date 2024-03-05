#include <stdio.h>

void swap(int *a, int *b);
void display(int *arr, int size);
void merge(int *arr, int s1, int e1, int s2, int e2);

int main()
{
    int arr[] = {23, 43, 45, 65, 12, 5};
    int size = 6;

    return 0;
}

void merge(int *arr, int s1, int e1, int s2, int e2)
{

    int _s1 = s1, _s2 = s2;
    while (_s1 < e1 && _s2 < e2)
    {
        /* code */
    }
}

void display(int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d, ", arr[i]);
    printf("\n");
}
