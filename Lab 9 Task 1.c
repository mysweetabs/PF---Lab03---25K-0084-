#include <stdio.h>

int mysteryAccess(int *ptr, int rows, int cols, int i, int j)
{
    return *(ptr + i * cols + j);
}

int main()
{
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    printf("Testing 3x3 matrix:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nAccessing element at [1][2] using pointer arithmetic: %d\n",
           mysteryAccess(&matrix[0][0], 3, 3, 1, 2));

    return 0;
}