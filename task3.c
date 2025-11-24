#include <stdio.h>

void swapByValue(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swapByPointer(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapByReference(int *a, int *b)
{
    int *temp = a;
    a = b;
    b = temp;
}

void swapRows(int *ptr, int cols, int row1, int row2)
{
    for (int j = 0; j < cols; j++)
    {
        int temp = *(ptr + row1 * cols + j);
        *(ptr + row1 * cols + j) = *(ptr + row2 * cols + j);
        *(ptr + row2 * cols + j) = temp;
    }
}

int main()
{
    int a = 5, b = 10;

    printf("Original values: a=%d, b=%d\n\n", a, b);

    printf("Testing swapByValue:\n");
    swapByValue(a, b);
    printf("After swapByValue: a=%d, b=%d\n", a, b);
    printf("Explanation: Values are copied, changes don't affect originals\n\n");

    printf("Testing swapByPointer:\n");
    swapByPointer(&a, &b);
    printf("After swapByPointer: a=%d, b=%d\n", a, b);
    printf("Explanation: Pointer dereferences allow actual swap in memory\n\n");

    int x = 15, y = 20;
    printf("Testing swapByReference: x=%d, y=%d\n", x, y);
    swapByReference(&x, &y);
    printf("After swapByReference: x=%d, y=%d\n", x, y);
    printf("Explanation: Only pointer variables swap, not actual values\n\n");

    printf("Testing row swap in 2D array:\n");
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};

    printf("Before:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    swapRows(&arr[0][0], 3, 0, 1);

    printf("After swapping rows 0 and 1:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}