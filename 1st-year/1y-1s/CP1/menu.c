//Programmed by: Ramos, Nick Daniel B.

#include <stdio.h>

int main(void){

    char choice;

    int age;
    int number;
    int score;
    int num1, num2, num3;
    char operator;

    printf("Menu Options\n");
    printf("[A]-Age\n");
    printf("[B]-EvenOdd\n");
    printf("[C]-Score\n");
    printf("[D]-GradeEquivalent\n");
    printf("[E]-Calculator/MDASR\n");
    printf("[F]-Profile\n");

    printf("Select a letter of choice: \n");
    scanf(" %c", &choice);

    if (choice == 'A'){
        printf("Enter your age: \n");
        scanf("%d", &age);

        if (age >= 18){
            printf("You are a qualified voter!\n");
        }
        else{
            printf("You are not a qualified voter!\n");
        }
    }
    else if (choice == 'B'){
        printf("Enter an integer: \n");
        scanf("%d", &number);

        if (number % 2 == 0){
            printf("The number %d is even!\n", number);
        }
        else{
            printf("The number %d is odd!\n", number);
        }

    } 
    else if(choice == 'C'){
        printf("Input your score: ");
        scanf("%d", &score);

        if (75<=score && score<=100){
            printf("Congratulations! you passed!\n");
        }
        else if (0<=score && score<=74){
            printf("Sorry, you failed!\n");
        }
        else{
            printf("Invalid Score!\n");
        }
    }
    else if (choice == 'D'){
        printf("Input your score: ");
        scanf("%d", &score);
        if (98<=score && score<=100){
            printf("The equivalent grade of %d is 1.00\n", score);
        }
        else if (95<=score && score<=97){
            printf("The equivalent grade of %d is 1.25\n", score);
        }
        else if (92<=score && score<=94){
            printf("The equivalent grade of %d is 1.50\n", score);
        }
        else if (89<=score && score<=91){
            printf("The equivalent grade of %d is 1.75\n", score);
        }
        else if (85<=score && score<=88){
            printf("The equivalent grade of %d is 2.00\n", score);
        }
        else if (82<=score && score<=84){
            printf("The equivalent grade of %d is 2.25\n", score);
        }
        else if (80<=score && score<=81){
            printf("The equivalent grade of %d is 2.50\n", score);
        }
        else if (77<=score && score<=79){
            printf("The equivalent grade of %d is 2.75\n", score);
        }
        else if (75<=score && score<=76){
            printf("The equivalent grade of %d is 3.00\n", score);
        }
        else if (0<=score && score<=74){
            printf("You Failed!\n");
        }
        else{
            printf("Invalid Score!\n");
        }
    }
    else if(choice == 'E'){
        printf("Enter first number: ");
        scanf("%d", &num1);
        printf("Enter an operator (+, -, *, /, %%): ");
        scanf(" %c", &operator);
        printf("Enter second number: ");
        scanf("%d", &num2);

        if (operator == '+'){
            num3 = num1 + num2;
            printf("The sum of %d and %d is equal to %d\n", num1, num2, num3);
        }
        else if (operator == '-'){
            num3 = num1 - num2;
            printf("The difference of %d and %d is equal to %d\n", num1, num2, num3);
        }
        else if (operator == '*'){
            num3 = num1 * num2;
            printf("The product of %d and %d is equal to %d\n", num1, num2, num3);
        }
        else if (operator == '/'){
            if (num2 != 0){
                num3 = num1 / num2;
                printf("The quotient of %d and %d is equal to %.2f\n", num1, num2, (float)num3);
            }
            else{
                printf("Error: Division by zero is not allowed.\n");
            }
        }
        else if (operator == '%'){
            if (num2 != 0){
                num3 = num1 % num2;
                printf("The remainder of %d and %d is equal to %d\n", num1, num2, num3);
            }
            else{
                printf("Error: Division by zero is not allowed.\n");
            }
        }
        else{
            printf("Invalid operator!\n");
        }
    }
    else if (choice == 'F'){
        printf("Programmed by: Ramos, Nick Daniel B.\n");

    }
    else{
        printf("Invalid choice!\n");
    }


    return 0;
}