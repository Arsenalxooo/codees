#include <stdio.h>
#include <string.h>
#define SIZE 100

typedef struct {
    int roll;
    char name[50];
    float marks;
} Student;

Student students[SIZE];
int count = 0;

void insertStudent() {
    if (count == SIZE) {
        printf("Database full!\n");
        return;
    }
    printf("Enter Roll No: ");
    scanf("%d", &students[count].roll);
    printf("Enter Name: ");
    scanf(" %[^\n]", students[count].name);
    printf("Enter Marks: ");
    scanf("%f", &students[count].marks);
    count++;
    printf("Student inserted successfully!\n");
}

void displayStudents() {
    if (count == 0) {
        printf("No students!\n");
        return;
    }
    printf("\n%-10s %-20s %-10s\n", "Roll No", "Name", "Marks");
    for (int i = 0; i < count; i++)
        printf("%-10d %-20s %-10.2f\n", students[i].roll, students[i].name, students[i].marks);
}

void deleteStudent() {
    int roll, found = 0;
    printf("Enter Roll No to delete: ");
    scanf("%d", &roll);
    for (int i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            for (int j = i; j < count - 1; j++)
                students[j] = students[j + 1];
            count--;
            found = 1;
            printf("Student deleted!\n");
            break;
        }
    }
    if (!found)
        printf("Student not found!\n");
}

void sortStudents() {
    for (int i = 0; i < count - 1; i++)
        for (int j = i + 1; j < count; j++)
            if (students[i].roll > students[j].roll) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
    printf("Sorted by Roll No!\n");
}

int main() {
    int choice;
    while (1) {
        printf("\n1.Insert\n2.Display\n3.Delete\n4.Sort\n5.Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: insertStudent(); break;
            case 2: displayStudents(); break;
            case 3: deleteStudent(); break;
            case 4: sortStudents(); break;
            case 5: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}

