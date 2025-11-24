#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
    {
        if (tolower(str[i]) != tolower(str[len - 1 - i]))
        {
            return 0;
        }
    }
    return 1;
}

void palindromeChecker(char *inputFile)
{
    FILE *fin = fopen(inputFile, "r");
    FILE *fpal = fopen("palindromes.txt", "w");
    FILE *fnon = fopen("non-palindromes.txt", "w");

    if (fin == NULL || fpal == NULL || fnon == NULL)
    {
        printf("Error opening files\n");
        return;
    }

    char word[100];
    int palCount = 0, nonCount = 0;

    while (fscanf(fin, "%s", word) == 1)
    {
        if (isPalindrome(word))
        {
            fprintf(fpal, "%s\n", word);
            palCount++;
        }
        else
        {
            fprintf(fnon, "%s\n", word);
            nonCount++;
        }
    }

    fclose(fin);
    fclose(fpal);
    fclose(fnon);

    printf("Processing complete!\n");
    printf("Palindromes: %d (saved to palindromes.txt)\n", palCount);
    printf("Non-palindromes: %d (saved to non-palindromes.txt)\n", nonCount);
    printf("Total words: %d\n", palCount + nonCount);
}

int main()
{
    char inputFile[] = "words.txt";

    FILE *test = fopen(inputFile, "w");
    fprintf(test, "radar level hello world\n");
    fprintf(test, "madam test racecar\n");
    fprintf(test, "noon programming kayak\n");
    fprintf(test, "civic palindrome deed\n");
    fclose(test);

    printf("Input file created: %s\n", inputFile);
    printf("Processing words...\n\n");

    palindromeChecker(inputFile);

    printf("\nPalindrome file contents:\n");
    FILE *display = fopen("palindromes.txt", "r");
    char line[100];
    while (fgets(line, sizeof(line), display))
    {
        printf("%s", line);
    }
    fclose(display);

    printf("\nNon-palindrome file contents:\n");
    display = fopen("non-palindromes.txt", "r");
    while (fgets(line, sizeof(line), display))
    {
        printf("%s", line);
    }
    fclose(display);

    return 0;
}