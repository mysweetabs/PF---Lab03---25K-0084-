#include <stdio.h>
#include <string.h>

typedef struct
{
    char flightNumber[10];
    char departureCity[50];
    char destinationCity[50];
    char date[15];
    int availableSeats;
} Flight;

void displayFlight(Flight f)
{
    printf("\n--- Flight Details ---\n");
    printf("Flight Number: %s\n", f.flightNumber);
    printf("From: %s\n", f.departureCity);
    printf("To: %s\n", f.destinationCity);
    printf("Date: %s\n", f.date);
    printf("Available Seats: %d\n", f.availableSeats);
}

int bookSeat(Flight *f)
{
    if (f->availableSeats > 0)
    {
        f->availableSeats--;
        printf("Seat booked successfully!\n");
        printf("Remaining seats: %d\n", f->availableSeats);
        return 1;
    }
    else
    {
        printf("Sorry, no seats available.\n");
        return 0;
    }
}

int main()
{
    Flight flights[3];

    strcpy(flights[0].flightNumber, "AA101");
    strcpy(flights[0].departureCity, "New York");
    strcpy(flights[0].destinationCity, "London");
    strcpy(flights[0].date, "2024-12-25");
    flights[0].availableSeats = 50;

    strcpy(flights[1].flightNumber, "BA202");
    strcpy(flights[1].departureCity, "Paris");
    strcpy(flights[1].destinationCity, "Tokyo");
    strcpy(flights[1].date, "2024-12-26");
    flights[1].availableSeats = 30;

    strcpy(flights[2].flightNumber, "CA303");
    strcpy(flights[2].departureCity, "Dubai");
    strcpy(flights[2].destinationCity, "Sydney");
    strcpy(flights[2].date, "2024-12-27");
    flights[2].availableSeats = 0;

    int choice;

    while (1)
    {
        printf("\n=== Flight Management System ===\n");
        printf("1. Display all flights\n");
        printf("2. Book a seat\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            for (int i = 0; i < 3; i++)
            {
                displayFlight(flights[i]);
            }
        }
        else if (choice == 2)
        {
            int flightNum;
            printf("\nAvailable flights:\n");
            for (int i = 0; i < 3; i++)
            {
                printf("%d. %s (%s to %s)\n", i + 1, flights[i].flightNumber,
                       flights[i].departureCity, flights[i].destinationCity);
            }
            printf("Select flight (1-3): ");
            scanf("%d", &flightNum);

            if (flightNum >= 1 && flightNum <= 3)
            {
                bookSeat(&flights[flightNum - 1]);
            }
            else
            {
                printf("Invalid flight selection.\n");
            }
        }
        else if (choice == 3)
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