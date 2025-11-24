#include <stdio.h>
#include <string.h>

void reverseString(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

void fileLineReverser(char *inputFile, char *outputFile)
{
    FILE *fin = fopen(inputFile, "r");
    FILE *fout = fopen(outputFile, "w");

    if (fin == NULL || fout == NULL)
    {
        printf("Error opening files\n");
        return;
    }

    char line[101];
    while (fgets(line, sizeof(line), fin))
    {
        int len = strlen(line);
        if (line[len - 1] == '\n')
        {
            line[len - 1] = '\0';
            len--;
        }
        reverseString(line);
        fprintf(fout, "%s\n", line);
    }

    fclose(fin);
    fclose(fout);
}

int main()
{
    char inputFile[] = "input.txt";
    char outputFile[] = "output.txt";

    FILE *test = fopen(inputFile, "w");
    fprintf(test, "Hello World\n");
    fprintf(test, "This is a test\n");
    fprintf(test, "C programming\n");
    fclose(test);

    printf("Input file created: %s\n", inputFile);
    printf("Original content:\n");

    FILE *display = fopen(inputFile, "r");
    char line[101];
    while (fgets(line, sizeof(line), display))
    {
        printf("%s", line);
    }
    fclose(display);

    fileLineReverser(inputFile, outputFile);

    printf("\nReversed content written to: %s\n", outputFile);
    printf("Reversed content:\n");

    display = fopen(outputFile, "r");
    while (fgets(line, sizeof(line), display))
    {
        printf("%s", line);
    }
    fclose(display);

    return 0;
}