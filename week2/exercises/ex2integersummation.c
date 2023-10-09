#include <stdio.h>

int main(){
    // declare variables
    int numone;
    int numtwo;
    int sum;

    // retrieve user input
    printf("Enter a number: ");
    scanf("%d", &numone);

    printf("Enter a number: ");
    scanf("%d", &numtwo);
    
    // add user numbers
    sum = numone + numtwo;

    // print sum value to screen
    printf("The sum of %d and %d is %d.\n", numone, numtwo, sum);
    return 0;
}