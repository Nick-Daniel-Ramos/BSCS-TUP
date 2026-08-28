// Programmed by RAMOS, NICK DANIEL B. (BSCS - 1B)
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int addition(int number);
int subtraction(int number);
int multiplication(int number);
int division(int number);

void number_generator(int *number1, int *number2);

int menu();

int main(){
    const int nTimes = 5;

    srand(time(0));

    while(1){
        switch(menu()){
        case 1:
            printf("You got %d out of %d\n", addition(nTimes), nTimes);
            system("pause");
            break;
        case 2:
            printf("You got %d out of %d\n", subtraction(nTimes), nTimes);
            system("pause");
            break;
        case 3:
            printf("You got %d out of %d\n", multiplication(nTimes), nTimes);
            system("pause");
            break;
        case 4:
            printf("You got %d out of %d\n", division(nTimes), nTimes);
            system("pause");
            break;
        case 5:
            exit(0);
        default:
            printf("1-4 lang po ma'am/sir\n");
            system("pause");
        }
    }
return 0;
}

int addition(int number){
    int num1, num2, answer, correct, i, counter = 0;

    for(i = 0; i < number; i++){

        number_generator(&num1, &num2);
        correct = num1 + num2;

        printf("What is %d + %d?: ", num1, num2);
        scanf("%d", &answer);
        getchar();

        if(answer != correct){
            printf("Wrong! the correct answer is %d\n", correct);
        } else{
            printf("Correct!\n");
            counter++;
        }
    }
    return counter;
}

int subtraction(int number){
    int num1, num2, answer, correct, i, counter = 0;

    for(i = 0; i < number; i++){
        number_generator(&num1, &num2);
        if(num1 <= num2){
            int temp = num1;
            num1 = num2;
            num2 = temp;
        }
        correct = num1 - num2;

        printf("What is %d - %d?: ", num1, num2);
        scanf("%d", &answer);
        getchar();

        if(answer != correct){
            printf("Wrong! the correct answer is %d\n", correct);
        } else{
            printf("Correct!\n");
            counter++;
        }
    }
    return counter;
}

int multiplication(int number){
    int num1, num2, answer, correct, i, counter = 0;

    for(i = 0; i < number; i++){
        number_generator(&num1, &num2);
        correct = num1 * num2;

        printf("What is %d * %d?: ", num1, num2);
        scanf("%d", &answer);
        getchar();

        if(answer != correct){
            printf("Wrong! the correct answer is %d\n", correct);
        } else{
            printf("Correct!\n");
            counter++;
        }
    }
    return counter;
}

int division(int number){
    int num1, num2, answer, correct, i, counter = 0;

    for(i = 0; i < number; i++){
        do{
            number_generator(&num1, &num2);
            correct = num1 / num2;
        } while(num1 % num2 != 0);

        printf("What is %d / %d?: ", num1, num2);
        scanf("%d", &answer);
        getchar();

        if(answer != correct){
            printf("Wrong! the correct answer is %d\n", correct);
        } else{
            printf("Correct!\n");
            counter++;
        }
    }
    return counter;
}

void number_generator(int *number1, int *number2){
    *number1 = (rand() % 20) + 1;
    *number2 = (rand() % 20) + 1;
}

int menu(){
    int choice;

    system("cls");
    printf("ARITHMETIC PRACTICE PROGRAM\n");
    printf("[1] Addition\n");
    printf("[2] Subtraction\n");
    printf("[3] Multiplication\n");
    printf("[4] Division\n");
    printf("[5] Exit\n");
    scanf("%d", &choice);
    getchar();
    system("cls");
    return choice;
}


