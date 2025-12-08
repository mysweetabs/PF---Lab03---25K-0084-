#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number_of_elements;
    int *numbers;
    int sum = 0;
    float average;

    printf("How many elements do you want to enter? ");
    scanf("%d", &number_of_elements);

    numbers = (int *)malloc(number_of_elements * sizeof(int));

    if (numbers == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d elements:\n", number_of_elements);
    for (int i = 0; i < number_of_elements; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &numbers[i]);
        sum += numbers[i];
    }

    average = (float)sum / number_of_elements;

    printf("\nSum: %d\n", sum);
    printf("Average: %.2f\n", average);

    free(numbers);
    numbers = NULL;

    return 0;
}