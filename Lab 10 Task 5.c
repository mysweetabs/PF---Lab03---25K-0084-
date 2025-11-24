#include <stdio.h>
#include <string.h>

void sortStringsAlphabetically(char arr[][50], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(arr[j], arr[j + 1]) > 0)
            {
                char temp[50];
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
        }
    }
}

void sortStringsByLength(char arr[][50], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strlen(arr[j]) > strlen(arr[j + 1]))
            {
                char temp[50];
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
        }
    }
}

void printStrings(char arr[][50], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d. %s\n", i + 1, arr[i]);
    }
}

int main()
{
    char names[5][50];
    int count = 0;

    printf("Enter 5 names:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("Name %d: ", i + 1);
        scanf("%s", names[i]);
        count++;
    }

    printf("\nOriginal list:\n");
    printStrings(names, count);

    char names_alpha[5][50];
    for (int i = 0; i < count; i++)
    {
        strcpy(names_alpha[i], names[i]);
    }
    sortStringsAlphabetically(names_alpha, count);

    printf("\nSorted alphabetically:\n");
    printStrings(names_alpha, count);

    char names_length[5][50];
    for (int i = 0; i < count; i++)
    {
        strcpy(names_length[i], names[i]);
    }
    sortStringsByLength(names_length, count);

    printf("\nSorted by length:\n");
    printStrings(names_length, count);

    return 0;
}