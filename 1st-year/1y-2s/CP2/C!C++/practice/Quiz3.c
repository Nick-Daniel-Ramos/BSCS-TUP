#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    srand(time(0));

    int num[45];
    int i, j, temp;

    for(i = 0; i < 45; i++){
        num[i] = i + 1;
    }

    for(i = 0; i < 6; i++){
        j = i + (rand() % (45 - i));
        temp = num[i];
        num[i] = num[j];
        num[j] = temp;
    }

    printf("Lotto number:\t");
    for(i = 0; i < 6; i++){
        printf("%02d\t", num[i]);
    }

    return 0;
}
