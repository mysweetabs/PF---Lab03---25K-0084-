#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_MEMBERS 50
#define MAX_BORROWED 3

typedef struct
{
    char title[100];
    char author[50];
    char ISBN[20];
    int publicationYear;
    int available;
} Book;

typedef struct
{
    int memberID;
    char name[50];
    char contact[20];
    int borrowedBooks[MAX_BORROWED];
    int borrowedCount;
} Member;

Book books[MAX_BOOKS];
Member members[MAX_MEMBERS];
int bookCount = 0;
int memberCount = 0;

void saveData()
{
    FILE *fb = fopen("books.dat", "w");
    FILE *fm = fopen("members.dat", "w");

    fprintf(fb, "%d\n", bookCount);
    for (int i = 0; i < bookCount; i++)
    {
        fprintf(fb, "%s\n%s\n%s\n%d\n%d\n",
                books[i].title, books[i].author, books[i].ISBN,
                books[i].publicationYear, books[i].available);
    }

    fprintf(fm, "%d\n", memberCount);
    for (int i = 0; i < memberCount; i++)
    {
        fprintf(fm, "%d\n%s\n%s\n%d\n",
                members[i].memberID, members[i].name,
                members[i].contact, members[i].borrowedCount);
        for (int j = 0; j < members[i].borrowedCount; j++)
        {
            fprintf(fm, "%d ", members[i].borrowedBooks[j]);
        }
        fprintf(fm, "\n");
    }

    fclose(fb);
    fclose(fm);
    printf("Data saved successfully.\n");
}

void loadData()
{
    FILE *fb = fopen("books.dat", "r");
    FILE *fm = fopen("members.dat", "r");

    if (fb == NULL || fm == NULL)
    {
        printf("No previous data found.\n");
        if (fb)
            fclose(fb);
        if (fm)
            fclose(fm);
        return;
    }

    fscanf(fb, "%d\n", &bookCount);
    for (int i = 0; i < bookCount; i++)
    {
        fgets(books[i].title, sizeof(books[i].title), fb);
        books[i].title[strlen(books[i].title) - 1] = '\0';
        fgets(books[i].author, sizeof(books[i].author), fb);
        books[i].author[strlen(books[i].author) - 1] = '\0';
        fgets(books[i].ISBN, sizeof(books[i].ISBN), fb);
        books[i].ISBN[strlen(books[i].ISBN) - 1] = '\0';
        fscanf(fb, "%d\n%d\n", &books[i].publicationYear, &books[i].available);
    }

    fscanf(fm, "%d\n", &memberCount);
    for (int i = 0; i < memberCount; i++)
    {
        fscanf(fm, "%d\n", &members[i].memberID);
        fgets(members[i].name, sizeof(members[i].name), fm);
        members[i].name[strlen(members[i].name) - 1] = '\0';
        fgets(members[i].contact, sizeof(members[i].contact), fm);
        members[i].contact[strlen(members[i].contact) - 1] = '\0';
        fscanf(fm, "%d\n", &members[i].borrowedCount);
        for (int j = 0; j < members[i].borrowedCount; j++)
        {
            fscanf(fm, "%d ", &members[i].borrowedBooks[j]);
        }
        fscanf(fm, "\n");
    }

    fclose(fb);
    fclose(fm);
    printf("Data loaded successfully.\n");
}

void addBook()
{
    printf("\n--- Add New Book ---\n");
    getchar();

    printf("Enter title: ");
    fgets(books[bookCount].title, sizeof(books[bookCount].title), stdin);
    books[bookCount].title[strlen(books[bookCount].title) - 1] = '\0';

    printf("Enter author: ");
    fgets(books[bookCount].author, sizeof(books[bookCount].author), stdin);
    books[bookCount].author[strlen(books[bookCount].author) - 1] = '\0';

    printf("Enter ISBN: ");
    fgets(books[bookCount].ISBN, sizeof(books[bookCount].ISBN), stdin);
    books[bookCount].ISBN[strlen(books[bookCount].ISBN) - 1] = '\0';

    printf("Enter publication year: ");
    scanf("%d", &books[bookCount].publicationYear);

    books[bookCount].available = 1;
    bookCount++;
    printf("Book added successfully.\n");
}

void addMember()
{
    printf("\n--- Add New Member ---\n");
    getchar();

    members[memberCount].memberID = memberCount + 1;

    printf("Enter name: ");
    fgets(members[memberCount].name, sizeof(members[memberCount].name), stdin);
    members[memberCount].name[strlen(members[memberCount].name) - 1] = '\0';

    printf("Enter contact: ");
    fgets(members[memberCount].contact, sizeof(members[memberCount].contact), stdin);
    members[memberCount].contact[strlen(members[memberCount].contact) - 1] = '\0';

    members[memberCount].borrowedCount = 0;
    memberCount++;
    printf("Member added with ID: %d\n", memberCount);
}

void issueBook()
{
    int memberID, bookIndex;
    char ISBN[20];

    printf("Enter member ID: ");
    scanf("%d", &memberID);

    if (memberID < 1 || memberID > memberCount)
    {
        printf("Invalid member ID.\n");
        return;
    }

    int memberIndex = memberID - 1;

    if (members[memberIndex].borrowedCount >= MAX_BORROWED)
    {
        printf("Member has reached maximum borrowing limit.\n");
        return;
    }

    getchar();
    printf("Enter ISBN: ");
    fgets(ISBN, sizeof(ISBN), stdin);
    ISBN[strlen(ISBN) - 1] = '\0';

    bookIndex = -1;
    for (int i = 0; i < bookCount; i++)
    {
        if (strcmp(books[i].ISBN, ISBN) == 0)
        {
            bookIndex = i;
            break;
        }
    }

    if (bookIndex == -1)
    {
        printf("Book not found.\n");
        return;
    }

    if (books[bookIndex].available == 0)
    {
        printf("Book is already borrowed.\n");
        return;
    }

    books[bookIndex].available = 0;
    members[memberIndex].borrowedBooks[members[memberIndex].borrowedCount] = bookIndex;
    members[memberIndex].borrowedCount++;

    printf("Book issued successfully to %s.\n", members[memberIndex].name);
}

void returnBook()
{
    int memberID, bookIndex;
    char ISBN[20];

    printf("Enter member ID: ");
    scanf("%d", &memberID);

    if (memberID < 1 || memberID > memberCount)
    {
        printf("Invalid member ID.\n");
        return;
    }

    int memberIndex = memberID - 1;

    getchar();
    printf("Enter ISBN: ");
    fgets(ISBN, sizeof(ISBN), stdin);
    ISBN[strlen(ISBN) - 1] = '\0';

    bookIndex = -1;
    for (int i = 0; i < bookCount; i++)
    {
        if (strcmp(books[i].ISBN, ISBN) == 0)
        {
            bookIndex = i;
            break;
        }
    }

    if (bookIndex == -1)
    {
        printf("Book not found.\n");
        return;
    }

    int found = -1;
    for (int i = 0; i < members[memberIndex].borrowedCount; i++)
    {
        if (members[memberIndex].borrowedBooks[i] == bookIndex)
        {
            found = i;
            break;
        }
    }

    if (found == -1)
    {
        printf("This member has not borrowed this book.\n");
        return;
    }

    books[bookIndex].available = 1;

    for (int i = found; i < members[memberIndex].borrowedCount - 1; i++)
    {
        members[memberIndex].borrowedBooks[i] = members[memberIndex].borrowedBooks[i + 1];
    }
    members[memberIndex].borrowedCount--;

    printf("Book returned successfully.\n");
}

void searchByAuthor()
{
    char author[50];
    int found = 0;

    getchar();
    printf("Enter author name: ");
    fgets(author, sizeof(author), stdin);
    author[strlen(author) - 1] = '\0';

    printf("\n--- Books by %s ---\n", author);
    for (int i = 0; i < bookCount; i++)
    {
        if (strstr(books[i].author, author) != NULL)
        {
            printf("Title: %s\n", books[i].title);
            printf("ISBN: %s\n", books[i].ISBN);
            printf("Year: %d\n", books[i].publicationYear);
            printf("Status: %s\n\n", books[i].available ? "Available" : "Borrowed");
            found = 1;
        }
    }

    if (!found)
    {
        printf("No books found.\n");
    }
}

void searchByTitle()
{
    char title[100];
    int found = 0;

    getchar();
    printf("Enter title: ");
    fgets(title, sizeof(title), stdin);
    title[strlen(title) - 1] = '\0';

    printf("\n--- Search Results ---\n");
    for (int i = 0; i < bookCount; i++)
    {
        if (strstr(books[i].title, title) != NULL)
        {
            printf("Title: %s\n", books[i].title);
            printf("Author: %s\n", books[i].author);
            printf("ISBN: %s\n", books[i].ISBN);
            printf("Year: %d\n", books[i].publicationYear);
            printf("Status: %s\n\n", books[i].available ? "Available" : "Borrowed");
            found = 1;
        }
    }

    if (!found)
    {
        printf("No books found.\n");
    }
}

void displayBorrowedBooks()
{
    int memberID;

    printf("Enter member ID: ");
    scanf("%d", &memberID);

    if (memberID < 1 || memberID > memberCount)
    {
        printf("Invalid member ID.\n");
        return;
    }

    int memberIndex = memberID - 1;

    printf("\n--- Books borrowed by %s ---\n", members[memberIndex].name);
    if (members[memberIndex].borrowedCount == 0)
    {
        printf("No books borrowed.\n");
        return;
    }

    for (int i = 0; i < members[memberIndex].borrowedCount; i++)
    {
        int bookIndex = members[memberIndex].borrowedBooks[i];
        printf("%d. %s by %s (ISBN: %s)\n", i + 1,
               books[bookIndex].title, books[bookIndex].author,
               books[bookIndex].ISBN);
    }
}

int main()
{
    int choice;

    loadData();

    while (1)
    {
        printf("\n=== Library Management System ===\n");
        printf("1. Add new book\n");
        printf("2. Add new member\n");
        printf("3. Issue book\n");
        printf("4. Return book\n");
        printf("5. Search by author\n");
        printf("6. Search by title\n");
        printf("7. Display borrowed books by member\n");
        printf("8. Save and exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            addBook();
        }
        else if (choice == 2)
        {
            addMember();
        }
        else if (choice == 3)
        {
            issueBook();
        }
        else if (choice == 4)
        {
            returnBook();
        }
        else if (choice == 5)
        {
            searchByAuthor();
        }
        else if (choice == 6)
        {
            searchByTitle();
        }
        else if (choice == 7)
        {
            displayBorrowedBooks();
        }
        else if (choice == 8)
        {
            saveData();
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