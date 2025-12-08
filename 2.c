#include <stdio.h>
#include <stdlib.h>

int main()
{
    int array_size;
    int *array;
    int temp;

    printf("Enter the size of the array: ");
    scanf("%d", &array_size);

    array = (int *)calloc(array_size, sizeof(int));

    if (array == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d elements:\n", array_size);
    for (int i = 0; i < array_size; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("\nOriginal array: ");
    for (int i = 0; i < array_size; i++)
    {
        printf("%d ", array[i]);
    }

    for (int i = 0; i < array_size / 2; i++)
    {
        temp = array[i];
        array[i] = array[array_size - 1 - i];
        array[array_size - 1 - i] = temp;
    }

    printf("\nReversed array: ");
    for (int i = 0; i < array_size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    free(array);
    array = NULL;

    return 0;
}