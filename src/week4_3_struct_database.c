/*
 * week4_3_struct_database.c
 * Author [Emir Zaman]
 * Student ID: [251ADB048]
 * Description:
 *   Simple in-memory "database" using an array of structs.
 *   Use malloc to allocate space for n Student records,
 *   read each record from the user, print them as a table,
 *   and then free the memory.
 *
 *   Output must match the format in the Week 4 instructions exactly
 *   (it is checked by the autograder).
 */

#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int id;
    float grade;
};

int main(void)
{
    int n, i;

    printf("Enter number of students: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("\nInvalid number.\n");
        return 1;
    }

    /* allocate an array of n students */
    struct Student *students = malloc(n * sizeof(struct Student));
    if (students == NULL) {
        printf("\nMemory allocation failed.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Enter data for student %d: ", i + 1);
        if (scanf("%49s %d %f", students[i].name, &students[i].id, &students[i].grade) != 3) {
            free(students);
            printf("\nInvalid input.\n");
            return 1;
        }
    }

    printf("\n");
    printf("%-6s %-11s %s\n", "ID", "Name", "Grade");
    for (i = 0; i < n; i++) {
        printf("%-6d %-11s %.1f\n", students[i].id, students[i].name, students[i].grade);
    }

    free(students); /* free memory before exit */
    return 0;
}
