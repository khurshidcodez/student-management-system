#include <stdio.h>
struct student
{
    char name[50];
    int roll;
    float per;
};
void addStudent()
{
    printf("Add Student Details");
}
void displayStudent()
{
    printf("Display Student Details");
}
void searchStudent()
{
    printf("Search Student Details");
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

int main() {

    int choice;
    char ch;

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
        scanf("%d",&choice);


        switch(choice)
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
    }while(ch=='y' || ch=='Y');


    
    return 0;
}