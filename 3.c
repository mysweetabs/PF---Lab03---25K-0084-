#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concatenate(char *string1, char *string2)
{
    int length1 = strlen(string1);
    int length2 = strlen(string2);

    char *result = (char *)malloc((length1 + length2 + 1) * sizeof(char));
    if (result == NULL)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    strcpy(result, string1);
    strcat(result, string2);

    return result;
}

int main()
{
    char *first_string = NULL;
    char *second_string = NULL;
    char *concatenated_result = NULL;
    char input_buffer[1000];

    printf("Enter first string: ");
    fgets(input_buffer, sizeof(input_buffer), stdin);
    input_buffer[strcspn(input_buffer, "\n")] = '\0';

    first_string = (char *)malloc((strlen(input_buffer) + 1) * sizeof(char));
    if (first_string == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }
    strcpy(first_string, input_buffer);

    printf("Enter second string: ");
    fgets(input_buffer, sizeof(input_buffer), stdin);
    input_buffer[strcspn(input_buffer, "\n")] = '\0';

    second_string = (char *)malloc((strlen(input_buffer) + 1) * sizeof(char));
    if (second_string == NULL)
    {
        printf("Memory allocation failed!\n");
        free(first_string);
        return 1;
    }
    strcpy(second_string, input_buffer);

    concatenated_result = concatenate(first_string, second_string);
    if (concatenated_result == NULL)
    {
        free(first_string);
        free(second_string);
        return 1;
    }

    printf("\nConcatenated result: %s\n", concatenated_result);

    while (1)
    {
        printf("\nEnter 'Q' to quit or press Enter to add more strings: ");
        fgets(input_buffer, sizeof(input_buffer), stdin);

        if (input_buffer[0] == 'Q' || input_buffer[0] == 'q')
        {
            break;
        }

        printf("Enter string to concatenate: ");
        fgets(input_buffer, sizeof(input_buffer), stdin);
        input_buffer[strcspn(input_buffer, "\n")] = '\0';

        char *new_string = (char *)malloc((strlen(input_buffer) + 1) * sizeof(char));
        if (new_string == NULL)
        {
            printf("Memory allocation failed!\n");
            break;
        }
        strcpy(new_string, input_buffer);

        char *updated_result = concatenate(concatenated_result, new_string);
        if (updated_result == NULL)
        {
            free(new_string);
            break;
        }

        free(concatenated_result);
        concatenated_result = updated_result;
        free(new_string);

        printf("Current concatenated result: %s\n", concatenated_result);
    }

    printf("\n=== Final Results ===\n");
    printf("Original String 1: %s\n", first_string);
    printf("Original String 2: %s\n", second_string);
    printf("Final Concatenated String: %s\n", concatenated_result);

    free(first_string);
    free(second_string);
    free(concatenated_result);

    return 0;
}