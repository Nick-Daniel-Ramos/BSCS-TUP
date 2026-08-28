#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 5
void addR(int number);
void delR(int number);
void display();
int locate(int number);
int isFull();
int isEmpty();
int menu();

int last = -1; //initially empty array;
int num[MAX];

int main(){
    int n;

    while(1){
        switch(menu()){
        case 1:
            printf("Input number: ");
            scanf("%d", &n);
            addR(n);
            break;
        case 2:
            printf("Input number: ");
            scanf("%d", &n);
            delR(n);
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


int menu(){
    int choice;
    system("cls");

    printf("Menu\n");
    printf("[1]Add a record\n");
    printf("[2]Delete a record\n");
    printf("[3]Display all record\n");
    printf("[4]Exit\n");
    printf("Select 1-4 only: ");
    scanf("%d", &choice);

    return choice;
}

void addR(int number){
    if(isFull()){
        printf("Array is full");
        system("pause");
    } else {
        last++;
        num[last] = number;
        printf("%d is successfully added\n", number);
        system("pause");
    }
}

void delR(int number){
    int i,p;
    if(isEmpty()){
        printf("Nothing to delete\n");
        system("pause");
    } else {
        p = locate(number);
        if(p==-1){
            printf("%d is not found\n", number);
            system("pause");
        } else{
            for(i=p;i<last;i++){
                num[i] = num[i+1];
            }
            last--;
            printf("%d is successfully deleted\n", number);
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


    printf("The array contains:\n");
    for(i=0;i<=last;i++){
        printf("%d.) %d\n", i+1, num[i]);
        }
    }
    system("pause");
}

int locate(int number){
    for(int i=0;i<=last;i++){
        if(num[i]==number){
            return i;
        }
    }
    return -1;
}

int isFull(){
    return(last==MAX-1);
}

int isEmpty(){
    return (last==-1);
}
