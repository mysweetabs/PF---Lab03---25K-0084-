#include <stdio.h>
#include <stdlib.h>

int **create_matrix(int rows, int cols)
{
    int **matrix;
    int i;

    matrix = (int **)malloc(sizeof(int *) * rows);
    if (matrix == NULL)
    {
        return NULL;
    }

    matrix[0] = (int *)malloc(sizeof(int) * rows * cols);
    if (matrix[0] == NULL)
    {
        free(matrix);
        return NULL;
    }

    for (i = 1; i < rows; i++)
    {
        matrix[i] = matrix[0] + i * cols;
    }

    return matrix;
}

void destroy_matrix(int **matrix)
{
    if (matrix != NULL)
    {
        free(matrix[0]);
        free(matrix);
    }
}

int main()
{
    int **matrix;
    int rows = 3, cols = 4;
    int i, j;

    matrix = create_matrix(rows, cols);
    if (matrix == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Matrix %dx%d:\n", rows, cols);
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            matrix[i][j] = i * cols + j;
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }

    destroy_matrix(matrix);
    return 0;
}