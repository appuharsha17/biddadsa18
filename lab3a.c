#include <stdio.h>

struct Student {
    char name[30];
    int Usn;
    int marks[3];
    float avg;
};

int main() {
    int n, sum;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student stu[n];

    printf("Enter student details:\n");
    for (int i = 0; i < n; i++) {
        printf("Name: ");
        scanf("%s", stu[i].name);
        printf("USN: ");
        scanf("%d", &stu[i].Usn);
        printf("Enter the marks in 3 subjects: ");
        sum = 0;
        for (int j = 0; j < 3; j++) {
            scanf("%d", &stu[i].marks[j]);
            sum += stu[i].marks[j];
        }
        stu[i].avg = (float)sum / 3;
    }

    // Sorting students based on average marks in descending order
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (stu[i].avg < stu[j].avg) {
                struct Student temp = stu[i];
                stu[i] = stu[j];
                stu[j] = temp;
            }
        }
    }

    printf("\nThe details of students in descending order of their total marks:\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s\n", stu[i].name);
        printf("USN: %d\n", stu[i].Usn);
        printf("Marks:\n");
        for (int j = 0; j < 3; j++) {
            printf("%d\n", stu[i].marks[j]);
        }
        printf("Average: %.2f\n", stu[i].avg);
    }

    return 0;
}