#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 5

int nums[MAX];
int last = -1;

void addR(int number);
void delR(int number);
void display();

int locatePos(int number);
int locate(int number);
int isFull();
int isEmpty();
int menu();

int main(){

    int main_number;

    while(1){
        switch(menu()){
        case 1:
            printf("Input number: ");
            scanf("%d", &main_number);
            addR(main_number);
            break;
        case 2:
            printf("Input number: ");
            scanf("%d", &main_number);
            delR(main_number);
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

void addR(int number){
    if(isFull()){
        printf("Record is full\n");
        system("pause");
    } else {
        int i, p;
        p = locatePos(number);
        last++;
        for(i = last; i >= p; i--){
            nums[i+1] = nums[i];
        }
        nums[p] = number;
        printf("%d is successfully recorded\n", number);
        system("pause");
    }
}

void delR(int number){
    if(isEmpty()){
        printf("Record is empty\n");
        system("pause");
    } else {
        int i, pos;
        pos = locate (number);

        if(pos == -1){
            printf("%d is not found", number);
            system("pause");
        } else {
            for(i = pos; i < last; i++){
                    nums[i] = nums[i+1];
            }
            last--;
            printf("%d is successfully removed", number);
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
        printf("%d.) %d\n", i+1, nums[i]);
        }
    }
    system("pause");
}

int locatePos(int number){
    int  i;
    for(i = 0; i <= last; i++){
        if(number<nums[i]){
            return i;
        }
    }
    return i;
}

int locate(int number){
    int i;
    for(i=0; i <= last; i++){
        if(nums[i] == number){
            return i;
        }
    }
    return -1;
}

int isFull(){
    return last == MAX - 1;
}

int isEmpty(){
    return last == -1;
}

int menu(){
    int choice;

    system("cls");
    printf("MENU\n");
    printf("[1] Add Record\n");
    printf("[2] Delete Record\n");
    printf("[3] Display Record\n");
    printf("[4] Exit\n");
    printf("Select [1-4] only\n");
    scanf("%d", &choice);
    return choice;
}
