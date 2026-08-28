#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 2

int main(){
    int q1[MAX],q2[MAX],q3[MAX];
    char name[MAX][50];
    int div = 3;
    float ave;

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

//DISPLAY
    system("cls");
    printf("%-5s %-20s %-6s %-6s %-6s %-8s %-8s\n", "No.", "NAME", "Q1", "Q2", "Q3", "AVERAGE", "REMARKS");
    for(int i=0;i<MAX;i++){
        ave=(float)(q1[i]+q2[i]+q3[i])/div;
        printf("%-5d %-20s %-6d %-6d %-6d %-8.2f %-8s\n", i+1, name[i], q1[i], q2[i], q3[i], ave, ave>=75?"PASSED":"FAILED");
    }

    return 0;
}
