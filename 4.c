#include <stdio.h>
#include <stdlib.h>

int main()
{
    int rows, columns;
    int **matrix_a, **matrix_b, **matrix_sum;

    printf("Enter number of rows: ");
    scanf("%d", &rows);
    printf("Enter number of columns: ");
    scanf("%d", &columns);

    matrix_a = (int **)malloc(rows * sizeof(int *));
    matrix_b = (int **)malloc(rows * sizeof(int *));
    matrix_sum = (int **)malloc(rows * sizeof(int *));

    if (matrix_a == NULL || matrix_b == NULL || matrix_sum == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < rows; i++)
    {
        matrix_a[i] = (int *)malloc(columns * sizeof(int));
        matrix_b[i] = (int *)malloc(columns * sizeof(int));
        matrix_sum[i] = (int *)malloc(columns * sizeof(int));

        if (matrix_a[i] == NULL || matrix_b[i] == NULL || matrix_sum[i] == NULL)
        {
            printf("Memory allocation failed!\n");
            return 1;
        }
    }

    printf("\nEnter elements for Matrix A:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &matrix_a[i][j]);
        }
    }

    printf("\nEnter elements for Matrix B:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("B[%d][%d]: ", i, j);
            scanf("%d", &matrix_b[i][j]);
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            matrix_sum[i][j] = matrix_a[i][j] + matrix_b[i][j];
        }
    }

    printf("\nMatrix A:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%d ", matrix_a[i][j]);
        }
        printf("\n");
    }

    printf("\nMatrix B:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%d ", matrix_b[i][j]);
        }
        printf("\n");
    }

    printf("\nSum Matrix:\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%d ", matrix_sum[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++)
    {
        free(matrix_a[i]);
        free(matrix_b[i]);
        free(matrix_sum[i]);
        matrix_a[i] = NULL;
        matrix_b[i] = NULL;
        matrix_sum[i] = NULL;
    }

    free(matrix_a);
    free(matrix_b);
    free(matrix_sum);
    matrix_a = NULL;
    matrix_b = NULL;
    matrix_sum = NULL;

    return 0;
}