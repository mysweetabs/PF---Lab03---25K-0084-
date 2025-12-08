#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *pointer_array[5];
    int allocated_count = 0;
    int freed_count = 0;
    int leaked_count = 0;

    printf("=== Memory Leak Detector Simulation ===\n\n");

    printf("Allocating memory for 5 integer pointers...\n");
    for (int i = 0; i < 5; i++)
    {
        pointer_array[i] = (int *)malloc(sizeof(int));

        if (pointer_array[i] != NULL)
        {
            *pointer_array[i] = (i + 1) * 10;
            allocated_count++;
            printf("Pointer %d: Allocated at address %p with value %d\n",
                   i + 1, (void *)pointer_array[i], *pointer_array[i]);
        }
    }

    printf("\nIntentionally losing some pointers (creating memory leaks)...\n");
    pointer_array[1] = NULL;
    pointer_array[3] = NULL;
    printf("Lost pointer 2 and pointer 4\n");

    printf("\nFreeing accessible pointers...\n");
    for (int i = 0; i < 5; i++)
    {
        if (pointer_array[i] != NULL)
        {
            printf("Pointer %d: Freed at address %p\n", i + 1, (void *)pointer_array[i]);
            free(pointer_array[i]);
            pointer_array[i] = NULL;
            freed_count++;
        }
        else
        {
            printf("Pointer %d: LEAKED (cannot be freed)\n", i + 1);
            leaked_count++;
        }
    }

    printf("\n=== Memory Report ===\n");
    printf("Total allocated: %d\n", allocated_count);
    printf("Successfully freed: %d\n", freed_count);
    printf("Memory leaks: %d\n", leaked_count);

    if (leaked_count > 0)
    {
        printf("\nWARNING: Memory leaks detected!\n");
        printf("The following allocations were leaked:\n");
        if (leaked_count >= 1)
            printf("  - Pointer 2\n");
        if (leaked_count >= 2)
            printf("  - Pointer 4\n");
    }
    else
    {
        printf("\nNo memory leaks detected. All memory properly freed!\n");
    }

    return 0;
}