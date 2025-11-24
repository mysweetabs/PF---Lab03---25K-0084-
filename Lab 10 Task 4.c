#include <stdio.h>

int myStrlen(char *str)
{
    int len = 0;
    while (*str != '\0')
    {
        len++;
        str++;
    }
    return len;
}

void myStrcpy(char *dest, char *src)
{
    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

void myStrcat_array(char *dest, char *src)
{
    int i = 0;
    while (dest[i] != '\0')
        i++;

    int j = 0;
    while (src[j] != '\0')
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
}

void myStrcat_pointer(char *dest, char *src)
{
    while (*dest != '\0')
        dest++;
    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
}

int myStrcmp(char *str1, char *str2)
{
    while (*str1 != '\0' && *str2 != '\0')
    {
        if (*str1 != *str2)
            return *str1 - *str2;
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

int main()
{
    printf("=== Custom strcat Implementation ===\n\n");

    char str1[100] = "Hello";
    char str2[] = " World";

    printf("Array indexing version:\n");
    printf("Before: str1 = \"%s\"\n", str1);
    myStrcat_array(str1, str2);
    printf("After:  str1 = \"%s\"\n\n", str1);

    char str3[100] = "Hello";
    char str4[] = " World";

    printf("Pointer arithmetic version:\n");
    printf("Before: str3 = \"%s\"\n", str3);
    myStrcat_pointer(str3, str4);
    printf("After:  str3 = \"%s\"\n\n", str3);

    printf("Comparison:\n");
    printf("Array indexing:\n");
    printf("  - Uses array indices [i], [j]\n");
    printf("  - More readable for beginners\n");
    printf("  - Slightly more overhead\n\n");

    printf("Pointer arithmetic:\n");
    printf("  - Uses pointer increments (ptr++)\n");
    printf("  - More efficient (fewer operations)\n");
    printf("  - Idiomatic C style\n");
    printf("  - Direct memory manipulation\n\n");

    printf("Testing other string functions:\n");
    char test[] = "Testing";
    printf("myStrlen(\"%s\") = %d\n", test, myStrlen(test));

    char dest[50];
    myStrcpy(dest, "Copied");
    printf("myStrcpy result: \"%s\"\n", dest);

    printf("myStrcmp(\"abc\", \"abc\") = %d\n", myStrcmp("abc", "abc"));
    printf("myStrcmp(\"abc\", \"xyz\") = %d\n", myStrcmp("abc", "xyz"));

    return 0;
}