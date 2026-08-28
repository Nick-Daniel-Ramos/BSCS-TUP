
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 5
void addR(char n[], int ag);
void delR(char n[]);
void display();
int locate(char n[]);
int isFull();
int isEmpty();
int menu();

char name[MAX][50];
int age[MAX];
int last = -1; //initially empty array;

int main(){
    char nm[50];
    int edad;

    while(1){
        switch(menu()){
        case 1:
            printf("Input Name: ");
            getchar();
            scanf(" %[^\n]", nm);
            printf("Input Age:");
            scanf("%d", &edad);
            addR(nm, edad);
            break;
        case 2:
            printf("Input Name: ");
            getchar();
            scanf(" %[^\n]", nm);
            delR(nm);
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

void addR(char n[], int ag){
    if(isFull()){
        printf("Array is full");
        system("pause");
    } else {
        last++;
        strcpy(name[last], n);
        age[last] = ag;
        printf("Record of %s is successfully added\n", n);
        system("pause");
    }
}

void delR(char n[]){
    int i,p;
    if(isEmpty()){
        printf("Nothing to delete\n");
        system("pause");
    } else {
        p = locate(n);
        if(p==-1){
            printf("Record of %s is not found\n", n);
            system("pause");
        } else{
            for(i=p;i<last;i++){
                strcpy(name[i], name[i+1]);
                age[i] = age[i+1];
            }
            last--;
            printf("Record of %s is successfully deleted\n", n);
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
    printf("%-4s %-20s %6s %10s\n", "No.", "NAME", "AGE", "REMARKS");
    for(i=0;i<=last;i++){
        printf("%-4d %-20s %6d %10s\n", i+1, name[i], age[i], age[i]>=18?"Adult":"Minor");
        }
    }
    system("pause");
}

int locate(char n[]){
    for(int i=0;i<=last;i++){
        if(strcmp(name[i], n)==0){
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
