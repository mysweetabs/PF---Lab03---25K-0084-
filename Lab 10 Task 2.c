#include <stdio.h>
#include <string.h>

void fileWordStatistics(char *inputFile, char *outputFile)
{
    FILE *fin = fopen(inputFile, "r");
    if (fin == NULL)
    {
        printf("Error opening input file\n");
        return;
    }

    char words[1000][50];
    int wordCount = 0;
    int lineCount = 0;
    int charCount = 0;
    char line[1000];

    while (fgets(line, sizeof(line), fin))
    {
        lineCount++;
        for (int i = 0; line[i] != '\0'; i++)
        {
            if (line[i] != '\n')
                charCount++;
        }

        char *token = strtok(line, " \t\n");
        while (token != NULL)
        {
            strcpy(words[wordCount++], token);
            token = strtok(NULL, " \t\n");
        }
    }
    fclose(fin);

    char longest[50] = "";
    char shortest[50];
    strcpy(shortest, words[0]);

    for (int i = 0; i < wordCount; i++)
    {
        if (strlen(words[i]) > strlen(longest))
        {
            strcpy(longest, words[i]);
        }
        if (strlen(words[i]) < strlen(shortest))
        {
            strcpy(shortest, words[i]);
        }
    }

    int freq[1000] = {0};
    int uniqueCount = wordCount;
    for (int i = 0; i < uniqueCount; i++)
    {
        freq[i] = 1;
        for (int j = i + 1; j < uniqueCount; j++)
        {
            if (strcmp(words[i], words[j]) == 0)
            {
                freq[i]++;
                for (int k = j; k < uniqueCount - 1; k++)
                {
                    strcpy(words[k], words[k + 1]);
                    freq[k] = freq[k + 1];
                }
                uniqueCount--;
                j--;
            }
        }
    }

    FILE *fout = fopen(outputFile, "w");
    fprintf(fout, "Total words: %d\n", wordCount);
    fprintf(fout, "Total lines: %d\n", lineCount);
    fprintf(fout, "Total characters: %d\n", charCount);
    fprintf(fout, "Longest word: %s (%lu chars)\n", longest, strlen(longest));
    fprintf(fout, "Shortest word: %s (%lu chars)\n", shortest, strlen(shortest));
    fprintf(fout, "\nWord frequencies:\n");
    for (int i = 0; i < uniqueCount; i++)
    {
        fprintf(fout, "%s: %d\n", words[i], freq[i]);
    }
    fclose(fout);

    printf("Statistics written to %s\n", outputFile);
}

int main()
{
    char inputFile[] = "input.txt";
    char outputFile[] = "statistics.txt";

    FILE *test = fopen(inputFile, "w");
    fprintf(test, "This is a test file\n");
    fprintf(test, "It contains multiple words and lines\n");
    fprintf(test, "Some words repeat like test and words\n");
    fclose(test);

    printf("Processing file: %s\n", inputFile);
    fileWordStatistics(inputFile, outputFile);
    printf("Results saved to: %s\n", outputFile);

    return 0;
}