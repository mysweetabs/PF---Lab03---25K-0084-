#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int nextEmployeeID = 1;

typedef struct Employee
{
    int id;
    char name[50];
    char designation[50];
    float salary;
    struct Employee *manager;
    struct Employee *subordinates[10];
    int subordinateCount;
} Employee;

typedef struct
{
    char name[50];
    Employee *employees[100];
    int employeeCount;
    Employee *head;
} Department;

Department departments[10];
int deptCount = 0;

Employee *createEmployee(char *name, char *designation, float salary)
{
    Employee *emp = (Employee *)malloc(sizeof(Employee));
    emp->id = nextEmployeeID++;
    strcpy(emp->name, name);
    strcpy(emp->designation, designation);
    emp->salary = salary;
    emp->manager = NULL;
    emp->subordinateCount = 0;
    return emp;
}

void addEmployee()
{
    char name[50], designation[50], deptName[50];
    float salary;
    int deptIndex = -1;

    getchar();
    printf("Enter department name: ");
    fgets(deptName, sizeof(deptName), stdin);
    deptName[strlen(deptName) - 1] = '\0';

    for (int i = 0; i < deptCount; i++)
    {
        if (strcmp(departments[i].name, deptName) == 0)
        {
            deptIndex = i;
            break;
        }
    }

    if (deptIndex == -1)
    {
        strcpy(departments[deptCount].name, deptName);
        departments[deptCount].employeeCount = 0;
        departments[deptCount].head = NULL;
        deptIndex = deptCount;
        deptCount++;
    }

    printf("Enter name: ");
    fgets(name, sizeof(name), stdin);
    name[strlen(name) - 1] = '\0';

    printf("Enter designation: ");
    fgets(designation, sizeof(designation), stdin);
    designation[strlen(designation) - 1] = '\0';

    printf("Enter salary: ");
    scanf("%f", &salary);

    Employee *emp = createEmployee(name, designation, salary);
    departments[deptIndex].employees[departments[deptIndex].employeeCount] = emp;
    departments[deptIndex].employeeCount++;

    if (departments[deptIndex].head == NULL)
    {
        departments[deptIndex].head = emp;
    }
    else
    {
        int managerID;
        printf("Enter manager ID (0 if reporting to head): ");
        scanf("%d", &managerID);

        if (managerID == 0)
        {
            emp->manager = departments[deptIndex].head;
            departments[deptIndex].head->subordinates[departments[deptIndex].head->subordinateCount] = emp;
            departments[deptIndex].head->subordinateCount++;
        }
        else
        {
            for (int i = 0; i < departments[deptIndex].employeeCount; i++)
            {
                if (departments[deptIndex].employees[i]->id == managerID)
                {
                    emp->manager = departments[deptIndex].employees[i];
                    departments[deptIndex].employees[i]->subordinates[departments[deptIndex].employees[i]->subordinateCount] = emp;
                    departments[deptIndex].employees[i]->subordinateCount++;
                    break;
                }
            }
        }
    }

    printf("Employee added with ID: %d\n", emp->id);
}

float calculateTotalSalaryExpense(Employee *emp)
{
    if (emp == NULL)
    {
        return 0;
    }

    float total = emp->salary;

    for (int i = 0; i < emp->subordinateCount; i++)
    {
        total += calculateTotalSalaryExpense(emp->subordinates[i]);
    }

    return total;
}

void findReportingChain(Employee *emp)
{
    if (emp == NULL)
    {
        return;
    }

    printf("\n--- Reporting Chain for %s ---\n", emp->name);

    Employee *current = emp;
    int level = 0;

    while (current != NULL)
    {
        for (int i = 0; i < level; i++)
            printf("  ");
        printf("%s (%s) - $%.2f\n", current->name, current->designation, current->salary);
        current = current->manager;
        level++;
    }
}

int countLevels(Employee *emp)
{
    if (emp == NULL)
    {
        return 0;
    }

    int maxDepth = 0;
    for (int i = 0; i < emp->subordinateCount; i++)
    {
        int depth = countLevels(emp->subordinates[i]);
        if (depth > maxDepth)
        {
            maxDepth = depth;
        }
    }

    return maxDepth + 1;
}

void displaySubordinates(Employee *emp, int level)
{
    if (emp == NULL)
    {
        return;
    }

    for (int i = 0; i < level; i++)
        printf("  ");
    printf("%s (%s) - ID: %d - $%.2f\n", emp->name, emp->designation, emp->id, emp->salary);

    for (int i = 0; i < emp->subordinateCount; i++)
    {
        displaySubordinates(emp->subordinates[i], level + 1);
    }
}

void displayUnderManager()
{
    int empID, deptIndex = -1;
    Employee *emp = NULL;

    printf("Enter employee ID: ");
    scanf("%d", &empID);

    for (int i = 0; i < deptCount; i++)
    {
        for (int j = 0; j < departments[i].employeeCount; j++)
        {
            if (departments[i].employees[j]->id == empID)
            {
                emp = departments[i].employees[j];
                deptIndex = i;
                break;
            }
        }
    }

    if (emp == NULL)
    {
        printf("Employee not found.\n");
        return;
    }

    printf("\n--- All employees under %s ---\n", emp->name);
    displaySubordinates(emp, 0);
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n=== Employee Hierarchy System ===\n");
        printf("1. Add employee\n");
        printf("2. Calculate total salary expense\n");
        printf("3. Find reporting chain\n");
        printf("4. Count organization levels\n");
        printf("5. Display all under manager\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            addEmployee();
        }
        else if (choice == 2)
        {
            int empID;
            Employee *emp = NULL;

            printf("Enter employee ID: ");
            scanf("%d", &empID);

            for (int i = 0; i < deptCount; i++)
            {
                for (int j = 0; j < departments[i].employeeCount; j++)
                {
                    if (departments[i].employees[j]->id == empID)
                    {
                        emp = departments[i].employees[j];
                        break;
                    }
                }
            }

            if (emp == NULL)
            {
                printf("Employee not found.\n");
            }
            else
            {
                float total = calculateTotalSalaryExpense(emp);
                printf("Total salary expense for %s and subordinates: $%.2f\n", emp->name, total);
            }
        }
        else if (choice == 3)
        {
            int empID;
            Employee *emp = NULL;

            printf("Enter employee ID: ");
            scanf("%d", &empID);

            for (int i = 0; i < deptCount; i++)
            {
                for (int j = 0; j < departments[i].employeeCount; j++)
                {
                    if (departments[i].employees[j]->id == empID)
                    {
                        emp = departments[i].employees[j];
                        break;
                    }
                }
            }

            if (emp == NULL)
            {
                printf("Employee not found.\n");
            }
            else
            {
                findReportingChain(emp);
            }
        }
        else if (choice == 4)
        {
            if (deptCount == 0)
            {
                printf("No departments found.\n");
            }
            else
            {
                for (int i = 0; i < deptCount; i++)
                {
                    int levels = countLevels(departments[i].head);
                    printf("Department '%s' has %d levels\n", departments[i].name, levels);
                }
            }
        }
        else if (choice == 5)
        {
            displayUnderManager();
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