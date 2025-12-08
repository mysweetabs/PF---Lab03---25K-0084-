#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int degree;
    double *coefficients;
    double x_value;
    double result;
    char choice;

    printf("Enter the degree of the polynomial: ");
    scanf("%d", &degree);

    coefficients = (double *)malloc((degree + 1) * sizeof(double));

    if (coefficients == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("\nEnter coefficients from highest to lowest degree:\n");
    for (int i = 0; i <= degree; i++)
    {
        printf("Coefficient of x^%d: ", degree - i);
        scanf("%lf", &coefficients[i]);
    }

    printf("\nPolynomial: P(x) = ");
    for (int i = 0; i <= degree; i++)
    {
        if (i > 0 && coefficients[i] >= 0)
        {
            printf("+ ");
        }

        if (degree - i == 0)
        {
            printf("%.2lf", coefficients[i]);
        }
        else if (degree - i == 1)
        {
            printf("%.2lfx ", coefficients[i]);
        }
        else
        {
            printf("%.2lfx^%d ", coefficients[i], degree - i);
        }
    }
    printf("\n");

    while (1)
    {
        printf("\nEnter x value to evaluate: ");
        scanf("%lf", &x_value);

        result = 0;
        for (int i = 0; i <= degree; i++)
        {
            result += coefficients[i] * pow(x_value, degree - i);
        }

        printf("P(%.2lf) = %.2lf\n", x_value, result);

        printf("\nDo you want to:\n");
        printf("1. Evaluate another x value (press 'e')\n");
        printf("2. Change polynomial degree (press 'c')\n");
        printf("3. Exit (press 'q')\n");
        printf("Your choice: ");
        scanf(" %c", &choice);

        if (choice == 'q' || choice == 'Q')
        {
            break;
        }
        else if (choice == 'c' || choice == 'C')
        {
            int new_degree;
            printf("\nEnter new degree: ");
            scanf("%d", &new_degree);

            coefficients = (double *)realloc(coefficients, (new_degree + 1) * sizeof(double));

            if (coefficients == NULL)
            {
                printf("Memory reallocation failed!\n");
                return 1;
            }

            degree = new_degree;

            printf("\nEnter new coefficients:\n");
            for (int i = 0; i <= degree; i++)
            {
                printf("Coefficient of x^%d: ", degree - i);
                scanf("%lf", &coefficients[i]);
            }

            printf("\nNew Polynomial: P(x) = ");
            for (int i = 0; i <= degree; i++)
            {
                if (i > 0 && coefficients[i] >= 0)
                {
                    printf("+ ");
                }

                if (degree - i == 0)
                {
                    printf("%.2lf", coefficients[i]);
                }
                else if (degree - i == 1)
                {
                    printf("%.2lfx ", coefficients[i]);
                }
                else
                {
                    printf("%.2lfx^%d ", coefficients[i], degree - i);
                }
            }
            printf("\n");
        }
    }

    free(coefficients);
    coefficients = NULL;

    return 0;
}