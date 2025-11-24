#include <stdio.h>

int ascending(int a, int b)
{
    return a - b;
}

int descending(int a, int b)
{
    return b - a;
}

int absoluteCompare(int a, int b)
{
    int absA = a < 0 ? -a : a;
    int absB = b < 0 ? -b : b;
    return absA - absB;
}

void customSort(int *arr, int size, int (*condition)(int, int))
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (condition(arr[j], arr[j + 1]) > 0)
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr1[] = {-5, 3, -8, 1, 9, -2};
    int arr2[] = {-5, 3, -8, 1, 9, -2};
    int arr3[] = {-5, 3, -8, 1, 9, -2};
    int size = 6;

    printf("Original array: ");
    printArray(arr1, size);
    printf("\n");

    customSort(arr1, size, ascending);
    printf("Ascending sort: ");
    printArray(arr1, size);

    customSort(arr2, size, descending);
    printf("Descending sort: ");
    printArray(arr2, size);

    customSort(arr3, size, absoluteCompare);
    printf("Absolute value sort: ");
    printArray(arr3, size);

    return 0;
}