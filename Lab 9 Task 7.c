#include <stdio.h>
#include <stdlib.h>

void rotateMatrix90(int **matrix, int n)
{
    int **temp = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        temp[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp[j][n - 1 - i] = matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = temp[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        free(temp[i]);
    }
    free(temp);
}

void printMatrix(int **matrix, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n = 3;

    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }

    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[0][2] = 3;
    matrix[1][0] = 4;
    matrix[1][1] = 5;
    matrix[1][2] = 6;
    matrix[2][0] = 7;
    matrix[2][1] = 8;
    matrix[2][2] = 9;

    printf("Original 3x3 matrix:\n");
    printMatrix(matrix, n);

    rotateMatrix90(matrix, n);

    printf("\nAfter 90-degree clockwise rotation:\n");
    printMatrix(matrix, n);

    for (int i = 0; i < n; i++)
    {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}