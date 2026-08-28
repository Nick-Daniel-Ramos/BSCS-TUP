// Programmed by: Ramos, Nick Daniel B.

#include <stdio.h>

int main(void) {

    int scanf_result;
    int number;
    int choice;
    char again;


    do {
    printf("Menu Choices\n");
    printf("[1] Increasing Numbers\n");
    printf("[2] Decreasing Numbers\n");
    printf("[3] Even Numbers\n");
    printf("[4] Odd Numbers\n");
    printf("[5] Exit\n");


    do    {
    printf("Input a number from the menu choices: \n");
    scanf_result = scanf(" %d", &choice);
    if (scanf_result != 1) {
        printf("Invalid input. Please enter a number not a letter.\n");
        scanf("%*[^\n]");
        scanf("%*c");
        choice = 0;
        
    } else if (choice < 1 || choice > 5) {
        printf("Invalid choice. Please select a number between 1 and 5.\n");
    }
    } while (choice < 1 || choice > 5);

    if(choice == 5){
        printf("Exiting the program.\n");
        break;
    }
    
    do{
    printf("Input a number between 1-50: \n");
    scanf_result = scanf("%d", &number);
    if (scanf_result != 1) {
        printf("Invalid input. Please enter a number not a letter.\n");
        scanf("%*[^\n]");
        scanf("%*c");
        number = 0;
    } else if (number < 1 || number > 50) {
        printf("Invalid number. Please enter a number between 1 and 50.\n");
    }
    }while(number < 1 || number > 50 || scanf_result != 1);

    switch (choice) {
        case 1:
            for(int i = 1; i <= number; i++) {
                printf("%d ", i);
            }
            break;
        case 2:
            for(int j = number; j >= 1; j--) {
                printf("%d ", j);
            }
            break;
        case 3:
            for(int k = 1; k <= number; k++) {
                if(k % 2 == 0) {
                    printf("%d ", k);
                }
            }
            break;
        case 4:
            for(int x = 1; x <= number; x++) {
                if(x % 2 != 0) {
                    printf("%d ", x);
                }
            }
            break;
        case 5:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
    }

    printf("\nWould you like to try again? Press Y for Yes and N for No: \n");
    scanf(" %c", &again);

    } while (again == 'Y' || again == 'y');

    return 0;
}