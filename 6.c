#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *string_1, *string_2, *result_string;
    int length_1 = 0, length_2 = 0;
    char temp_char;

    printf("Enter first string: ");

    string_1 = (char *)malloc(1 * sizeof(char));
    if (string_1 == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    while ((temp_char = getchar()) != '\n' && temp_char != EOF)
    {
        string_1[length_1] = temp_char;
        length_1++;
        string_1 = (char *)realloc(string_1, (length_1 + 1) * sizeof(char));
        if (string_1 == NULL)
        {
            printf("Memory allocation failed!\n");
            return 1;
        }
    }
    string_1[length_1] = '\0';

    printf("Enter second string: ");

    string_2 = (char *)malloc(1 * sizeof(char));
    if (string_2 == NULL)
    {
        printf("Memory allocation failed!\n");
        free(string_1);
        string_1 = NULL;
        return 1;
    }

    while ((temp_char = getchar()) != '\n' && temp_char != EOF)
    {
        string_2[length_2] = temp_char;
        length_2++;
        string_2 = (char *)realloc(string_2, (length_2 + 1) * sizeof(char));
        if (string_2 == NULL)
        {
            printf("Memory allocation failed!\n");
            free(string_1);
            string_1 = NULL;
            return 1;
        }
    }
    string_2[length_2] = '\0';

    result_string = (char *)malloc((length_1 + length_2 + 1) * sizeof(char));

    if (result_string == NULL)
    {
        printf("Memory allocation failed!\n");
        free(string_1);
        free(string_2);
        string_1 = NULL;
        string_2 = NULL;
        return 1;
    }

    for (int i = 0; i < length_1; i++)
    {
        result_string[i] = string_1[i];
    }

    for (int i = 0; i < length_2; i++)
    {
        result_string[length_1 + i] = string_2[i];
    }

    result_string[length_1 + length_2] = '\0';

    printf("\nConcatenated string: %s\n", result_string);

    free(string_1);
    free(string_2);
    free(result_string);
    string_1 = NULL;
    string_2 = NULL;
    result_string = NULL;

    return 0;
}