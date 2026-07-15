#include <stdio.h>
#include <string.h>
struct student
{
    char name[50];
    int roll;
    float per;
};

struct student s[100];
int sr_no = 0;
void loadStudents()
{
    FILE *fp;

    fp = fopen("students.txt", "r");

    if (fp == NULL)
    {
        return;
    }

    while (fscanf(fp, "%s %d %f",
                  s[sr_no].name,
                  &s[sr_no].roll,
                  &s[sr_no].per) != EOF)
    {
        sr_no++;
    }

    fclose(fp);
}
void addStudent()
{
    FILE *fp;
    int n;

    printf("Enter number of students you want to add: ");
    scanf("%d", &n);
    while (getchar() != '\n');
    if (n + sr_no > 100)
    {
        printf("Only %d entries possible.", 100 - sr_no);
        return;
    }
    fp = fopen("students.txt", "a");
    if (fp == NULL)
    {
        printf("File opening error!");
        return;
    }
    printf("\nEnter Student Details\n");
    printf("Instead of Spaces Use _ in Names\n");

    for (int i = 1; i <= n; i++)
    {
        printf("Enter Name of Student%d: ", i);
        fgets(s[sr_no].name, 50, stdin);
        s[sr_no].name[strcspn(s[sr_no].name, "\n")] = '\0';
        printf("Enter Roll of Student%d: ", i);
        scanf("%d", &s[sr_no].roll);
        printf("Enter Percentage of Student%d: ", i);
        scanf("%f", &s[sr_no].per);
        while (getchar() != '\n');

        fprintf(fp, "%-20s\t %-10d\t %-10.2f\n",
                s[sr_no].name,
                s[sr_no].roll,
                s[sr_no].per);

        sr_no++;
    }
    fclose(fp);
}
void displayStudent()
{
    FILE *fp;
    fp = fopen("students.txt", "r");
    if (fp == NULL)
    {
        printf("File not found");
        return;
    }
    int i = 0;
    printf("\nName\t\tRoll\t\tPercentage\n");
    printf("-------------------------------------\n");
    while (i < 100 && fscanf(fp, "%s %d %f",
                             s[i].name,
                             &s[i].roll,
                             &s[i].per) == 3)
    {
        printf("%-15s\t%-10d\t%-10.2f\n",
               s[i].name,
               s[i].roll,
               s[i].per);
        i++;
    }

    fclose(fp);
}
void searchStudent()
{

    int i=0;
    int roll;
    printf("Enter roll number to search: ");
    scanf("%d", &roll);
    FILE *fp;
    fp = fopen("students.txt", "r");
    if (fp == NULL)
    {
        printf("File not Found\n");
        return;
    }
    while (i < 100 && fscanf(fp, "%s %d %f",
                             s[i].name,
                             &s[i].roll,
                             &s[i].per) == 3)
    {
        if (s[i].roll == roll)
        {
            printf("\nName\t\tRoll\t\tPercentage\n");
            printf("-------------------------------------\n");
            printf("%-15s\t%-10d\t%-10.2f\n",
                   s[i].name,
                   s[i].roll,
                   s[i].per);
                    fclose(fp);

            return;
        }
        i++;
    } 
    printf("No such record\n");
    fclose(fp);
}
void updateStudent()
{
    printf("Update Student Details");
}
void deleteStudent()
{
    printf("Delete Student Details");
}
void sortStudent()
{
    printf("Sort Student Details");
}

int main()
{

    int choice;
    char ch;
    loadStudents();

    do
    {
        printf("\n========================");
        printf("\n Student Management System");
        printf("\n========================");

        printf("\n1. Add Student");
        printf("\n2. Display Students");
        printf("\n3. Search Student");
        printf("\n4. Update Student");
        printf("\n5. Delete Student");
        printf("\n6. Sort Students");
        printf("\n7. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addStudent();
            break;

        case 2:
            displayStudent();
            break;

        case 3:
            searchStudent();
            break;

        case 4:
            updateStudent();
            break;

        case 5:
            deleteStudent();
            break;

        case 6:
            sortStudent();
            break;

        case 7:
            return 0;

        default:
            printf("\nInvalid choice");
        }

        printf("Do you want to perform another operation? (y/n): ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');

    return 0;
}