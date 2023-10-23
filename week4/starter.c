#include <stdio.h>

int main(){
    int numarray[10];
    int i=0;
    int total;
    int mean;
    printf("Enter numbers:\n");
    for(i=0; i<10; i++){
        scanf("%d",numarray);
        total += numarray[i];
    }
    mean = total/10;
    printf("%d",mean);
}