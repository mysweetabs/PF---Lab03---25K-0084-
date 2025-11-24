#include <stdio.h>

void testArr3(int arr3[3][4])
{
    printf("arr3[3][4] - Array of 3 arrays of 4 ints\n");
    printf("Access arr3[1][2]: %d\n", arr3[1][2]);
    printf("Size: %lu bytes\n\n", sizeof(int) * 3 * 4);
}

void testArr2(int *arr2[3])
{
    printf("arr2[3] - Array of 3 pointers to int\n");
    printf("Access arr2[1][2]: %d\n", arr2[1][2]);
    printf("Each pointer can point to different sized arrays\n\n");
}

void testArr1(int (*arr1)[4])
{
    printf("arr1[4] - Pointer to array of 4 ints\n");
    printf("Access arr1[1][2]: %d\n", arr1[1][2]);
    printf("Points to entire row at once\n\n");
}

int main()
{
    printf("=== Explanation ===\n\n");

    printf("int arr3[3][4]:\n");
    printf("- Contiguous 2D array in memory\n");
    printf("- All elements stored sequentially\n");
    printf("- Cannot reassign rows\n\n");

    int arr3[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};
    testArr3(arr3);

    printf("int *arr2[3]:\n");
    printf("- Array of pointers\n");
    printf("- Each pointer can point to different locations\n");
    printf("- Rows can be reassigned\n\n");

    int row0[] = {1, 2, 3, 4};
    int row1[] = {5, 6, 7, 8};
    int row2[] = {9, 10, 11, 12};
    int *arr2[3] = {row0, row1, row2};
    testArr2(arr2);

    printf("int (*arr1)[4]:\n");
    printf("- Pointer to an array of 4 ints\n");
    printf("- Can point to different arrays\n");
    printf("- Treats each row as a unit\n\n");

    int (*arr1)[4] = arr3;
    testArr1(arr1);

    printf("=== Type Compatibility ===\n");
    printf("Passing wrong type causes:\n");
    printf("- Compiler warnings or errors\n");
    printf("- Incorrect memory access\n");
    printf("- Undefined behavior\n");

    return 0;
}