#include <stdio.h>
#include <stdlib.h>

int main()
{
    int array_size;
    int *array;
    int *unique_array;
    int unique_count = 0;
    int is_duplicate;

    printf("Enter the size of the array: ");
    scanf("%d", &array_size);

    array = (int *)malloc(array_size * sizeof(int));

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
    printf("\n");

    unique_array = (int *)malloc(array_size * sizeof(int));

    if (unique_array == NULL)
    {
        printf("Memory allocation failed!\n");
        free(array);
        array = NULL;
        return 1;
    }

    for (int i = 0; i < array_size; i++)
    {
        is_duplicate = 0;

        for (int j = 0; j < unique_count; j++)
        {
            if (array[i] == unique_array[j])
            {
                is_duplicate = 1;
                break;
            }
        }

        if (!is_duplicate)
        {
            unique_array[unique_count] = array[i];
            unique_count++;
        }
    }

    printf("\nDuplicates found: ");
    if (array_size == unique_count)
    {
        printf("None\n");
    }
    else
    {
        for (int i = 0; i < array_size; i++)
        {
            int count = 0;
            for (int j = 0; j < array_size; j++)
            {
                if (array[i] == array[j])
                {
                    count++;
                }
            }
            if (count > 1)
            {
                int already_printed = 0;
                for (int k = 0; k < i; k++)
                {
                    if (array[k] == array[i])
                    {
                        already_printed = 1;
                        break;
                    }
                }
                if (!already_printed)
                {
                    printf("%d ", array[i]);
                }
            }
        }
        printf("\n");
    }

    unique_array = (int *)realloc(unique_array, unique_count * sizeof(int));

    if (unique_array == NULL && unique_count > 0)
    {
        printf("Memory reallocation failed!\n");
        free(array);
        array = NULL;
        return 1;
    }

    printf("\nFinal array (duplicates removed): ");
    for (int i = 0; i < unique_count; i++)
    {
        printf("%d ", unique_array[i]);
    }
    printf("\n");

    printf("New size: %d\n", unique_count);

    free(array);
    free(unique_array);
    array = NULL;
    unique_array = NULL;

    return 0;
}