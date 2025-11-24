#include <stdio.h>

void *findMax(void *arr, int size, int elementSize, int (*compare)(void *, void *))
{
    void *max = arr;
    for (int i = 1; i < size; i++)
    {
        void *current = (char *)arr + i * elementSize;
        if (compare(current, max) > 0)
        {
            max = current;
        }
    }
    return max;
}

int compareInt(void *a, void *b)
{
    return (*(int *)a - *(int *)b);
}

int compareFloat(void *a, void *b)
{
    float diff = *(float *)a - *(float *)b;
    if (diff > 0)
        return 1;
    if (diff < 0)
        return -1;
    return 0;
}

int compareChar(void *a, void *b)
{
    return (*(char *)a - *(char *)b);
}

int main()
{
    printf("Testing with int array:\n");
    int intArr[] = {3, 7, 2, 9, 1};
    int *maxInt = (int *)findMax(intArr, 5, sizeof(int), compareInt);
    printf("Array: 3, 7, 2, 9, 1\n");
    printf("Max int: %d\n\n", *maxInt);

    printf("Testing with float array:\n");
    float floatArr[] = {3.5, 7.2, 2.1, 9.8, 1.3};
    float *maxFloat = (float *)findMax(floatArr, 5, sizeof(float), compareFloat);
    printf("Array: 3.5, 7.2, 2.1, 9.8, 1.3\n");
    printf("Max float: %.1f\n\n", *maxFloat);

    printf("Testing with char array:\n");
    char charArr[] = {'d', 'a', 'z', 'b', 'k'};
    char *maxChar = (char *)findMax(charArr, 5, sizeof(char), compareChar);
    printf("Array: d, a, z, b, k\n");
    printf("Max char: %c\n", *maxChar);

    return 0;
}