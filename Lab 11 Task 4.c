#include <stdio.h>
#include <string.h>

typedef struct
{
    char title[100];
    char genre[50];
    char director[50];
    int releaseYear;
    float rating;
} Movie;

Movie movies[100];
int movieCount = 0;

void addMovie()
{
    printf("\n--- Add New Movie ---\n");
    getchar();

    printf("Enter title: ");
    fgets(movies[movieCount].title, sizeof(movies[movieCount].title), stdin);
    movies[movieCount].title[strlen(movies[movieCount].title) - 1] = '\0';

    printf("Enter genre: ");
    fgets(movies[movieCount].genre, sizeof(movies[movieCount].genre), stdin);
    movies[movieCount].genre[strlen(movies[movieCount].genre) - 1] = '\0';

    printf("Enter director: ");
    fgets(movies[movieCount].director, sizeof(movies[movieCount].director), stdin);
    movies[movieCount].director[strlen(movies[movieCount].director) - 1] = '\0';

    printf("Enter release year: ");
    scanf("%d", &movies[movieCount].releaseYear);

    printf("Enter rating (0-10): ");
    scanf("%f", &movies[movieCount].rating);

    movieCount++;
    printf("Movie added successfully!\n");
}

void searchByGenre()
{
    char searchGenre[50];
    int found = 0;

    getchar();
    printf("\nEnter genre to search: ");
    fgets(searchGenre, sizeof(searchGenre), stdin);
    searchGenre[strlen(searchGenre) - 1] = '\0';

    printf("\n--- Movies in genre '%s' ---\n", searchGenre);
    for (int i = 0; i < movieCount; i++)
    {
        if (strcmp(movies[i].genre, searchGenre) == 0)
        {
            printf("\nTitle: %s\n", movies[i].title);
            printf("Director: %s\n", movies[i].director);
            printf("Release Year: %d\n", movies[i].releaseYear);
            printf("Rating: %.1f/10\n", movies[i].rating);
            found = 1;
        }
    }

    if (!found)
    {
        printf("No movies found in this genre.\n");
    }
}

void displayAllMovies()
{
    if (movieCount == 0)
    {
        printf("\nNo movies in database.\n");
        return;
    }

    printf("\n=== All Movies ===\n");
    for (int i = 0; i < movieCount; i++)
    {
        printf("\n%d. %s\n", i + 1, movies[i].title);
        printf("   Genre: %s\n", movies[i].genre);
        printf("   Director: %s\n", movies[i].director);
        printf("   Year: %d\n", movies[i].releaseYear);
        printf("   Rating: %.1f/10\n", movies[i].rating);
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n=== Movie Management System ===\n");
        printf("1. Add new movie\n");
        printf("2. Search movies by genre\n");
        printf("3. Display all movies\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            addMovie();
        }
        else if (choice == 2)
        {
            searchByGenre();
        }
        else if (choice == 3)
        {
            displayAllMovies();
        }
        else if (choice == 4)
        {
            printf("Exiting...\n");
            break;
        }
        else
        {
            printf("Invalid choice.\n");
        }
    }

    return 0;
}