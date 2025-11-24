#include <stdio.h>
#include <string.h>

int main()
{
    char str1[] = "hello";
    char str2[] = "hello";
    char str3[] = "hello";
    char str4[] = "world";

    printf("=== String Comparison Mystery ===\n\n");

    printf("Case 1: str1 == str2\n");
    printf("str1: %s (address: %p)\n", str1, (void *)str1);
    printf("str2: %s (address: %p)\n", str2, (void *)str2);
    printf("Result: %d\n", str1 == str2);
    printf("Explanation: == compares memory addresses, not content\n");
    printf("str1 and str2 are different arrays in memory\n\n");

    printf("Case 2: strcmp(str1, str2)\n");
    printf("Result: %d\n", strcmp(str1, str2));
    printf("Explanation: strcmp compares character by character\n");
    printf("Returns 0 when strings are identical\n\n");

    printf("Case 3: strcmp(str3, str4)\n");
    printf("str3: %s\n", str3);
    printf("str4: %s\n", str4);
    printf("Result: %d\n", strcmp(str3, str4));
    printf("Explanation: Returns negative if str3 < str4 lexicographically\n");
    printf("'h' (104) < 'w' (119) in ASCII\n\n");

    printf("Case 4: Pointer comparison\n");
    char *p1 = str1;
    char *p2 = str1;
    char *p3 = str2;
    printf("p1 points to: %p\n", (void *)p1);
    printf("p2 points to: %p\n", (void *)p2);
    printf("p3 points to: %p\n", (void *)p3);
    printf("p1 == p2: %d (both point to same address)\n", p1 == p2);
    printf("p1 == p3: %d (point to different addresses)\n", p1 == p3);
    printf("strcmp(p1, p3): %d (content is same)\n\n", strcmp(p1, p3));

    printf("Summary:\n");
    printf("- Use == for pointer address comparison\n");
    printf("- Use strcmp() for string content comparison\n");
    printf("- strcmp returns: 0 (equal), <0 (less), >0 (greater)\n");

    return 0;
}