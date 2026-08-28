//Programmed By: Ramos, Nick Daniel B.

#include <stdio.h>

int main() {
    int choice;
    do {
        printf("Array Menu\n");
        printf("[1] Sum and Average\n");
        printf("[2] Largest and Smallest\n");
        printf("[3] Reverse\n");
        printf("[0] Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int num1[5], i, sum = 0;
            float ave;

            printf("Enter 5 numbers: \n");
            for (i = 0; i < 5; i++) {
                scanf("%d", &num1[i]);
            }
            for (i = 0; i < 5; i++) {
                sum += num1[i];
            }

            printf("Sum = %d\n", sum);

            ave = (float)sum / 5;
            printf("Average = %.2f\n", ave);

        } else if (choice == 2) {
            int num2[10], i;
            int max, min;

            printf("Enter 10 integers: \n");
            for (i = 0; i < 10; i++) {
                scanf("%d", &num2[i]);
            }

            max = min = num2[0];
            for (i = 1; i < 10; i++) {
                if (num2[i] > max) {
                    max = num2[i];
                }
                if (num2[i] < min) {
                    min = num2[i];
                }
            }

            printf("Largest = %d\n", max);
            printf("Smallest = %d\n", min);

        } else if (choice == 3) {
            int num3[7], i;

            printf("Enter 7 numbers: \n");
            for (i = 0; i < 7; i++) {
                scanf("%d", &num3[i]);
            }

            printf("Original: ");
            for (i = 0; i < 7; i++) {
                printf("%d ", num3[i]);
            }
            printf("\nReversed: ");
            for (i = 6; i >= 0; i--) {
                printf("%d ", num3[i]);
            }
            printf("\n");

        } else if (choice != 0) {
            printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 0);

    return 0;
}
