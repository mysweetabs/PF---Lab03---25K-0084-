#include <stdio.h>
#include <string.h>

void textSearchReplace(char *inputFile, char *outputFile, char *search, char *replace)
{
    FILE *fin = fopen(inputFile, "r");
    FILE *fout = fopen(outputFile, "w");

    if (fin == NULL || fout == NULL)
    {
        printf("Error opening files\n");
        return;
    }

    char lines[1000][1000];
    int lineCount = 0;
    int replaceCount = 0;

    while (fgets(lines[lineCount], 1000, fin))
    {
        lineCount++;
    }
    fclose(fin);

    for (int i = 0; i < lineCount; i++)
    {
        char *pos = strstr(lines[i], search);
        while (pos != NULL)
        {
            replaceCount++;
            int searchLen = strlen(search);
            int replaceLen = strlen(replace);
            int tailLen = strlen(pos + searchLen);

            memmove(pos + replaceLen, pos + searchLen, tailLen + 1);
            memcpy(pos, replace, replaceLen);

            pos = strstr(pos + replaceLen, search);
        }
        fprintf(fout, "%s", lines[i]);
    }

    fclose(fout);
    printf("Replacements made: %d\n", replaceCount);
}

int main()
{
    char inputFile[] = "input.txt";
    char outputFile[] = "output.txt";
    char search[100], replace[100];

    FILE *test = fopen(inputFile, "w");
    fprintf(test, "This is a test file.\n");
    fprintf(test, "This file contains test data.\n");
    fprintf(test, "We will test the search and replace.\n");
    fclose(test);

    printf("=== Text Search and Replace ===\n\n");

    printf("Input file created: %s\n", inputFile);
    printf("Original content:\n");
    FILE *display = fopen(inputFile, "r");
    char line[1000];
    while (fgets(line, sizeof(line), display))
    {
        printf("%s", line);
    }
    fclose(display);

    printf("\nEnter word to search: ");
    scanf("%s", search);

    printf("Enter replacement word: ");
    scanf("%s", replace);

    printf("\nProcessing...\n");
    textSearchReplace(inputFile, outputFile, search, replace);

    printf("\nModified content (saved to %s):\n", outputFile);
    display = fopen(outputFile, "r");
    while (fgets(line, sizeof(line), display))
    {
        printf("%s", line);
    }
    fclose(display);

    return 0;
}