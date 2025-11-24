#include <stdio.h>
#include <string.h>
#include <ctype.h>

void caesarEncrypt(char *text, int shift, char *result)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isupper(text[i]))
        {
            result[i] = ((text[i] - 'A' + shift) % 26) + 'A';
        }
        else if (islower(text[i]))
        {
            result[i] = ((text[i] - 'a' + shift) % 26) + 'a';
        }
        else
        {
            result[i] = text[i];
        }
    }
    result[strlen(text)] = '\0';
}

void caesarDecrypt(char *text, int shift, char *result)
{
    caesarEncrypt(text, 26 - shift, result);
}

int main()
{
    char text[1000];
    char result[1000];
    int choice, shift;

    printf("=== Caesar Cipher Program ===\n\n");

    printf("Menu:\n");
    printf("1 - Encrypt text and save to file\n");
    printf("2 - Decrypt text and display\n");
    printf("3 - Exit\n\n");

    printf("Enter choice: ");
    scanf("%d", &choice);
    getchar();

    if (choice == 3)
    {
        printf("Exiting...\n");
        return 0;
    }

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    text[strlen(text) - 1] = '\0';

    printf("Enter shift value: ");
    scanf("%d", &shift);

    if (choice == 1)
    {
        caesarEncrypt(text, shift, result);
        printf("\nEncrypted text: %s\n", result);

        FILE *f = fopen("encrypted.txt", "w");
        fprintf(f, "%s", result);
        fclose(f);
        printf("Encrypted text saved to encrypted.txt\n");
    }
    else if (choice == 2)
    {
        caesarDecrypt(text, shift, result);
        printf("\nDecrypted text: %s\n", result);
    }
    else
    {
        printf("Invalid choice\n");
    }

    return 0;
}