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

    printf("Enter Number Of Students You Want To Add: ");
    scanf("%d", &n);
    while (getchar() != '\n')
        ;
    if (n + sr_no > 100)
    {
        printf("Only %d Entries Possible.\n", 100 - sr_no);
        return;
    }
    fp = fopen("students.txt", "a");
    if (fp == NULL)
    {
        printf("File Opening Error!");
        return;
    }
    printf("\nEnter Student Details\n");
    printf("Instead Of Spaces Use _ in Names\n");

    for (int i = 1; i <= n; i++)
    {
        printf("Enter Name Of Student%d: ", i);
        fgets(s[sr_no].name, 50, stdin);
        s[sr_no].name[strcspn(s[sr_no].name, "\n")] = '\0';
        printf("Enter Roll Of Student%d: ", i);
        scanf("%d", &s[sr_no].roll);
        printf("Enter Percentage Of Student%d: ", i);
        scanf("%f", &s[sr_no].per);
        while (getchar() != '\n')
            ;

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
        printf("File Not found");
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

    int i = 0;
    int roll;
    printf("Enter Roll Number To Search: ");
    scanf("%d", &roll);
    FILE *fp;
    fp = fopen("students.txt", "r");
    if (fp == NULL)
    {
        printf("File Not Found\n");
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
    printf("No Such Record\n");
    fclose(fp);
}
void updateStudent()
{
    int roll;
    int found = 0;
    printf("\nEnter Roll Number Of Student: ");
    scanf("%d", &roll);
    FILE *fp;
    FILE *fq;
    fp = fopen("students.txt", "r");
    if (fp == NULL)
    {
        printf("File Not Found");
        return;
    }
    fq = fopen("temp.txt", "w");

    if (fq == NULL)
    {
        printf("Unable To Create Temporary File.\n");
        fclose(fp);
        return;
    }
    int i = 0;
    while (i < 100 && fscanf(fp, "%s %d %f",
                             s[i].name,
                             &s[i].roll,
                             &s[i].per) == 3)
    {
        if (s[i].roll == roll)
        {
            found = 1;
            printf("\nStudent Found Enter New Details\n");
            printf("----------------------------------\n");

            printf("Enter New Roll Number: ");
            scanf("%d", &s[i].roll);
            printf("Enter New Percentage: ");
            scanf("%f", &s[i].per);
            printf("Use _ Instead Of Spaces in New Name:\n");
            while (getchar() != '\n')
                ;
            printf("Enter New Name:");
            fgets(s[i].name, 50, stdin);
            s[i].name[strcspn(s[i].name, "\n")] = '\0';
            fprintf(fq, "%-20s\t %-10d\t %-10.2f\n",
                    s[i].name,
                    s[i].roll,
                    s[i].per);
        }
        else
        {
            fprintf(fq, "%-20s\t %-10d\t %-10.2f\n",
                    s[i].name,
                    s[i].roll,
                    s[i].per);
        }

        i++;
    }
    fclose(fp);
    fclose(fq);
    if (found)
    {
        if (remove("students.txt") == 0)
        {
            if (rename("temp.txt", "students.txt") == 0)
            {
                printf("Student Updated Successfully.\n");
            }
            else
            {
                printf("Error Renaming File.\n");
            }
        }
        else
        {
            printf("Error Deleting Original File.\n");
        }
    }
    else
    {
        remove("temp.txt");
        printf("Student Not Found.\n");
    }
}
void deleteStudent()
{
int roll;
    int found = 0;
    printf("\nEnter Roll Number Of Student: ");
    scanf("%d", &roll);
    FILE *fp;
    FILE *fq;
    fp = fopen("students.txt", "r");
    if (fp == NULL)
    {
        printf("File Not Found");
        return;
    }
    fq = fopen("temp.txt", "w");

    if (fq == NULL)
    {
        printf("Unable To Create Temporary File.\n");
        fclose(fp);
        return;
    }
    int i = 0;
    while (i < 100 && fscanf(fp, "%s %d %f",
                             s[i].name,
                             &s[i].roll,
                             &s[i].per) == 3)
    {
        if (s[i].roll == roll)
        {
            found = 1;
        
        }
        else
        {
            fprintf(fq, "%-20s\t %-10d\t %-10.2f\n",
                    s[i].name,
                    s[i].roll,
                    s[i].per);
        }

        i++;
    }
    fclose(fp);
    fclose(fq);
    if (found)
    {
        if (remove("students.txt") == 0)
        {
            if (rename("temp.txt", "students.txt") == 0)
            {
                printf("Student Deleted Successfully.\n");
            }
            else
            {
                printf("Error Renaming File.\n");
            }
        }
        else
        {
            printf("Error Deleting Original File.\n");
        }
    }
    else
    {
        remove("temp.txt");
        printf("Student Not Found.\n");
    }}

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
        printf("\n6. Exit");

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
            return 0;

        default:
            printf("\nInvalid choice");
        }

        printf("\nDo you want to perform another operation? (y/n): ");
        scanf(" %c", &ch);
    } while (ch == 'y' || ch == 'Y');

    return 0;
}