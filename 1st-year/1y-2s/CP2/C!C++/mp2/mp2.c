#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 2
//GLOBAL VAR
int q1[MAX],q2[MAX],q3[MAX];
char name[MAX][50];
float ave;
//DECLARE
void getRecord();
void display();
float avg(int a, int b, int c);

int main(){
    getRecord();
    display();
    return 0;
}
//DEFINE
void getRecord(){
    for(int i=0;i<MAX;i++){

        printf("Input student name: ");
        fgets(name[i],sizeof(name[i]),stdin);
        int index = strcspn(name[i],"\n");
        name[i][index] = '\0';
        printf("Input the score on Quiz 1: ");
        scanf("%d",&q1[i]);
        printf("Input the score on Quiz 2: ");
        scanf("%d",&q2[i]);
        printf("Input the score on Quiz 3: ");
        scanf("%d",&q3[i]);
        getchar();

    }
}
void display(){
    system("cls");
    printf("%-5s %-20s %-6s %-6s %-6s %-8s %-8s\n", "No.", "NAME", "Q1", "Q2", "Q3", "AVERAGE", "REMARKS");
    for(int i=0;i<MAX;i++){
        ave=avg(q1[i],q2[i],q3[i]);
        printf("%-5d %-20s %-6d %-6d %-6d %-8.2f %-8s\n", i+1, name[i], q1[i], q2[i], q3[i], ave, ave>=75?"PASSED":"FAILED");
    }
}
float avg(int a, int b, int c){
    return (float)(a+b+c)/3.0;
}
