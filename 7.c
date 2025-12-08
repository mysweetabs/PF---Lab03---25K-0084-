#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *sorted_array;
    int array_size = 0;
    int number_of_inputs;
    int new_number;
    int insert_position;
    int *temp_pointer;

    sorted_array = (int *)malloc(0);

    if (sorted_array == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("How many numbers do you want to insert? ");
    scanf("%d", &number_of_inputs);

    for (int count = 0; count < number_of_inputs; count++)
    {
        printf("\nEnter number %d: ", count + 1);
        scanf("%d", &new_number);

        array_size++;
        temp_pointer = (int *)realloc(sorted_array, array_size * sizeof(int));

        if (temp_pointer == NULL)
        {
            printf("Memory reallocation failed!\n");
            free(sorted_array);
            sorted_array = NULL;
            return 1;
        }

        sorted_array = temp_pointer;

        insert_position = array_size - 1;

        while (insert_position > 0 && sorted_array[insert_position - 1] > new_number)
        {
            sorted_array[insert_position] = sorted_array[insert_position - 1];
            insert_position--;
        }

        sorted_array[insert_position] = new_number;

        printf("Array after insertion: ");
        for (int i = 0; i < array_size; i++)
        {
            printf("%d ", sorted_array[i]);
        }
        printf("\n");
    }

    printf("\nFinal sorted array: ");
    for (int i = 0; i < array_size; i++)
    {
        printf("%d ", sorted_array[i]);
    }
    printf("\n");

    free(sorted_array);
    sorted_array = NULL;

    return 0;
}