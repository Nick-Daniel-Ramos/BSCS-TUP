#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 2

//DECLARE
void getRecord(char n[][50],int a[],int b[],int c[]);
void display(char n[][50],int a[],int b[],int c[]);
float avg(int a, int b, int c);

int main(){
    //LOCAL VAR
    int q1[MAX],q2[MAX],q3[MAX];
    char name[MAX][50];
    float ave;

    getRecord(name,q1,q2,q3);
    display(name,q1,q2,q3);
    return 0;
}
//DEFINE
void getRecord(char name[][50], int a[], int b[], int c[]){
    for(int i=0;i<MAX;i++){

        printf("Input student name: ");
        fgets(name[i],sizeof(name[i]),stdin);
        int index = strcspn(name[i],"\n");
        name[i][index] = '\0';
        printf("Input the score on Quiz 1: ");
        scanf("%d",&a[i]);
        printf("Input the score on Quiz 2: ");
        scanf("%d",&b[i]);
        printf("Input the score on Quiz 3: ");
        scanf("%d",&c[i]);
        getchar();

    }
}
void display(char n[][50],int a[],int b[],int c[]){
    float ave;
    system("cls");
    printf("%-5s %-20s %-6s %-6s %-6s %-8s %-8s\n", "No.", "NAME", "Q1", "Q2", "Q3", "AVERAGE", "REMARKS");
    for(int i=0;i<MAX;i++){
        ave=avg(a[i],b[i],c[i]);
        printf("%-5d %-20s %-6d %-6d %-6d %-8.2f %-8s\n", i+1, n[i], a[i], b[i], c[i], ave, ave>=75?"PASSED":"FAILED");
    }
}
float avg(int a, int b, int c){
    return (float)(a+b+c)/3.0;
}

