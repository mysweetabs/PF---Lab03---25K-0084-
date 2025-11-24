#include <stdio.h>
#include <string.h>

int splitString(char *input, char result[][20], char delimiter)
{
    int count = 0;
    int idx = 0;

    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == delimiter)
        {
            if (idx > 0)
            {
                result[count][idx] = '\0';
                count++;
                idx = 0;
            }
        }
        else
        {
            result[count][idx++] = input[i];
        }
    }

    if (idx > 0)
    {
        result[count][idx] = '\0';
        count++;
    }

    return count;
}

int main()
{
    char input[] = "apple,banana,orange";
    char tokens[20][20];
    char delimiter = ',';

    printf("Input string: %s\n", input);
    printf("Delimiter: '%c'\n\n", delimiter);

    int count = splitString(input, tokens, delimiter);

    printf("Token count: %d\n\n", count);

    for (int i = 0; i < count; i++)
    {
        printf("Token %d: %s\n", i + 1, tokens[i]);
    }

    printf("\nTesting with multiple delimiters:\n");
    char input2[] = "hello,,world,,test";
    int count2 = splitString(input2, tokens, ',');
    printf("Input: %s\n", input2);
    printf("Count: %d\n", count2);
    for (int i = 0; i < count2; i++)
    {
        printf("Token %d: %s\n", i + 1, tokens[i]);
    }

    return 0;
}