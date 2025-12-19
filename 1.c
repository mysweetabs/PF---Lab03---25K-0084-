#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **array;
    int columns[10];
    int row, col;

    array = (int **)malloc(10 * sizeof(int *));
    if (array == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (row = 0; row < 10; row++)
    {
        printf("Enter number of columns for row %d: ", row + 1);
        scanf("%d", &columns[row]);

        array[row] = (int *)malloc(columns[row] * sizeof(int));
        if (array[row] == NULL)
        {
            printf("Memory allocation failed!\n");
            for (col = 0; col < row; col++)
            {
                free(array[col]);
            }
            free(array);
            return 1;
        }

        for (col = 0; col < columns[row]; col++)
        {
            array[row][col] = row + 1;
        }
    }

    printf("\n2D Array:\n");
    for (row = 0; row < 10; row++)
    {
        printf("Row %d -> ", row + 1);
        for (col = 0; col < columns[row]; col++)
        {
            printf("%d ", array[row][col]);
        }
        printf("\n");
    }

    for (row = 0; row < 10; row++)
    {
        free(array[row]);
    }
    free(array);

    return 0;
}