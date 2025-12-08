#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *student_ids;
    int current_capacity = 3;
    int student_count = 0;
    char choice;
    int new_id;
    int *temp_pointer;

    student_ids = (int *)malloc(current_capacity * sizeof(int));

    if (student_ids == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter 3 student IDs:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("Student ID %d: ", i + 1);
        scanf("%d", &student_ids[i]);
        student_count++;
    }

    while (1)
    {
        printf("\nDo you want to add more students? (y/n): ");
        scanf(" %c", &choice);

        if (choice == 'n' || choice == 'N')
        {
            break;
        }

        if (choice == 'y' || choice == 'Y')
        {
            printf("Enter new student ID: ");
            scanf("%d", &new_id);

            current_capacity++;
            temp_pointer = (int *)realloc(student_ids, current_capacity * sizeof(int));

            if (temp_pointer == NULL)
            {
                printf("Memory reallocation failed!\n");
                free(student_ids);
                student_ids = NULL;
                return 1;
            }

            student_ids = temp_pointer;
            student_ids[student_count] = new_id;
            student_count++;

            printf("Student added successfully!\n");
        }
    }

    printf("\nAll Student IDs:\n");
    for (int i = 0; i < student_count; i++)
    {
        printf("Student %d: %d\n", i + 1, student_ids[i]);
    }

    free(student_ids);
    student_ids = NULL;

    return 0;
}