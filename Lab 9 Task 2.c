#include <stdio.h>
#include <stdlib.h>

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return b != 0 ? a / b : 0; }

int chainCalculator(int start, int *values, int n, int (**ops)(int, int))
{
    int result = start;
    for (int i = 0; i < n; i++)
    {
        result = ops[i](result, values[i]);
    }
    return result;
}

int main()
{
    int values[] = {5, 3, 2};
    int (**operations)(int, int) = malloc(3 * sizeof(int (*)(int, int)));

    operations[0] = add;
    operations[1] = multiply;
    operations[2] = subtract;

    int result = chainCalculator(10, values, 3, operations);
    printf("Start: 10\n");
    printf("OP1: 10 + 5 = 15\n");
    printf("OP2: 15 * 3 = 45\n");
    printf("OP3: 45 - 2 = 43\n");
    printf("Final result: %d\n", result);

    free(operations);
    return 0;
}