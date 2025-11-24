#include <stdio.h>
#include <string.h>

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int mul(int a, int b)
{
    return a * b;
}

int divi(int a, int b)
{
    return b != 0 ? a / b : 0;
}

int (*processCommand(char *cmd))(int, int)
{
    if (cmd == NULL)
        return NULL;

    if (strcmp(cmd, "add") == 0)
        return add;
    if (strcmp(cmd, "sub") == 0)
        return sub;
    if (strcmp(cmd, "mul") == 0)
        return mul;
    if (strcmp(cmd, "div") == 0)
        return divi;

    return NULL;
}

int main()
{
    char command[10];
    int a, b;

    printf("Command processor\n");
    printf("Available commands: add, sub, mul, div\n\n");

    printf("Enter command: ");
    scanf("%s", command);

    int (*operation)(int, int) = processCommand(command);

    if (operation == NULL)
    {
        printf("Invalid command\n");
        return 1;
    }

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    int result = operation(a, b);
    printf("Result: %d\n", result);

    printf("\nTesting all operations:\n");
    printf("10 + 5 = %d\n", processCommand("add")(10, 5));
    printf("10 - 5 = %d\n", processCommand("sub")(10, 5));
    printf("10 * 5 = %d\n", processCommand("mul")(10, 5));
    printf("10 / 5 = %d\n", processCommand("div")(10, 5));

    return 0;
}