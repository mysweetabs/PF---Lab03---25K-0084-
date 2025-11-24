#include <stdio.h>
#include <string.h>

int main()
{
    printf("=== String Memory Detective ===\n\n");

    char arr1[10] = "Hello";
    char arr2[10] = "Hello";
    char *str3 = "Hello";

    printf("1. Comparing char arr1[10] = \"Hello\":\n");
    printf("   Address of arr1: %p\n", (void *)arr1);
    printf("   Content: %s\n", arr1);
    printf("   Size: %lu bytes\n\n", sizeof(arr1));

    printf("2. Comparing char arr2[10] = \"Hello\":\n");
    printf("   Address of arr2: %p\n", (void *)arr2);
    printf("   Content: %s\n", arr2);
    printf("   Size: %lu bytes\n\n", sizeof(arr2));

    printf("3. Comparing char *str3 = \"Hello\":\n");
    printf("   Address of pointer str3: %p\n", (void *)&str3);
    printf("   str3 points to: %p (string literal)\n", (void *)str3);
    printf("   Content: %s\n", str3);
    printf("   Size of pointer: %lu bytes\n\n", sizeof(str3));

    printf("=== Testing arr1 == arr2 ===\n");
    printf("Result: %d\n", arr1 == arr2);
    printf("Explanation: Compares addresses (different arrays)\n\n");

    printf("=== Testing strcmp(arr1, arr2) ===\n");
    printf("Result: %d\n", strcmp(arr1, arr2));
    printf("Explanation: Compares content (both are \"Hello\")\n\n");

    printf("=== Modifying arr1[0] ===\n");
    arr1[0] = 'h';
    printf("arr1 after modification: %s\n", arr1);
    printf("Allowed: Stack arrays can be modified\n\n");

    printf("=== String Literal Memory ===\n");
    printf("String literals are stored in read-only memory\n");
    printf("Attempting to modify str3[0] would cause segmentation fault\n\n");

    printf("=== Character Storage ===\n");
    printf("Each character: 1 byte\n");
    printf("Null terminator: 1 byte\n");
    printf("\"Hello\" needs: 6 bytes (5 chars + '\\0')\n\n");

    printf("=== Memory Layout ===\n");
    for (int i = 0; i < 6; i++)
    {
        printf("arr1[%d] = '%c' (ASCII %d) at %p\n",
               i, arr1[i] ? arr1[i] : '0', arr1[i], (void *)&arr1[i]);
    }

    printf("\n=== Summary ===\n");
    printf("1. Stack strings: Can be modified\n");
    printf("2. String literals: Read-only, in text segment\n");
    printf("3. == compares addresses, strcmp() compares content\n");
    printf("4. Modifying string literals causes undefined behavior\n");

    return 0;
}