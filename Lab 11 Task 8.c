#include <stdio.h>

typedef struct
{
    int row;
    int column;
} Position;

Position path[100];
int pathLength = 0;

int solveMaze(int maze[][5], int n, int m, int row, int col, int visited[][5])
{
    if (row < 0 || row >= n || col < 0 || col >= m)
    {
        return 0;
    }

    if (maze[row][col] == 1 || visited[row][col] == 1)
    {
        return 0;
    }

    visited[row][col] = 1;
    path[pathLength].row = row;
    path[pathLength].column = col;
    pathLength++;

    if (row == n - 1 && col == m - 1)
    {
        return 1;
    }

    if (solveMaze(maze, n, m, row - 1, col, visited))
        return 1;
    if (solveMaze(maze, n, m, row + 1, col, visited))
        return 1;
    if (solveMaze(maze, n, m, row, col - 1, visited))
        return 1;
    if (solveMaze(maze, n, m, row, col + 1, visited))
        return 1;

    pathLength--;
    return 0;
}

void displayMaze(int maze[][5], int n, int m)
{
    printf("\nMaze (0 = path, 1 = wall):\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int maze[5][5] = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 0, 1, 0}};

    int visited[5][5] = {0};
    int n = 5, m = 5;

    displayMaze(maze, n, m);

    printf("\nSolving maze from (0,0) to (%d,%d)...\n", n - 1, m - 1);

    if (solveMaze(maze, n, m, 0, 0, visited))
    {
        printf("\nPath found!\n");
        printf("Path coordinates:\n");
        for (int i = 0; i < pathLength; i++)
        {
            printf("(%d, %d)", path[i].row, path[i].column);
            if (i < pathLength - 1)
                printf(" -> ");
        }
        printf("\n\nTotal steps: %d\n", pathLength);
    }
    else
    {
        printf("\nNo path exists.\n");
    }

    return 0;
}