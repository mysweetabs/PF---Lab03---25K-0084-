#include <stdio.h>
#include <string.h>

typedef struct
{
    int day;
    int month;
    int year;
} Date;

typedef struct
{
    int houseNumber;
    char street[50];
    char city[50];
    char postalCode[10];
} Address;

typedef struct
{
    char courseCode[10];
    char courseName[50];
    int creditHours;
    float grade;
} Course;

typedef struct
{
    char studentID[15];
    char name[50];
    Date dateOfBirth;
    Address address;
    Course courses[5];
    int courseCount;
    float cgpa;
} Student;

Student students[100];
int studentCount = 0;

void addStudent()
{
    printf("\n--- Add New Student ---\n");
    getchar();

    printf("Enter Student ID: ");
    fgets(students[studentCount].studentID, sizeof(students[studentCount].studentID), stdin);
    students[studentCount].studentID[strlen(students[studentCount].studentID) - 1] = '\0';

    printf("Enter Name: ");
    fgets(students[studentCount].name, sizeof(students[studentCount].name), stdin);
    students[studentCount].name[strlen(students[studentCount].name) - 1] = '\0';

    printf("Enter Date of Birth (DD MM YYYY): ");
    scanf("%d %d %d", &students[studentCount].dateOfBirth.day,
          &students[studentCount].dateOfBirth.month,
          &students[studentCount].dateOfBirth.year);

    getchar();
    printf("Enter House Number: ");
    scanf("%d", &students[studentCount].address.houseNumber);
    getchar();

    printf("Enter Street: ");
    fgets(students[studentCount].address.street, sizeof(students[studentCount].address.street), stdin);
    students[studentCount].address.street[strlen(students[studentCount].address.street) - 1] = '\0';

    printf("Enter City: ");
    fgets(students[studentCount].address.city, sizeof(students[studentCount].address.city), stdin);
    students[studentCount].address.city[strlen(students[studentCount].address.city) - 1] = '\0';

    printf("Enter Postal Code: ");
    fgets(students[studentCount].address.postalCode, sizeof(students[studentCount].address.postalCode), stdin);
    students[studentCount].address.postalCode[strlen(students[studentCount].address.postalCode) - 1] = '\0';

    students[studentCount].courseCount = 0;
    students[studentCount].cgpa = 0.0;

    studentCount++;
    printf("Student added successfully!\n");
}

void calculateCGPA(int studentIndex)
{
    float totalPoints = 0.0;
    int totalCredits = 0;

    for (int i = 0; i < students[studentIndex].courseCount; i++)
    {
        totalPoints += students[studentIndex].courses[i].grade * students[studentIndex].courses[i].creditHours;
        totalCredits += students[studentIndex].courses[i].creditHours;
    }

    if (totalCredits > 0)
    {
        students[studentIndex].cgpa = totalPoints / totalCredits;
    }
    else
    {
        students[studentIndex].cgpa = 0.0;
    }
}

void updateCGPA()
{
    char id[15];
    int found = -1;

    getchar();
    printf("Enter Student ID: ");
    fgets(id, sizeof(id), stdin);
    id[strlen(id) - 1] = '\0';

    for (int i = 0; i < studentCount; i++)
    {
        if (strcmp(students[i].studentID, id) == 0)
        {
            found = i;
            break;
        }
    }

    if (found == -1)
    {
        printf("Student not found.\n");
        return;
    }

    if (students[found].courseCount >= 5)
    {
        printf("Maximum courses already added.\n");
        return;
    }

    int courseIndex = students[found].courseCount;

    printf("Enter Course Code: ");
    fgets(students[found].courses[courseIndex].courseCode,
          sizeof(students[found].courses[courseIndex].courseCode), stdin);
    students[found].courses[courseIndex].courseCode[strlen(students[found].courses[courseIndex].courseCode) - 1] = '\0';

    printf("Enter Course Name: ");
    fgets(students[found].courses[courseIndex].courseName,
          sizeof(students[found].courses[courseIndex].courseName), stdin);
    students[found].courses[courseIndex].courseName[strlen(students[found].courses[courseIndex].courseName) - 1] = '\0';

    printf("Enter Credit Hours: ");
    scanf("%d", &students[found].courses[courseIndex].creditHours);

    printf("Enter Grade (0-4): ");
    scanf("%f", &students[found].courses[courseIndex].grade);

    students[found].courseCount++;
    calculateCGPA(found);

    printf("Course added and CGPA updated to: %.2f\n", students[found].cgpa);
}

void searchByID()
{
    char id[15];
    int found = -1;

    getchar();
    printf("Enter Student ID: ");
    fgets(id, sizeof(id), stdin);
    id[strlen(id) - 1] = '\0';

    for (int i = 0; i < studentCount; i++)
    {
        if (strcmp(students[i].studentID, id) == 0)
        {
            found = i;
            break;
        }
    }

    if (found == -1)
    {
        printf("Student not found.\n");
        return;
    }

    printf("\n--- Student Details ---\n");
    printf("ID: %s\n", students[found].studentID);
    printf("Name: %s\n", students[found].name);
    printf("DOB: %02d/%02d/%d\n", students[found].dateOfBirth.day,
           students[found].dateOfBirth.month, students[found].dateOfBirth.year);
    printf("Address: %d %s, %s, %s\n", students[found].address.houseNumber,
           students[found].address.street, students[found].address.city,
           students[found].address.postalCode);
    printf("CGPA: %.2f\n", students[found].cgpa);
    printf("Courses:\n");
    for (int i = 0; i < students[found].courseCount; i++)
    {
        printf("  %s - %s (%d credits, Grade: %.1f)\n",
               students[found].courses[i].courseCode,
               students[found].courses[i].courseName,
               students[found].courses[i].creditHours,
               students[found].courses[i].grade);
    }
}

void displayHighCGPA()
{
    float threshold;
    int found = 0;

    printf("Enter CGPA threshold: ");
    scanf("%f", &threshold);

    printf("\n--- Students with CGPA above %.2f ---\n", threshold);
    for (int i = 0; i < studentCount; i++)
    {
        if (students[i].cgpa > threshold)
        {
            printf("ID: %s, Name: %s, CGPA: %.2f\n",
                   students[i].studentID, students[i].name, students[i].cgpa);
            found = 1;
        }
    }

    if (!found)
    {
        printf("No students found.\n");
    }
}

void findOldestYoungest()
{
    if (studentCount == 0)
    {
        printf("No students in database.\n");
        return;
    }

    int oldest = 0, youngest = 0;

    for (int i = 1; i < studentCount; i++)
    {
        if (students[i].dateOfBirth.year < students[oldest].dateOfBirth.year ||
            (students[i].dateOfBirth.year == students[oldest].dateOfBirth.year &&
             students[i].dateOfBirth.month < students[oldest].dateOfBirth.month) ||
            (students[i].dateOfBirth.year == students[oldest].dateOfBirth.year &&
             students[i].dateOfBirth.month == students[oldest].dateOfBirth.month &&
             students[i].dateOfBirth.day < students[oldest].dateOfBirth.day))
        {
            oldest = i;
        }

        if (students[i].dateOfBirth.year > students[youngest].dateOfBirth.year ||
            (students[i].dateOfBirth.year == students[youngest].dateOfBirth.year &&
             students[i].dateOfBirth.month > students[youngest].dateOfBirth.month) ||
            (students[i].dateOfBirth.year == students[youngest].dateOfBirth.year &&
             students[i].dateOfBirth.month == students[youngest].dateOfBirth.month &&
             students[i].dateOfBirth.day > students[youngest].dateOfBirth.day))
        {
            youngest = i;
        }
    }

    printf("\nOldest Student: %s (DOB: %02d/%02d/%d)\n",
           students[oldest].name, students[oldest].dateOfBirth.day,
           students[oldest].dateOfBirth.month, students[oldest].dateOfBirth.year);

    printf("Youngest Student: %s (DOB: %02d/%02d/%d)\n",
           students[youngest].name, students[youngest].dateOfBirth.day,
           students[youngest].dateOfBirth.month, students[youngest].dateOfBirth.year);
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n=== Student Management System ===\n");
        printf("1. Add new student\n");
        printf("2. Add course and update CGPA\n");
        printf("3. Search student by ID\n");
        printf("4. Display students with CGPA above threshold\n");
        printf("5. Find oldest and youngest student\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            addStudent();
        }
        else if (choice == 2)
        {
            updateCGPA();
        }
        else if (choice == 3)
        {
            searchByID();
        }
        else if (choice == 4)
        {
            displayHighCGPA();
        }
        else if (choice == 5)
        {
            findOldestYoungest();
        }
        else if (choice == 6)
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