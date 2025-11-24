#include <stdio.h>

int *(*stateA(int *num))(int *);
int *(*stateB(int *num))(int *);
int *(*stateC(int *num))(int *);
int *(*stateD(int *num))(int *);

int *(*stateA(int *num))(int *)
{
    printf("State A: Enter number: ");
    scanf("%d", num);
    if (*num > 5)
    {
        printf("Number > 5, going to State B\n");
        return stateB;
    }
    else
    {
        printf("Number <= 5, going to State C\n");
        return stateC;
    }
}

int *(*stateB(int *num))(int *)
{
    printf("State B: Multiplying by 2\n");
    *num *= 2;
    printf("Result: %d, going to State D\n", *num);
    return stateD;
}

int *(*stateC(int *num))(int *)
{
    printf("State C: Adding 10\n");
    *num += 10;
    printf("Result: %d, going to State D\n", *num);
    return stateD;
}

int *(*stateD(int *num))(int *)
{
    printf("State D: Final result = %d\n", *num);
    printf("Game over\n");
    return NULL;
}

int main()
{
    int num;
    int *(*currentState)(int *) = stateA;

    printf("=== Pointer State Machine ===\n\n");

    while (currentState != NULL)
    {
        currentState = currentState(&num);
        printf("\n");
    }

    return 0;
}