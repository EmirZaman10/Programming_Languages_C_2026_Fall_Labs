/*
 * week4_1_dynamic_array.c
 * Author: [Emir Zaman]
 * Student ID: [251ADB048]
 * Description:
 *   Demonstrates creation and usage of a dynamic array using malloc.
 *   Allocate memory for n integers, read them from the user,
 *   print their sum and average, and then free the memory.
 *
 *   Output must match the format in the Week 4 instructions exactly
 *   (it is checked by the autograder).
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, i;
    int sum = 0;

    printf("Enter number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("\nInvalid size.\n");
        return 1;
    }


    int *arr = malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("\nMemory allocation failed.\n");
        return 1;
    }

    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            free(arr);
            printf("\nInvalid input.\n");
            return 1;
        }
        sum += arr[i];
    }

    printf("Sum = %d\n", sum);
    printf("Average = %.2f\n", (float)sum / n);

    free(arr);
    return 0;
}
