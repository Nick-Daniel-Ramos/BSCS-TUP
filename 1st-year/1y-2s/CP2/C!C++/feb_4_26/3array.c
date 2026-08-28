#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

char name[MAX][50];
int quiz1[MAX], quiz2[MAX], quiz3[MAX], age[MAX];
float ave[MAX];
int last = -1;

void addR(char naME[], int qz1[], int qz2[], int qz3[], float average[], int aGE[]);
void delR(char naME[]);
void display();
int locate(char naME[]);
int isEmpty();
int isFull();
int menu();

int main(){
    int array_size = 50;
    char name_menu[array_size];
    int age_menu[array_size];
    int q1[array_size],q2[array_size],q3[array_size];
    float average_menu = 0.0;

    while(1){
        switch(menu()){
        case 1:
            printf("Input name: ");
            fgets(name_menu, array_size, stdin);
            name_menu[strcspn(name_menu, "\n")] = '\0';
            printf("Input age: ");
            scanf("%d", age_menu);
            printf("Quiz 1 score: ");
            scanf("%d", q1);
            printf("Quiz 2 score: ");
            scanf("%d", q2);
            printf("Quiz 3 score: ");
            scanf("%d", q3);

            average_menu = (float)(q1[0]+q2[0]+q3[0])/3.0;
            addR(name_menu, q1, q2, q3, &average_menu, age_menu);
            break;
        case 2:
            printf("Input name: ");
            fgets(name_menu, array_size, stdin);
            name_menu[strcspn(name_menu, "\n")] = '\0';
            delR(name_menu);
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Thank you for using me.");
            exit(0);
        default:
            printf("1-4 lang po mam/ser\n");
            system("pause");
        }
    }
    return 0;
}

void addR(char naME[], int qz1[], int qz2[], int qz3[], float average[], int aGE[]){
    if(isFull()){
        printf("The array is already full!\n");
        system("pause");
    } else if(locate(naME)!=-1){
            printf("%s is already in record\n", naME);
            system("pause");
            system("cls");
        } else {
        last++;
        strcpy(name[last], naME);
        quiz1[last] = qz1[0];
        quiz2[last] = qz2[0];
        quiz3[last] = qz3[0];
        ave[last] = average[0];
        age[last] = aGE[0];
        printf("%s is successfully added!\n", naME);
        system("pause");
    }
}
void delR(char naME[]){
    int i, p;
    if(isEmpty()){
        printf("The array is empty!\n");
        system("pause");
    } else {
        p = locate(naME);
        if(p==-1){
            printf("%s is not found\n", naME);
            system("pause");
        } else{
            for(i=p;i<last;i++){
                strcpy(name[i], name[i+1]);
                age[i]   = age[i+1];
                quiz1[i] = quiz1[i+1];
                quiz2[i] = quiz2[i+1];
                quiz3[i] = quiz3[i+1];
                ave[i]   = ave[i+1];
            }
            last--;
            printf("%s is successfully deleted\n", naME);
            system("pause");
        }
    }
}
void display(){
    int i;
    system("cls");

    if(isEmpty()){
        printf("Array is empty\n");
    }else {


    printf("%-4s %-20s %4s %10s %10s %10s %10s %10s\n", "No.", "NAME", "AGE", "QUIZ 1", "QUIZ 2", "QUIZ 3", "AVERAGE", "REMARKS");
    for(i=0;i<=last;i++){
        printf("%-4d %-20s %4d %10d %10d %10d %10.2f %10s\n", i+1, name[i], age[i], quiz1[i], quiz2[i], quiz3[i], ave[i], ave[i]>=75?"PASSED":"FAILED");
        }
    }
    system("pause");
}
int locate(char naME[]){
    int i;
    for(i=0;i<=last;i++){
        if(strcmp(name[i], naME)==0)
            return i;  // Return the index of the match
    }
    return -1;  // Not found
}

int isEmpty(){
    return last == -1;
}
int isFull(){
    return last == MAX-1;
}
int menu(){
    int choice;

    system("cls");
    printf("MENU\n\n");
    printf("[1]Add Record\n");
    printf("[2]Delete Record\n");
    printf("[3]Display All Record\n");
    printf("[4]Exit\n");
    printf("Select [1-4] only: ");
    scanf("%d", &choice);
    getchar();
    return choice;
}
