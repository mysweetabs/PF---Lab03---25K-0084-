#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

void printMemory(void *ptr, int size)
{
    unsigned char *bytes = (unsigned char *)ptr;
    printf("Memory content: ");
    for (int i = 0; i < size; i++)
    {
        printf("%02x ", bytes[i]);
    }
    printf("\n");
}

int main()
{
    int x = 42;
    int *px = &x;
    int arr[3] = {1, 2, 3};
    int *parr = arr;
    int (*fp)(int, int) = add;

    printf("=== Memory Layout Detective ===\n\n");

    printf("1. int x = 42:\n");
    printf("   Address: %p\n", (void *)&x);
    printf("   Size: %lu bytes\n", sizeof(x));
    printMemory(&x, sizeof(x));
    printf("\n");

    printf("2. int *px (pointer to int):\n");
    printf("   Pointer address: %p\n", (void *)&px);
    printf("   Points to: %p\n", (void *)px);
    printf("   Size: %lu bytes\n", sizeof(px));
    printMemory(&px, sizeof(px));
    printf("\n");

    printf("3. int arr[3] = {1, 2, 3}:\n");
    printf("   Array address: %p\n", (void *)arr);
    printf("   Size: %lu bytes\n", sizeof(arr));
    for (int i = 0; i < 3; i++)
    {
        printf("   arr[%d] at %p: ", i, (void *)&arr[i]);
        printMemory(&arr[i], sizeof(int));
    }
    printf("\n");

    printf("4. int *parr (pointer to array):\n");
    printf("   Pointer address: %p\n", (void *)&parr);
    printf("   Points to: %p\n", (void *)parr);
    printf("   Size: %lu bytes\n", sizeof(parr));
    printMemory(&parr, sizeof(parr));
    printf("\n");

    printf("5. Function pointer:\n");
    printf("   Pointer address: %p\n", (void *)&fp);
    printf("   Points to function at: %p\n", (void *)fp);
    printf("   Size: %lu bytes\n", sizeof(fp));
    printMemory(&fp, sizeof(fp));
    printf("\n");

    printf("=== Observations ===\n");
    printf("1. Memory alignment: addresses are typically aligned\n");
    printf("2. Pointer sizes: all pointers are %lu bytes (platform dependent)\n", sizeof(void *));
    printf("3. int size: %lu bytes\n", sizeof(int));
    printf("4. Arrays stored contiguously in memory\n");
    printf("5. Little-endian byte order (least significant byte first)\n");

    return 0;
}