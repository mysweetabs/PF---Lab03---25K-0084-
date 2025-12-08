#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows, columns;
    int **original_matrix;
    int **transposed_matrix;

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &columns);

    original_matrix = (int **)malloc(rows * sizeof(int *));

    if (original_matrix == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < rows; i++)
    {
        original_matrix[i] = (int *)malloc(columns * sizeof(int));
        if (original_matrix[i] == NULL)
        {
            printf("Memory allocation failed!\n");
            return 1;
        }
    }

    printf("\nEnter matrix elements:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &original_matrix[i][j]);
        }
    }

    transposed_matrix = (int **)malloc(columns * sizeof(int *));

    if (transposed_matrix == NULL)
    {
        printf("Memory allocation failed!\n");
        for (int i = 0; i < rows; i++)
        {
            free(original_matrix[i]);
            original_matrix[i] = NULL;
        }
        free(original_matrix);
        original_matrix = NULL;
        return 1;
    }

    for (int i = 0; i < columns; i++)
    {
        transposed_matrix[i] = (int *)malloc(rows * sizeof(int));
        if (transposed_matrix[i] == NULL)
        {
            printf("Memory allocation failed!\n");
            return 1;
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            transposed_matrix[j][i] = original_matrix[i][j];
        }
    }

    printf("\nOriginal Matrix (%dx%d):\n", rows, columns);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%d ", original_matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nTransposed Matrix (%dx%d):\n", columns, rows);
    for (int i = 0; i < columns; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            printf("%d ", transposed_matrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++)
    {
        free(original_matrix[i]);
        original_matrix[i] = NULL;
    }
    free(original_matrix);
    original_matrix = NULL;

    for (int i = 0; i < columns; i++)
    {
        free(transposed_matrix[i]);
        transposed_matrix[i] = NULL;
    }
    free(transposed_matrix);
    transposed_matrix = NULL;

    return 0;
}