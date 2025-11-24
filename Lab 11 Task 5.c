#include <stdio.h>

typedef struct
{
    int diskNumber;
    char source;
    char destination;
} Move;

Move moves[1000];
int moveCount = 0;
static int totalMoves = 0;

void towerOfHanoi(int n, char source, char destination, char auxiliary)
{
    if (n == 1)
    {
        moves[moveCount].diskNumber = 1;
        moves[moveCount].source = source;
        moves[moveCount].destination = destination;
        moveCount++;
        totalMoves++;
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    towerOfHanoi(n - 1, source, auxiliary, destination);

    moves[moveCount].diskNumber = n;
    moves[moveCount].source = source;
    moves[moveCount].destination = destination;
    moveCount++;
    totalMoves++;
    printf("Move disk %d from %c to %c\n", n, source, destination);

    towerOfHanoi(n - 1, auxiliary, destination, source);
}

void displayMove(int moveNumber)
{
    if (moveNumber < 1 || moveNumber > moveCount)
    {
        printf("Invalid move number.\n");
        return;
    }

    printf("\nMove #%d:\n", moveNumber);
    printf("Disk: %d\n", moves[moveNumber - 1].diskNumber);
    printf("From: %c\n", moves[moveNumber - 1].source);
    printf("To: %c\n", moves[moveNumber - 1].destination);
}

int main()
{
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    printf("\n=== Solving Tower of Hanoi for %d disks ===\n\n", n);

    towerOfHanoi(n, 'A', 'C', 'B');

    printf("\n=== Summary ===\n");
    printf("Total number of moves: %d\n", totalMoves);

    int choice;
    while (1)
    {
        printf("\nEnter move number to view (0 to exit): ");
        scanf("%d", &choice);

        if (choice == 0)
        {
            break;
        }

        displayMove(choice);
    }

    return 0;
}