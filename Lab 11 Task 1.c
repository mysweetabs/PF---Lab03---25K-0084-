#include <stdio.h>

int sumOfDigits(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return (n % 10) + sumOfDigits(n / 10);
}

int main()
{
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    int result = sumOfDigits(num);
    printf("Sum of digits of %d is: %d\n", num, result);

    printf("\nTesting with more examples:\n");
    printf("Sum of digits of 123: %d\n", sumOfDigits(123));
    printf("Sum of digits of 456: %d\n", sumOfDigits(456));
    printf("Sum of digits of 9999: %d\n", sumOfDigits(9999));

    return 0;
}