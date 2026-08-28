// Programmed by: Ramos, Nick Daniel B.
#include <stdio.h>

int main() {
    
    for(int i = 5; i >= 1; i--){
        printf("%d",i);
            for(int j = i-1; j>=1 ; j--){
                printf("\t%d", j);
            }
        printf("\n");
    }
    
    return 0;
}